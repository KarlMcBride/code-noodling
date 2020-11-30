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
            // MainUI
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.labelLanIpAddress);
            this.Controls.Add(this.labelPublicIpAddress);
            this.Name = "MainUI";
            this.ShowIcon = false;
            this.Text = "Lidgren Chat";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label labelPublicIpAddress;
        private System.Windows.Forms.Label labelLanIpAddress;
    }
}

