using System;

namespace ChatNetworking
{
    /// <summary>
    /// Interface that the UI can use to create a client or client & server according to the option selected.
    /// Instances that run a server will also run a client on the same machine.
    /// </summary>
    public class ClientServerInterface
    {
        public event EventHandler<ParticipantMessageEventArgs>          InterfaceNewMessageReceived_Event;
        public event EventHandler<ConnectedParticipantListEventArgs>    InterfaceParticipantListChanged_Event;

        public bool M_Connected;

        private Client m_client;
        private Server m_server;

        /// <summary>
        /// Starts a client with provided participant name and server IP.
        /// </summary>
        /// <param name="_participantName">Name used to identify this participant.</param>
        /// <param name="_serverIp">Optional: server IP to connect to. Default is local host IP.</param>
        public void StartClient(string _participantName, string _serverIp = Constants.LOCAL_HOST_IP)
        {
            m_client = new Client(_participantName, _serverIp);
            m_client.NewMessageReceived_Event           += InterfaceNewMessageReceived_Event;
            m_client.NewParticipantListReceived_Event   += InterfaceParticipantListChanged_Event;
            M_Connected = true;
        }

        public void StartServer()
        {
            m_server = new Server();
        }

        public void SendMessage(string _message)
        {
            m_client.QueueMessage(_message);
        }

        public void StopClient()
        {
            if (m_client != null)
            {
                m_client.Stop();
            }
        }

        public void StopAll()
        {
            StopClient();
            if (m_server != null)
            {
                m_server.Stop();
            }
        }
    }
}
