#pragma once
#include<iostream>
#include <string>
#include <chrono>
#include <msclr\marshal_cppstd.h>

#include "CPU_Filters.cpp"
#include "Gpu_filters.h"
#include "loadImage.h"

namespace PAVICPROJECTIMAGEPROCESSING2022 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std::chrono;

	/// <summary>
	/// Summary for My_Color_bar
	/// </summary>
	public ref class My_Color_bar : public System::Windows::Forms::Form
	{
	public:
		My_Color_bar(void)
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
		~My_Color_bar()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:


	private: System::Windows::Forms::TextBox^ txtGreen;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ txtBlue;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ txtRed;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panelColor;
	private: System::Windows::Forms::Button^ buttonCopy;

	private: System::Windows::Forms::Button^ buttonLoad;
	private: System::Windows::Forms::Button^ buttonReset;


	private: TrackBarControl::MyTrackBarControl^ myTrackBarControlRed;
	private: TrackBarControl::MyTrackBarControl^ myTrackBarControlGreen;
	private: TrackBarControl::MyTrackBarControl^ myTrackBarControlBlue;
	private: System::Windows::Forms::CheckBox^ checkGPU;

	private: System::Windows::Forms::Label^ time_exec;
	private: System::Windows::Forms::PictureBox^ pictureOutput;
	private: System::Windows::Forms::PictureBox^ pictureInput;



	private: System::Windows::Forms::Button^ convertToGray;
	private: System::Windows::Forms::Button^ close;
	private: System::Windows::Forms::Button^ load_Img;

	private: System::Windows::Forms::Button^ exit;
	private: System::Windows::Forms::CheckBox^ checkCPU;
	private: System::Windows::Forms::TextBox^ txtRun;




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
			this->txtGreen = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtBlue = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txtRed = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panelColor = (gcnew System::Windows::Forms::Panel());
			this->buttonCopy = (gcnew System::Windows::Forms::Button());
			this->buttonLoad = (gcnew System::Windows::Forms::Button());
			this->buttonReset = (gcnew System::Windows::Forms::Button());
			this->myTrackBarControlRed = (gcnew TrackBarControl::MyTrackBarControl());
			this->myTrackBarControlGreen = (gcnew TrackBarControl::MyTrackBarControl());
			this->myTrackBarControlBlue = (gcnew TrackBarControl::MyTrackBarControl());
			this->checkGPU = (gcnew System::Windows::Forms::CheckBox());
			this->time_exec = (gcnew System::Windows::Forms::Label());
			this->pictureOutput = (gcnew System::Windows::Forms::PictureBox());
			this->pictureInput = (gcnew System::Windows::Forms::PictureBox());
			this->convertToGray = (gcnew System::Windows::Forms::Button());
			this->close = (gcnew System::Windows::Forms::Button());
			this->load_Img = (gcnew System::Windows::Forms::Button());
			this->exit = (gcnew System::Windows::Forms::Button());
			this->checkCPU = (gcnew System::Windows::Forms::CheckBox());
			this->txtRun = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureOutput))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureInput))->BeginInit();
			this->SuspendLayout();
			// 
			// txtGreen
			// 
			this->txtGreen->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->txtGreen->Location = System::Drawing::Point(364, 66);
			this->txtGreen->Name = L"txtGreen";
			this->txtGreen->ReadOnly = true;
			this->txtGreen->Size = System::Drawing::Size(76, 22);
			this->txtGreen->TabIndex = 6;
			this->txtGreen->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(318, 67);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(17, 16);
			this->label2->TabIndex = 5;
			this->label2->Text = L"G";
			// 
			// txtBlue
			// 
			this->txtBlue->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->txtBlue->Location = System::Drawing::Point(364, 112);
			this->txtBlue->Name = L"txtBlue";
			this->txtBlue->ReadOnly = true;
			this->txtBlue->Size = System::Drawing::Size(76, 22);
			this->txtBlue->TabIndex = 8;
			this->txtBlue->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(319, 117);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(16, 16);
			this->label3->TabIndex = 7;
			this->label3->Text = L"B";
			// 
			// txtRed
			// 
			this->txtRed->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->txtRed->Location = System::Drawing::Point(364, 21);
			this->txtRed->Name = L"txtRed";
			this->txtRed->ReadOnly = true;
			this->txtRed->Size = System::Drawing::Size(76, 22);
			this->txtRed->TabIndex = 10;
			this->txtRed->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(316, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(17, 16);
			this->label1->TabIndex = 9;
			this->label1->Text = L"R";
			// 
			// panelColor
			// 
			this->panelColor->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->panelColor->Location = System::Drawing::Point(832, 7);
			this->panelColor->Name = L"panelColor";
			this->panelColor->Size = System::Drawing::Size(428, 55);
			this->panelColor->TabIndex = 11;
			// 
			// buttonCopy
			// 
			this->buttonCopy->Location = System::Drawing::Point(832, 74);
			this->buttonCopy->Name = L"buttonCopy";
			this->buttonCopy->Size = System::Drawing::Size(129, 37);
			this->buttonCopy->TabIndex = 12;
			this->buttonCopy->Text = L"Copy Image";
			this->buttonCopy->UseVisualStyleBackColor = true;
			this->buttonCopy->Click += gcnew System::EventHandler(this, &My_Color_bar::buttonCopy_Click);
			// 
			// buttonLoad
			// 
			this->buttonLoad->Location = System::Drawing::Point(985, 74);
			this->buttonLoad->Name = L"buttonLoad";
			this->buttonLoad->Size = System::Drawing::Size(129, 37);
			this->buttonLoad->TabIndex = 13;
			this->buttonLoad->Text = L"Load Image";
			this->buttonLoad->UseVisualStyleBackColor = true;
			this->buttonLoad->Click += gcnew System::EventHandler(this, &My_Color_bar::buttonLoad_Click);
			// 
			// buttonReset
			// 
			this->buttonReset->Location = System::Drawing::Point(1131, 74);
			this->buttonReset->Name = L"buttonReset";
			this->buttonReset->Size = System::Drawing::Size(129, 37);
			this->buttonReset->TabIndex = 14;
			this->buttonReset->Text = L"Reset";
			this->buttonReset->UseVisualStyleBackColor = true;
			this->buttonReset->Click += gcnew System::EventHandler(this, &My_Color_bar::button3_Click);
			// 
			// myTrackBarControlRed
			// 
			this->myTrackBarControlRed->ColorText = L"Red";
			this->myTrackBarControlRed->Location = System::Drawing::Point(5, 2);
			this->myTrackBarControlRed->MinimumSize = System::Drawing::Size(266, 60);
			this->myTrackBarControlRed->Name = L"myTrackBarControlRed";
			this->myTrackBarControlRed->Size = System::Drawing::Size(266, 60);
			this->myTrackBarControlRed->TabIndex = 15;
			this->myTrackBarControlRed->ValueChanged += gcnew System::EventHandler(this, &My_Color_bar::myTrackBarControlRed_ValueChanged);
			// 
			// myTrackBarControlGreen
			// 
			this->myTrackBarControlGreen->ColorText = L"Green";
			this->myTrackBarControlGreen->Location = System::Drawing::Point(3, 51);
			this->myTrackBarControlGreen->MinimumSize = System::Drawing::Size(266, 60);
			this->myTrackBarControlGreen->Name = L"myTrackBarControlGreen";
			this->myTrackBarControlGreen->Size = System::Drawing::Size(266, 60);
			this->myTrackBarControlGreen->TabIndex = 16;
			this->myTrackBarControlGreen->ValueChanged += gcnew System::EventHandler(this, &My_Color_bar::myTrackBarControlRed_ValueChanged);
			// 
			// myTrackBarControlBlue
			// 
			this->myTrackBarControlBlue->ColorText = L"Blue";
			this->myTrackBarControlBlue->Location = System::Drawing::Point(6, 95);
			this->myTrackBarControlBlue->MinimumSize = System::Drawing::Size(266, 60);
			this->myTrackBarControlBlue->Name = L"myTrackBarControlBlue";
			this->myTrackBarControlBlue->Size = System::Drawing::Size(266, 60);
			this->myTrackBarControlBlue->TabIndex = 17;
			this->myTrackBarControlBlue->ValueChanged += gcnew System::EventHandler(this, &My_Color_bar::myTrackBarControlRed_ValueChanged);
			// 
			// checkGPU
			// 
			this->checkGPU->AutoSize = true;
			this->checkGPU->Location = System::Drawing::Point(568, 16);
			this->checkGPU->Name = L"checkGPU";
			this->checkGPU->Size = System::Drawing::Size(58, 20);
			this->checkGPU->TabIndex = 21;
			this->checkGPU->Text = L"GPU";
			this->checkGPU->UseVisualStyleBackColor = true;
			// 
			// time_exec
			// 
			this->time_exec->AutoSize = true;
			this->time_exec->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->time_exec->Location = System::Drawing::Point(553, 130);
			this->time_exec->Name = L"time_exec";
			this->time_exec->Size = System::Drawing::Size(64, 16);
			this->time_exec->TabIndex = 20;
			this->time_exec->Text = L"Velocity : ";
			// 
			// pictureOutput
			// 
			this->pictureOutput->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->pictureOutput->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureOutput->Location = System::Drawing::Point(662, 205);
			this->pictureOutput->Name = L"pictureOutput";
			this->pictureOutput->Size = System::Drawing::Size(599, 445);
			this->pictureOutput->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureOutput->TabIndex = 19;
			this->pictureOutput->TabStop = false;
			// 
			// pictureInput
			// 
			this->pictureInput->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->pictureInput->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureInput->Location = System::Drawing::Point(8, 205);
			this->pictureInput->Name = L"pictureInput";
			this->pictureInput->Size = System::Drawing::Size(601, 445);
			this->pictureInput->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureInput->TabIndex = 18;
			this->pictureInput->TabStop = false;
			// 
			// convertToGray
			// 
			this->convertToGray->Location = System::Drawing::Point(317, 165);
			this->convertToGray->Name = L"convertToGray";
			this->convertToGray->Size = System::Drawing::Size(123, 34);
			this->convertToGray->TabIndex = 24;
			this->convertToGray->Text = L"GrayScale";
			this->convertToGray->UseVisualStyleBackColor = true;
			this->convertToGray->Click += gcnew System::EventHandler(this, &My_Color_bar::convertToGray_Click);
			// 
			// close
			// 
			this->close->Location = System::Drawing::Point(169, 165);
			this->close->Name = L"close";
			this->close->Size = System::Drawing::Size(107, 34);
			this->close->TabIndex = 23;
			this->close->Text = L"Close IMG";
			this->close->UseVisualStyleBackColor = true;
			this->close->Click += gcnew System::EventHandler(this, &My_Color_bar::close_Click);
			// 
			// load_Img
			// 
			this->load_Img->Location = System::Drawing::Point(7, 165);
			this->load_Img->Name = L"load_Img";
			this->load_Img->Size = System::Drawing::Size(121, 34);
			this->load_Img->TabIndex = 22;
			this->load_Img->Text = L"Load IMG";
			this->load_Img->UseVisualStyleBackColor = true;
			this->load_Img->Click += gcnew System::EventHandler(this, &My_Color_bar::load_Click);
			// 
			// exit
			// 
			this->exit->Location = System::Drawing::Point(1140, 162);
			this->exit->Name = L"exit";
			this->exit->Size = System::Drawing::Size(121, 37);
			this->exit->TabIndex = 25;
			this->exit->Text = L"Exit";
			this->exit->UseVisualStyleBackColor = true;
			this->exit->Click += gcnew System::EventHandler(this, &My_Color_bar::exit_Click);
			// 
			// checkCPU
			// 
			this->checkCPU->AutoSize = true;
			this->checkCPU->Location = System::Drawing::Point(569, 42);
			this->checkCPU->Name = L"checkCPU";
			this->checkCPU->Size = System::Drawing::Size(57, 20);
			this->checkCPU->TabIndex = 26;
			this->checkCPU->Text = L"CPU";
			this->checkCPU->UseVisualStyleBackColor = true;
			// 
			// txtRun
			// 
			this->txtRun->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->txtRun->Location = System::Drawing::Point(558, 95);
			this->txtRun->Name = L"txtRun";
			this->txtRun->ReadOnly = true;
			this->txtRun->Size = System::Drawing::Size(268, 22);
			this->txtRun->TabIndex = 27;
			this->txtRun->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// My_Color_bar
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1272, 658);
			this->Controls->Add(this->txtRun);
			this->Controls->Add(this->checkCPU);
			this->Controls->Add(this->exit);
			this->Controls->Add(this->convertToGray);
			this->Controls->Add(this->close);
			this->Controls->Add(this->load_Img);
			this->Controls->Add(this->checkGPU);
			this->Controls->Add(this->time_exec);
			this->Controls->Add(this->pictureOutput);
			this->Controls->Add(this->pictureInput);
			this->Controls->Add(this->myTrackBarControlBlue);
			this->Controls->Add(this->myTrackBarControlGreen);
			this->Controls->Add(this->myTrackBarControlRed);
			this->Controls->Add(this->buttonReset);
			this->Controls->Add(this->buttonLoad);
			this->Controls->Add(this->buttonCopy);
			this->Controls->Add(this->panelColor);
			this->Controls->Add(this->txtRed);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txtBlue);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->txtGreen);
			this->Controls->Add(this->label2);
			this->MinimumSize = System::Drawing::Size(1290, 700);
			this->Name = L"My_Color_bar";
			this->Text = L"By: Antonio Souto Rodriguez 2022 - IMAGE PROCESSING  CPU VS GPU";
			this->TopMost = true;
			this->TransparencyKey = System::Drawing::Color::Blue;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureOutput))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureInput))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		Color color;
