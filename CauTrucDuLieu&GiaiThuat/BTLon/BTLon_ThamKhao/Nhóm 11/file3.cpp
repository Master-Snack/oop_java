#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "ThuVienDoHoa.h"

using namespace std;
 struct TL
 {
 	string a;
 	string b;
 	string c;
 	string d;
 };
 
 struct TracNghiem
 {
 	string stt;
 	string cauhoi;
 	TL traLoi;
 	string dapan;
 };
 
 struct Node
 {
 	TracNghiem data;
 	Node *link;
 };
 struct List
 {
 	Node *first;
 	Node *last;
 };
 void Init(List &l)
{
	l.first=l.last=NULL;
}
 Node *GetNode(TracNghiem x)
{
	Node *p;
	p=new Node;
	if(p== NULL)
	{
		return NULL;
	}
	p->data = x;
	p->link = NULL;
	return p;
}
void AddLast(List &l,Node *p)
{
	if(l.first==NULL)
	{
		l.first = l.last = p;
	}
	else
	{
		l.last->link = p;
		 l.last = p;
	}
	
}
void InsertLast(List &l,TracNghiem x)
{
	Node *p;
	p = GetNode(x);
	if(p==NULL)
		return;
	AddLast(l,p);	
}
void XoaDau(List &l)
{
	
	if (l.first == NULL)
	{
		return;
	}
	Node *p = l.first;
	l.first = l.first->link;
	delete p;
}
void XoaCuoi(List &l)
{


	if (l.first == NULL)
	{
		return;
	}
	
	if (l.first->link == NULL)
	{
		XoaDau(l);
		return;
	}
	
	for (Node *k = l.first; k != NULL; k = k->link)
	{
	
		if (k->link == l.last)
		{
			delete l.last; 
			k->link = NULL; 
			l.last = k; 
			return;
		}
	}
}

void DocFile(List &l,int &dem)
{
	
	ifstream f;
	TracNghiem x;
	f.open("tienganh.txt",ios::in);
	while(!f.eof())
	{
		
		getline(f,x.stt);
		getline(f,x.cauhoi);
		getline(f,x.traLoi.a);
		getline(f,x.traLoi.b);
		getline(f,x.traLoi.c);
		getline(f,x.traLoi.d);
		getline(f,x.dapan);
		InsertLast(l,x);
		dem++;
	}
	f.close();
}

void GhiFile(List l)
{
	ofstream f;
	Node *p = l.first;
	f.open("tienganh.txt",ios::out);
	int a = 1;
	while(p!=NULL)
	{
		f<<a++<<endl;
		f<<p->data.cauhoi<<endl;
		f<<p->data.traLoi.a<<endl;
		f<<p->data.traLoi.b<<endl;
		f<<p->data.traLoi.c<<endl;
		f<<p->data.traLoi.d<<endl;
		f<<p->data.dapan;
		if(p!=l.last)
			f<<endl;
		p = p->link;
	}
	f.close();
	
}
void khung2()
{
	gotoxy(1,7);
	cout<<"________________________________________________________________________________________________________________________";
	gotoxy(1,20);
	cout<<"________________________________________________________________________________________________________________________";
		
}
Node *search(List l,string a)
{
	Node *p = l.first;
	while(p!=NULL)
	{
		if(p->data.stt == a)
			return p;
		p = p->link;	
	}
	return NULL;
}

