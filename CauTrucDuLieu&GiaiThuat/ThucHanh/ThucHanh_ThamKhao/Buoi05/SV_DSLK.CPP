#include <bits/stdc++.h>
using namespace std;

struct Ngay
{
    int ngay, thang, nam;
};
struct sinhvien
{
    char mssv[10],hoten[40],  diachi[100], lop[12], khoa[7];
    int gioitinh;
    Ngay ngaysinh;

};

struct Node
{
    sinhvien data;
    Node *link;
};
struct List
{
    Node *first, *last;
};

Node *GetNode(int x);
void Init(List &l);
void AddLast(List &l, Node *new_ele);
void InsertLast(List &l, sinhvien x);
int NhapSV(sinhvien &x);
void NhapDSSV(List &l);
void xuatSV(sinhvien s);
void xuatDSSV(List l);
Node* Search(List l,  char x[]);
void InsertLast_KhongTrung(List &l, sinhvien x);
void Delete_Head(List &l);
void Delete_Tail(List &l);
void XoaSauNode_q(List &l, Node *q);
void Delete_Node(List &l, char d[]);
int main()
{
    char d[10];
    List l;
    Init(l);
    NhapDSSV(l);
    xuatDSSV(l);
    do{
        printf("Nhap ma so sinh vien cua sinh vien ban muon xoa: ");
        fflush(stdin);
        gets(d);
        Delete_Node(l, d);
    }while (strcmp(d, "0")!=0);

    xuatDSSV(l);
    return 0;
}
void Init(List &l)
{
    l.first = l.last = NULL;
}
Node *GetNode(sinhvien x)
{
    Node *p;
    p= new Node;
    if (p == NULL)
        return NULL;
    p->data = x;
    p->link = NULL;
    return p;
}
void AddLast(List &l, Node *new_ele)
{
    if (l.first == NULL)
    {
        l.last = new_ele;
        l.first = l.last;
    }
    else
    {
        l.last -> link = new_ele;
        l.last  = new_ele;
    }
}
void InsertLast(List &l, sinhvien x)
{
    Node* new_ele = GetNode(x);
    if (new_ele == NULL)
        return;
    AddLast(l, new_ele);
}
void InsertLast_KhongTrung(List &l, sinhvien x)
{
    if (Search(l, x.mssv)==NULL)
        InsertLast(l, x);
}
int NhapSV(sinhvien &x)
{
    printf("Ma so sinh vien: ");
    fflush(stdin);
    gets(x.mssv);
    if (strcmp(x.mssv,"0")==0)
        return 0;
    fflush(stdin);
    printf("Ho va ten sinh vien: ");
    fflush(stdin);
    gets(x.hoten);
    cout<<"Gioi tinh: ";
    fflush(stdin);
    cin>>x.gioitinh;
    printf("Ngay thang nam sinh: ");
    fflush(stdin);
    cin>>x.ngaysinh.ngay>>x.ngaysinh.thang>>x.ngaysinh.nam;
    printf("Dia chi: ");
    fflush(stdin);
    gets(x.diachi);
    printf("Lop: ");
    fflush(stdin);
    gets(x.lop);
    printf("Khoa: ");
    fflush(stdin);
    gets(x.khoa);
    return 1;
}
void NhapDSSV(List &l)
{
    cout<<"\Bat dau nhap DSSV. Nhap mssv=0 de dung\n";
    sinhvien x;
    int flag=NhapSV(x);
    while (flag)
    {
        InsertLast_KhongTrung(l,x);
        flag=NhapSV(x);
    }
    cout<<"\n Ket thuc nhap DSSV.\n";

}
void xuatSV(sinhvien s)
{
    char gt[4];
    if (s.gioitinh==0)
        strcpy(gt, "Nam");
    else
        strcpy(gt, "Nu");
    cout<<left<<setw(10)<<s.mssv<<setw(25)<<s.hoten<<setw(2)<< s.ngaysinh.ngay<<"/"<<setw(2)<<s.ngaysinh.thang<<"/"<<setw(8)<<s.ngaysinh.nam
    <<setw(8)<<gt<<setw(10)<<s.diachi<<setw(8)<<s.khoa<<setw(8)<<s.lop<<endl;

}
void xuatDSSV(List l)
{
    Node* p=l.first;
    cout<<"============================================================================================\n";
    //cout<<setw(-8)<<"MSSV"<<setw(-20)<<"HO TEN"<<setw(10)<<"NGAY SINH"<<setw(10)<<"GIOI TINH"<<setw(10)<<"DIA CHI"<<setw(8)<<"KHOA"<<setw(8)<<"LOP\n";

    while (p)
    {
        xuatSV(p->data);
        p=p->link;
    }
}

Node* Search(List l, char x[])
{
    Node *p;
    p=l.first;
    while (p!= NULL)
    {
        if (strcmp(p->data.mssv,x)==0)
            return p;
        p= p->link;
    }
    return NULL;
}
void Delete_Head(List &l)
{
	if (l.first == NULL)
	{
		return;
	}
	Node *p = l.first;
	l.first = l.first->link;
	delete p;
}
void Delete_Tail(List &l)
{
	if (l.first == NULL)
	{
		return;
	}
	if (l.first->link == NULL)
	{
		Delete_Head(l);
		return;
	}
	for (Node *k = l.first; k != NULL; k = k->link)
	{
		if (k->link == l.last)
		{
			delete l.first;
			k->link = NULL;
			l.last = k;
			return;
		}
	}
}
void XoaSauNode_q(List &l, Node *q)
{
	for (Node *k = l.first; k != NULL; k = k->link)
	{
		if (strcmp(k->data.mssv,q->data.mssv)==0)
		{
			Node *g = k->link;
			k->link = g->link;
			delete g;
		}
	}
}

void Delete_Node(List &l, char d[])
{

	if (l.first == NULL)
	{
		return;
	}
	if (strcmp(l.first->data.mssv,d)==0)
	{
		Delete_Head(l);
		return;
	}
	if (strcmp(l.last->data.mssv,d)==0)
	{
		Delete_Tail(l);
		return;
	}

	Node *g = new Node;
	for (Node *k = l.first; k != NULL; k = k->link)
	{
		if (strcmp(k->data.mssv,d)==0)
		{
			g->link = k->link;
			delete k;
			return;
		}
		g = k;
	}

}








