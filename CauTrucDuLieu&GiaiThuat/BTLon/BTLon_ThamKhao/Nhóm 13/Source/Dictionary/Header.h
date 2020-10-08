#pragma once
#include <conio.h>
#include <string>
#include <iostream>
#include <conio.h>
#include <fcntl.h>
#include <io.h>
#include <locale>
#include <codecvt>
#include <fstream>
#include <Windows.h>
#include <sstream>
#include <stdio.h>
#include <thread>
#include<stdlib.h>

const HANDLE StdHandel = GetStdHandle(STD_OUTPUT_HANDLE);

struct COLOR
{
	int Black = 0,
		Blue = 1,
		Green = 2,
		Cyan = 3,
		Red = 4,
		Magenta = 5,
		Yellow = 6,
		White = 7;
};
static int Light = 8;
COLOR Color;
const int Default_FontColor = 15, Default_BackgroundFontColor = 0;

void DefaultColor()
{
	SetConsoleTextAttribute(StdHandel, (Default_BackgroundFontColor << 4)| Default_FontColor);
}

int GetID()
{
	static int ID = 1;
	return ++ID;
}
int ID_Huy = 0;
/*void Set_FontSize(int FontSize)
{
	CONSOLE_FONT_INFOEX info = { 0 };
	info.cbSize = sizeof(info);
	info.dwFontSize.Y = FontSize;
	info.FontWeight = FW_NORMAL;
	wcscpy(info.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(StdHandel, NULL, &info);
}*/

using namespace std; // +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

const char firstString = 120, lastString = 121, firstFile = 122, lastFile = 123, newString = 124;


locale loc(locale(), new codecvt_utf8<wchar_t>);


int CodeTable_length = 231;
wchar_t* CodeTable = new wchar_t[CodeTable_length];

wchar_t Decode_value(char value)
{
	return CodeTable[value + 126];
}

char Encode_value(wchar_t value)
{
	for (int i = 0; i < CodeTable_length; i++)
	{
		if (value == CodeTable[i])
		{
			i = i - 126;
			return i;
		}
	}
	return -126;
}

void Load_CodeTable()
{
	wifstream CodeTableFile(L"P:/Project Tu de AV/data/CodeTable.dictionary");
	if (!CodeTableFile)
	{
		wcout << L"Loi khong the doc file";
	}
	else
	{
		wstring StringCodeTable;
		CodeTableFile.imbue(loc);
		while (!CodeTableFile.eof())
		{
			getline(CodeTableFile, StringCodeTable);
		}
		CodeTableFile.close();
		if (StringCodeTable.length() == 229)
		{
			CodeTable[0] = NULL;
			CodeTable[1] = 13;
			for (int i = 2; i < 231; i++)
			{
				CodeTable[i] = StringCodeTable[i - 2];
			}
		}
	}
}
//---------------------------------
struct PATHS_
{
	/*path_av_dictionary = L"data/root/av.dictionary";
   path_help_dictionary = L"data/root/help.dictionary";
	*path_va_dictionary = L"data/root/va.dictionary";
	*path_user_av_dictionary = L"data/user/av.dictionary";
	*path_user_Set = L"data/user/set.setting";*/
	wstring
		//av = L"P:/Project/Dictionary/data/root/av.dictionary",
		av = L"data/root/av.dictionary",
		help = L"",
		//user_av = L"P:/Project/Dictionary/data/user/av.dictionary",
		user_av = L"data/user/av.dictionary",
		user_set = L"P:/Project/Dictionary/data/user/set";
}; typedef struct PATHS_* Paths_;
//const Path_ Path;
const PATHS_ paths;

wstring
*path_av_dictionary,
*path_help_dictionary,
*path_va_dictionary,
*path_user_av_dictionary,
*path_user_Set;

//------title-----------------------




//----------------------------------

void LoadFileHelp()
{
	wifstream fin(paths.help);
	wstring str;
	if (!fin)
	{
		MessageBoxW(NULL, ( LPCWSTR )L"Dữ liệu phần mềm bị hỏng !\nThoát !",
			( LPCWSTR )L"Dictionary thông báo",
					MB_OK | MB_ICONERROR);
		quick_exit(0);
	}
	else
	{
		system("cls&color 2");
		while (!fin.eof())
		{
			getline(fin, str);
			wcout << str;
		}
		fin.close();
		while (true)
		{
			if (_getch() == 27) quick_exit(0);
			else
				MessageBoxW(NULL, ( LPCWSTR )L"Nhấn phím ESC hoặc click vào [x] để thoát !",
				( LPCWSTR )L"Dictionary thông báo",
							MB_OK | MB_ICONINFORMATION);
		}
		
	}
}

COORD *Toa_Do_Select;

CONSOLE_CURSOR_INFO* StdCursorInfo;


RECT Rect_Desktop;
int width_console = 1000,
height_console = 500;


void EvenSlect(COORD* ToaDoSelect_)
{
	CONSOLE_SELECTION_INFO ToaDoSelect;
	HWND consoleWD = GetConsoleWindow();
	RECT RectConsoleWD;
	while (true)
	{
		
		GetConsoleSelectionInfo(&ToaDoSelect);
		if (ToaDoSelect.dwSelectionAnchor.X != 0 || ToaDoSelect.dwSelectionAnchor.Y != 0)
		{
			ToaDoSelect_->X = ToaDoSelect.dwSelectionAnchor.X;
			ToaDoSelect_->Y = ToaDoSelect.dwSelectionAnchor.Y;
			Sleep(50);
			keybd_event(0, NULL, NULL, NULL);
			keybd_event(13, NULL, NULL, NULL);
		}

		GetWindowRect(consoleWD, &RectConsoleWD);
		if (RectConsoleWD.right != width_console || RectConsoleWD.bottom != height_console)
		{
			consoleWD = GetConsoleWindow();
			MoveWindow(consoleWD, RectConsoleWD.left, RectConsoleWD.top, width_console, height_console, true);
		}
		Sleep(50);
	}
}