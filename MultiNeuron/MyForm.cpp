#include "MyForm.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	ysaproje2::MyForm form;//image yerine proje adý gelecek
	Application::Run(% form);
	return 0;
}
