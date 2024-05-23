﻿#pragma once
#include "MyFunction.h";
#include "enum.h"

namespace Client {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// FriendsResponse에 대한 요약입니다.
	/// </summary>
	public ref class FriendsResponse : public System::Windows::Forms::Form
	{
	public:
		FriendsResponse(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
		}
		FriendsResponse(MyFunction^ my)
		{
			InitializeComponent();
			this->_my = my;
			this->_my->MyEvent += gcnew Action<String^>(this, &FriendsResponse::ReceivedMsg);

		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~FriendsResponse()
		{
			if (_my != nullptr) {
				// MyEvent 이벤트 핸들러를 해제
				_my->MyEvent -= gcnew Action<String^>(this, &FriendsResponse::ReceivedMsg);

				// _my를 삭제
				delete _my;
				_my = nullptr;  // nullptr로 설정하여 dangling pointer를 방지
			}
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ ViewResponseList;
	protected:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ NumOfList;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ FromWho;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ReqMsg;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ btnAccept;
	private: System::Windows::Forms::Button^ btnReject;
	private: System::Windows::Forms::Button^ btnClose;
	private: MyFunction^ _my;

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
			this->ViewResponseList = (gcnew System::Windows::Forms::DataGridView());
			this->NumOfList = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->FromWho = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ReqMsg = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btnAccept = (gcnew System::Windows::Forms::Button());
			this->btnReject = (gcnew System::Windows::Forms::Button());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ViewResponseList))->BeginInit();
			this->SuspendLayout();
			// 
			// ViewResponseList
			// 
			this->ViewResponseList->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->ViewResponseList->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->NumOfList,
					this->FromWho, this->ReqMsg
			});
			this->ViewResponseList->Location = System::Drawing::Point(23, 94);
			this->ViewResponseList->Name = L"ViewResponseList";
			this->ViewResponseList->RowHeadersWidth = 51;
			this->ViewResponseList->RowTemplate->Height = 27;
			this->ViewResponseList->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->ViewResponseList->Size = System::Drawing::Size(662, 343);
			this->ViewResponseList->TabIndex = 21;
			// 
			// NumOfList
			// 
			this->NumOfList->Frozen = true;
			this->NumOfList->HeaderText = L"#";
			this->NumOfList->MinimumWidth = 8;
			this->NumOfList->Name = L"NumOfList";
			this->NumOfList->ReadOnly = true;
			this->NumOfList->Width = 50;
			// 
			// FromWho
			// 
			this->FromWho->Frozen = true;
			this->FromWho->HeaderText = L"From.";
			this->FromWho->MinimumWidth = 6;
			this->FromWho->Name = L"FromWho";
			this->FromWho->ReadOnly = true;
			this->FromWho->Width = 125;
			// 
			// ReqMsg
			// 
			this->ReqMsg->Frozen = true;
			this->ReqMsg->HeaderText = L"Req Message";
			this->ReqMsg->MinimumWidth = 6;
			this->ReqMsg->Name = L"ReqMsg";
			this->ReqMsg->ReadOnly = true;
			this->ReqMsg->Width = 125;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 20));
			this->label2->ForeColor = System::Drawing::Color::Cornsilk;
			this->label2->Location = System::Drawing::Point(16, 32);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(90, 32);
			this->label2->TabIndex = 20;
			this->label2->Text = L"From.";
			// 
			// btnAccept
			// 
			this->btnAccept->Location = System::Drawing::Point(725, 94);
			this->btnAccept->Name = L"btnAccept";
			this->btnAccept->Size = System::Drawing::Size(119, 48);
			this->btnAccept->TabIndex = 22;
			this->btnAccept->Text = L"Accept";
			this->btnAccept->UseVisualStyleBackColor = true;
			// 
			// btnReject
			// 
			this->btnReject->Location = System::Drawing::Point(725, 184);
			this->btnReject->Name = L"btnReject";
			this->btnReject->Size = System::Drawing::Size(119, 48);
			this->btnReject->TabIndex = 22;
			this->btnReject->Text = L"Reject";
			this->btnReject->UseVisualStyleBackColor = true;
			// 
			// btnClose
			// 
			this->btnClose->Location = System::Drawing::Point(698, 472);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(119, 48);
			this->btnClose->TabIndex = 22;
			this->btnClose->Text = L"Close";
			this->btnClose->UseVisualStyleBackColor = true;
			// 
			// FriendsResponse
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(900, 565);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->btnReject);
			this->Controls->Add(this->btnAccept);
			this->Controls->Add(this->ViewResponseList);
			this->Controls->Add(this->label2);
			this->Name = L"FriendsResponse";
			this->Text = L"FriendsResponse";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ViewResponseList))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
				public: void SendMessageForm(int index)
				{

					switch (index)
					{
					case e_friends_Accept:
					{

						DataGridViewRow^ selectedRow = ViewResponseList->SelectedRows[0];
						String^ tmptxt_1 = safe_cast<String^>(selectedRow->Cells[1]->Value);

						int t_index = e_id_find_ID;
						String^ buffer = t_index.ToString() + " " + tmptxt_1;
						_my->SendMessage(buffer);

						break;
					}

					case e_friends_Request_Decline:
					{
						// 선택한 행의 정보를 저장할 DataGridViewRow 객체를 선언합니다.

						DataGridViewRow^ selectedRow = ViewResponseList->SelectedRows[0];
						String^ tmptxt_1 = safe_cast<String^>(selectedRow->Cells[1]->Value);

						int t_index = e_id_find_ID;
						String^ buffer = t_index.ToString() + " " + tmptxt_1;
						_my->SendMessage(buffer);

						break;
					}

					}

				}

	public: void ReceivedMsg(String^ message)
	{
		String^ inputString = message;


		array<String^>^ subString = inputString->Split(' ');


		String^ index_s = subString[0];
		String^ isTrue = subString[1];
		int index = Int32::Parse(index_s);


		switch (index)
		{
		case e_friends_Request_Accept:
		{
			if (isTrue == "true")
			{
				System::Windows::Forms::MessageBox::Show("friends accepted", "Notice", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			else
			{
				// false
			}
			break;
		}
		case e_friends_Request_Decline:
		{
			if (isTrue == "true")
			{
				System::Windows::Forms::MessageBox::Show("friends request rejected", "Notice", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			else
			{
				// false
			}
			break;
		}
		case e_friends_Response_List:



			if (isTrue == "true")
			{
				this->Invoke(gcnew Action<String^>(this, &FriendsResponse::UpdateFriendResponse), message);
			}
			else
			{
				// false
			}
			break;


		}

	}

		  void UpdateFriendResponse(String^ message)
		  {
			  String^ inputString = message;


			  array<String^>^ subString = inputString->Split(gcnew array<String^>{ "*/" }, StringSplitOptions::None);
			  int count = 0;
			  ViewResponseList->Rows->Clear();

			  for (int i = 1; i < subString->Length - 1; i++)
			  {

				  size_t pos = subString[i]->IndexOf(" ");
				  String^ first = subString[i]->Substring(0, pos);
				  String^ second = subString[i]->Substring(pos + 1, subString[i]->Length - (pos + 1));

				  ViewResponseList->Rows->Add();
				  ViewResponseList->Rows[count]->Cells["NumOfList"]->Value = System::Convert::ToString(count);
				  ViewResponseList->Rows[count]->Cells["FromWho"]->Value = first;
				  ViewResponseList->Rows[count]->Cells["ReqMsg"]->Value = second;
				  count++;
			  }



		  }

		private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}
		private: System::Void FriendResponse_Activated(System::Object^ sender, System::EventArgs^ e) {


			int t_index = e_friends_Response_List;
			String^ buffer = t_index.ToString();
			_my->SendMessage(buffer);


		}
		private: System::Void btnAccept_Click(System::Object^ sender, System::EventArgs^ e) {
			if (ViewResponseList->SelectedCells->Count == 0)
			{
				System::Windows::Forms::MessageBox::Show("Select ID From List", "Notice", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}

			SendMessageForm(e_friends_Accept);
		}
		private: System::Void btnReject_Click(System::Object^ sender, System::EventArgs^ e) {

			// 아무것도 선택하지 않았을 때
			if (ViewResponseList->SelectedCells->Count == 0)
			{
				System::Windows::Forms::MessageBox::Show("Select ID From List", "Notice", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}

			SendMessageForm(e_friends_Request_Decline);
		}


	};
}