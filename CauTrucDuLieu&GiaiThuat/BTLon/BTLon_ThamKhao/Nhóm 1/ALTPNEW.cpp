#include <stdio.h>
#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//Su dung ham trong windows.h
#define _WIN32_WINNT 0x0500
#include <windows.h>
LPSTR className = TEXT("Ai la trieu phu");

const int RED = 140;
const int WHITE = 15;
const int BLUE = 57;
const int WIDTH = 700;
const int HEIGHT = 500;
const int WRONG = 12;
const int WRIGHT = 10;
const int YELLOW = 14;

int SoCauDatDuoc = 0;

const wchar_t FileName[] = L"D:\\AiLaTrieuPhu.txt";

void TextColor(int x)
{
	HANDLE mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}

void ResizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void ToaDo(int x,int y)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD toado = {x,y};
	SetConsoleCursorPosition(mau,toado);
}

void DrawLine()
{
	
	for(int i=0;i<80;i++)
	{
		ToaDo(i,4);
		wprintf(L"-");
	}
	for(int i=10;i<20;i++)
	{
		ToaDo(40,i);
		wprintf(L"|");
	}
}

int isCall5050Help = 0;

void XuatMenu()
{
	if(isCall5050Help==0)
	{
		ToaDo(0,0);
		wprintf(L"1.50:50");
	}
}
void TaoGiaoDien()
{
	SetConsoleTitle(className);
	
	ResizeConsole(WIDTH,HEIGHT);
	
}

typedef struct 
{
	wchar_t cauHoi[255];
	wchar_t A[255];
	wchar_t B[255];
	wchar_t C[255];
	wchar_t D[255];
	wchar_t dapAn;
}Question;

typedef struct Node
{
	Question data;
	Node *link;
}Node;

typedef struct
{
	Node *first;
	Node *last;
}List;

void Initialize(List &list)
{
	list.first = list.last = NULL;
}

Node *GetNode(Question x)
{
	Node *p;
	p = new Node;
	if(p == NULL)
		return NULL;
	p->data = x;
	p->link = NULL;
	return p;
}

void AddFirst(List &list, Node* node)
{
	
	if (list.first == NULL)  //Danh sách r?ng
	{
		list.first = node;
		list.last  = list.first;
	}
	else {	
		node->link = list.first;  
		list.first = node; 	
	}
}

void InsertFirst(List &list, Question x)
{	
	Node* node = GetNode(x);
	if (node == NULL)
		return;
	AddFirst(list, node);
}
void DocFile(List &list)
{
	FILE *f = _wfopen(L"D:\\AiLaTrieuPhu.txt",L"r, ccs=UTF-8");
	if(f==NULL)
	{
		wprintf(L"Loi file\n");
		exit(0);
	}
	Question x;
	wchar_t temp[255];
	while(!feof(f))
	{
		fgetws(x.cauHoi,255,f);
		fgetws(x.A,255,f);
		fgetws(x.B,255,f);
		fgetws(x.C,255,f);
		fgetws(x.D,255,f);
		x.dapAn = fgetwc(f);
		fgetwc(f);
		fgetwc(f);
		InsertFirst(list,x);
	}
	fclose(f);
}


void XuatA(wchar_t s[])
{
	//A
	ToaDo(0,10);
	wprintf(L"%ls", s);
}

void XuatB(wchar_t s[])
{
	//B
	ToaDo(42,10);
	wprintf(L"%ls", s);
}

void XuatC(wchar_t s[])
{
	//A
	ToaDo(0,15);
	wprintf(L"%ls", s);
}

void XuatD(wchar_t s[])
{
	//A
	ToaDo(42,15);
	wprintf(L"%ls", s);
}

void XuatCauHoi(Question x)
{
	ToaDo(0,6);
	wprintf(L"%ls", x.cauHoi);
	
	XuatA(x.A);
	XuatB(x.B);
	XuatC(x.C);
	XuatD(x.D);
}

void Xuat1Question(Question x)
{
	wprintf(L"%ls",x.cauHoi);
	wprintf(L"%ls",x.A);
	wprintf(L"%ls",x.B);
	wprintf(L"%ls",x.C);
	wprintf(L"%ls",x.D);
	wprintf(L"%c\n",x.dapAn);
}

void XuatDanhSach(List list)
{
	Node *p = list.first;
	while(p != NULL)
	{
		Xuat1Question(p->data);
		p = p->link;
	}
}

