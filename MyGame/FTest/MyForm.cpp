#include "MyForm.h"
#include <cstdlib>
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute] // ������ main() � ��������� ������ ������
int main(array<String^>^ args)
{
	Application::SetCompatibleTextRenderingDefault(false); // ��� ���������� ��������� ������
	Application::EnableVisualStyles(); // ����������� ��������� ������
	FTest::MyForm form;
	Application::Run(% form); // % - ���� ��� �������� ������� ������ � .NET
}