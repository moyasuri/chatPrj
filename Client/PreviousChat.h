#pragma once
#include "MyFunction.h"
#include "enum.h"

namespace Client {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// PreviousChat에 대한 요약입니다.
	/// </summary>
	public ref class PreviousChat : public System::Windows::Forms::Form
	{
	public:
		PreviousChat(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
		}

		PreviousChat(MyFunction^ my)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
			_my = my;
			_my->MyEvent += gcnew Action<String^>(this, &PreviousChat::ReceivedMsg);

			int t_index = e_room_show_whole_Text;
			String^ buffer = _my->s_(t_index);
			_my->SendMessage(buffer);


		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~PreviousChat()
		{

			if (_my != nullptr) {
				// MyEvent 이벤트 핸들러를 해제
				_my->MyEvent -= gcnew Action<String^>(this, &PreviousChat::ReceivedMsg);

				// _my를 삭제
				delete _my;
				_my = nullptr;  // nullptr로 설정하여 dangling pointer를 방지
			}

			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ ViewDataChat;
	protected:



	private: MyFunction^ _my;
	private: System::Windows::Forms::Button^ btnClose;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ViewId;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ViewMsg;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Date;








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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(PreviousChat::typeid));
			this->ViewDataChat = (gcnew System::Windows::Forms::DataGridView());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->ViewId = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ViewMsg = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Date = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ViewDataChat))->BeginInit();
			this->SuspendLayout();
			// 
			// ViewDataChat
			// 
			this->ViewDataChat->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->ViewDataChat->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::Raised;
			this->ViewDataChat->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->ViewDataChat->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->ViewId,
					this->ViewMsg, this->Date
			});
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"굴림", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->ViewDataChat->DefaultCellStyle = dataGridViewCellStyle1;
			this->ViewDataChat->Location = System::Drawing::Point(28, 34);
			this->ViewDataChat->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->ViewDataChat->Name = L"ViewDataChat";
			this->ViewDataChat->RowTemplate->Height = 27;
			this->ViewDataChat->Size = System::Drawing::Size(502, 311);
			this->ViewDataChat->TabIndex = 4;
			// 
			// btnClose
			// 
			this->btnClose->BackColor = System::Drawing::Color::Transparent;
			this->btnClose->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnClose.BackgroundImage")));
			this->btnClose->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->btnClose->FlatAppearance->BorderSize = 0;
			this->btnClose->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnClose->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnClose->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnClose->Location = System::Drawing::Point(628, 453);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(164, 59);
			this->btnClose->TabIndex = 5;
			this->btnClose->UseVisualStyleBackColor = false;
			this->btnClose->Click += gcnew System::EventHandler(this, &PreviousChat::btnClose_Click);
			// 
			// ViewId
			// 
			this->ViewId->HeaderText = L"ID";
			this->ViewId->Name = L"ViewId";
			this->ViewId->Width = 50;
			// 
			// ViewMsg
			// 
			this->ViewMsg->HeaderText = L"Message";
			this->ViewMsg->Name = L"ViewMsg";
			this->ViewMsg->Width = 250;
			// 
			// Date
			// 
			this->Date->HeaderText = L"Time";
			this->Date->Name = L"Date";
			this->Date->Width = 150;
			// 
			// PreviousChat
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ClientSize = System::Drawing::Size(876, 562);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->ViewDataChat);
			this->Name = L"PreviousChat";
			this->Text = L"PreviousChat";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ViewDataChat))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion




		private: void ReceivedMsg(String^ message)
		{
			String^ inputString = message;

			array<String^>^ subString = inputString->Split(' ');

			String^ index_s = subString[0];
			String^ isTrue = subString[1];
			int index = Int32::Parse(index_s);

			switch (index)
			{

			case e_room_show_whole_Text:
			{
				if (isTrue == "true")
				{
					this->Invoke(gcnew Action<String^>(this, &PreviousChat::PreviousMsgShow), message);
				}
				else if (isTrue == "else")
				{
					// nothing to do
				}
				break;
			}

			}

		}
		public: void PreviousMsgShow(String^ message)
		{
			String^ e_length = _my->s_(e_room_show_whole_Text);
			String^ msg = message->Substring(e_length->Length + 6);

			//// 아이디 추출
			int idEndIndex = msg->IndexOf(' '); // 공백 이전까지가 아이디
			String^ id = msg->Substring(0, idEndIndex)->Trim();

			// 메시지 추출
			String^ messagePart = msg->Substring(idEndIndex)->Trim();

			//// 날짜 추출
			int lastSpaceIndex = messagePart->LastIndexOf(' '); // 뒤에서부터 첫 번째 공백의 위치
			int dateEndIndex = messagePart->LastIndexOf(' ', lastSpaceIndex - 1); // 뒤에서부터 두 번째 공백의 위치
			String^ date = messagePart->Substring(dateEndIndex)->Trim();

			//// 실제 메시지 추출 (날짜 이전의 부분)
			String^ messageText = messagePart->Substring(0, dateEndIndex)->Trim();
			int rowIndex = ViewDataChat->Rows->Add();
			ViewDataChat->Rows[rowIndex]->Cells["ViewId"]->Value = id;
			ViewDataChat->Rows[rowIndex]->Cells["ViewMsg"]->Value = messageText;
			ViewDataChat->Rows[rowIndex]->Cells["Date"]->Value = date;

		}



	private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
};
}
