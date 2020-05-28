#pragma once
#include"game.h"
namespace Secondform {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Summary for MyForm
	/// </summary>
	int N, M;
	int Maxsize;
	char dir;
	game* firstgame;
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::TextBox^ textBox4;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::Gold;
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->ColumnHeadersVisible = false;
			this->dataGridView1->GridColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->dataGridView1->Location = System::Drawing::Point(12, 12);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(729, 472);
			this->dataGridView1->TabIndex = 11;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::Highlight;
			this->button1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button1->Location = System::Drawing::Point(737, 318);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(86, 25);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Game";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Red;
			this->button2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button2->Location = System::Drawing::Point(737, 257);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(86, 25);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Start";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(750, 26);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(67, 17);
			this->label1->TabIndex = 3;
			this->label1->Text = L"size_field";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(771, 54);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(18, 17);
			this->label2->TabIndex = 4;
			this->label2->Text = L"N";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(771, 99);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(19, 17);
			this->label3->TabIndex = 5;
			this->label3->Text = L"M";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(734, 145);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(112, 17);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Max_size_snake";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(753, 74);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(62, 22);
			this->textBox1->TabIndex = 7;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged_1);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(753, 119);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(62, 22);
			this->textBox2->TabIndex = 8;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(753, 165);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(62, 22);
			this->textBox3->TabIndex = 9;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(765, 374);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(23, 28);
			this->button3->TabIndex = 12;
			this->button3->Text = L"Up";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(765, 431);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(23, 28);
			this->button4->TabIndex = 13;
			this->button4->Text = L"D";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(737, 403);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(23, 28);
			this->button5->TabIndex = 14;
			this->button5->Text = L"L";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(792, 403);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(23, 28);
			this->button6->TabIndex = 15;
			this->button6->Text = L"Right";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(737, 216);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 22);
			this->textBox4->TabIndex = 16;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox4_TextChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::Color::Gold;
			this->ClientSize = System::Drawing::Size(851, 485);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void textBox1_TextChanged_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	snake*first_snake;
	N = System::Convert::ToDouble(this->textBox1->Text);
	M = System::Convert::ToDouble(this->textBox2->Text);
	Maxsize = System::Convert::ToDouble(this->textBox3->Text);
	this->dataGridView1->RowCount = N + 2;
	this->dataGridView1->ColumnCount = M + 2;
	for (int i = 1; i < N+1 ; i++)
	{
		

		for (int j = 1; j < M+1 ; j++)
		{
			dataGridView1->Rows[i]->Cells[j]->Style->BackColor = Color::Blue;
		}
		dataGridView1->Rows[i]->Cells[0]->Style->BackColor = Color::Red;
		dataGridView1->Rows[i]->Cells[M + 1]->Style->BackColor = Color::Red;
	}
	for (int i = 0; i < M+2; i++)
	{
		dataGridView1->Rows[0]->Cells[i]->Style->BackColor = Color::Red;

		dataGridView1->Rows[N + 1]->Cells[i]->Style->BackColor = Color::Red;

	}
	//first_snake = new snake(N / 2, M / 2);
	//first_snake->show_snake(dataGridView1);
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	firstgame= new game (N,M,Maxsize);
	//snake snakke(N / 2, M / 2);
	//snakke.show_snake(dataGridView1);
	firstgame->play(dataGridView1,'L');
	textBox4->Text = "Играем";
	//firstgame->game_repeat(dataGridView1, 'L');
}
private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	int x, y;
	x = dataGridView1->NewRowIndex;
	//y = dataGridView1->Index;
}

private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	dir = 'U';
		int res = firstgame->play(dataGridView1, dir);
		Sleep(10);
		if (res == 3)
		{
			textBox4->Text = "Выйгрыш";
		}
		else
		{
			if (res == -1)
			{
				textBox4->Text = "Проигрыш";

			}
		}
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	dir = 'D';
		int res = firstgame->play(dataGridView1, dir);
		Sleep(10);
		if (res == 3)
		{
			textBox4->Text = "Выйгрыш";
		}
		else
		{
			if (res == -1)
			{
				textBox4->Text = "Проигрыш";

			}
		}
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	dir = 'L';
		int res = firstgame->play(dataGridView1, dir);
		Sleep(10);
		if (res == 3)
		{
			textBox4->Text = "Выйгрыш";
		}
		else
		{
			if (res == -1)
			{
				textBox4->Text = "Проигрыш";

			}
		}
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	dir = 'R';
		int res = firstgame->play(dataGridView1, dir);
		//Sleep(10);
		if (res == 3)
		{
			textBox4->Text = "Выйгрыш";
		}
		else
		{
			if (res == -1)
			{
				textBox4->Text = "Проигрыш";

			}
		}
}
private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
	  // private void O
};
}