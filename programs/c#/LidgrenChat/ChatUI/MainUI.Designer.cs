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
            this.SuspendLayout();
            // 
            // labelPublicIpAddress
            // 
            this.labelPublicIpAddress.AutoSize = true;
            this.labelPublicIpAddress.Location = new System.Drawing.Point(5, 428);
            this.labelPublicIpAddress.Name = "labelPublicIpAddress";
            this.labelPublicIpAddress.Size = new System.Drawing.Size(76, 13);
            this.labelPublicIpAddress.TabIndex = 1;
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
            this.textBoxChatInput.Location = new System.Drawing.Point(8, 369);
            this.textBoxChatInput.Name = "textBoxChatInput";
            this.textBoxChatInput.Size = new System.Drawing.Size(249, 20);
            this.textBoxChatInput.TabIndex = 3;
            this.textBoxChatInput.KeyDown += new System.Windows.Forms.KeyEventHandler(this.TextBoxChatInput_KeyDown);
            // 
            // textBoxChatHistory
            // 
            this.textBoxChatHistory.Location = new System.Drawing.Point(12, 12);
            this.textBoxChatHistory.Multiline = true;
            this.textBoxChatHistory.Name = "textBoxChatHistory";
            this.textBoxChatHistory.ReadOnly = true;
            this.textBoxChatHistory.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.textBoxChatHistory.Size = new System.Drawing.Size(245, 351);
            this.textBoxChatHistory.TabIndex = 2;
            this.textBoxChatHistory.WordWrap = false;
            // 
            // MainUI
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.textBoxChatHistory);
            this.Controls.Add(this.textBoxChatInput);
            this.Controls.Add(this.labelLanIpAddress);
            this.Controls.Add(this.labelPublicIpAddress);
            this.Name = "MainUI";
            this.ShowIcon = false;
            this.Text = "Lidgren Chat";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.MainUI_FormClosing);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label labelPublicIpAddress;
        private System.Windows.Forms.Label labelLanIpAddress;
        private System.Windows.Forms.TextBox textBoxChatInput;
        private System.Windows.Forms.TextBox textBoxChatHistory;
    }
}