private: System::Void myTrackBarControlRed_ValueChanged(System::Object^ sender,
	System::EventArgs^ e) {
	color = Color::FromArgb(255,
		myTrackBarControlRed->GetColor(),
		myTrackBarControlGreen->GetColor(),
		myTrackBarControlBlue->GetColor());
	panelColor->BackColor = color;
	
	txtRed->Text = color.R.ToString();
	txtGreen->Text = color.G.ToString();
	txtBlue->Text = color.B.ToString();
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Restart();
}
private: System::Void buttonCopy_Click(System::Object^ sender, System::EventArgs^ e) {
	Clipboard::SetText(ColorTranslator::ToHtml(color));
}
private: System::Void buttonLoad_Click(System::Object^ sender, System::EventArgs^ e) {
	Clipboard::SetText(color.R.ToString() + ", " + color.G.ToString() + ", " + color.B.ToString());
}
private: System::Void convertToGray_Click(System::Object^ sender, System::EventArgs^ e) {
	//useGPU obj;
	System::String^ file = pictureInput->ImageLocation;
	std::string converted_xyz = msclr::interop::marshal_as< std::string >(file);
	int width, height, channels;
	const char* c = converted_xyz.c_str();
	int time = 0;
	// LOAD IMAGES
	unsigned char* img = stbi_load(c, &width, &height, &channels, 4);

	if (checkGPU->Checked) {
		//GPU
		txtRun->Text = "Hello GPU";
		
	}
	else {
		// CPU
		txtRun->Text = "Hello ONLY CPU";
		auto start = high_resolution_clock::now();
		ConvertImageToGrayCpu(img, width, height);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
		time = duration.count();
	}
	time_exec->Text = "Velocity : " + time.ToString() + " microseconds";
	stbi_write_png("images/output/output.jpg", width, height, 4, img, 4 * width);
	pictureOutput->ImageLocation = "images/output/output.jpg";
	stbi_image_free(img);

}
private: System::Void load_Click(System::Object^ sender, System::EventArgs^ e) {
	// open file dialog   
	OpenFileDialog^ ofd = gcnew OpenFileDialog();

	if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK) {

		//img_input->Image = Image::FromFile(ofd->FileName);
		//System::String^ strFilename = ofd->FileName;

		pictureInput->ImageLocation = ofd->FileName;

	}

}
private: System::Void close_Click(System::Object^ sender, System::EventArgs^ e) {
	pictureInput->ImageLocation = "";
	pictureOutput->Image = nullptr;
}
private: System::Void exit_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
}
};
}
