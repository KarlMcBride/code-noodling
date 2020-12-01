using Lidgren.Network;
using System;
using System.Collections.Generic;
using System.Threading;

namespace ChatNetworking
{
    public class Server
    {
        private NetServer           m_server;
        private Thread              m_serverThread;
        private List<Participant>   m_ParticipantList;

        private bool                m_keepRunning;


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
            m_server = new NetServer(config);
            m_server.Start();
            Console.WriteLine("Server Started");

            m_serverThread = new Thread(MainLoop);
            m_serverThread.Start();
        }


        private void MainLoop()
        {
            NetIncomingMessage incomingMessage;

            m_keepRunning = true;
            while (m_keepRunning)
            {
                incomingMessage = m_server.ReadMessage();

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
                                NetOutgoingMessage outgoingMessage = m_server.CreateMessage();
                                outgoingMessage.Write((byte)PacketTypes.NOTIFY_CLIENTS_OF_NEW_PARTICIPANT);
                                outgoingMessage.Write(m_ParticipantList.Count);

                                foreach (Participant participant in m_ParticipantList)
                                {
                                    outgoingMessage.WriteAllProperties(participant);
                                }

                                // At this point, the packet will contain:
                                //    - byte            : packet type (PacketTypes.NOTIFY_CLIENTS_OF_NEW_PARTICIPANT).
                                //    - int n           : number of participants now present.
                                //    - participant * n : participant object containing their name and connection ID.

                                // Reliable = each packet arrives in order they were sent.
                                m_server.SendMessage(outgoingMessage, incomingMessage.SenderConnection, NetDeliveryMethod.ReliableOrdered, 0);

                                Console.WriteLine("Approved new connection [" + newParticipantName + "]");
                            }
                            break;
                        }
                        // Data type is for messages manually sent from the client (i.e. participant's messages).
                        case NetIncomingMessageType.Data:
                        {
                            // First byte indicates message type. Read it before logic switching as once we read it,
                            // it's removed from the incoming packet.
                            byte messageType = incomingMessage.ReadByte();
                            if (messageType == (byte)PacketTypes.NOTIFY_CLIENTS_OF_NEW_MESSAGE)
                            {
                                // Read message into class instance via properties, then iterate over each participant to receive it.
                                ParticipantMessage messageToBeRelayed = new ParticipantMessage();
                                incomingMessage.ReadAllProperties(messageToBeRelayed);

                                Console.WriteLine("Relaying message from [" + messageToBeRelayed.Sender + "]: [" + messageToBeRelayed.Message + "]");
                                
                                NetOutgoingMessage outgoingMessage = m_server.CreateMessage();
                                outgoingMessage.Write((byte)PacketTypes.NOTIFY_CLIENTS_OF_NEW_MESSAGE);
                                outgoingMessage.WriteAllProperties(messageToBeRelayed);
                                // Using 'm_server.Connections' as this contains connections for each connected client.
                                // This results in a client that sends a message to receive it again.
                                m_server.SendMessage(outgoingMessage, m_server.Connections, NetDeliveryMethod.ReliableOrdered, 0);
                            }

                            break;
                        }
                    }
                }

                Thread.Sleep(Constants.MAIN_LOOP_DELAY_MS);
            }

            m_server.Shutdown("Server stopping");
        }


        public void Stop()
        {
            m_keepRunning = false;
            m_serverThread.Join();
        }
    }
}
