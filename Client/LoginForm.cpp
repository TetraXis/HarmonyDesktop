#include "LoginForm.h"
#include "terminal.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args)
{
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	HarmonyWinforms::LoginForm login_form;
	Application::Run(% login_form);
}