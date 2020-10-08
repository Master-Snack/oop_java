#pragma once
#include "Header.h"
#include "GraphicsConsole.h"
#include "Database.h"
#include "List_WordMean.h"

void LoadFile(List_WordMean* List_, wstring* path_)
{
	wifstream fin(*path_);
	if (!fin)
	{
		List_->ADD(L"]", L"]");
		return;
	}
	else
	{
		fin.imbue(loc);
		int giatri = 0;
		ProgressBar* PrB = new ProgressBar;
		PrB->Refresh();

		wstring word, mean;
		wchar_t c;
		fin >> c;
		if (c == '[')
			while (!fin.eof())
			{
				fin >> c;
				if (c == '{')
				{
					getline(fin, word);
					getline(fin, word);
					getline(fin, mean);
					List_->ADD(word, mean);
					giatri++;
					if (giatri >= 1256)
					{
						PrB->value++;
						PrB->Refresh();
						giatri = 0;
					}
				}
				if (c == ']')
				{
					List_->ADD(L"]", L"]");
					break;
				}
			}
	}
	fin.close();
}

void LoadData(List_WordMean* List_)
{
	ifstream fin(paths.user_av, ios::binary);
	if (!fin)
	{
		fin.open(paths.av, ios::binary);
	}

	//------Khai bao -------------------------------------------------------

	wstring word, mean;

	char data_in = 'a';
	int streamSize = sizeof(data_in);
	//---------------------------------------------------------------------
	fin.read(&data_in, streamSize);
	if (data_in == firstFile)
	{
		while (!fin.eof())
		{
			// ----------------- Load Word Mean -----------------------------------
			fin.read(&data_in, streamSize);

			if (data_in == firstString)
			{
				//------------------ Load Word -------------------------------------
				word.clear();
				while (true)
				{
					fin.read(&data_in, streamSize);
					if (data_in == lastString) break;
					else
					{
						word.push_back(Decode_value(data_in));
					}
				}
				//------------------ Load Mean --------------------------------------
				fin.read(&data_in, streamSize);
				if (data_in == firstString)
				{
					mean.clear();
					while (true)
					{
						fin.read(&data_in, streamSize);
						if (data_in == lastString)
						{
							fin.read(&data_in, streamSize);
							break;
						}
						else
						{
							mean.push_back(Decode_value(data_in));
						}
					}
				}
				else break;
			}
			// --------------------------------------------------------------------
			if (data_in == newString)
			{
				List_->ADD(word, mean);
			}
			else if (data_in == lastFile)
			{
				if (word == L"]" && mean == L"]") fin.close();
				else List_->ADD(L"]", L"]");
				return;
			}
			else break;
		}
	}
	//----------------------------------------------------------------
	fin.close();
	int dialogresult =
		MessageBoxW(NULL, ( LPCWSTR )L"Database bị lỗi !\nThoát ?",
		( LPCWSTR )L"Dictionary thông báo",
					MB_OK | MB_HELP | MB_ICONERROR);
	if (dialogresult == IDHELP) LoadFileHelp();
	else exit(1);
}

void SetData(List_WordMean* List_, Database* Db_)
{
	wstring word, mean;

	int giatri = 0;

	ProgressBar* PrB = new ProgressBar;
	PrB->Location.X = 15;
	PrB->Location.Y = 3;
	PrB->ColorA = Color.Blue;
	PrB->Refresh();

	while (true)
	{
		if (List_->FirstNode_ != NULL)
		{
			word = *(List_->FirstNode_->Word);
			mean = *(List_->FirstNode_->Mean);
			if (word == L"]" && mean == L"]") break;
			Db_->ADD(word, mean);
			List_->RemoveFirst();

			giatri++;
			if (giatri >= 1256)
			{
				giatri = 0;
				PrB->ColorA = Color.Blue;
				PrB->value++;
				PrB->Refresh();
			}
		}
		else
		{
			PrB->ColorA = Color.Red;
			PrB->Refresh();
			Sleep(10);
		}
	}
}

string ConvertoString(wstring str_, int *length)
{
	string temm;
	for (int i = 0; i < str_.length(); i++)
	{
		temm.push_back(str_[i]);
	}
	return temm;
}

bool Delete_File(const char* file_path)
{
	int ret = remove(file_path);
	bool is_ok = (ret == 0) ? true : false;
	return ret;
}

void ResetData()
{
	int lengOfpath;
	string pathOf_userAv = ConvertoString(paths.av, &lengOfpath);
	DeleteFile(( LPCSTR )"P:/Project/Dictionary/data/user/av.dictionary");
}
