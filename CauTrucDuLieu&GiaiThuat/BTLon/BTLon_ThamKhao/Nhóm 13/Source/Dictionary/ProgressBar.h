#pragma once
#include "Header.h"

class ProgressBar
{
public:
	int value, minimum, maximum, ColorA, ColorZ, load_value, ID;
	wstring Text, DonVi;
	COORD Location;
	int* Value = &value;
	ProgressBar();

	~ProgressBar();
private:
	wchar_t A = ' ',
		Z = ' ';
	bool Enabled = false,
		Deactivate = false;
	void Load()
	{
		load_value = 0;
		Text = L"";
		DonVi = L"%";
		value = 0;
		minimum = 0;
		maximum = 100;
		ColorA = Color.Green + Light;
		ColorZ = Color.White + Light;
		Location.X = 0;
		Location.Y = 0;
		ID = GetID();
	}
public:
	void Refresh()
	{
		Enabled = true;
		wstring temp = Text + L" "+ to_wstring(*Value) + L" " + DonVi;
		int tempSize = temp.length(),
			half_tempSize = 50 - (tempSize / 2);

		SetConsoleCursorPosition(StdHandel, Location);
		for (int i = minimum; i < maximum; i++)
		{
			
			if (Deactivate)
			{
				Enabled = false;
				Deactivate = false;
				return;
			}
			if (i < *Value)
			{
				if (i >= load_value - 4 && i <= load_value) SetConsoleTextAttribute(StdHandel, ((ColorA + Light) << 4) | ColorZ);
				else SetConsoleTextAttribute(StdHandel, (ColorA << 4) | ColorZ);

				if (i >= half_tempSize && i < half_tempSize + tempSize)
				{
					wcout << temp[i - half_tempSize];
				}
				else
				{
					wcout << A;
				}
			}
			else
			{
				SetConsoleTextAttribute(StdHandel, (ColorZ << 4) | ColorA);
				if (i >= half_tempSize && i < half_tempSize + tempSize)
				{
					wcout << temp[i - half_tempSize];
				}
				else
				{
					wcout << Z;
				}
			}
			Enabled = false;
		}
		DefaultColor();
	}
	void Refresh(int value_)
	{
		*Value = value_;
		Refresh();
	}

	void operator()(int load_value_)
	{
		load_value = load_value_;
		Refresh();
	}
	void operator()()
	{
		Refresh();
	}

	friend void Set_ProgressBar(ProgressBar pb, int value_);
	friend void operator <<(ProgressBar pb, int value_);

};

ProgressBar::ProgressBar()
{
	Load();
}
ProgressBar::~ProgressBar()
{
	 
}

void Set_ProgressBar(ProgressBar pb, int value_)
{
	thread thr_Temp(pb, value_);
	thr_Temp.join();
}

void operator <<(ProgressBar pb, int value_)
{
	*(pb.Value) = value_;
}

void Temp_ProgressBar(ProgressBar pb)
{
	int load_value_ = 0;
	while (true)
	{
		Set_ProgressBar(pb, load_value_);
		if (pb.ID == ID_Huy)
		{
			ID_Huy = 0;
			break;
		}
		load_value_++;
		if (load_value_ > *(pb.Value)) load_value_ = 0;
		Sleep(100);
	}
}
void Start_ProgressBar(ProgressBar pb)
{
	thread thr_temp(Temp_ProgressBar, pb);
	thr_temp.detach();
}
void End_ProgressBar(int ID_ProgressBar_)
{
	ID_Huy = ID_ProgressBar_;
	while (ID_Huy != 0)
	{
		Sleep(50);
	}
}