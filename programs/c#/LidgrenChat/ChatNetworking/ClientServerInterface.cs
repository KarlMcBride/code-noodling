namespace ChatNetworking
{
    /// <summary>
    /// Interface that the UI can use to create a client or client & server according to the option selected.
    /// Instances that run a server will also run a client on the same machine.
    /// </summary>
    public class ClientServerInterface
    {
        private Client m_client;
        private Server m_server;

        public void StartClient(string _participantName, string _serverIp)
        {
            m_client = new Client(_participantName, _serverIp);
        }

        public void StartClientAndServer(string _participantName)
        {
            m_server = new Server();
            StartClient(_participantName, Constants.LOCAL_HOST_IP);
        }

        public void SendMessage(string _message)
        {
            m_client.QueueMessage(_message);
        }

        public void Stop()
        {
            if (m_client != null)
            {
                m_client.Stop();
            }
            if (m_server != null)
            {
                m_server.Stop();
            }
        }
    }
}
