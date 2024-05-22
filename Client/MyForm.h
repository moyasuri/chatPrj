#pragma once


#include "enum.h"
#include "MyFunction.h"
#include "FindAccountForm.h"
#include "SignupForm.h"
#include "MainForm.h"

namespace Client {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm에 대한 요약입니다.
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ txtBoxID;
	private: System::Windows::Forms::TextBox^ txtBoxPW;
	private: System::Windows::Forms::Button^ btnSignIn;
	private: System::Windows::Forms::Button^ btnSignUp;
	private: System::Windows::Forms::Button^ btnExit;

	private: System::Windows::Forms::Button^ btnFindAccount;



	private:
		/// <summary>
		/// 필수 디자이너 변수입니다.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 디자이너 지원에 필요한 메서드입니다. 
		/// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtBoxID = (gcnew System::Windows::Forms::TextBox());
			this->txtBoxPW = (gcnew System::Windows::Forms::TextBox());
			this->btnSignIn = (gcnew System::Windows::Forms::Button());
			this->btnSignUp = (gcnew System::Windows::Forms::Button());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->btnFindAccount = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(190, 350);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(20, 15);
			this->label1->TabIndex = 0;
			this->label1->Text = L"ID";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(190, 377);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(72, 15);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Password";
			// 
			// txtBoxID
			// 
			this->txtBoxID->Location = System::Drawing::Point(306, 340);
			this->txtBoxID->Name = L"txtBoxID";
			this->txtBoxID->Size = System::Drawing::Size(173, 25);
			this->txtBoxID->TabIndex = 2;
			// 
			// txtBoxPW
			// 
			this->txtBoxPW->Location = System::Drawing::Point(306, 377);
			this->txtBoxPW->Name = L"txtBoxPW";
			this->txtBoxPW->Size = System::Drawing::Size(173, 25);
			this->txtBoxPW->TabIndex = 2;
			// 
			// btnSignIn
			// 
			this->btnSignIn->BackColor = System::Drawing::Color::Transparent;
			this->btnSignIn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnSignIn->FlatAppearance->BorderSize = 0;
			this->btnSignIn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSignIn->ForeColor = System::Drawing::Color::Black;
			this->btnSignIn->Location = System::Drawing::Point(513, 340);
			this->btnSignIn->Name = L"btnSignIn";
			this->btnSignIn->Size = System::Drawing::Size(159, 35);
			this->btnSignIn->TabIndex = 3;
			this->btnSignIn->Text = L"signin";
			this->btnSignIn->UseVisualStyleBackColor = false;
			// 
			// btnSignUp
			// 
			this->btnSignUp->BackColor = System::Drawing::Color::Transparent;
			this->btnSignUp->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnSignUp->FlatAppearance->BorderSize = 0;
			this->btnSignUp->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSignUp->ForeColor = System::Drawing::Color::Black;
			this->btnSignUp->Location = System::Drawing::Point(667, 340);
			this->btnSignUp->Name = L"btnSignUp";
			this->btnSignUp->Size = System::Drawing::Size(159, 35);
			this->btnSignUp->TabIndex = 3;
			this->btnSignUp->Text = L"signup";
			this->btnSignUp->UseVisualStyleBackColor = false;
			// 
			// btnExit
			// 
			this->btnExit->BackColor = System::Drawing::Color::Transparent;
			this->btnExit->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnExit->FlatAppearance->BorderSize = 0;
			this->btnExit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnExit->ForeColor = System::Drawing::Color::Black;
			this->btnExit->Location = System::Drawing::Point(667, 414);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(159, 35);
			this->btnExit->TabIndex = 3;
			this->btnExit->Text = L"exit";
			this->btnExit->UseVisualStyleBackColor = false;
			// 
			// btnFindAccount
			// 
			this->btnFindAccount->BackColor = System::Drawing::Color::Transparent;
			this->btnFindAccount->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnFindAccount->FlatAppearance->BorderSize = 0;
			this->btnFindAccount->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnFindAccount->ForeColor = System::Drawing::Color::Black;
			this->btnFindAccount->Location = System::Drawing::Point(513, 414);
			this->btnFindAccount->Name = L"btnFindAccount";
			this->btnFindAccount->Size = System::Drawing::Size(159, 35);
			this->btnFindAccount->TabIndex = 3;
			this->btnFindAccount->Text = L"find account";
			this->btnFindAccount->UseVisualStyleBackColor = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(816, 475);
			this->Controls->Add(this->btnFindAccount);
			this->Controls->Add(this->btnExit);
			this->Controls->Add(this->btnSignUp);
			this->Controls->Add(this->btnSignIn);
			this->Controls->Add(this->txtBoxPW);
			this->Controls->Add(this->txtBoxID);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
