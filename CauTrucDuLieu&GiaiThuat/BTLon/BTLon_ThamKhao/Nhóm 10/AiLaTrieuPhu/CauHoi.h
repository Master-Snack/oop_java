#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <iomanip>
using namespace std;

enum DapAn
{
	A = 0,
	B,
	C,
	D
};

struct CauHoi{
	char maCauHoi[64];
	char noiDungCauHoi[5000];
	char noiDungDapAn[4][500];
	int dapAnDung;
	int thuTuCauHoi; //Gia tri tu 0 den 14
};

struct Node
{
	CauHoi	data;		//du lieu
	Node* link;			//con trỏ chỉ đến cấu trúc Node
	Node(CauHoi _data);
	void XuatRaManHinh();
	void XuatRa2DapAnDung();
};

struct ListCauHoi 	// kiểu danh sách liên kết
{
	Node* first;
	Node* last;
	int count;

	ListCauHoi();
	void AddFirst(Node* new_ele);
	void AddLast(Node* new_ele);
	void InsertFirst(CauHoi x);
	void InsertLast(CauHoi x);
	void RemoveFirst();
	void RemoveAllFirst();
	void SuaCauHoi(CauHoi x, int s);
	void XuatCauHoiBiSua(CauHoi x);
	void XuatCauHoiBiXoa(CauHoi x);
	void RemoveLast();
	Node* RemoveNodeCoKhoaBatKy();	
	Node* Search(int thuTuCauHoi);
	Node* SearchRandom(int thuTuCauHoi);	
};