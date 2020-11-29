using Lidgren.Network;
using System;
using System.Collections.Generic;
using System.Threading;

namespace ChatNetworking
{
    public class Server
    {
        private NetServer           m_LidgrenServer;
        private Thread              m_serverThread;
        private List<Participant>   m_ParticipantList;

        public Server()
        {
            ServerInit();
        }

        private void ServerInit()
        {
            m_ParticipantList = new List<Participant>();

            NetPeerConfiguration config = new NetPeerConfiguration(Constants.APP_IDENTIFIER)
            {
                Port = Constants.HOST_PORT,
                MaximumConnections = 200
            };
            config.EnableMessageType(NetIncomingMessageType.ConnectionApproval);
            m_LidgrenServer = new NetServer(config);
            m_LidgrenServer.Start();
            Console.WriteLine("Server Started");

            m_serverThread = new Thread(MainLoop);
            m_serverThread.Start();
        }

        private void MainLoop()
        {
            NetIncomingMessage incomingMessage;
            while (true)
            {
                incomingMessage = m_LidgrenServer.ReadMessage();

                if (incomingMessage != null && incomingMessage.LengthBytes > 0)
                {
                    switch (incomingMessage.MessageType)
                    {
                        // First message each client should create is request for connection approval.
                        case NetIncomingMessageType.ConnectionApproval:
                        {
                            if (incomingMessage.ReadByte() == (byte)PacketTypes.LOGIN)
                            {
                                Console.WriteLine("Incoming LOGIN");
                                incomingMessage.SenderConnection.Approve();

                                // Get participant name and add them to the participant list.
                                string newParticipantName = incomingMessage.ReadString();
                                m_ParticipantList.Add(new Participant(newParticipantName, incomingMessage.SenderConnection));

                                // Create message, that can be written and sent
                                NetOutgoingMessage outmsg = m_LidgrenServer.CreateMessage();
                                outmsg.Write((byte)PacketTypes.NOTIFY_CLIENTS_OF_NEW_PARTICIPANT);
                                outmsg.Write(m_ParticipantList.Count);

                                foreach (Participant participant in m_ParticipantList)
                                {
                                    outmsg.WriteAllProperties(participant);
                                }

                                // At this point, the packet will contain:
                                //    - byte            : packet type (PacketTypes.NOTIFY_CLIENTS_OF_NEW_PARTICIPANT).
                                //    - int n           : number of participants now present.
                                //    - participant * n : participant object containing their name and connection ID.

                                // Reliable = each packet arrives in order they were sent.
                                m_LidgrenServer.SendMessage(outmsg, incomingMessage.SenderConnection, NetDeliveryMethod.ReliableOrdered, 0);

                                Console.WriteLine("Approved new connection [" + newParticipantName + "] and updated participant list");
                            }
                            break;
                        }
                        // Data type is for messages manually sent from the client (i.e. participant's messages).
                        case NetIncomingMessageType.Data:
                        {
                            break;
                        }
                    }
                }

                Thread.Sleep(1000);
            }
        }
    }
}