void NhapCauTraLoi(wchar_t &tl)
{
	ToaDo(0,25);
	wprintf(L"Answer:\t");
	fflush(stdin);
	wscanf(L"%c",&tl);
}

void DoiMauKetQua(Question qs,int mau, wchar_t tl)
{
	TextColor(mau);
	if(tl == 'A' || tl == 'a')
	{
		XuatA(qs.A);
	}
	else if(tl == 'B' || tl == 'b')
	{
		XuatB(qs.B);
	}
	else if(tl == 'C' || tl == 'c')
	{
		XuatC(qs.C);
	}
	else if(tl == 'D' || tl == 'd')
	{
		XuatD(qs.D);
	}
}

int KiemTraDungSai(Question qs, wchar_t tl)
{
	if(tl >= 'a')
		tl = tl - 32;
	if(qs.dapAn == tl)
	{
		//Right
		DoiMauKetQua(qs,WRIGHT,tl);
		return 1;
	}
	else
	{
		//Wrong
		//Doi mau cau dung
		DoiMauKetQua(qs,WRIGHT,qs.dapAn);
		//Doi mau cau sai
		DoiMauKetQua(qs,WRONG,tl);
		return 0;
	}
	TextColor(WHITE);
}

void InSoTienDatDuoc(int m)
{
	ToaDo(70,0);
	TextColor(YELLOW);
	wprintf(L"%d VND",m);
	TextColor(WHITE);
}

void EndGame()
{
	system("cls");
	ToaDo(37,13);
	wprintf(L"END GAME!!");
	Sleep(1000);
	ToaDo(35,16);
	
	if(SoCauDatDuoc < 5)
		wprintf(L"Ban nhan duoc: 0\n");
	else if(SoCauDatDuoc >= 5 && SoCauDatDuoc <10)
		wprintf(L"Ban nhan duoc: %ld\n", (long)pow(2,5) * 100000);
	else if(SoCauDatDuoc <15)
		wprintf(L"Ban nhan duoc: %ld\n", (long)pow(2,10) * 100000);
	else if(SoCauDatDuoc == 15)
		wprintf(L"Ban nhan duoc: %.0lf\n", pow(2,15) * 100000);
	
	
	getwchar();
}

void Help_50_50(Question q)
{
	int kq;
	if(q.dapAn == 'A' || q.dapAn == 'a')
		kq = 1;
	if(q.dapAn == 'B' || q.dapAn == 'b')
		kq = 2;
	if(q.dapAn == 'C' || q.dapAn == 'c')
		kq = 3;
	if(q.dapAn == 'D' || q.dapAn == 'd')
		kq = 4;
		
	srand(time(NULL));

	int d_1 = rand()%4 + 1;
	while(d_1 == kq) d_1 = rand()%4 +1;
	int d_2 = rand()%4 + 1;
	while(d_2 == kq || d_2 == d_1) d_2 = rand()%4 +1;
	if(d_1 == 1 || d_2 == 1)
		XuatA(L"                   ");
	if(d_1 == 2 || d_2 == 2)
		XuatB(L"                   ");
	if(d_1 == 3 || d_2 == 3)
		XuatC(L"                   ");
	if(d_1 == 4 || d_2 == 4)
		XuatD(L"                   ");
}

void XoaTaiToaDo(int x,int y)
{
	ToaDo(x,y);
	for(int i=0;i<80;i++)
		wprintf(L" ");
	
}

void QuyenTroGiup(Question q)
{
	XoaTaiToaDo(0,25);
	XoaTaiToaDo(0,24);
	ToaDo(0,23);
	wprintf(L"Chon Quyen Tro Giup? Nhap !1 De Bo Qua\n ");
	int chon;
	wscanf(L"%d",&chon);
	switch(chon)
	{
		case 1: 
		{
			if(isCall5050Help==0)
			{
				Help_50_50(q);
				isCall5050Help = 1;
			}
			else
			{
				return;
			}
		 	break;
		}
		default: break;
	}
}

void DungCuocChoi(long m)
{
	system("cls");
	ToaDo(37,13);
	wprintf(L"END GAME!!");
	Sleep(1000);
	ToaDo(35,16);
	
	wprintf(L"Ban Nhan Duoc: %ld\n",m);
	getwchar();
}

