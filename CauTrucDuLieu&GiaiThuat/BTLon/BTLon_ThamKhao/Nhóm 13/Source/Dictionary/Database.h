#pragma once
#include "Header.h"
#include "GraphicsConsole.h"
#include "List_WordMean.h"
class Database
{
public:
	int NumberOfDeXuat;
	wstring DeXuat[4];

	Database();
	~Database();
private:
	wstring path;
	List_WordMean* ListSave;

	struct NODE
	{
		wchar_t c;
		wstring* Mean;
		NODE* Next;
		NODE* Down;
	}; typedef struct NODE* Node;

	Node Root;

	Node Make_Node(wchar_t c)
	{
		Node NewNode = new NODE;
		NewNode->c = c;
		NewNode->Mean = NULL;
		NewNode->Next = NULL;
		NewNode->Down = NULL;
		return NewNode;
	}
	
	void Load()
	{
		Root = NULL;
		//DeXuat = new wstring[4];
		NumberOfDeXuat = 0;
		ListSave = new List_WordMean;
	}

	Node GetNode(wchar_t c, Node TempNode)
	{
		if (TempNode != NULL)
		{
			Node Temp = TempNode;
			while (true)
			{
				if (Temp->c == c)
				{
					return Temp;
				}

				if (Temp->Next == NULL) break;
				else Temp = Temp->Next;
			}
			Node NewNode = Make_Node(c);
			Temp->Next = NewNode;
			return NewNode;
		}
		return NULL;
	}
public:

	void ADD(wstring word, wstring mean)
	{
		int word_length = word.length();
		if (word_length == 0) return;
		int last_c = word_length - 1;

		wstring* Mean = new wstring;
		*Mean = mean;

		wchar_t temp_C;
	
		if (Root == NULL) Root = Make_Node(word[0]);

		Node TempNode = Root;
		for (int i = 0; i < word_length; i++)
		{
			temp_C = word[i];
			TempNode = GetNode(temp_C, TempNode);
			if (i == last_c)
			{
				TempNode->Mean = Mean;
				return;
			}

			if (TempNode->Down == NULL)
			{
				Node NewNode = Make_Node(word[i + 1]);
				TempNode->Down = NewNode;
				TempNode = NewNode;
			}
			else TempNode = TempNode->Down;
		}
	}

private:
	void GetValueRow(wstring word, Node Temp)
	{
		Node NutTam = Temp;
		while (NutTam != NULL)
		{
			if (NutTam->Mean != NULL)
			{
				wstring word_Temp = word;
				word_Temp.push_back(NutTam->c);
				ListSave->ADD(word_Temp, *(NutTam->Mean));
			}
			Node tammm = NutTam->Down;
			wstring word_Temp = word;
			word_Temp.push_back(NutTam->c);
			GetValueRow(word_Temp, tammm);
			NutTam = NutTam->Next;
		}
	}
	void Get_DeXuat_(wstring word_, Node Temp_)
	{
		Node Temp = Temp_;
		while (Temp != NULL && NumberOfDeXuat < 4)
		{
			if (Temp->Mean != NULL)
			{
				wstring Temp_word = word_;
				Temp_word.push_back(Temp->c);
				DeXuat[NumberOfDeXuat] = Temp_word;
				NumberOfDeXuat++;
			}
			wstring Temp_word = word_;
			Temp_word.push_back(Temp->c);

			Get_DeXuat_(Temp_word, Temp->Down);

			Temp = Temp->Next;
		}
	}
	void Get_DeXuat(wstring word, Node Temp)
	{
		NumberOfDeXuat = 0;
		Get_DeXuat_(word, Temp);
	}

public:
	wstring* Search(wstring word_)
	{
		Node Temp = Root;
		wstring word_DeXuat;
		int word_length = word_.length();
		wchar_t C_Seacrch;
		for (int i = 0; i < word_length; i++)
		{
			C_Seacrch = word_[i];
			while (Temp != NULL)
			{
				if (Temp->c == C_Seacrch)
				{
					if (i == (word_length - 1))
					{
						Get_DeXuat(word_DeXuat, Temp);
						return Temp->Mean;
					}
					if (Temp->Down == NULL)
					{
						Get_DeXuat(word_DeXuat, Temp);
						return NULL;
					}
					Temp = Temp->Down;
					break;
				}
				Temp = Temp->Next;
			}
			if (Temp == NULL)
			{
				Get_DeXuat(word_DeXuat, Temp);
				return NULL;
			}
			word_DeXuat.push_back(C_Seacrch);
		}
		Get_DeXuat(word_DeXuat, Temp);
		return NULL;
	}

	bool RemoveItem(wstring word_)
	{
		Node Temp = Root;
		int word_length = word_.length();
		wchar_t C_Seacrch;

		Node* TempList = new Node[word_length];
		for (int i = 0; i < word_length; i++)
		{
			C_Seacrch = word_[i];
			while (Temp != NULL)
			{
				if (Temp->c == C_Seacrch)
				{
					TempList[i] = Temp;
					if (i == (word_length - 1))
					{
						TempList[i] = Temp;
						delete Temp->Mean;
						Temp->Mean = NULL;
						return true;
					}
					if (Temp->Down == NULL)
					{
						return false;
					}
					Temp = Temp->Down;
					break;
				}
				Temp = Temp->Next;
			}
			if (Temp == NULL)
			{
				return false;
			}
		}
		return false;
	}

	void SaveDatabase()
	{
		system("cls");
		wcout << L"Đang xử lý dữ liệu ... ";
		GetValueRow(L"", Root);
		wcout << L"Đang lưu dữ liệu ... ";
		ListSave->SaveFile();
		ListSave->~List_WordMean();
	}
};
Database::Database()
{
	Load();
}
Database::~Database()
{

}