void Output(List l,int socau)
{
	
	int b = 1;
	int c = 0;
	Node *p = l.first;
	Node *q;
	string x;
	textcolor(2);
	while(b<=socau)
	{
		system("cls");
		khung2();
		gotoxy(15,9);
		cout<<"cau "<<p->data.stt<<": ";
		gotoxy(22,9);
		cout<<p->data.cauhoi<<endl;
		gotoxy(17,12);
		cout<<p->data.traLoi.a<<endl;
		gotoxy(17,14);
		cout<<p->data.traLoi.b<<endl;
		gotoxy(17,16);
		cout<<p->data.traLoi.c<<endl;
		gotoxy(17,18);
		cout<<p->data.traLoi.d<<endl;
		gotoxy(50,21);
		cout<<"nhap lua chon: ";
	 	x =_getch();
		cout<<x;
		
		if(x == p->data.dapan)
		{
			c++;
		}
		p = p->link;
	 	b++;
	}
	system("cls");
	khung2();
	gotoxy(50,9);
	cout<<"so cau dung cua ban la:"<<c<<"/"<<socau;
	gotoxy(1,30);
	system("pause");
}
void ThemCauHoi(List &l)
{
	
	TracNghiem Them;
	do{
		system("cls");
		gotoxy(1,5);
		cout << "Nhap cau hoi ke tiep" << endl;
		khung2();
		gotoxy(15,9);
		cout<<"nhap cau hoi:";
		getline(cin,Them.cauhoi);
		gotoxy(17,11);
		cout<<"nhap cau a:";
		getline(cin,Them.traLoi.a);
		gotoxy(17,13);
		cout<<"nhap cau b:";
		getline(cin,Them.traLoi.b);
		gotoxy(17,15);
		cout<<"nhap cau c:";
		getline(cin,Them.traLoi.c);
		gotoxy(17,17);
		cout<<"nhap cau d:";
		getline(cin,Them.traLoi.d);
		gotoxy(17,19);
		cout<<"nhap dap an dung:";
		getline(cin,Them.dapan);

		if (Them.stt == ""|| Them.cauhoi == "" || Them.traLoi.a == "" || Them.traLoi.b == "" || Them.traLoi.c == "" || Them.traLoi.a == "" || Them.dapan == "")
		{ 
			gotoxy(50,21);
			cout << "Khong de trong yeu cau nhap lai!" << endl;
			Sleep(800);
		}
		else InsertLast(l,Them);
	}while(Them.stt == ""|| Them.cauhoi == "" || Them.traLoi.a == "" || Them.traLoi.b == "" || Them.traLoi.c == "" || Them.traLoi.a == "" || Them.dapan == "");
}

