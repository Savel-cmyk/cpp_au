#include "MyForm.h"
#include <Windows.h>
#include <cmath>
#include <cstdlib>
#include <stdlib.h>
using namespace Project4;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
	return 0;
}
