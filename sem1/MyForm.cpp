#include "MyForm.h"
#include <Windows.h>
using namespace sem1; //пространство имен из заголовочного файла формы !!!
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
	return 0;
}