using ChatNetworking;
using System.Windows.Forms;

namespace ChatUI
{
    public partial class MainUI : Form
    {
        Server m_server;
        Client m_clientAlpha;
        Client m_clientBravo;

        public MainUI()
        {
            InitializeComponent();

            m_server = new Server();
            m_clientAlpha = new Client("Client Alpha");
            m_clientBravo = new Client("Client Bravo");

            m_clientAlpha.QueueMessage("Alpha's colour: amber");
            m_clientAlpha.QueueMessage("Alpha's location: NI");
            m_clientBravo.QueueMessage("Bravo's colour: blue");

            labelLanIpAddress.Text      = "LAN IP   : " + Utils.GetLanIpAddress();
            labelPublicIpAddress.Text   = "Public IP: " + Utils.GetPublicIpAddress();
        }
    }
}
