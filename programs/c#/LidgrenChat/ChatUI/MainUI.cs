using ChatNetworking;
using System.Windows.Forms;

namespace ChatUI
{
    public partial class MainUI : Form
    {
        private ClientServerInterface m_clientServerInterface;

        public MainUI()
        {
            InitializeComponent();

            labelLanIpAddress.Text      = "LAN IP   : " + Utils.GetLanIpAddress();
            labelPublicIpAddress.Text   = "Public IP: " + Utils.GetPublicIpAddress();

            m_clientServerInterface = new ClientServerInterface();

            DialogResult result = MessageBox.Show("Run chat server?", "Startup", MessageBoxButtons.YesNo);
            if (result == DialogResult.Yes)
            {
                m_clientServerInterface.StartClientAndServer("Bob");
            }

            m_clientServerInterface.SendMessage("Hello");
        }

        private void MainUI_FormClosing(object sender, FormClosingEventArgs e)
        {
            m_clientServerInterface.Stop();
        }
    }
}
