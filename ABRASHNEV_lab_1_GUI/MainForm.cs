/*
 * Created by SharpDevelop.
 * User: Nikita
 * Date: 14.02.2017
 * Time: 12:26
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
using System;
using System.Collections.Generic;
using System.Drawing;
using System.Diagnostics;
using System.Windows.Forms;
using System.IO;

namespace lab_1_GUI
{
	/// <summary>
	/// Description of MainForm.
	/// </summary>
	public partial class MainForm : Form
	{
		protected int iRowCount;
		
		public MainForm()
		{
			//
			// The InitializeComponent() call is required for Windows Forms designer support.
			//
			InitializeComponent();
			
			ConstructPanel();
		}
		
		// Inserts headers of the table
		void ConstructPanel(){
			panel.Controls.Clear();
			
			Font HeadersFont = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
			panel.Controls.Add(new Label() { Text = "Int", Font = HeadersFont}, 0, 0);
			panel.Controls.Add(new Label() { Text = "Char[255]", Font = HeadersFont }, 1, 0);
			panel.Controls.Add(new Label() { Text = "Float", Font = HeadersFont }, 2, 0);	
		}
		
		void InsertRow(string cell1 = "hey", string cell2 = "ho", string cell3 = "yo-yo"){
				panel.RowCount = panel.RowCount + 1;
				panel.RowStyles.Add(new RowStyle(SizeType.Absolute, 18F));
				panel.Controls.Add(new TextBox() { Text = cell1 }, 0, panel.RowCount-1);
				panel.Controls.Add(new TextBox() { Text = cell2, Width = 300}, 1, panel.RowCount-1);
				panel.Controls.Add(new TextBox() { Text = cell3 }, 2, panel.RowCount-1);
				
				iRowCount++;
			}
		
		void but_start_Click(object sender, EventArgs e)
		{
			ConstructPanel();
			
			iRowCount = 0;
			
			// Reading data from file through usage of lab_1.exe
			string data_filename = tb_filename.Text;
			Process proc = new System.Diagnostics.Process ();
			proc.StartInfo.FileName = tb_executable_filename.Text;
			proc.StartInfo.Arguments = "\"" + data_filename + "\"";
			proc.StartInfo.UseShellExecute = false; 
			proc.StartInfo.RedirectStandardOutput = true;
            proc.Start ();
			
            // Static data
            int ch = 9; // tab
            char[] sep = new char[1]; // separator array
            sep[0] = (char)ch;
            
            // Writing data to the table
            while (!proc.StandardOutput.EndOfStream) {
            	string s = proc.StandardOutput.ReadLine ();
            	// if it is data
            	if (s.IndexOf(sep[0]) > 0){
            		string[] str = s.Split(sep);
            		InsertRow (str[0], str[1], str[2]);
            	}
            	// else there is the size of the file:
            	else {
            		panel.Height = 18 * iRowCount + 30;
            		MessageBox.Show("Parsing data from \"" + data_filename + "\" was succeffully finished. " + s);
            	}
            }
            //MessageBox.Show(panel.Controls[7].Text);
            
		}
		
		
		void TextBox1TextChanged(object sender, EventArgs e)
		{
	
		}
		void MainFormLoad(object sender, EventArgs e)
		{
	
		}
		void Label1Click(object sender, EventArgs e)
		{
	
		}
		void TableLayoutPanel1Paint(object sender, PaintEventArgs e)
		{
	
		}
		
		// writing binary data
		void But_saveClick(object sender, EventArgs e)
		{
			StreamWriter sw;
			
			//create the file
			try
			{
				sw = new StreamWriter(new FileStream("temp.dat", FileMode.Create));
			}
			catch (IOException er)
			{
				MessageBox.Show(er.Message + "\n Cannot create file.");
				return;
			}
			
			//writing into the file
			try
			{
				sw.WriteLine(iRowCount);
				
				int iMaxElements = iRowCount * 3 + 3;
				for (int iCurElement = 3; iCurElement < iMaxElements; iCurElement++){
					string sCurElement = panel.Controls[iCurElement].Text;
					sw.WriteLine(sCurElement);
				}
			}
			
			catch (IOException er)
			{
				MessageBox.Show(er.Message + "\n Cannot write to file.");
				return;
			}
			sw.Close();
			
			// Saving data from file through usage of lab_1_Binary_Convertor.exe
			string data_filename = tb_filename.Text;
			Process proc = new System.Diagnostics.Process ();
			proc.StartInfo.FileName = "lab_1_Binary_Convertor";
			proc.StartInfo.Arguments = "\"" + data_filename + "\"";
			proc.StartInfo.UseShellExecute = false; 
			proc.StartInfo.RedirectStandardOutput = true;
            proc.Start ();
			MessageBox.Show("Changes were saved successfully");
		}
		
		// Adds row to a table
		void But_addrowClick(object sender, EventArgs e){
			MessageBox.Show("New row was added at the bottom of the table");
			InsertRow("", "", "");
			panel.Height += 18;
		}
	}
}
