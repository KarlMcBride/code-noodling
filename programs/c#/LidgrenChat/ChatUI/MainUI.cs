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
                m_clientServerInterface.StartServer();
            }

            m_clientServerInterface.InterfaceNewMessageReceived_Event += HandleIncomingMessage;
        }

        private void MainUI_FormClosing(object sender, FormClosingEventArgs e)
        {
            m_clientServerInterface.StopAll();
        }

        private void TextBoxChatInput_KeyDown(object sender, KeyEventArgs e)
        {
            if (textBoxChatInput.Text.Length > 0 && e.KeyCode == Keys.Enter)
            {
                e.SuppressKeyPress = true;  // Disable Windows "ding" playing when pressing enter.
                m_clientServerInterface.SendMessage(textBoxChatInput.Text);
                textBoxChatInput.Clear();
            }
        }

        private void TextBoxParticipantName_TextChanged(object sender, EventArgs e)
        {
            VerifySettings();
        }

        private void TextBoxServerIP_TextChanged(object sender, EventArgs e)
        {
            VerifySettings();
        }

        private void VerifySettings()
        {
            if (textBoxParticipantName.Text.Length > 0 && textBoxServerIP.Text.Length > 0)
            {
                buttonConnectDisconnect.Enabled = true;
            }
            else
            {
                buttonConnectDisconnect.Enabled = false;
            }
        }

        private void ButtonConnectDisconnect_Click(object sender, EventArgs e)
        {
            if (!m_clientServerInterface.M_Connected)
            {
                m_clientServerInterface.StartClient(textBoxParticipantName.Text, textBoxServerIP.Text);
                buttonConnectDisconnect.Text = "Disconnect";
                textBoxChatInput.Enabled = true;
            }
            else
            {
                m_clientServerInterface.StopClient();
                buttonConnectDisconnect.Text = "Connect";
                textBoxChatInput.Enabled = false;
            }
        }

        private void HandleIncomingMessage(object _sender, ParticipantMessageEventArgs _messageArgs)
        {
            BeginInvoke(new MethodInvoker(delegate
            {
                textBoxChatHistory.AppendText(_messageArgs.Time.ToShortTimeString() + ": " + _messageArgs.Sender + ": " + _messageArgs.Message);
                textBoxChatHistory.AppendText(Environment.NewLine);
            }));
        }
    }
}
