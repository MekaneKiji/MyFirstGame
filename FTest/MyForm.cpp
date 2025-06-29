#include "MyForm.h"
#include <cstdlib>
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute] // запуск main() в отдельном потоке данных
int main(array<String^>^ args)
{
	Application::SetCompatibleTextRenderingDefault(false); // для корректной обработки текста
	Application::EnableVisualStyles(); // подключение различных стилей
	FTest::MyForm form;
	Application::Run(% form); // % - знак для передачи объекта класса в .NET
}