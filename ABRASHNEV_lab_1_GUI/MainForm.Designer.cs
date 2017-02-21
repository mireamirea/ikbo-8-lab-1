/*
 * Created by SharpDevelop.
 * User: Nikita
 * Date: 14.02.2017
 * Time: 12:26
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
 using System.Windows.Forms;
namespace lab_1_GUI
{
	partial class MainForm
	{
		/// <summary>
		/// Designer variable used to keep track of non-visual components.
		/// </summary>
		private System.ComponentModel.IContainer components = null;
		private System.Windows.Forms.Button but_start;
		private System.Windows.Forms.TextBox tb_filename;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.TableLayoutPanel panel;
		private System.Windows.Forms.Label label2;
		private System.Windows.Forms.TextBox tb_executable_filename;
		private System.Windows.Forms.Button but_save;
		private System.Windows.Forms.Button but_addrow;
		
		/// <summary>
		/// Disposes resources used by the form.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing) {
				if (components != null) {
					components.Dispose();
				}
			}
			base.Dispose(disposing);
		}
		
		/// <summary>
		/// This method is required for Windows Forms designer support.
		/// Do not change the method contents inside the source code editor. The Forms designer might
		/// not be able to load this method if it was changed manually.
		/// </summary>
		private void InitializeComponent()
		{
			this.but_start = new System.Windows.Forms.Button();
			this.tb_filename = new System.Windows.Forms.TextBox();
			this.label1 = new System.Windows.Forms.Label();
			this.panel = new System.Windows.Forms.TableLayoutPanel();
			this.label2 = new System.Windows.Forms.Label();
			this.tb_executable_filename = new System.Windows.Forms.TextBox();
			this.but_save = new System.Windows.Forms.Button();
			this.but_addrow = new System.Windows.Forms.Button();
			this.SuspendLayout();
			// 
			// but_start
			// 
			this.but_start.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
			this.but_start.Location = new System.Drawing.Point(44, 159);
			this.but_start.Name = "but_start";
			this.but_start.Size = new System.Drawing.Size(232, 29);
			this.but_start.TabIndex = 0;
			this.but_start.Text = "Read";
			this.but_start.UseVisualStyleBackColor = true;
			this.but_start.Click += new System.EventHandler(this.but_start_Click);
			// 
			// tb_filename
			// 
			this.tb_filename.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
			this.tb_filename.ForeColor = System.Drawing.Color.DarkGreen;
			this.tb_filename.Location = new System.Drawing.Point(328, 105);
			this.tb_filename.Name = "tb_filename";
			this.tb_filename.Size = new System.Drawing.Size(262, 29);
			this.tb_filename.TabIndex = 1;
			this.tb_filename.Text = "data.dat";
			this.tb_filename.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
			this.tb_filename.TextChanged += new System.EventHandler(this.TextBox1TextChanged);
			// 
			// label1
			// 
			this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
			this.label1.Location = new System.Drawing.Point(415, 59);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(98, 30);
			this.label1.TabIndex = 2;
			this.label1.Text = "Data file:";
			this.label1.Click += new System.EventHandler(this.Label1Click);
			// 
			// panel
			// 
			this.panel.BackColor = System.Drawing.SystemColors.Window;
			this.panel.ColumnCount = 3;
			this.panel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 20F));
			this.panel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 60F));
			this.panel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 20F));
			this.panel.Font = new System.Drawing.Font("Times New Roman", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
			this.panel.Location = new System.Drawing.Point(98, 194);
			this.panel.Name = "panel";
			this.panel.RowCount = 1;
			this.panel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 10F));
			this.panel.Size = new System.Drawing.Size(500, 30);
			this.panel.TabIndex = 3;
			// 
			// label2
			// 
			this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
			this.label2.Location = new System.Drawing.Point(84, 59);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(183, 43);
			this.label2.TabIndex = 5;
			this.label2.Text = "Executable file:";
			// 
			// tb_executable_filename
			// 
			this.tb_executable_filename.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
			this.tb_executable_filename.ForeColor = System.Drawing.Color.DarkGreen;
			this.tb_executable_filename.Location = new System.Drawing.Point(25, 105);
			this.tb_executable_filename.Name = "tb_executable_filename";
			this.tb_executable_filename.Size = new System.Drawing.Size(262, 29);
			this.tb_executable_filename.TabIndex = 4;
			this.tb_executable_filename.Text = "lab_1";
			this.tb_executable_filename.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
			// 
			// but_save
			// 
			this.but_save.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
			this.but_save.Location = new System.Drawing.Point(344, 159);
			this.but_save.Name = "but_save";
			this.but_save.Size = new System.Drawing.Size(232, 29);
			this.but_save.TabIndex = 6;
			this.but_save.Text = "Save";
			this.but_save.UseVisualStyleBackColor = true;
			this.but_save.Click += new System.EventHandler(this.But_saveClick);
			// 
			// but_addrow
			// 
			this.but_addrow.AutoEllipsis = true;
			this.but_addrow.Location = new System.Drawing.Point(598, 108);
			this.but_addrow.Name = "but_addrow";
			this.but_addrow.Size = new System.Drawing.Size(75, 23);
			this.but_addrow.TabIndex = 7;
			this.but_addrow.Text = "Add Row";
			this.but_addrow.UseVisualStyleBackColor = true;
			this.but_addrow.Click += new System.EventHandler(this.But_addrowClick);
			// 
			// MainForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.AutoScroll = true;
			this.ClientSize = new System.Drawing.Size(677, 538);
			this.Controls.Add(this.but_addrow);
			this.Controls.Add(this.but_save);
			this.Controls.Add(this.label2);
			this.Controls.Add(this.tb_executable_filename);
			this.Controls.Add(this.panel);
			this.Controls.Add(this.label1);
			this.Controls.Add(this.tb_filename);
			this.Controls.Add(this.but_start);
			this.Name = "MainForm";
			this.Text = "Hello from IKBO-08-16";
			this.Load += new System.EventHandler(this.MainFormLoad);
			this.ResumeLayout(false);
			this.PerformLayout();

		}
	}
}
