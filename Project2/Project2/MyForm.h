#pragma once

namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button2;
	protected:
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::ComboBox^ comboBox2;

	private: System::Windows::Forms::Label^ label1;


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(130, 181);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(94, 27);
			this->button2->TabIndex = 18;
			this->button2->Text = L"Сброс";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(26, 181);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(94, 27);
			this->button1->TabIndex = 17;
			this->button1->Text = L"Вычислить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(269, 83);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(16, 17);
			this->label4->TabIndex = 15;
			this->label4->Text = L"=";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(208, 80);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(30, 22);
			this->textBox3->TabIndex = 13;
			this->textBox3->Text = L"0";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(117, 80);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(30, 22);
			this->textBox2->TabIndex = 12;
			this->textBox2->Text = L"0";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(26, 80);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(30, 22);
			this->textBox1->TabIndex = 10;
			this->textBox1->Text = L"0";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"+", L"-", L"*", L"/" });
			this->comboBox1->Location = System::Drawing::Point(62, 79);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(49, 24);
			this->comboBox1->TabIndex = 19;
			this->comboBox1->Text = L"+";
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"+", L"-", L"*", L"/" });
			this->comboBox2->Location = System::Drawing::Point(153, 79);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(49, 24);
			this->comboBox2->TabIndex = 20;
			this->comboBox2->Text = L"+";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(318, 82);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(16, 17);
			this->label1->TabIndex = 21;
			this->label1->Text = L"0";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(363, 227);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"Lab 1.2";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		bool Protect() {
			if ((textBox1->Text->Length == 0) || (textBox2->Text->Length == 0) || (textBox3->Text->Length == 0)) { return false; }

			for (int i = 0; i < textBox1->Text->Length; i++) {
				if ((textBox1->Text[i] >= '0') && (textBox1->Text[i] <= '9') || (textBox1->Text[i] == ',')) {}
				else { return false; }
			}
			for (int i = 0; i < textBox2->Text->Length; i++) {
				if ((textBox2->Text[i] >= '0') && (textBox2->Text[i] <= '9') || (textBox2->Text[i] == ',')) {}
				else { return false; }
			}
			for (int i = 0; i < textBox3->Text->Length; i++) {
				if ((textBox3->Text[i] >= '0') && (textBox3->Text[i] <= '9') || (textBox3->Text[i] == ',')) {}
				else { return false; }
			}
			return true;
		}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (Protect()) {
			if (comboBox1->SelectedItem == "+") {
				if (comboBox2->SelectedItem == "+") { label1->Text = System::Convert::ToString(System::Convert::ToDouble(textBox1->Text) + System::Convert::ToDouble(textBox2->Text) + System::Convert::ToDouble(textBox3->Text)); }
				if (comboBox2->SelectedItem == "-") { label1->Text = System::Convert::ToString(System::Convert::ToDouble(textBox1->Text) + System::Convert::ToDouble(textBox2->Text) - System::Convert::ToDouble(textBox3->Text)); }
				if (comboBox2->SelectedItem == "*") { label1->Text = System::Convert::ToString(System::Convert::ToDouble(textBox1->Text) + (System::Convert::ToDouble(textBox2->Text) * System::Convert::ToDouble(textBox3->Text))); }
				if (comboBox2->SelectedItem == "/") {
					if (System::Convert::ToDouble(textBox3->Text) != 0) {
						label1->Text = System::Convert::ToString(System::Convert::ToDouble(textBox1->Text) + (System::Convert::ToDouble(textBox2->Text) / System::Convert::ToDouble(textBox3->Text)));
					}
					else { MessageBox::Show("Попытка деления на ноль!", "Ошибка"); }
				}
			}
			if (comboBox1->SelectedItem == "-") {
				if (comboBox2->SelectedItem == "+") { label1->Text = System::Convert::ToString((System::Convert::ToDouble(textBox1->Text) - System::Convert::ToDouble(textBox2->Text)) + System::Convert::ToDouble(textBox3->Text)); }
				if (comboBox2->SelectedItem == "-") { label1->Text = System::Convert::ToString((System::Convert::ToDouble(textBox1->Text) - System::Convert::ToDouble(textBox2->Text)) - System::Convert::ToDouble(textBox3->Text)); }
				if (comboBox2->SelectedItem == "*") { label1->Text = System::Convert::ToString(System::Convert::ToDouble(textBox1->Text) - (System::Convert::ToDouble(textBox2->Text) * System::Convert::ToDouble(textBox3->Text))); }
				if (comboBox2->SelectedItem == "/") {
					if (comboBox2->SelectedItem == "/") {
						label1->Text = System::Convert::ToString(System::Convert::ToDouble(textBox1->Text) - (System::Convert::ToDouble(textBox2->Text) / System::Convert::ToDouble(textBox3->Text)));
					}
					else {
						MessageBox::Show("Попытка деления на ноль!", "Ошибка");
					}
				}
			}
			if (comboBox1->SelectedItem == "*") {
				if (comboBox2->SelectedItem == "+") { label1->Text = System::Convert::ToString((System::Convert::ToDouble(textBox1->Text) * System::Convert::ToDouble(textBox2->Text)) + System::Convert::ToDouble(textBox3->Text)); }
				if (comboBox2->SelectedItem == "-") { label1->Text = System::Convert::ToString((System::Convert::ToDouble(textBox1->Text) * System::Convert::ToDouble(textBox2->Text)) - System::Convert::ToDouble(textBox3->Text)); }
				if (comboBox2->SelectedItem == "*") { label1->Text = System::Convert::ToString(System::Convert::ToDouble(textBox1->Text) * System::Convert::ToDouble(textBox2->Text) * System::Convert::ToDouble(textBox3->Text)); }
				if (comboBox2->SelectedItem == "/") {
					if (comboBox2->SelectedItem == "/") {
						label1->Text = System::Convert::ToString((System::Convert::ToDouble(textBox1->Text) * System::Convert::ToDouble(textBox2->Text)) / System::Convert::ToDouble(textBox3->Text));
					}
					else {
						MessageBox::Show("Попытка деления на ноль!", "Ошибка");
					}
				}
			}
			if (comboBox1->SelectedItem == "/") {
				if (System::Convert::ToDouble(textBox2->Text) != 0) {
					if (comboBox2->SelectedItem == "+") { label1->Text = System::Convert::ToString((System::Convert::ToDouble(textBox1->Text) / System::Convert::ToDouble(textBox2->Text)) + System::Convert::ToDouble(textBox3->Text)); }
					if (comboBox2->SelectedItem == "-") { label1->Text = System::Convert::ToString((System::Convert::ToDouble(textBox1->Text) / System::Convert::ToDouble(textBox2->Text)) - System::Convert::ToDouble(textBox3->Text)); }
					if (comboBox2->SelectedItem == "*") { label1->Text = System::Convert::ToString((System::Convert::ToDouble(textBox1->Text) / System::Convert::ToDouble(textBox2->Text)) * System::Convert::ToDouble(textBox3->Text)); }
					if (System::Convert::ToDouble(textBox3->Text) != 0) {
						if (comboBox2->SelectedItem == "/") { label1->Text = System::Convert::ToString((System::Convert::ToDouble(textBox1->Text) / System::Convert::ToDouble(textBox2->Text)) / System::Convert::ToDouble(textBox3->Text)); }
					}
					else {
						MessageBox::Show("Попытка деления на ноль!", "Ошибка");
					}
				}
				else {
					MessageBox::Show("Попытка деления на ноль!", "Ошибка");
				}
			}
		}
		else {
			MessageBox::Show("Заполните пустые поля числами.", "Предупреждение");
		}
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	textBox1->Text = L"0";
	textBox2->Text = L"0";
	textBox3->Text = L"0";
	label1->Text = L"0";
}
};
}