#pragma once

namespace Project4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
#define NULL 0

	typedef struct tree {
		struct tree* left;
		int value;
		struct tree* right;
	};

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
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;




	protected:

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(39, 85);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(287, 22);
			this->textBox1->TabIndex = 0;
			this->textBox1->Text = L"0";
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(332, 88);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(16, 17);
			this->label1->TabIndex = 1;
			this->label1->Text = L"=";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(354, 88);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(16, 17);
			this->label2->TabIndex = 2;
			this->label2->Text = L"0";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Mongolian Baiti", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(39, 191);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(102, 30);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Вычислить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Mongolian Baiti", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(145, 191);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(110, 30);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Сгенерировать";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Mongolian Baiti", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(259, 191);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(110, 30);
			this->button3->TabIndex = 5;
			this->button3->Text = L"Сбросить";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(425, 260);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		void addtree(tree*& p, int n) {
			Random^ rnd = gcnew Random();
			int b = rnd->Next() % 2;
			
			if (p == NULL) {
				tree* ptr = new tree;
				p = ptr;
				p->value = n;
				p->left = p->right = NULL;
			}
			else {
				if (b == 0)
					addtree(p->left, n);
				else
					addtree(p->right, n);
			}
		}

		void addleafs(tree* p) {
			Random^ rnd = gcnew Random();
			int l;

			if (p->left == 0) {
				l = (rnd->Next() % 100) + 1;
				addtree(p->left, l);
			}
			else { addleafs(p->left); }

			if (p->right == 0) {
				l = (rnd->Next() % 100) + 1;
				addtree(p->right, l);
			}
			else { addleafs(p->right); }
		}

		String^ inf_tree_trav(tree* p) {
			if (p == 0) { return ""; }

			if ((p->left != 0) && (p->right != 0)) {
				switch (p->value) {
				case 43: return ("(" + inf_tree_trav(p->left) + "+" + inf_tree_trav(p->right) + ")"); break;
				case 45: return ("(" + inf_tree_trav(p->left) + "-" + inf_tree_trav(p->right) + ")"); break;
				case 42: return (inf_tree_trav(p->left) + "*" + inf_tree_trav(p->right)); break;
				case 47: return (inf_tree_trav(p->left) + "/" + inf_tree_trav(p->right)); break;
				};
			}

			return inf_tree_trav(p->left) + System::Convert::ToString(p->value) + inf_tree_trav(p->right);
		}

		double Convertation_To_Double(int& stt) {
			double number = 0;

			while ((textBox1->Text[stt] != '+') && (textBox1->Text[stt] != '-') && (textBox1->Text[stt] != '/') && (textBox1->Text[stt] != '*') && (textBox1->Text[stt] != '(') && (textBox1->Text[stt] != ')')) {
				if (textBox1->Text[stt] != ',') { 
					number = number * 10 + ((int)textBox1->Text[stt] - (int)'0'); 
					stt++;
					if (textBox1->Text->Length <= stt) { break; }
				}
				else {
					int j = stt;
					stt++;
					while ((textBox1->Text[stt] != '+') && (textBox1->Text[stt] != '-') && (textBox1->Text[stt] != '/') && (textBox1->Text[stt] != '*') && (textBox1->Text[stt] != '(') && (textBox1->Text[stt] != ')')) {
						number = number + (((double)textBox1->Text[stt] - (double)'0') / System::Math::Pow(10, (stt - j)));
						stt++;
						if (textBox1->Text->Length <= stt) { break; }
					}
				}
			}
			stt--;

			return number;
		}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Stack^ stk_1 = gcnew Stack; //for numbers
		Stack^ stk_2 = gcnew Stack; //for symbols of op
		double num_1, num_2;
		bool bo = true;

		for (int i = 0; i < textBox1->Text->Length; i++) {
			if ((textBox1->Text[i] != '+') && (textBox1->Text[i] != '-') && (textBox1->Text[i] != '/') && (textBox1->Text[i] != '*') && (textBox1->Text[i] != '(') && (textBox1->Text[i] != ')')) {
				
				num_1 = Convertation_To_Double(i);
				stk_1->Push(num_1);
				
			}
			else {
				switch (textBox1->Text[i]) {
				case '+': {
					
					while (stk_2->Count > 0) {
						if (((int)stk_2->Peek() == '*') || ((int)stk_2->Peek() == '-') || (((int)stk_2->Peek() == '/') && (System::Convert::ToDouble(stk_1->Peek()) != 0))) {
							num_2 = System::Convert::ToDouble(stk_1->Peek());
							stk_1->Pop();
							num_1 = System::Convert::ToDouble(stk_1->Peek());
							stk_1->Pop();
							if ((int)stk_2->Peek() == '*') { stk_1->Push(num_1 * num_2); }
							else if ((int)stk_2->Peek() == '-') { stk_1->Push(num_1 - num_2); }
							else { stk_1->Push(num_1 / num_2); }
							stk_2->Pop();
						}
						else if (((int)stk_2->Peek() == '/') && (System::Convert::ToDouble(stk_1->Peek()) == 0)) {
							MessageBox::Show("Попытка деления на ноль!", "Ошибка");
							bo = false;
						}
						else { break; }
					}
					stk_2->Push(43);

				} break;
				case '-': {
					
					while (stk_2->Count > 0) {
						if (((int)stk_2->Peek() == '*') || (((int)stk_2->Peek() == '/') && (System::Convert::ToDouble(stk_1->Peek()) != 0))) {
							num_2 = System::Convert::ToDouble(stk_1->Peek());
							stk_1->Pop();
							num_1 = System::Convert::ToDouble(stk_1->Peek());
							stk_1->Pop();
							if ((int)stk_2->Peek() == '*') { stk_1->Push(num_1 * num_2); }
							else { stk_1->Push(num_1 / num_2); }
							stk_2->Pop();
						}
						else if (((int)stk_2->Peek() == '/') && (System::Convert::ToDouble(stk_1->Peek()) == 0)) {
							MessageBox::Show("Попытка деления на ноль!", "Ошибка");
							bo = false;
						}
						else { break; }
					}
					stk_2->Push(45);
				} break;
				case '*': {
					if (stk_2->Count > 0) {
						if (((int)stk_2->Peek() == '/') && (System::Convert::ToDouble(stk_1->Peek()) != 0)) {
							num_2 = System::Convert::ToDouble(stk_1->Peek());
							stk_1->Pop();
							num_1 = System::Convert::ToDouble(stk_1->Peek());
							stk_1->Pop();
							stk_1->Push(num_1 / num_2);
							stk_2->Pop();
						}
						else if (((int)stk_2->Peek() == '/') && (System::Convert::ToDouble(stk_1->Peek()) == 0)) {
							MessageBox::Show("Попытка деления на ноль!", "Ошибка");
							bo = false;
						}
					}
					stk_2->Push(42);
				} break;
				case '/': {
					if (stk_2->Count > 0) {
						if (((int)stk_2->Peek() == '/') && (System::Convert::ToDouble(stk_1->Peek()) != 0)) {
							num_2 = System::Convert::ToDouble(stk_1->Peek());
							stk_1->Pop();
							num_1 = System::Convert::ToDouble(stk_1->Peek());
							stk_1->Pop();
							stk_1->Push(num_1 / num_2);
							stk_2->Pop();
						}
						else if (((int)stk_2->Peek() == '/') && (System::Convert::ToDouble(stk_1->Peek()) == 0)) {
							MessageBox::Show("Попытка деления на ноль!", "Ошибка");
							bo = false;
						}
					}
					stk_2->Push(47); 
				} break;
				case '(': {
					
					if (textBox1->Text[i + 1] == '-') {
						textBox1->Text = textBox1->Text->Substring(0, i+1) + System::Convert::ToString(0) + textBox1->Text->Substring(i + 1, textBox1->Text->Length - (i + 1));
					}
					stk_2->Push(40);
					
				} break;
				case ')': {
					
					while (((int)stk_2->Peek() != '(') && bo) {
						num_2 = System::Convert::ToDouble(stk_1->Peek());
						stk_1->Pop();
						num_1 = System::Convert::ToDouble(stk_1->Peek());
						stk_1->Pop();
						switch ((int)stk_2->Peek()) {
						case '+': stk_1->Push(num_1 + num_2); break;
						case '-': stk_1->Push(num_1 - num_2); break;
						case '/': {
							if (num_2 != 0) {
								stk_1->Push(num_1 / num_2);
							}
							else {
								MessageBox::Show("Попытка деления на ноль!", "Ошибка");
								bo = false;
							}
						} break;
						case '*': stk_1->Push(num_1 * num_2); break;
						}
						stk_2->Pop();
					}
					stk_2->Pop();
				} break;
				}
			}
			if (bo == false) { break; }
		}
		
		while ((stk_2->Count != 0) && bo) {
			num_2 = System::Convert::ToDouble(stk_1->Peek());
			stk_1->Pop();
			num_1 = System::Convert::ToDouble(stk_1->Peek());
			stk_1->Pop();
			switch ((int)stk_2->Peek()) {
			case '+': stk_1->Push(num_1 + num_2); break;
			case '-': stk_1->Push(num_1 - num_2); break;
			case '/': {
				if (num_2 != 0) {
					stk_1->Push(num_1 / num_2);
				}
				else {
					MessageBox::Show("Попытка деления на ноль!", "Ошибка");
					bo = false;
				}
			} break;
			case '*': stk_1->Push(num_1 * num_2); break;
			}
			stk_2->Pop();
		}
		
		if (bo) { label2->Text = System::Convert::ToString(stk_1->Peek()); }
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		Random^ rnd = gcnew Random();
		int k = (rnd->Next() % 5) + 1;
		int m;
		tree* root = NULL;

		for (int i = 0; i < k; i++) {
			m = rnd->Next() % 4;
			switch (m) {
			case 0: addtree(root, 43); break;
			case 1: addtree(root, 45); break;
			case 2: addtree(root, 42); break;
			case 3: addtree(root, 47); break;
			}
		}

		addleafs(root);

		textBox1->Text = inf_tree_trav(root);
	}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	label2->Text = L"0";
	textBox1->Text = L"0";
}
};
}