void xoacauhoi(List &l)
{
	string a;
	Node *p= NULL;
	do{
		system("cls");
		khung2();
		gotoxy(1,5);
		cout<<"nhap cau hoi muon xoa:";
		cin>>a;
		p = search(l,a);
		if(p != NULL)
		{
			gotoxy(15,9);
			cout<<"cau "<<p->data.stt<<": ";
			gotoxy(21,9);
			cout<<p->data.cauhoi;
			gotoxy(15,11);
			cout<<p->data.traLoi.a;
			gotoxy(15,13);
			cout<<p->data.traLoi.b;
			gotoxy(15,15);
			cout<<p->data.traLoi.c;
			gotoxy(15,17);
			cout<<p->data.traLoi.d;
			
			if(p == l.first)
			{
				XoaDau(l);
				gotoxy(50,21);
				cout<<"da xoa thanh cong"<<endl;
				gotoxy(1,30);
				system("pause");
				return;
			}
			if(p == l.last)
			{
				XoaCuoi(l);
				gotoxy(50,21);
				cout<<"da xoa thanh cong"<<endl;
				gotoxy(1,30);
				system("pause");
				return;
			}
			for( Node *q = l.first;q!= NULL;q = q->link)
			{
				if(q->link == p)
				{
					q->link = p->link;
					delete(p);
					gotoxy(50,21);
					cout<<"da xoa thanh cong"<<endl;
					gotoxy(1,30);
					system("pause");
					return;
				}
			}
		
		}
		else
		{
			gotoxy(15,9);
			cout<<"khong tim thay cau hoi";
			gotoxy(15,11);
			cout<<"1.thu lai";
			gotoxy(15,13);
			cout<<"2.thoat";
			gotoxy(55,21);
			cout<<"nhap lua chon";
			cin>>a;
		}
	}while(p==NULL && a == "1");
}
void suacauhoi(List &l)
{
	string a;
	Node *p =NULL;
	do{
		system("cls");
		khung2();
		gotoxy(1,5);
		cout<<"nhap STT cau hoi muon sua: ";
		getline(cin,a);
		p = search(l,a);
		if(p != NULL)
		{
			do{
			gotoxy(15,9);
			cout<<"nhap cau hoi: ";
			getline(cin,p->data.cauhoi);
			gotoxy(15,11);
			cout<<"nhap cau a: ";
			getline(cin,p->data.traLoi.a);
			gotoxy(15,13);
			cout<<"nhap cau b: ";
			getline(cin,p->data.traLoi.b);
			gotoxy(15,15);
			cout<<"nhap cau c: ";
			getline(cin,p->data.traLoi.c);
			gotoxy(15,17);
			cout<<"nhap cau d: ";
			getline(cin,p->data.traLoi.d);
			gotoxy(15,19);
			cout<<"nhap dap an dung: ";
			getline(cin,p->data.dapan);
			if(p->data.cauhoi==""||p->data.traLoi.a==""||p->data.traLoi.b==""||p->data.traLoi.c==""||p->data.traLoi.d==""||p->data.dapan=="")
			{
				gotoxy(50,21);
				cout << "Khong de trong yeu cau nhap lai!" << endl;
				Sleep(800);
			}
			else
			{
				GhiFile(l);
				gotoxy(50,21);
				cout<<"sua thanh cong";
			}
			}while(p->data.cauhoi==""||p->data.traLoi.a==""||p->data.traLoi.b==""||p->data.traLoi.c==""||p->data.traLoi.d==""||p->data.dapan=="");
			
		}
		else
		{
			gotoxy(15,9);
			cout<<"khong tim thay cau hoi";
			gotoxy(15,11);
			cout<<"1.thu lai";
			gotoxy(15,13);
			cout<<"2.thoat";
			gotoxy(55,21);
			cout<<"nhap lua chon";
			cin>>a;
		}
	}while(p==NULL && a == "1");
}
void khung()
{
	gotoxy(25,8);
	cout<<"+------------------------------------------------------+";
	gotoxy(25,9);
	cout<<"+                                                      +";
	gotoxy(25,10);
	cout<<"+                                                      +";
	gotoxy(25,11);           
	cout<<"+                                                      +";
	gotoxy(25,12);
	cout<<"+                                                      +";
	gotoxy(25,13);
	cout<<"+------------------------------------------------------+";
}
void SignUp()
{
	string a,b;
	
	system("cls");
	khung();
	gotoxy(27,10);
	cout<<"nhap ho ten: ";
	gotoxy(27,11);
	cout<<"nhap MSSV: ";
	gotoxy(40,10);
	getline(cin,a);
	gotoxy(40,11);
	getline(cin,b);
	
	
}
int ChonSoCau(int dem)
{
	int x = 10;
	system("cls");
	gotoxy(27,10);
	do{
		if(x!= 10&&x!=20&&x!=30)
		{
			gotoxy(45,15);
			cout<<"khong hop le!"<<endl;
			Sleep(1000);
		}
		system("cls");
		khung();
		gotoxy(27,10);
		cout<<"chon moc cau hoi(10 ,20 ,30): ";
		cin>>x;
	}while(x!= 10&&x!=20&&x!=30);
	return x;
}
void ChuongTrinh(List &l)
{
	
	char b;
	int dem = 0;
	int socau;
	bool t;
	
	do{
		xuatGiaoDienChinh();
		b = _getch();
		cout<<b<<endl;
		switch(b)
		{
		case 49:
		{
			Init(l);
			DocFile(l,dem);
			socau = ChonSoCau(dem);
			Output(l,socau);
		
			break;
		}
		case 50:
		{
			Init(l);
			DocFile(l,dem);
			ThemCauHoi(l);
			GhiFile(l);
			break;
		}
		case 51:
		{
			Init(l);
			DocFile(l,dem);
			xoacauhoi(l);
			GhiFile(l);
			break;
		}
		case 52:
		{
			Init(l);
			DocFile(l,dem);
			suacauhoi(l);
			
			break;
		}
		case 27:
		{
			system("cls");
			khung2();
			gotoxy(55,14);
			cout<<"thank you!";
			gotoxy(1,30);
			break;
		}	
		default:
			break;
		}
	}while(b!=27);	
}
int main()
{
	List l;
	Init(l);
	manHinhLoading();
	ChuongTrinh(l);	
}
