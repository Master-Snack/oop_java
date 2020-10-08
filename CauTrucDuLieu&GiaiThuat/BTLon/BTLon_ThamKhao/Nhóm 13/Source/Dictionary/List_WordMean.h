#pragma once
#include "Header.h";
class List_WordMean
{
public:
	List_WordMean();
	~List_WordMean();
private:
	struct NODE
	{
		wstring* Word, * Mean;
		NODE* Next;
	}; typedef struct  NODE* Node;

public:
	Node FirstNode_, LastNode_, NodeNext;
	int Length;
private:

	Node MakeNode(wstring word, wstring mean)
	{
		wstring* Word, * Mean;

		Word = new wstring;
		*Word = word;

		Mean = new wstring;
		*Mean = mean;

		Node NewNode = new NODE;
		NewNode->Mean = Mean;
		NewNode->Word = Word;
		NewNode->Next = NULL;
		return NewNode;
	}
	Node MakeNode(wstring word, wstring mean, Node Next)
	{
		Node NewNode = MakeNode(word, mean);
		NewNode->Next = Next;
		return NewNode;
	}

	void Load()
	{
		FirstNode_ = NULL;
		LastNode_ = NULL;
		Length = 0;
	}

public:
	void ADD(wstring word, wstring mean)
	{
		Node NewNode = MakeNode(word, mean);
		if (FirstNode_ == NULL)
		{
			FirstNode_ = NewNode;
			LastNode_ = FirstNode_;
		}
		else
		{
			LastNode_->Next = NewNode;
			LastNode_ = NewNode;
		}
		Length++;
	}

	void RemoveFirst()
	{
		Node Temp = FirstNode_;
		FirstNode_ = FirstNode_->Next;
		delete Temp->Word;
		delete Temp->Mean;
		delete Temp;
		Length--;
	}

	void ShowAllItem()
	{
		Node TempNode = FirstNode_;
		int Dem = 0;
		while (TempNode != NULL)
		{
			wcout << L"\tItem: " << Dem << L"\n";
			wcout << L"\t\tWord: " << *(TempNode->Word) << L"\n";
			wcout << L"\t\tMean: " << *(TempNode->Mean) << L"\n\n";
			Dem++;
			TempNode = TempNode->Next;
		}
	}

	void SaveFile()
	{
		ofstream fo(paths.user_av, ios::binary);
		Node Temp = FirstNode_;
		//---------------------------------------------------------------------------
		wstring word;

		char write_c = 'a';

		ProgressBar PrB;
		PrB.ColorA = Color.Yellow;
		PrB.Location.Y = 5;
		PrB.Refresh();
		int MaxGiatri = Length / 100, giatri = 0;

		int streamSize = sizeof(write_c);

		// First file -----------------------------------------------------------------
		fo.write(&firstFile, streamSize);


		while (Temp != NULL)
		{
			//Save word ---------------------

			fo.write(&firstString, streamSize);

			word = *(Temp->Word);
			for (int i = 0; i < word.length(); i++)
			{
				write_c = Encode_value(word[i]);
				fo.write(&write_c, streamSize);
			}

			fo.write(&lastString, streamSize);
			// Save mean -----------------------

			fo.write(&firstString, streamSize);


			word = *(Temp->Mean);
			for (int i = 0; i < word.length(); i++)
			{
				write_c = Encode_value(word[i]);
				fo.write(&write_c, streamSize);
			}

			fo.write(&lastString, streamSize);
			//-----------------------------------
			fo.write(&newString, streamSize);

			giatri++;
			if (giatri >= MaxGiatri)
			{
				giatri = 0;
				PrB.value++;
				PrB.Refresh();
			}

			Temp = Temp->Next;
		}
		fo.write(&lastFile, streamSize);
		fo.close();
		// Last file -----------------------------------------------------------------
	}

};

List_WordMean::List_WordMean()
{
	Load();
}
List_WordMean::~List_WordMean()
{
	while (FirstNode_ != NULL)
	{
		RemoveFirst();
	}
}