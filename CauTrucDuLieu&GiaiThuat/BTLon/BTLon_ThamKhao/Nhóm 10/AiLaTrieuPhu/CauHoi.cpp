#include "stdafx.h"
#include "CauHoi.h"

Node::Node(CauHoi _data)
{
	data = _data;
	link = NULL;
}

ListCauHoi::ListCauHoi()
{
	first = last = NULL;
	count = 0;
}

void ListCauHoi::AddFirst(Node* new_ele)
{
	if (first == NULL) //danh sach rong
	{
		first = last = new_ele;
	}
	else
	{
		new_ele->link = first;
		first = new_ele;
	}
	count++;
}

void ListCauHoi::AddLast(Node* new_ele)
{
	if (first == NULL) //danh sach rong
	{
		first = last = new_ele;
	}
	else
	{
		last->link = new_ele;
		last = new_ele;
	}
	count++;
}

void ListCauHoi::InsertFirst(CauHoi x)
{
	Node* new_ele = new Node(x);
	AddFirst(new_ele);
}

void ListCauHoi::InsertLast(CauHoi x)
{
	Node* new_ele = new Node(x);
	AddLast(new_ele);
}

void ListCauHoi::RemoveFirst()
{
	if (first == NULL)
		return;

	Node* temp = first;
	first = first->link;
	delete temp;

	if (first == NULL)
		last = NULL;
	count--;
}

void ListCauHoi::RemoveAllFirst()
{
	while (first != NULL)
	{
		RemoveFirst();
	}
}

Node* ListCauHoi::SearchRandom(int thuTuCauHoi)
{
	int count = 0;
	Node** nodeSearch = new Node*[10000];

	Node* p = first;
	while (p != NULL)
	{
		if (p->data.thuTuCauHoi == thuTuCauHoi)
		{
			nodeSearch[count] = p;
			count++;
		}
		p = p->link;
	}

	if (count == 0)
	{
		delete[]nodeSearch;
		return NULL;
	}

	int r = rand() % 10000;
	Node* result = nodeSearch[r%count];
	delete[]nodeSearch;
	return result;
}

Node* ListCauHoi::Search(int thuTuCauHoi)
{
	Node* p = first;
	while (p != NULL)
	{
		if (p->data.thuTuCauHoi == thuTuCauHoi)
		{
			return p;
		}
		p = p->link;
	}
	return NULL;
}

void Node::XuatRaManHinh()
{
	cout << "Cau hoi so " << data.thuTuCauHoi + 1 << " nhu sau:\n";
	cout << data.noiDungCauHoi << endl;
	cout << "A. " << data.noiDungDapAn[A] << endl;
	cout << "B. " << data.noiDungDapAn[B] << endl;
	cout << "C. " << data.noiDungDapAn[C] << endl;
	cout << "D. " << data.noiDungDapAn[D] << endl;
}

void Node::XuatRa2DapAnDung()
{	
	cout << "Dap an con lai la:" << endl;
	int count = 0;
	int dapAnSai = 0;
	for (int i = 0; i < 4; i++)
	{
		int r = rand() % 3;
		if (data.dapAnDung != i)
		{		
			if (count == r)
			{
				dapAnSai = i;
				break;
			}
			count++;
		}
	}

	int daMin = dapAnSai > data.dapAnDung ? data.dapAnDung : dapAnSai;
	int daMax = dapAnSai < data.dapAnDung ? data.dapAnDung : dapAnSai;

	if (daMin == A)
		cout << "A. " << data.noiDungDapAn[daMin] << endl;
	else if (daMin == B)
		cout << "B. " << data.noiDungDapAn[daMin] << endl;
	else if (daMin == C)
		cout << "C. " << data.noiDungDapAn[daMin] << endl;
	else if (daMin == D)
		cout << "D. " << data.noiDungDapAn[daMin] << endl;
		
	if (daMax == A)
		cout << "A. " << data.noiDungDapAn[daMax] << endl;
	else if (daMax == B)
		cout << "B. " << data.noiDungDapAn[daMax] << endl;
	else if (daMax == C)
		cout << "C. " << data.noiDungDapAn[daMax] << endl;
	else if (daMax == D)
		cout << "D. " << data.noiDungDapAn[daMax] << endl;
}

void ListCauHoi::RemoveLast() {
	if (first == NULL)
	{
		return;
	}


	for (Node* k = first; k != NULL; k = k->link)
	{

		if (k->link == last)
		{
			delete last;
			k->link = NULL;
			last = k;
			return;
		}
	}
}

Node* ListCauHoi::RemoveNodeCoKhoaBatKy() {
	cout << "Ban muon xoa cau nao: ";
	int x = 0;
	//std::getline(std::cin, x);
	if (first == NULL)
	{
		return NULL;
	}

	if (first->data.thuTuCauHoi == x)
	{
		RemoveFirst();
		return first;
	}

	if (last->data.thuTuCauHoi == x)
	{
		RemoveLast();
		return last;
	}
	CauHoi a;
	Node* g = new Node(a);

	for (Node* k = first; k != NULL; k = k->link)
	{

		if (k->data.thuTuCauHoi == x)
		{
			g->link = k->link;
			delete k;
			return g;
		}
		g = k;
	}
	return NULL;

}

void ListCauHoi::XuatCauHoiBiXoa(CauHoi x)
{

	cout << "Cau hoi ma ban vua moi xoa xong:";
	cout << x.noiDungCauHoi;
	cout << "Dap an: " << x.noiDungDapAn << endl << endl;
}

void ListCauHoi::XuatCauHoiBiSua(CauHoi x)
{

	cout << "Cau hoi ban muon sua co thong tin nhu sau" << "\n";
	cout << "Noi Dung cua cau hoi: " << x.noiDungCauHoi << "\n";
	//cout << "Ma cua cau hoi " << x.maCauHoi << "\n";
	//cout << "Thu tu cua cua hoi " << x.thuTuCauHoi << "\n";
	cout << "Dap an A la: " << x.noiDungDapAn[A] << endl;
	cout << "Dap an B la: " << x.noiDungDapAn[B] << endl;
	cout << "Dap an C la: " << x.noiDungDapAn[C] << endl;
	cout << "Dap an D la: " << x.noiDungDapAn[D] << endl;
	cout << "Dap an chinh xac: " << x.dapAnDung << endl << endl;
	cout << "Ban chi duoc sua do kho cua cau hoi: " << endl;
}

void ListCauHoi::SuaCauHoi(CauHoi x, int s) {
	CauHoi ch;
	for (Node* k = first; k != NULL; k = k->link) {

		if (s == k->data.thuTuCauHoi) {
			XuatCauHoiBiSua(k->data);
			ch.thuTuCauHoi = s;

			cout << "Moi ban nhap Muc Do Kho cua Cau Hoi (tu 1 den 15)";
			cin >> ch.thuTuCauHoi;
			ch.thuTuCauHoi--;


		}

	}
}