using ChatNetworking;
using System.Windows.Forms;

namespace ChatUI
{
    public partial class ChatUI : Form
    {
        Server m_server;
        Client m_client;

        public ChatUI()
        {
            InitializeComponent();

            m_server = new Server();
            m_client = new Client("ChatUI");
        }
    }
}
