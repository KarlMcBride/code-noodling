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

            string lanIP = Utils.GetLanIpAddress();
            string pubIP = Utils.GetPublicIpAddress();

            labelLanIpAddress.Text      = "LAN IP   : " + lanIP;
            labelPublicIpAddress.Text   = "Public IP: " + pubIP;

            textBoxServerIP.Text = lanIP;

            m_clientServerInterface = new ClientServerInterface();

            DialogResult result = MessageBox.Show("Run chat server?", "Startup", MessageBoxButtons.YesNo);
            if (result == DialogResult.Yes)
            {
                m_clientServerInterface.StartServer();
            }

            m_clientServerInterface.InterfaceNewMessageReceived_Event       += HandleIncomingMessage;
            m_clientServerInterface.InterfaceParticipantListChanged_Event   += HandleParticipantListChange;
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
                groupBoxConnection.Enabled = false;
                textBoxChatInput.Enabled = true;
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

        private void HandleParticipantListChange(object _sender, ConnectedParticipantListEventArgs _participantListArgs)
        {
            BeginInvoke(new MethodInvoker(delegate
            {
                textBoxConnectedParticipants.Clear();

                foreach (var participant in _participantListArgs.ConnectedList)
                {
                    textBoxConnectedParticipants.AppendText(participant.Name);
                    textBoxConnectedParticipants.AppendText(Environment.NewLine);
                }
            }));
        }
    }
}