int MuonDung()
{
	system("cls");
	wprintf(L"Ban Co Muon Dung Cuoc Choi? 0 De Tiep Tuc 1 De Dung Lai\n");
	int c;
	wscanf(L"%d",&c);
	return c;
}

void GameManager(List list)
{
	Node *node = list.first;
	wchar_t luaChon;
	long diem = 0;
	do
	{
		system("cls");
		ToaDo(0,25);
		XuatMenu();
		InSoTienDatDuoc(diem);
		XuatCauHoi(node->data);
		fflush(stdin);
		QuyenTroGiup(node->data);
		NhapCauTraLoi(luaChon);
		while((luaChon < 'a' || luaChon > 'd') && (luaChon < 'A' || luaChon > 'D'))
		{
			//Xoa dong nhap cau tra loi
			ToaDo(0,25);
			wprintf(L"                  ");
			NhapCauTraLoi(luaChon);
		}
		if(KiemTraDungSai(node->data,luaChon))
		{
			if(diem == 0)
				diem = 100000;
			diem *= 2;
		}
		else
		{
			Sleep(2000);
			EndGame();
			break;
		}
		
		Sleep(3000);
		TextColor(WHITE);
		node = node->link;
		
		SoCauDatDuoc++;
		if(SoCauDatDuoc == 15)
		{
			EndGame();
			ToaDo(37,10);
			wprintf(L"CHIEN THANG!!");
			
			break;
		}
		if(MuonDung())
		{
			DungCuocChoi(diem);
			break;
		}
		
	}while(node != NULL);
}

void CapNhatFile(Question q)
{
	FILE *f = _wfopen(FileName,L"a, ccs=UTF-8");
	if(f==NULL)
	{
		wprintf(L"Loi file\n");
		exit(0);
	}
	Xuat1Question(q);
	fputws(q.cauHoi,f);
	fputws(q.A,f);
	fputws(q.B,f);
	fputws(q.C,f);
	fputws(q.D,f);
	fwprintf(f,L"%c",q.dapAn);
	fputws(L"\n\n",f);
	
	fclose(f);
}

void ThemCauHoi(List ds)
{
	Question newQ;
	wprintf(L"Nhap Cau Hoi: ");
	fflush(stdin);
	_getws(newQ.cauHoi);
	wcscat(newQ.cauHoi,L"\n");
	
	wprintf(L"Nhap cau tra loi A: ");
	fflush(stdin);
	_getws(newQ.A);
	wcscat(newQ.A,L"\n");
	
	wprintf(L"Nhap tra loi B: ");
	fflush(stdin);
	_getws(newQ.B);
	wcscat(newQ.B,L"\n");
	
	wprintf(L"Nhap tra loi C: ");
	fflush(stdin);
	_getws(newQ.C);
	wcscat(newQ.C,L"\n");
	
	wprintf(L"Nhap tra loi D: ");
	fflush(stdin);
	_getws(newQ.D);
	wcscat(newQ.D,L"\n");
	
	wprintf(L"Nhap dap an: ");
	wscanf(L"%c",&newQ.dapAn);
	
	Node* q = GetNode(newQ);
	AddFirst(ds,q);
	CapNhatFile(newQ);
}

void QuanTriVien(List ds)
{
	wprintf(L"---Vui Long Chon---\n");
	wprintf(L"\t1.Them.\n");
	wprintf(L"\t2.Xem Toan Bo Danh Sach\n");
	
	int chon;
	wscanf(L"%d",&chon);
	switch(chon)
	{
		case 1: ThemCauHoi(ds); break;
		case 2: XuatDanhSach(ds); break;
	}
}

void LuaChonCheDo(List ds)
{
	int chon;
	ToaDo(25,13);
	wprintf(L"Lua Chon:\n");
	ToaDo(25,14);
	wprintf(L"1.Admin");
	ToaDo(25,16);
	wprintf(L"2.Gaming");
	ToaDo(25,18);
	wprintf(L"Answer: ");
	wscanf(L"%d",&chon);
	
	switch(chon)
	{
		case 1: 
		{
			system("cls"); 
			QuanTriVien(ds);
			break;
			
		}
		case 2: GameManager(ds);
	}
}

int main()
{
	//Su dung UTF-16, doc file Tieng Viet
    _setmode(_fileno(stdout), 0x00020000);
	
	//GiaoDien();
	List list;
	Initialize(list);
	
	DocFile(list);
	TaoGiaoDien();
	LuaChonCheDo(list);
	
	getchar();
	return 0;
}