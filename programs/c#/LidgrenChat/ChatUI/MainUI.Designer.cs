namespace ChatUI
{
    partial class MainUI
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.labelPublicIpAddress = new System.Windows.Forms.Label();
            this.labelLanIpAddress = new System.Windows.Forms.Label();
            this.textBoxChatInput = new System.Windows.Forms.TextBox();
            this.textBoxChatHistory = new System.Windows.Forms.TextBox();
            this.labelParticipantName = new System.Windows.Forms.Label();
            this.textBoxParticipantName = new System.Windows.Forms.TextBox();
            this.textBoxServerIP = new System.Windows.Forms.TextBox();
            this.labelServerIP = new System.Windows.Forms.Label();
            this.buttonConnectDisconnect = new System.Windows.Forms.Button();
            this.groupBoxConnection = new System.Windows.Forms.GroupBox();
            this.textBoxConnectedParticipants = new System.Windows.Forms.TextBox();
            this.groupBoxConnection.SuspendLayout();
            this.SuspendLayout();
            // 
            // labelPublicIpAddress
            // 
            this.labelPublicIpAddress.AutoSize = true;
            this.labelPublicIpAddress.Location = new System.Drawing.Point(5, 428);
            this.labelPublicIpAddress.Name = "labelPublicIpAddress";
            this.labelPublicIpAddress.Size = new System.Drawing.Size(76, 13);
            this.labelPublicIpAddress.TabIndex = 0;
            this.labelPublicIpAddress.Text = "Public IP: - - - -";
            // 
            // labelLanIpAddress
            // 
            this.labelLanIpAddress.AutoSize = true;
            this.labelLanIpAddress.Location = new System.Drawing.Point(5, 415);
            this.labelLanIpAddress.Name = "labelLanIpAddress";
            this.labelLanIpAddress.Size = new System.Drawing.Size(77, 13);
            this.labelLanIpAddress.TabIndex = 0;
            this.labelLanIpAddress.Text = "LAN IP   : - - - -";
            // 
            // textBoxChatInput
            // 
            this.textBoxChatInput.Enabled = false;
            this.textBoxChatInput.Location = new System.Drawing.Point(8, 369);
            this.textBoxChatInput.Name = "textBoxChatInput";
            this.textBoxChatInput.Size = new System.Drawing.Size(288, 20);
            this.textBoxChatInput.TabIndex = 1;
            this.textBoxChatInput.KeyDown += new System.Windows.Forms.KeyEventHandler(this.TextBoxChatInput_KeyDown);
            // 
            // textBoxChatHistory
            // 
            this.textBoxChatHistory.Location = new System.Drawing.Point(8, 12);
            this.textBoxChatHistory.Multiline = true;
            this.textBoxChatHistory.Name = "textBoxChatHistory";
            this.textBoxChatHistory.ReadOnly = true;
            this.textBoxChatHistory.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.textBoxChatHistory.Size = new System.Drawing.Size(288, 351);
            this.textBoxChatHistory.TabIndex = 0;
            this.textBoxChatHistory.TabStop = false;
            this.textBoxChatHistory.WordWrap = false;
            // 
            // labelParticipantName
            // 
            this.labelParticipantName.AutoSize = true;
            this.labelParticipantName.Location = new System.Drawing.Point(6, 16);
            this.labelParticipantName.Name = "labelParticipantName";
            this.labelParticipantName.Size = new System.Drawing.Size(60, 13);
            this.labelParticipantName.TabIndex = 0;
            this.labelParticipantName.Text = "Your Name";
            // 
            // textBoxParticipantName
            // 
            this.textBoxParticipantName.Location = new System.Drawing.Point(72, 13);
            this.textBoxParticipantName.Name = "textBoxParticipantName";
            this.textBoxParticipantName.Size = new System.Drawing.Size(125, 20);
            this.textBoxParticipantName.TabIndex = 2;
            this.textBoxParticipantName.TextChanged += new System.EventHandler(this.TextBoxParticipantName_TextChanged);
            // 
            // textBoxServerIP
            // 
            this.textBoxServerIP.Location = new System.Drawing.Point(72, 39);
            this.textBoxServerIP.Name = "textBoxServerIP";
            this.textBoxServerIP.Size = new System.Drawing.Size(125, 20);
            this.textBoxServerIP.TabIndex = 4;
            this.textBoxServerIP.TextChanged += new System.EventHandler(this.TextBoxServerIP_TextChanged);
            // 
            // labelServerIP
            // 
            this.labelServerIP.AutoSize = true;
            this.labelServerIP.Location = new System.Drawing.Point(6, 42);
            this.labelServerIP.Name = "labelServerIP";
            this.labelServerIP.Size = new System.Drawing.Size(51, 13);
            this.labelServerIP.TabIndex = 3;
            this.labelServerIP.Text = "Server IP";
            // 
            // buttonConnectDisconnect
            // 
            this.buttonConnectDisconnect.Enabled = false;
            this.buttonConnectDisconnect.Location = new System.Drawing.Point(96, 65);
            this.buttonConnectDisconnect.Name = "buttonConnectDisconnect";
            this.buttonConnectDisconnect.Size = new System.Drawing.Size(75, 23);
            this.buttonConnectDisconnect.TabIndex = 5;
            this.buttonConnectDisconnect.Text = "Connect";
            this.buttonConnectDisconnect.UseVisualStyleBackColor = true;
            this.buttonConnectDisconnect.Click += new System.EventHandler(this.ButtonConnectDisconnect_Click);
            // 
            // groupBoxConnection
            // 
            this.groupBoxConnection.Controls.Add(this.buttonConnectDisconnect);
            this.groupBoxConnection.Controls.Add(this.labelParticipantName);
            this.groupBoxConnection.Controls.Add(this.textBoxServerIP);
            this.groupBoxConnection.Controls.Add(this.textBoxParticipantName);
            this.groupBoxConnection.Controls.Add(this.labelServerIP);
            this.groupBoxConnection.Location = new System.Drawing.Point(311, 12);
            this.groupBoxConnection.Name = "groupBoxConnection";
            this.groupBoxConnection.Size = new System.Drawing.Size(203, 100);
            this.groupBoxConnection.TabIndex = 6;
            this.groupBoxConnection.TabStop = false;
            // 
            // textBoxConnectedParticipants
            // 
            this.textBoxConnectedParticipants.Location = new System.Drawing.Point(311, 118);
            this.textBoxConnectedParticipants.Multiline = true;
            this.textBoxConnectedParticipants.Name = "textBoxConnectedParticipants";
            this.textBoxConnectedParticipants.ReadOnly = true;
            this.textBoxConnectedParticipants.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.textBoxConnectedParticipants.Size = new System.Drawing.Size(203, 245);
            this.textBoxConnectedParticipants.TabIndex = 7;
            this.textBoxConnectedParticipants.TabStop = false;
            this.textBoxConnectedParticipants.WordWrap = false;
            // 
            // MainUI
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.textBoxConnectedParticipants);
            this.Controls.Add(this.groupBoxConnection);
            this.Controls.Add(this.textBoxChatHistory);
            this.Controls.Add(this.textBoxChatInput);
            this.Controls.Add(this.labelLanIpAddress);
            this.Controls.Add(this.labelPublicIpAddress);
            this.Name = "MainUI";
            this.ShowIcon = false;
            this.Text = "Lidgren Chat";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.MainUI_FormClosing);
            this.groupBoxConnection.ResumeLayout(false);
            this.groupBoxConnection.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label labelPublicIpAddress;
        private System.Windows.Forms.Label labelLanIpAddress;
        private System.Windows.Forms.TextBox textBoxChatInput;
        private System.Windows.Forms.TextBox textBoxChatHistory;
        private System.Windows.Forms.Label labelParticipantName;
        private System.Windows.Forms.TextBox textBoxParticipantName;
        private System.Windows.Forms.TextBox textBoxServerIP;
        private System.Windows.Forms.Label labelServerIP;
        private System.Windows.Forms.Button buttonConnectDisconnect;
        private System.Windows.Forms.GroupBox groupBoxConnection;
        private System.Windows.Forms.TextBox textBoxConnectedParticipants;
    }
}

