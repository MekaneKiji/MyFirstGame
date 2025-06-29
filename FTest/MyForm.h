#pragma once
#include "MyForm2.h"
#include <Windows.h>
#include <vcclr.h>
namespace FTest {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void) {
			InitializeComponent();
			LoadDir();
			LoadCount(); // Загружаем последний режим и прогресс
			UpdateUI();
			this->FormClosing += gcnew FormClosingEventHandler(this, &MyForm::MyForm_FormClosing);
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
	private: System::Windows::Forms::Button^ Click;
	private: Random^ random = gcnew Random();
	private: MyForm2 _form2Instance;
	protected:

	private: System::Windows::Forms::ProgressBar^ ClickBar;
	private: System::Windows::Forms::Label^ win;
	private: System::Windows::Forms::Button^ reset;
	private: System::Windows::Forms::Label^ labelcount;

	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::RadioButton^ radioButton1;

	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::RadioButton^ radioButton3;
	private: System::Windows::Forms::Label^ scet;

	private: System::Windows::Forms::Button^ MenuFormButton;
	private: System::Windows::Forms::Button^ button1;
	private:
		Point easyButtonPosition = Point(42, 136);
		Point hardButtonPosition = Point(50, 145);
		Point ultraHardButtonPosition = Point(60, 154);







	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->Click = (gcnew System::Windows::Forms::Button());
			this->ClickBar = (gcnew System::Windows::Forms::ProgressBar());
			this->win = (gcnew System::Windows::Forms::Label());
			this->reset = (gcnew System::Windows::Forms::Button());
			this->labelcount = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->scet = (gcnew System::Windows::Forms::Label());
			this->MenuFormButton = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// Click
			// 
			this->Click->BackColor = System::Drawing::Color::White;
			this->Click->Font = (gcnew System::Drawing::Font(L"Arial", 14));
			this->Click->ForeColor = System::Drawing::Color::Black;
			this->Click->Location = System::Drawing::Point(42, 136);
			this->Click->Name = L"Click";
			this->Click->Size = System::Drawing::Size(88, 84);
			this->Click->TabIndex = 0;
			this->Click->TabStop = false;
			this->Click->Text = L"Нажми";
			this->Click->UseVisualStyleBackColor = false;
			this->Click->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Click_MouseClick);
			// 
			// ClickBar
			// 
			this->ClickBar->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClickBar->Location = System::Drawing::Point(42, 75);
			this->ClickBar->Maximum = 10;
			this->ClickBar->Name = L"ClickBar";
			this->ClickBar->Size = System::Drawing::Size(223, 23);
			this->ClickBar->TabIndex = 1;
			// 
			// win
			// 
			this->win->AutoSize = true;
			this->win->Location = System::Drawing::Point(115, 59);
			this->win->Name = L"win";
			this->win->Size = System::Drawing::Size(71, 13);
			this->win->TabIndex = 3;
			this->win->Text = L"Поздравляю";
			this->win->Visible = false;
			// 
			// reset
			// 
			this->reset->Location = System::Drawing::Point(147, 226);
			this->reset->Name = L"reset";
			this->reset->Size = System::Drawing::Size(88, 23);
			this->reset->TabIndex = 4;
			this->reset->Text = L"Сброс";
			this->reset->UseVisualStyleBackColor = true;
			this->reset->Visible = false;
			this->reset->Click += gcnew System::EventHandler(this, &MyForm::reset_Click);
			// 
			// labelcount
			// 
			this->labelcount->Location = System::Drawing::Point(102, 33);
			this->labelcount->Name = L"labelcount";
			this->labelcount->Size = System::Drawing::Size(100, 13);
			this->labelcount->TabIndex = 5;
			this->labelcount->Text = L"1";
			this->labelcount->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->radioButton1);
			this->groupBox1->Controls->Add(this->radioButton2);
			this->groupBox1->Controls->Add(this->radioButton3);
			this->groupBox1->Location = System::Drawing::Point(147, 131);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(125, 89);
			this->groupBox1->TabIndex = 7;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Режим сложности";
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Checked = true;
			this->radioButton1->Location = System::Drawing::Point(6, 19);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(112, 17);
			this->radioButton1->TabIndex = 2;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Простой уровень";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::RadioButton_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(6, 42);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(116, 17);
			this->radioButton2->TabIndex = 1;
			this->radioButton2->Text = L"Сложный уровень";
			this->radioButton2->Visible = false;
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &MyForm::RadioButton_CheckedChanged);
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(6, 64);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(88, 17);
			this->radioButton3->TabIndex = 0;
			this->radioButton3->Text = L"Ультра хард";
			this->radioButton3->Visible = false;
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &MyForm::RadioButton_CheckedChanged);
			// 
			// scet
			// 
			this->scet->Location = System::Drawing::Point(102, 46);
			this->scet->Name = L"scet";
			this->scet->Size = System::Drawing::Size(94, 13);
			this->scet->TabIndex = 9;
			this->scet->Text = L"0 / 10";
			this->scet->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// MenuFormButton
			// 
			this->MenuFormButton->Location = System::Drawing::Point(235, 12);
			this->MenuFormButton->Name = L"MenuFormButton";
			this->MenuFormButton->Size = System::Drawing::Size(37, 37);
			this->MenuFormButton->TabIndex = 11;
			this->MenuFormButton->Text = L"C";
			this->MenuFormButton->UseVisualStyleBackColor = true;
			this->MenuFormButton->Click += gcnew System::EventHandler(this, &MyForm::MenuFormButton_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(62, 37);
			this->button1->TabIndex = 12;
			this->button1->Text = L"Full Reset";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->MenuFormButton);
			this->Controls->Add(this->scet);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->labelcount);
			this->Controls->Add(this->reset);
			this->Controls->Add(this->win);
			this->Controls->Add(this->ClickBar);
			this->Controls->Add(this->Click);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"MyForm";
			this->Text = L"Кликер";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
		int EasyPrestige = 1;
		int HardPrestige = 1;
		int UltraHardPrestige = 1;
		int LightweightCounter, HeavyCounter, UltraHeavyCounter = 0;
		int RandomModifier = 0;
		int LCUseful, HCUseful, UHCUseful = 0;
		int Counter = 0;


	private: int GetRandomNumber(int minValue, int maxValue)
	{
		return random->Next(minValue, maxValue);
	}

	private: System::Void Click_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Space)
		{
			e->SuppressKeyPress = true;  // Блокируем обработку пробела
			e->Handled = true;           // Помечаем событие как обработанное
		}
	}

		   String^ GetApplicationDirectory() {
			   return Path::GetDirectoryName(Application::ExecutablePath);
		   }

		   // Сохранение счетчика в файл
		   void SaveCount() {
			   String^ filePath = Path::Combine(GetApplicationDirectory(), "Save.nbt");
			   int currentMode = 0;
			   if (radioButton1->Checked) currentMode = 0;
			   else if (radioButton2->Checked) currentMode = 1;
			   else if (radioButton3->Checked) currentMode = 2;

			   // Сохраняем все данные, включая sh (прогресс) и currentMode (режим)
			   String^ str = EasyPrestige.ToString() + " " + HardPrestige.ToString() + " " + UltraHardPrestige.ToString() + " " +
				   LCUseful.ToString() + " " + HCUseful.ToString() + " " + UHCUseful.ToString() + " " +
				   Counter.ToString() + " " + currentMode.ToString() + " " + LightweightCounter.ToString() + " "
				   + HeavyCounter.ToString() + " " + UltraHeavyCounter.ToString();
			   File::WriteAllText(filePath, str);

			   String^ filePathDir = Path::Combine(GetApplicationDirectory(), "SaveDir.nbt");
			   String^ strDir = easyButtonPosition.X.ToString() + " " + easyButtonPosition.Y.ToString() + " " +
				   hardButtonPosition.X.ToString() + " " + hardButtonPosition.Y.ToString() + " " +
				   ultraHardButtonPosition.X.ToString() + " " + ultraHardButtonPosition.Y.ToString() + " " + currentMode.ToString();
			   File::WriteAllText(filePathDir, strDir);
		   }

		   // Загрузка расположения
		   void LoadDir() {
			   String^ filePathDir = Path::Combine(GetApplicationDirectory(), "SaveDir.nbt");
			   if (File::Exists(filePathDir)) {
				   String^ savedCount = File::ReadAllText(filePathDir);
				   array<String^>^ components = savedCount->Split(' ');

				   if (components->Length >= 4) {
					   easyButtonPosition = Point(Convert::ToInt32(components[0]), Convert::ToInt32(components[1]));
					   hardButtonPosition = Point(Convert::ToInt32(components[2]), Convert::ToInt32(components[3]));
					   ultraHardButtonPosition = Point(Convert::ToInt32(components[4]), Convert::ToInt32(components[5]));
					   int savedMode = Convert::ToInt32(components[6]);
					   if (savedMode == 0) {
						   radioButton1->Checked = true;
						   this->Click->Location = easyButtonPosition;
						   this->Click->Font = gcnew System::Drawing::Font("Arial", 14.0f);
					   }
					   else if (savedMode == 1) {
						   radioButton2->Checked = true;
						   this->Click->Location = hardButtonPosition;
						   this->Click->Font = gcnew System::Drawing::Font("Arial", 10.0f);
					   }
					   else if (savedMode == 2) {
						   radioButton3->Checked = true;
						   this->Click->Location = ultraHardButtonPosition;
						   this->Click->Font = gcnew System::Drawing::Font("Arial", 6.0f);
					   }
				   }
			   }
		   }


		   // Загрузка прогресса из файла
		   void LoadCount() {
			   String^ filePath = Path::Combine(GetApplicationDirectory(), "Save.nbt");
			   if (File::Exists(filePath)) {
				   String^ savedCount = File::ReadAllText(filePath);
				   array<String^>^ components = savedCount->Split(' ');

				   if (components->Length >= 9) {
					   EasyPrestige = Convert::ToInt32(components[0]);
					   HardPrestige = Convert::ToInt32(components[1]);
					   UltraHardPrestige = Convert::ToInt32(components[2]);
					   LCUseful = Convert::ToInt32(components[3]);
					   HCUseful = Convert::ToInt32(components[4]);
					   UHCUseful = Convert::ToInt32(components[5]);
					   Counter = Convert::ToInt32(components[6]);

					   int savedMode = Convert::ToInt32(components[7]); // Режим

					   // Восстанавливаем режим сложности БЕЗ сброса прогресса
					   if (savedMode == 0) {
						   radioButton1->Checked = true;
						   this->ClickBar->Maximum = 10;
						   labelcount->Text = EasyPrestige.ToString();
					   }
					   else if (savedMode == 1) {
						   radioButton2->Checked = true;
						   this->ClickBar->Maximum = 50;
						   labelcount->Text = HardPrestige.ToString();
					   }
					   else if (savedMode == 2) {
						   radioButton3->Checked = true;
						   this->ClickBar->Maximum = 500;
						   labelcount->Text = UltraHardPrestige.ToString();
					   }
					   LightweightCounter = Convert::ToInt32(components[8]); // Прогресс
					   HeavyCounter = Convert::ToInt32(components[9]); // Прогресс
					   UltraHeavyCounter = Convert::ToInt32(components[10]); // Прогресс
					   // Восстанавливаем прогресс
					   if (savedMode == 0) {
						   this->ClickBar->Value = LightweightCounter;
						   scet->Text = LightweightCounter.ToString() + " / " + this->ClickBar->Maximum.ToString();

						   // Проверяем, не достигнут ли максимум
						   if (LightweightCounter >= this->ClickBar->Maximum) {
							   this->win->Visible = true;
							   this->reset->Visible = true;
							   this->Click->Enabled = false;
						   }
					   }
					   if (savedMode == 1) {
						   this->ClickBar->Value = HeavyCounter;
						   scet->Text = HeavyCounter.ToString() + " / " + this->ClickBar->Maximum.ToString();

						   // Проверяем, не достигнут ли максимум
						   if (HeavyCounter >= this->ClickBar->Maximum) {
							   this->win->Visible = true;
							   this->reset->Visible = true;
							   this->Click->Enabled = false;
						   }
					   }
					   if (savedMode == 2) {
						   this->ClickBar->Value = UltraHeavyCounter;
						   scet->Text = UltraHeavyCounter.ToString() + " / " + this->ClickBar->Maximum.ToString();

						   // Проверяем, не достигнут ли максимум
						   if (UltraHeavyCounter >= this->ClickBar->Maximum) {
							   this->win->Visible = true;
							   this->reset->Visible = true;
							   this->Click->Enabled = false;
						   }
					   }
					   // Проверка прогресса
					   if (EasyPrestige >= 10) {
						   this->radioButton2->Visible = true;
					   }
					   if (HardPrestige >= 10) {
						   this->radioButton3->Visible = true;
					   }
				   }
			   }
		   }
		   // Обновление интерфейса после загрузки
		   void UpdateUI() {
			   if (radioButton1->Checked) labelcount->Text = EasyPrestige.ToString();
			   else if (radioButton2->Checked) labelcount->Text = HardPrestige.ToString();
			   else if (radioButton3->Checked) labelcount->Text = UltraHardPrestige.ToString();
		   }

		   System::Void MyForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
			   SaveCount();
		   }


	private: System::Void reset_Click(System::Object^ sender, System::EventArgs^ e) {
		bool isEasy = radioButton1->Checked;
		bool isHard = radioButton2->Checked;
		bool isUltraHard = radioButton3->Checked;
		this->ClickBar->Value = 0;
		this->win->Visible = false;
		this->reset->Visible = false;
		this->Click->Enabled = true;

		if (isEasy) {
			EasyPrestige += 1;
			LightweightCounter = 0;
			labelcount->Text = EasyPrestige.ToString();
			this->Click->Location = System::Drawing::Point(42, 136);
			scet->Text = LightweightCounter.ToString() + " / 10";
		}
		else if (isHard) {
			HardPrestige += 1;
			HeavyCounter = 0;
			labelcount->Text = HardPrestige.ToString();
			this->Click->Location = System::Drawing::Point(50, 145);
			scet->Text = HeavyCounter.ToString() + " / 50";
		}
		else {
			UltraHardPrestige += 1;
			UltraHeavyCounter = 0;
			labelcount->Text = UltraHardPrestige.ToString();
			this->Click->Location = System::Drawing::Point(60, 154);
			scet->Text = UltraHeavyCounter.ToString() + " / 500";
		}
		if (EasyPrestige >= 10) {
			this->radioButton2->Visible = true;
		}
		if (HardPrestige >= 10) {
			this->radioButton3->Visible = true;
		}
	}

		   System::Void RadioButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			   RadioButton^ selectedRadio = safe_cast<RadioButton^>(sender);

			   if (selectedRadio->Checked) {
				   // Устанавливаем Maximum для нового режима
				   if (selectedRadio == radioButton3) { // Ультра-хард
					   this->ClickBar->Maximum = 500;
					   RandomModifier = 4;
					   this->Click->Size = System::Drawing::Size(44, 42);
					   this->Click->Font = gcnew System::Drawing::Font("Arial", 6.0f);
					   labelcount->Text = UltraHardPrestige.ToString();
					   this->ClickBar->Value = UltraHeavyCounter;
					   scet->Text = UltraHeavyCounter.ToString() + " / 500";
					   this->Click->Location = ultraHardButtonPosition;
					   // Проверяем, не достигнут ли максимум
					   if (UltraHeavyCounter >= this->ClickBar->Maximum) {
						   this->win->Visible = true;
						   this->reset->Visible = true;
						   this->Click->Enabled = false;
					   }
					   else {
						   this->win->Visible = false;
						   this->reset->Visible = false;
						   this->Click->Enabled = true;
					   }
				   }
				   else if (selectedRadio == radioButton2) { // Сложный
					   this->ClickBar->Maximum = 50;
					   RandomModifier = 2;
					   labelcount->Text = HardPrestige.ToString();
					   this->Click->Size = System::Drawing::Size(66, 63);
					   this->Click->Font = gcnew System::Drawing::Font("Arial", 10.0f);
					   this->ClickBar->Value = HeavyCounter;
					   scet->Text = HeavyCounter.ToString() + " / 50";
					   this->Click->Location = hardButtonPosition;
					   // Проверяем, не достигнут ли максимум
					   if (HeavyCounter >= this->ClickBar->Maximum) {
						   this->win->Visible = true;
						   this->reset->Visible = true;
						   this->Click->Enabled = false;
					   }
					   else {
						   this->win->Visible = false;
						   this->reset->Visible = false;
						   this->Click->Enabled = true;
					   }
				   }
				   else { // Простой
					   this->ClickBar->Maximum = 10;
					   RandomModifier = 0;
					   this->Click->Size = System::Drawing::Size(88, 84);
					   this->Click->Font = gcnew System::Drawing::Font("Arial", 14.0f);
					   labelcount->Text = EasyPrestige.ToString();
					   this->ClickBar->Value = LightweightCounter;
					   scet->Text = LightweightCounter.ToString() + " / 10";
					   this->Click->Location = easyButtonPosition;
					   // Проверяем, не достигнут ли максимум
					   if (LightweightCounter >= this->ClickBar->Maximum) {
						   this->win->Visible = true;
						   this->reset->Visible = true;
						   this->Click->Enabled = false;
					   }
					   else {
						   this->win->Visible = false;
						   this->reset->Visible = false;
						   this->Click->Enabled = true;
					   }
				   }

			   }
		   }

		   bool isDarkMode = false;

	private: System::Void MenuFormButton_Click(System::Object^ sender, System::EventArgs^ e) {
		int UsefulCounter = LCUseful + HCUseful + UHCUseful;
		MyForm2^ secondForm = gcnew MyForm2(Counter.ToString(), UsefulCounter.ToString());
		secondForm->ShowDialog();
	}

	private: System::Void Click_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		bool isEasy = radioButton1->Checked;
		bool isHard = radioButton2->Checked;
		bool isUltraHard = radioButton3->Checked;
		if (isEasy) {
			if (this->ClickBar->Value < 10) {
				LightweightCounter += EasyPrestige;
				LCUseful += EasyPrestige;
				Counter += EasyPrestige;
				if (LightweightCounter > 10) { LightweightCounter = 10; }
				this->ClickBar->Value = LightweightCounter;
				scet->Text = LightweightCounter.ToString() + " / 10";
			}
		}
		else if (isHard) {
			if (this->ClickBar->Value < 50) {
				HeavyCounter += HardPrestige;
				HCUseful += HardPrestige;
				Counter += HardPrestige;
				if (HeavyCounter > 50) { HeavyCounter = 50; }
				this->ClickBar->Value = HeavyCounter;
				scet->Text = HeavyCounter.ToString() + " / 50";
			}
			if ((HeavyCounter / HardPrestige) % 10 == 0) {
				this->Click->Location = System::Drawing::Point(GetRandomNumber(24, 80), GetRandomNumber(116, 180));
			}
		}
		else {
			if (this->ClickBar->Value < 500) {
				UltraHeavyCounter += UltraHardPrestige;
				UHCUseful += UltraHardPrestige;
				Counter += UltraHardPrestige;
				if (UltraHeavyCounter > 500) { UltraHeavyCounter = 500; }
				this->ClickBar->Value = UltraHeavyCounter;
				scet->Text = UltraHeavyCounter.ToString() + " / 500";
			}
			if ((UltraHeavyCounter / UltraHardPrestige) % 5 == 0) {
				this->Click->Location = System::Drawing::Point(GetRandomNumber(24, 80), GetRandomNumber(116, 180));
			}
		}
		if (this->ClickBar->Value == this->ClickBar->Maximum) {
			this->win->Visible = true;
			this->reset->Visible = true;
			this->Click->Enabled = false;
		}
		if (radioButton1->Checked) {
			easyButtonPosition = this->Click->Location;
		}
		else if (radioButton2->Checked) {
			hardButtonPosition = this->Click->Location;
		}
		else if (radioButton3->Checked) {
			ultraHardButtonPosition = this->Click->Location;
		}
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		System::Windows::Forms::DialogResult result = MessageBox::Show(
			"Вы уверены, что хотите полностью сбросить прогресс?\nЭто действие нельзя отменить.",
			"Подтверждение сброса",
			MessageBoxButtons::YesNo,
			MessageBoxIcon::Warning
		);

		if (result == System::Windows::Forms::DialogResult::Yes) {
			// Сброс всех переменных
			EasyPrestige = 1;
			HardPrestige = 1;
			UltraHardPrestige = 1;
			LightweightCounter = 0;
			HeavyCounter = 0;
			UltraHeavyCounter = 0;
			LCUseful = 0;
			HCUseful = 0;
			UHCUseful = 0;
			Counter = 0;
			easyButtonPosition = Point(42, 136);
			hardButtonPosition = Point(50, 145);
			ultraHardButtonPosition = Point(60, 154);
			// Сброс UI
			this->ClickBar->Value = 0;
			this->win->Visible = false;
			this->reset->Visible = false;
			this->Click->Enabled = true;
			this->radioButton2->Visible = false;
			this->radioButton3->Visible = false;
			// Обновление интерфейса
			scet->Text = "0 / " + this->ClickBar->Maximum.ToString();
			UpdateUI();

			// Удаление файла сохранения
			String^ filePath = Path::Combine(GetApplicationDirectory(), "Save.txt");
			if (File::Exists(filePath)) {
				File::Delete(filePath);
			}

			// Применение текущего режима сложности
			if (radioButton1->Checked) RadioButton_CheckedChanged(radioButton1, nullptr);
			else if (radioButton2->Checked) RadioButton_CheckedChanged(radioButton2, nullptr);
			else if (radioButton3->Checked) RadioButton_CheckedChanged(radioButton3, nullptr);
		}
	}
	};
}
