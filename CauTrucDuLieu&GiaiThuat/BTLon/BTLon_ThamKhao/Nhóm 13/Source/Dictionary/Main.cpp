#include "Main_Header.h"
#include "Main_From.h"
int main()
{
	system("cls");
	GetWindowRect(GetDesktopWindow(), &Rect_Desktop);
	MoveWindow(GetConsoleWindow(), (Rect_Desktop.right - width_console)/2, (Rect_Desktop.bottom - height_console) / 2, width_console, height_console, true);

	CONSOLE_FONT_INFOEX StdFont;
	StdFont.cbSize = sizeof(StdFont);
	GetCurrentConsoleFontEx(StdHandel, FALSE, &StdFont);
	memcpy(StdFont.FaceName, L"Consolas", sizeof(StdFont.FaceName));
	SetCurrentConsoleFontEx(StdHandel, false, &StdFont);
	StdCursorInfo = new CONSOLE_CURSOR_INFO;
	StdCursorInfo->dwSize = 1;
	StdCursorInfo->bVisible = false;
	SetConsoleCursorInfo(StdHandel, StdCursorInfo);

	
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stdout), _O_U16TEXT);
	SetConsoleTitleW(( LPCWSTR )L"Dictionary");
	
	Toa_Do_Select = new COORD;
	Toa_Do_Select->X = 0;
	Toa_Do_Select->Y = 0;
	thread t1(EvenSlect, Toa_Do_Select);
	t1.detach();

	Load_CodeTable();

	

	Main_From* M_Form = new Main_From;
	thread t2(*M_Form);
	t2.join();

	return 0;
}