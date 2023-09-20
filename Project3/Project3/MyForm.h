#pragma once

namespace Project3 {

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
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label3;


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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(29, 81);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(255, 22);
			this->textBox1->TabIndex = 0;
			this->textBox1->Text = L"10+3/11*(12+(13-1)*(-1))";
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(307, 83);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(16, 17);
			this->label1->TabIndex = 2;
			this->label1->Text = L"=";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(347, 83);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(16, 17);
			this->label2->TabIndex = 3;
			this->label2->Text = L"0";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(29, 197);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(97, 28);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Вычислить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(132, 197);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(97, 28);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Сбросить";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(26, 136);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(46, 17);
			this->label3->TabIndex = 6;
			this->label3->Text = L"label3";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(395, 237);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"Lab. 1.3";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		bool Protect() {
			if (label2->Text->Length == 0) { return false; }

			for (int i = 0; label2->Text->Length > i; i++) {
				if ((label2->Text[i] >= '0') && (label2->Text[i] <= '9') || (label2->Text[i] == '/') || (label2->Text[i] == '*') || (label2->Text[i] == '+') || (label2->Text[i] == '-') || (label2->Text[i] == ',') || (label2->Text[i] == '(') || (label2->Text[i] == ')')) {
					if (label2->Text[i] == ',') {
						if ((label2->Text[i-1] >= '0') && (label2->Text[i-1] <= '9') && (label2->Text[i+1] >= '0') && (label2->Text[i+1] <= '9')) {}
						else { return false; }
					}
				}
				else { return false; }
			}

			return true;
		}

		void Symbol_Search( int& ft, int& sw , int& num) {
			int slower = sw + 1;
			bool bo = false;

			if (num == -1) {
				int faster = ft;

				while (((label2->Text[sw] != '(') || (label2->Text[ft] != ')')) && (faster < label2->Text->Length)) {
					
					if ((faster + 1) < label2->Text->Length) {
						if ((label2->Text[faster] == '(') && (label2->Text[(faster + 1)] != '-')) { 
							sw = faster; 
							bo = true;
						}
						else if ((label2->Text[faster] == '(') && (label2->Text[(faster + 1)] == '-')) {
							bo = false;
						}
					}
					if (bo && (label2->Text[faster] == ')')) { ft = faster; }
					else if ((bo == false) && (label2->Text[faster] == ')')) { bo = true; }

					faster += 1;
				}
			} else
			if (num == -2) {
				for (; slower < ft; slower++) {
					if (label2->Text[slower] == '*') {
						num = slower;
						break;
					}
					else if (label2->Text[slower] == '/') {
						num = slower;
						break;
					}
					else if (((label2->Text[slower] == '-') || (label2->Text[slower] == '+')) && ((label2->Text[slower] != '/') || (label2->Text[slower] != '*'))) {
						num = slower;
					}
				}
			}
		}

		void Number_Search( int& coord00, int& coord01, int& coord10, int& coord11 ) {
			int i = 0, j = 0;
			
			if (label2->Text[coord01] == ')') {
				coord01--;
				coord00 = coord01 - 1;
			}
			if (label2->Text[coord10] == '(') {
				coord10++;
				if (label2->Text[coord10] == '-') { coord10++; }
				coord11 = coord10 + 1;
			}

			while ((i == 0) || (j == 0)) {
				if ((label2->Text[coord00] != '-') && (label2->Text[coord00] != '+') && (label2->Text[coord00] != '*') && (label2->Text[coord00] != '/') && (label2->Text[coord00] != '(')) { coord00 -= 1; }
				else { i += 1; }
				if (coord00 < 0) {
					coord00 += 1;
					i += 1;
				}
				if ((label2->Text[coord11] != '-') && (label2->Text[coord11] != '+') && (label2->Text[coord11] != '*') && (label2->Text[coord11] != '/') && (label2->Text[coord11] != ')')) { coord11 += 1; }
				else { j += 1; }
				if (coord11 >= label2->Text->Length) {
					coord11 -= 1;
					j += 1;
				}
			}

			if ((label2->Text[coord00] == '-') || (label2->Text[coord00] == '+') || (label2->Text[coord00] == '*') || (label2->Text[coord00] == '/') || (label2->Text[coord00] == '(')) { coord00++; };

			if ((label2->Text[coord11] == '-') || (label2->Text[coord11] == '+') || (label2->Text[coord11] == '*') || (label2->Text[coord11] == '/') || (label2->Text[coord11] == ')')) { coord11--; };
		}

		double Convertation_To_Double( int& stt, int& nd ) {
			double number = 0;
			int j;

			for (int i = stt; i <= nd; i++) {
				if (label2->Text[i] != ',') { number = number * 10 + ((int)label2->Text[i] - (int)'0'); }
				else {
					j = i;
					i++;
					for (; i <= nd; i++) {
						number = number + (((double)label2->Text[i] - (double)'0') / pow(10, (i - j)));
					}
				}
			}
			if (stt > 0) {
				if ((label2->Text[stt - 1] == '-') && (label2->Text[stt - 2] == '(')) { number *= (-1); }
			}

			return number;
		}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (Protect()) {
			int fast = 0;
			int slow = 0;
			double num0 = 0;
			double num1 = 0;
			int k = 0, l = 0;
			int coords[4] = {0, 0, 0, 0};

			label2->Text = textBox1->Text;

			while (true) {
				fast = 0;
				slow = 0;
				k = -1;
				Symbol_Search(fast, slow, k);
				k = -2;
				Symbol_Search(fast, slow, k);
				while (k != -2) {
					coords[0] = k - 1;
					coords[1] = k - 1;
					coords[2] = k + 1;
					coords[3] = k + 1;
					Number_Search(coords[0], coords[1], coords[2], coords[3]);
					num0 = Convertation_To_Double(coords[0], coords[1]);
					num1 = Convertation_To_Double(coords[2], coords[3]);

					if ((num1 == 0) && (label2->Text[k] == '/')) {
						MessageBox::Show("Попытка деления на ноль!", "Ошибка");
						k = -3;
						break;
					}
					else {
						if (label2->Text[k] == '+') {
							
						} else
						if (label2->Text[k] == '-') {
							
						} else
						if (label2->Text[k] == '*') {
							
						} else
						if (label2->Text[k] == '/') {
							
						}
					}
					k = -2;
					Symbol_Search(fast, slow, k);
					l += 1;
					if (l == 2) {
						label3->Text = System::Convert::ToString(num1);
						k = -3;
						break;
					}
					if ((k == -2) && (fast - slow + 1 != label2->Text->Length)) { label2->Text = label2->Text->Substring(0, slow) + label2->Text->Substring((slow + 1), (fast - slow - 1)) + label2->Text->Substring((fast + 1)); }
				}
				if ((k == -3) || ((k == -2) && (fast - slow + 1 == label2->Text->Length))) { break; }
			}
		}
		else { MessageBox::Show("Заполните пустые поля числами.", "Предупреждение"); }
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	textBox1->Text = L"0";
	label2->Text = L"0";
}
};
}
