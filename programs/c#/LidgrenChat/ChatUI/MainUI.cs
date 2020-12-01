using ChatNetworking;
using System;
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

            m_clientServerInterface.InterfaceNewMessageReceived_Event += HandleIncomingMessage;

            m_clientServerInterface.SendMessage("Hello");
        }

        private void MainUI_FormClosing(object sender, FormClosingEventArgs e)
        {
            m_clientServerInterface.Stop();
        }

        private void TextBoxChatInput_KeyDown(object sender, KeyEventArgs e)
        {
            if (Text.Length > 0 && e.KeyCode == Keys.Enter)
            {
                e.SuppressKeyPress = true;  // Disable Windows "ding" playing when pressing enter.
                m_clientServerInterface.SendMessage(textBoxChatInput.Text);
                textBoxChatInput.Text = "";
            }
        }

        private void HandleIncomingMessage(object _sender, ParticipantMessageEventArgs _messageArgs)
        {

        }
    }
}
