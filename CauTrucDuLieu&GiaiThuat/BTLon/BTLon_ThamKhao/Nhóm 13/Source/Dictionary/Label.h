#pragma once
#include "Header.h"
class Label
{
public:
	COORD Location;
	int FontColor, BackgroundFontColor, FontSize, Size;
	wstring Text;
	bool AutoSize;
	

	Label();
	Label(wstring);
	~Label();
private:
	friend void operator << (Label lb_, wstring text_);

	COORD Location_Prev;
	int SizeText_Pre;
	bool AutoSize_Pre;
	bool refresh;

	void Load()
	{
		Location.X = 0;
		Location.Y = 0;
		FontColor = Default_FontColor;
		BackgroundFontColor = Default_BackgroundFontColor;
		Size = 30;
		FontSize = 14;
		AutoSize = true;
		refresh = false;
	}

public:
	bool IsMe()
	{
		if (!AutoSize)
		{
			if (Toa_Do_Select->Y == Location.Y &&
				Toa_Do_Select->X >= Location.X &&
				Toa_Do_Select->X <= Location.X + Size)
				return true;
		}
		else
		{
			if (Toa_Do_Select->Y == Location.Y &&
				Toa_Do_Select->X >= Location.X &&
				Toa_Do_Select->X <= Location.X + Text.length())
				return true;
		}
		return false;
	}

	void Hightlight()
	{
		int TempColor = BackgroundFontColor;
		BackgroundFontColor = FontColor;
		FontColor = TempColor;
		Refresh();
	}

	void Refresh()
	{
		if (!refresh)
		{
			SetConsoleCursorPosition(StdHandel, Location);
			SetConsoleTextAttribute(StdHandel, (BackgroundFontColor << 4) | FontColor);
			if (AutoSize)
			{
				wcout << Text;
			}
			else
			{
				int temp = Size - Text.length();
				if (temp >= 0)
				{
					wcout << Text;
					for (int i = 0; i < temp; i++)
					{
						wcout << " ";
					}
				}
				else
				{
					for (int i = 0; i < Size; i++)
					{
						wcout << Text[i];
					}
				}
			}
		}
		else if (Location.X == Location_Prev.X && Location.Y == Location_Prev.Y)
		{
			SetConsoleCursorPosition(StdHandel, Location);
			SetConsoleTextAttribute(StdHandel, (BackgroundFontColor << 4) | FontColor);

			wcout << Text;
			if (!AutoSize)
			{
				if (Text.length() <= Size)
				{
					for (int i = 0; i < Size - Text.length(); i++)
					{
						//DefaultColor();
						wcout << L" ";
					}
				}
				if (Size < SizeText_Pre)
				{
					for (int i = 0; i < SizeText_Pre - Size; i++)
					{
						DefaultColor();
						wcout << L" ";
					}
				}
			}
			else
			{
				if (Text.length() < SizeText_Pre)
				{
					for (int i = 0; i < SizeText_Pre - Text.length(); i++)
					{
						DefaultColor();
						wcout << L" ";
					}
				}
			}
			
		}
		else
		{
			if (refresh)
			{
				SetConsoleCursorPosition(StdHandel, Location_Prev);
				DefaultColor();
				if (AutoSize_Pre)
				{
					for (int i = 0; i < SizeText_Pre; i++)
					{
						wcout << " ";
					}
				}
				else
				{
					for (int i = 0; i < Size; i++)
					{
						wcout << " ";
					}
				}
			}

			SetConsoleCursorPosition(StdHandel, Location);
			SetConsoleTextAttribute(StdHandel, (BackgroundFontColor << 4) | FontColor);
			if (AutoSize)
			{
				wcout << Text;
			}
			else
			{
				int temp = Size - Text.length();
				if (temp >= 0)
				{
					wcout << Text;
					for (int i = 0; i < temp; i++)
					{
						wcout << " ";
					}
				}
				else
				{
					for (int i = 0; i < Size; i++)
					{
						wcout << Text[i];
					}
				}
			}
		}
		//-------------------------------

		SizeText_Pre = Text.length();
		AutoSize_Pre = AutoSize;
		Location_Prev = Location;
		refresh = true;
		DefaultColor();
	}
	void Refresh(wstring Text_)
	{
		Text = Text_;
		Refresh();
	}

};
Label::Label()
{
	Load();
}
Label::Label(wstring Text_)
{
	Load();
	Text = Text_;
}
Label::~Label()
{

}

void operator << (Label lb_, wstring text_)
{
	lb_.Refresh(text_);
}

