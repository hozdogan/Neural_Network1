#include "MyForm.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	ysaproje3::MyForm form;//image yerine proje ad� gelecek
	Application::Run(% form);
	return 0;
}
