#pragma once

namespace Project5 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	using namespace System::Drawing::Drawing2D;
	using namespace System::Windows::Forms::DataVisualization::Charting;

	/// <summary>
	/// ������ ��� MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	protected:

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(25, 21);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(987, 338);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1038, 381);
			this->Controls->Add(this->chart1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		
		Dictionary <double, double>^ f1 = gcnew Dictionary<double, double>();
		chart1->Series[0]->ChartType = SeriesChartType::Line;
		chart1->Series[0]->MarkerStyle = MarkerStyle::Square;

		chart1->ChartAreas[0]->AxisY->ScaleBreakStyle->Enabled = true;
		chart1->ChartAreas[0]->AxisY->ScaleBreakStyle->CollapsibleSpaceThreshold = 20;
		chart1->ChartAreas[0]->AxisY->ScaleBreakStyle->LineWidth = 2;
		chart1->ChartAreas[0]->AxisY->ScaleBreakStyle->LineColor = Color::Black;
		chart1->ChartAreas[0]->AxisY->ScaleBreakStyle->StartFromZero = StartFromZero::Auto;
		chart1->ChartAreas[0]->AxisY->ScaleBreakStyle->Spacing = 5;

		chart1->ChartAreas[0]->AxisX->Interval = 1;

		for (double x = -2.86; x < 3.14; x += 0.1) {
			double f = System::Math::Tan(x);
			f1->Add(x, f);
		}

		chart1->Series[0]->Points->DataBindXY(f1->Keys, f1->Values);
		chart1->Series[0]->LegendText = L"tan(x)";
		chart1->Series[0]->Color = System::Drawing::Color::Blue;
		chart1->Series[0]->BorderWidth = 0;
	}
	};
}
