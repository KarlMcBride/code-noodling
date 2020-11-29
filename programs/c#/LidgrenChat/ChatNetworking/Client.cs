using Lidgren.Network;
using System;
using System.Collections.Generic;
using System.Threading;

namespace ChatNetworking
{
    public class Client
    {
        private string              m_name;
        private NetClient           m_client;
        private Thread              m_clientThread;
        private List<Participant>   m_ParticipantList;

        public Client(string _name)
        {
            m_name = _name;
            m_clientThread = new Thread(ClientInit);
            m_clientThread.Start();
        }

        public void ClientInit()
        {
            m_ParticipantList = new List<Participant>();

            NetPeerConfiguration config = new NetPeerConfiguration(Constants.APP_IDENTIFIER);

            m_client = new NetClient(config);
            m_client.Start();

            NetOutgoingMessage outmsg = m_client.CreateMessage();
            outmsg.Write((byte)PacketTypes.LOGIN);
            outmsg.Write(m_name);
            m_client.Connect(Constants.HOST_IP, Constants.HOST_PORT, outmsg);

            WaitForStartingInfo();
        }

        private void WaitForStartingInfo()
        {
            // When this is set to true, we are approved and ready to go
            bool canStart = false;

            NetIncomingMessage incomingMessage;
            
            // Loop until approved.
            while (!canStart)
            {
                if ((incomingMessage = m_client.ReadMessage()) != null)
                {
                    switch (incomingMessage.MessageType)
                    {
                        // All manually sent messages are type of "Data".
                        case NetIncomingMessageType.Data:
                        {
                            // First byte indicates message type. Read it before logic switching as once we read it,
                            // it's removed from the incoming packet.
                            byte messageType = incomingMessage.ReadByte();
                            if (messageType == (byte)PacketTypes.NOTIFY_CLIENTS_OF_NEW_PARTICIPANT)
                            {
                                // Packet will contain
                                //    - byte            : packet type (PacketTypes.NOTIFY_CLIENTS_OF_NEW_PARTICIPANT).
                                //    - int n           : number of participants now present.
                                //    - participant * n : participant object containing their name and connection ID.

                                m_ParticipantList.Clear();
                                int participantCount = incomingMessage.ReadInt32();

                                // Iterate all players
                                for (int index = 0; index < participantCount; index++)
                                {
                                    // Create new character to hold the data
                                    Participant newParticipant = new Participant();

                                    // Read all properties from the packet and add them into the newParticipant instance.
                                    incomingMessage.ReadAllProperties(newParticipant);
                                    m_ParticipantList.Add(newParticipant);
                                }

                                canStart = true;

                                Console.WriteLine("Client connected");
                            }
                            break;
                        }
                        case NetIncomingMessageType.StatusChanged:
                        {
                            Console.WriteLine("Status changed: [" + incomingMessage.SenderConnection.Status + "]");
                            break;
                        }
                        default:
                        {
                            Console.WriteLine("Unknown message type received: [" + incomingMessage.MessageType + "]");
                            break;
                        }
                    }
                }
            }
        }

        private void MainLoop()
        {

        }
    }
}
