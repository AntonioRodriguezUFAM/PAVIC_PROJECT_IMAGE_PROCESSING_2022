#include "My_Color_bar.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main(array< String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	PAVICPROJECTIMAGEPROCESSING2022::My_Color_bar form;
	Application::Run(% form);
}