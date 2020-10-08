#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include<windows.h>
#include<time.h>
#include<conio.h>
using namespace std;
struct CAUHOI
{
	
	string  stt, cauHoi, cauA, cauB, cauC, cauD, dapAn;
};

struct NODE
{
	CAUHOI data;
	NODE *link;
};

struct LIST
{
	NODE *first, *last;
	int soLuong;
};
struct RAND_NODE
{
	int a;
	RAND_NODE *link;
};
struct RAND_LIST
{
	RAND_NODE *first, *last;
};
struct DANGKY
{
	string tk;
	string mk;
	
};
struct NODE_DK 
{
	DANGKY data;
	NODE_DK *link;
};
struct LIST_DK
{
	NODE_DK *first,*last;
};
void Init(LIST &l);
NODE *getNode(CAUHOI x);
void addLastCauHoi(LIST &l, CAUHOI x);
void InitRand(RAND_LIST &l);
void capNhatCauHoi(LIST &l, int maCauHoi);//Cap nhat lai noi dung cau hoi, cau tra loi hoac dap an
RAND_NODE *getNodeRand(int a);
void addLastRand(RAND_LIST &l, int a);
void createSTT(RAND_LIST &l, LIST l1, int soLuong);
bool kiemTraTrung(RAND_LIST l, int so);
void themVaoList(LIST &l);//doc file them cau hoi vao list
void xuatCauHoi(LIST l,int &y);
void themCauHoi(LIST &l);
void playGame(LIST l, LIST &l1);
void xuatCauDung(LIST l1);
NODE* search(LIST l,int so);
void xoaDau(LIST &l);
void xoaCuoi(LIST &l);
void xoaCauHoi(LIST &l, int stt);
void capNhatFileCauHoi(LIST l);// cap nhat cau hoi sau khi ket thuc ct
void capNhatSTTSauXoa(LIST &l);//cap nhat stt sau khi xoa
void over();
void loading();
void gotoxy(int x,int y);
bool kiemTraTKAdmin(string tk, string mk);
void chucNangAdmin(LIST &l);
void endProgram();
void passSao(char s[]);//tao * khi nha password
void deleteNodeCauHoi(LIST &l);
void deleteNodeDK(LIST_DK &l);
void deleteNodeRand(RAND_LIST &l);
void menu();
void InitDK(LIST_DK &l);
NODE_DK *getNodeDK(DANGKY x);
void addLastDK(LIST_DK &l,DANGKY x);
void docFile(LIST_DK &l); //doc file them tai khoan vs mat khau vao list_dk
int tim(LIST_DK l, DANGKY x);
void dangKyTK(LIST_DK &l);
int dangNhap(LIST_DK l,string tk, string mk);
void chucNangThiSinh(LIST l);
void thisinh(LIST l);
void color(int x);
int main(int argc, char *argv[])
{
	LIST l;//Danh sach cau hoi
	Init(l);//Khoi tao danh sach cau hoi
	int y;
	char a;
	char MK[50];
	string tk,mk;
	themVaoList(l);//Lay du lieu cau hoi tu file
	do
	{
		system("cls");
		menu();
		color(14);
		gotoxy(45,12);
		cout<<"0. Thoat";
		gotoxy(45,14);
		cout<<"1. Thi sinh";
		gotoxy(45,16);
		cout<<"2. Quyen Admin";
		a=getch();
		switch(a)
		{
			case 48:
				capNhatFileCauHoi(l);//Ghi lai danh sach cau hoi vao file
				deleteNodeCauHoi(l);//Xoa l -> giai phong bo nho
				endProgram();//Man hinh ket thuc chuong trinh
				gotoxy(34,15);
				break;
			case 49:
				thisinh(l);//Chuc nang thi sinh
				break;
			case 50:
				system("cls");
				gotoxy(25,3);
				cout<<"Vui long dang nhap tai khoan admin de su dung";
				gotoxy(30,5);
				cout<<"Tai khoan: ";
				gotoxy(41,5);
				getline(cin,tk);
				gotoxy(30,7);
				fflush(stdin);
				cout<<"Mat khau: ";
				gotoxy(40,7);
				passSao(MK);//Hien dau * khi nhap mat khau
				mk=MK;
				if(kiemTraTKAdmin(tk,mk))//Neu tai khoan dung -> thuc hien chuc nang admin
					chucNangAdmin(l);
				else//Nguoc lai thong bao tai khoan chua dung
				{
					gotoxy(30,9);
					cout<<"Tai khoan chua dung!";
					Sleep(2000);
				}
				break;
			default:
				break;
		}
	}while(a!=48);
	return 0;
}

void Init(LIST &l)
{
	l.first=l.last=NULL;
	l.soLuong=0;
}

NODE *getNode(CAUHOI x)
{
	NODE *p=new NODE;
	if(p==NULL)
		return NULL;
	p->data=x;
	p->link=NULL;
	return p;
}
void addLastCauHoi(LIST &l, CAUHOI x)
{
	NODE *p=getNode(x);
	if(p==NULL)
		return;
	if(l.first==NULL){
		l.first=l.last=p;
		l.soLuong++;
	}	
	else
	{
		l.last->link=p;
		l.last=p;
		l.soLuong++;
	}
}
//Doc file luu vao list
void themVaoList(LIST &l)
{
	ifstream fp;
	fp.open("cauhoi.txt",ios_base::in);
	while(!fp.eof())
	{
		CAUHOI x;
		getline(fp,x.stt);
		getline(fp,x.cauHoi);
		getline(fp,x.cauA);
		getline(fp,x.cauB); 
		getline(fp,x.cauC);
		getline(fp,x.cauD);
		getline(fp,x.dapAn);
		addLastCauHoi(l,x);
	}
	fp.close();
}
//Xuat ra STT va noi dung cau hoi
void xuatCauHoi(LIST l, int &y)
{
	if(l.first==NULL)
		return;
	NODE *p=l.first;
	while(p!=NULL)
	{
		gotoxy(20,y);
		cout<<"Cau "<<p->data.stt<<": "<<p->data.cauHoi<<endl;
		y++;
		p=p->link;
	}
}
void playGame(LIST l, LIST &l1)
{
	NODE *q;
	RAND_LIST l2;
	InitRand(l2);
	int dung=0, STT=1;
	int soLuong;
	//nhap so luong cau hoi
	while(true)
	{
		system("cls");
		gotoxy(40,5);
		cout<<"Vui long chon moc cau hoi: 10 | 20 | 40 |";
		cin>>soLuong;
		if(soLuong==10 || soLuong==20|| soLuong==40)
			break;
	}
	loading();
	color(2);
	createSTT(l2,l,soLuong);//tao ngau nhien list stt
	RAND_NODE *p=l2.first;
	while(p!=NULL)
	{	
		q = search(l,p->a);//tim kiem dia chi cua stt tuong ung
		system("cls");
		//xuat cau hoi
		gotoxy(25,5);
		cout<<"Cau "<<STT<<" :"<<q->data.cauHoi<<endl;
		gotoxy(25,7);
		cout<<q->data.cauA<<endl;
		gotoxy(25,9);
		cout<<q->data.cauB<<endl;
		gotoxy(25,11);
		cout<<q->data.cauC<<endl;
		gotoxy(25,13);
		cout<<q->data.cauD<<endl;
		//kiem tra dap an
		string s;;//luu dap an nhap vao cua thi sinh
		int y=15;
		while(true)
		{
			//char dapAn;
			gotoxy(25,y);
			fflush(stdin);
			cout<<"Nhap dap an: ";
			getline(cin,s);
			if(stricmp(s.c_str(),"a")!=0 && stricmp(s.c_str(),"b")!=0 && stricmp(s.c_str(),"c")!=0 && stricmp(s.c_str(),"d")!=0)
			{
				y++;
				gotoxy(25,y);
				printf("Nhap lai\n");
				y++;
			}	
			else
				break;	
		}
		//so sanh voi dap an dung
		if(stricmp(s.c_str(),q->data.dapAn.c_str())==0)
			dung++;	
		//luu vao danh sach cau hoi va dap an dung
		CAUHOI x;
		char s4[10];
		sprintf(s4,"%d",STT);
		x.stt=s4;
		x.cauHoi=q->data.cauHoi;
		if(stricmp(q->data.dapAn.c_str(),"a")==0)
			x.dapAn=q->data.cauA;
		if(stricmp(q->data.dapAn.c_str(),"b")==0)
			x.dapAn=q->data.cauB;
		if(stricmp(q->data.dapAn.c_str(),"c")==0)
			x.dapAn=q->data.cauC;
		if(stricmp(q->data.dapAn.c_str(),"d")==0)
			x.dapAn=q->data.cauD;
		addLastCauHoi(l1,x);		
		STT++;
		p=p->link;
	}
	//thong bao ket qua, tinh diem
	system("cls");
	char s5[50];
	float diem=(10.0/soLuong)*dung;
	sprintf(s5,"Dap an dung: %d cau\nSo diem : %.2f diem",dung,diem);
	MessageBox(NULL,s5,"Dap an dung",MB_OK | MB_ICONINFORMATION);
	over();
	deleteNodeRand(l2);
	Sleep(1500);
}
//them 1 cau hoi vao cuoi file
void themCauHoi(LIST &l)
{
	system("cls");
	char check[5]="";
	CAUHOI x;
	char temp[20];
	char s[500];
	sprintf(temp,"%d",l.soLuong+1);//tao stt cho cau moi
	x.stt=temp;
	//nhap cau hoi
	gotoxy(10,4);
	cout<<"Nhap cau hoi: ";
	fflush(stdin);
	getline(cin,x.cauHoi);
	gotoxy(10,6);
	cout<<"Nhap dap an: ";
	fflush(stdin);
	gotoxy(10,7);
	cout<<"a. ";
	getline(cin,x.cauA);
	sprintf(s,"a. %s",x.cauA.c_str());
	x.cauA=s;
	fflush(stdin);
	gotoxy(10,9);
	cout<<"b. ";
	getline(cin,x.cauB);
	sprintf(s,"b. %s",x.cauB.c_str());
	x.cauB=s;
	fflush(stdin);
	gotoxy(10,11);
	cout<<"c. ";
	getline(cin,x.cauC);
	sprintf(s,"c. %s",x.cauC.c_str());
	x.cauC=s;
	fflush(stdin);
	gotoxy(10,13);
	cout<<"d. ";
	getline(cin,x.cauD);
	sprintf(s,"d. %s",x.cauD.c_str());
	x.cauD=s;	
	//kiem tra dap an
	char s1[5];
	int y=15;
	while(true)
	{
		gotoxy(10,y++);
		cout<<"Dap an dung: ";
		fflush(stdin);
		gets(s1);
		if(stricmp(s1,"a")!=0 && stricmp(s1,"b")!=0 && stricmp(s1,"c")!=0 && stricmp(s1,"d")!=0)
		{
			gotoxy(10,y++);
			cout<<"Nhap lai";
		}	
		else
			break;	
	}
	x.dapAn=s1;
	addLastCauHoi(l,x);
}
//Xuat ra cau hoi va dap an dung 
void xuatCauDung(LIST l1)
{
	NODE *p=l1.first;
	int y=5;
	if(l1.first==NULL)
	{
		MessageBox(NULL,"Ban chua lam bai","Thong bao",MB_OK|MB_ICONSTOP);
		return;
	}
	while(p!=NULL)
	{
		
		gotoxy(25,y);
		cout<<"Cau "<<p->data.stt<<": "<<p->data.cauHoi<<endl;
		y++;
		gotoxy(25,y);
		cout<<p->data.dapAn<<endl;//dap an khong con la a/b/c/d ma la noi dung dap an dung
		y++;
		p=p->link;			
	}
	gotoxy(25,y);
	system("pause");
}
void InitRand(RAND_LIST &l)
{
	l.first=l.last=NULL;
}
RAND_NODE *getNodeRand(int a)
{
	RAND_NODE *p=new RAND_NODE;
	if(p==NULL)
		return NULL;
	p->a=a;
	p->link=NULL;
	return p;
}
void addLastRand(RAND_LIST &l, int a)
{
	RAND_NODE *p=getNodeRand(a);
	if(p==NULL)
		return;
	if(l.first==NULL)
		l.first=l.last=p;
	else
	{
		l.last->link=p;
		l.last=p;
	}
}
bool kiemTraTrung(RAND_LIST l, int so)
{
	if(l.first==NULL)
		return true;
	else
	{
		RAND_NODE *p=l.first;
		while(p!=NULL)
		{
			if(p->a==so)
				return false;
			p=p->link;
		}		
	}
	return true;
}
void createSTT(RAND_LIST &l,LIST l1, int soLuong)
{
	srand(time(NULL));
	for(int i=0;i<soLuong;i++)
	{
		int x=1+ rand()%l1.soLuong;
		if(kiemTraTrung(l,x)==false)
			i--;
		else
			addLastRand(l,x);
	}
}
NODE *search(LIST l, int so)
{
	NODE *p=l.first;	
	while(p!=NULL)
	{
		int a=atof(p->data.stt.c_str());// chuyen stt(string) sang int 
		if(so==a){
			return p;
		}
		p=p->link;
	}
	return NULL;
}
void xoaDau(LIST &l)
{
	NODE *p=l.first;
	l.first=p->link;
	delete p;
}
void xoaCuoi(LIST &l)
{
	NODE *p=l.first;
	while(p!=NULL)
	{
		if(p->link==l.last)
		{
			p->link=NULL;
			delete l.last;
			l.last=p;
			break;			
		}
		p=p->link;
	}
}

void xoaCauHoi(LIST &l, int stt)
{
	NODE *p=l.first;
	NODE *q;
	if(stt==atof(l.first->data.stt.c_str()))
	{
		xoaDau(l);
		l.soLuong--;
		return;
	}
	if(stt==atof(l.last->data.stt.c_str()))
	{
		xoaCuoi(l);
		l.soLuong--;
		return;
	}
	while(p!=NULL)
	{
		q=p;
		p=p->link;
		if(stt==atof(p->data.stt.c_str()))
		{
			q->link=p->link;
			delete p;
			l.soLuong--;
			return;
		}
	}	
}
void capNhatFileCauHoi(LIST l)
{
	ofstream fp;
	fp.open("cauhoi.txt",ios_base::trunc);
	NODE *p=l.first;
	while(p!=NULL)
	{
		fp<<p->data.stt<<endl;
		fp<<p->data.cauHoi<<endl;
		fp<<p->data.cauA<<endl;
		fp<<p->data.cauB<<endl;
		fp<<p->data.cauC<<endl;
		fp<<p->data.cauD<<endl;
		if(p!=l.last)
			fp<<p->data.dapAn<<endl;
		else
			fp<<p->data.dapAn;
		p=p->link;
	}
	fp.close();
}
void capNhatSTTSauXoa(LIST &l)
{
	NODE *p=l.first;
	for(int i=1;i<=l.soLuong;i++)
	{
		char s[5];
		sprintf(s,"%d",i);
		p->data.stt=s;
		p=p->link;
	}
}
void over()
{
	ifstream fp;
	int x=30, y=10;
	fp.open("over.txt",ios_base::in);
	int i=10;
	while(!fp.eof())
	{
		string s;
		gotoxy(x,y);
		y++;
		getline(fp,s);
		color(i++);
		cout<<s<<endl;
	}
	fp.close();
	color(14);
}
void gotoxy(int x, int y)
{
  HANDLE h = NULL;  
  if(!h)
  	h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
}
void color(int x)
{
    HANDLE mau;
    mau = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(mau,x);
}
void loading()
{
	gotoxy(50,10);
	cout<<"Loading...."<<endl;
	int x1=45,y=12,j=4;
	for(int i=0;i<49;i++)
	{
		gotoxy(x1,y);
		cout<<"|";
		if(i%2==0)
			x1++;
		gotoxy(61,10);
		cout<<j<<"%";
		j+=2;
		Sleep(70);		
	}
}
bool kiemTraTKAdmin(string tk, string mk)
{
	if(tk.compare("admin123")==0&&mk.compare("123")==0)
		return true;
	return false;
}
void chucNangAdmin(LIST &l)
{
	int stt,y=3;
	char a='a';
	while(a!=48)
	{
		system("cls");
		menu();
		color(4);
		gotoxy(40,12);
		cout<<"0. Quay lai";
		gotoxy(40,14);
		cout<<"1. Xuat cau hoi";
		gotoxy(40,16);
		cout<<"2. Them cau hoi";
		gotoxy(40,18);
		cout<<"3. Xoa cau hoi";
		gotoxy(40,20);
		cout<<"4. Cap nhat cau hoi";
		a=getch();
		color(14);
		switch(a)
		{
			case 48:
				break;
			case 49:
				system("cls");
				y=5;
				xuatCauHoi(l,y);
				gotoxy(20,y);
				system("pause");
				break;
			case 50:
				themCauHoi(l);
				break;
			case 51:
				y=5;
				system("cls");	
				xuatCauHoi(l,y);
				gotoxy(20,y);
				cout<<"Nhap stt cau hoi can xoa: ";
				cin>>stt;
				if(stt<1 || stt > l.soLuong)
				{
					MessageBox(NULL,"Xoa khong thanh cong","Thong bao",MB_OK|MB_ICONINFORMATION);
				}	
				else
				{
					xoaCauHoi(l, stt);
					capNhatSTTSauXoa(l);
					MessageBox(NULL,"Xoa thanh cong","Thong bao",MB_OK|MB_ICONINFORMATION);					
				}
				break;
			case 52:
				int so;
				y=5;
				system("cls");	
				xuatCauHoi(l,y);
				gotoxy(20,y);
				cout<<"Nhap STT cau hoi can chinh sua:";
				cin>>so;
				capNhatCauHoi(l,so);
				break;
			default:
				break;
		}
	}
}
void endProgram()
{
	int x=0, y=10;
	while(true)
	{
		system("cls");
		gotoxy(x,y);
		cout<<"Program is coded by:";
		gotoxy(x,y+1);
		cout<<"Dang Van Nghiem";
		gotoxy(x,y+2);
		cout<<"To Van Hau";
		gotoxy(x,y+3);
		cout<<"Vo Quoc Khanh";
		gotoxy(x,y+4);
		cout<<"Truong Tuan Phuc";
		Sleep(10);
		x++;
		if(x==35)
			return;		
	}
}
void passSao(char s[])
{
	char c='a',pass[20];
	int i=0;
	fflush(stdin);
	while(c!=13)
	{
		if(kbhit())//true neu phim duoc nhan
		{	
			c=getch();
			if(c!=8&& c!= 13)
			{
				cout<<"*";
				pass[i]=c;
				i++;
			}
			else if(c==8 && i!=0)
			{
				cout<<"\b \b";
				i--;
			}
		}
	}
	strcpy(s,pass);
}
//Giai phong bo nho luu list cau hoi
void deleteNodeCauHoi(LIST &l)
{
	NODE *p;
	while(l.first!=NULL)
	{
		p=l.first;
		l.first=p->link;
		delete p;	
	}
	l.last=NULL;	
}
//Giai phong bo nho luu danh sach cau hoi random 
void deleteNodeRand(RAND_LIST &l)
{
	RAND_NODE *p;
	while(l.first!=NULL)
	{
		p=l.first;
		l.first=p->link;
		delete p;
	}
	l.last=NULL;
}
//Giai phong bo nho luu danh sach tai khoan 
void deleteNodeDK(LIST_DK &l)
{
	NODE_DK *p;
	while(l.first!=NULL)
	{
		p=l.first;
		l.first=p->link;
		delete p;
	}
	l.last=NULL;
}
void menu()
{
	ifstream fp;
	int i=2;
	fp.open("menu.txt",ios_base::in);
	string s;
	int y=2;
	while(!fp.eof())
	{
		getline(fp,s);
		gotoxy(25,y++);
		color(i);i++;
		cout<<s;
	}
	color(7);
}
void InitDK(LIST_DK &l)
{
	l.first=l.last=NULL;

}
NODE_DK *getNodeDK(DANGKY x)
{
	NODE_DK *p=new NODE_DK;
	if(p==NULL)
		return NULL;
	p->data=x;
	p->link=NULL;
	return p;	
}
void addLastDK(LIST_DK &l,DANGKY x)
{
	NODE_DK *p = getNodeDK(x);
	if(l.first == NULL)
	{
		l.first=l.last=p;
	
	}	
	else
	{
		l.last->link=p;
		l.last=p;
	}
}
void docFile(LIST_DK &l)
{
	DANGKY x;
	ifstream fp;
	fp.open("dangKi.txt",ios_base::in);
	while(!fp.eof())
	{
		getline(fp,x.tk);
		getline(fp,x.mk);
		addLastDK(l,x);	
	}
	fp.close();
}
int tim(LIST_DK l, DANGKY x) // tim tai khoan va mat khau trong list_dk
{
	NODE_DK *p=l.first;
	while(p!=NULL)
	{
		if(p->data.tk.compare(x.tk)==0 && p->data.mk.compare(x.mk)==0)
			return 1;
		else if(p->data.tk.compare(x.tk)==0)
			return -1;
		p=p->link;
	}
	return 0;	
}
void dangKyTK(LIST_DK &l)
{
	DANGKY x;
	string mk1;
	system("cls");	
	char MK[20],MK1[20];
	gotoxy(25,3);
	cout<<"Vui long dien thong tin";
	gotoxy(25,5);
	cout<<"Nhap ten TK :"; //nhap ten tai khoan
	fflush(stdin);
	getline(cin,x.tk);
	if(tim(l,x)==-1) // kiem tra tai khoan dang ki co trung khong
	{
		gotoxy(25,7);
		cout<<"Tai khoan da ton tai !!";
		Sleep(2000);
	}
	else 
	{
		gotoxy(25,7);
		cout<<"Nhap MK :"; // nhap mat khau
		passSao(MK);
		x.mk=MK;
		gotoxy(25,9);
		cout<<"Nhap lai MK :"; // nhap lai mat khau
		passSao(MK1);
		mk1=MK1;
		if(x.mk.compare(mk1)==0) // kiem tra nhap lai mat khau co dung khong
		{
			gotoxy(25,11);
			cout<<"Dang Ki Thanh Cong !!!"<<endl;
			Sleep(2000);
			addLastDK(l,x);
			ofstream fp;
			fp.open("dangKi.txt",ios_base::app);
			fp<<"\n";
			fp<<x.tk<<endl;
			fp<<x.mk;
			fp.close();
		}
		else
		{
			gotoxy(25,11);
			cout<<"Mat khau khong khop !!!";
			Sleep(2000);
		}	
	}	
}
int dangNhap(LIST_DK l,DANGKY x)
{
	if(tim(l,x)==1)
		return 1;
	return 0;
}
void chucNangThiSinh(LIST l)
{
	LIST l1;
	Init(l1);
	char luachon='a';
	while(luachon!=48)
	{
		system("cls");
		menu();
		color(14);
		gotoxy(45,12);
		cout<<"0. Quay lai";
		gotoxy(45,14);
		cout<<"1. Vao thi";
		gotoxy(45,16);
		cout<<"2. Xem dap an";
		gotoxy(45,18);
		fflush(stdin);
		luachon=getch();
		system("cls");
		switch(luachon)
		{
			case 48:
		 		break;
			case 49:
				Init(l1);
				playGame(l,l1);
				break;
			case 50:
				xuatCauDung(l1);
				break;
			default:
				break;				
		}
	}
}
void thisinh(LIST l)
{
	LIST_DK l1;
	InitDK(l1);
	docFile(l1);
	char luachon='a';
	DANGKY x;
	char MK[20];
	while(luachon!=48)
	{
		system("cls");
		menu();
		color(14);
		gotoxy(45,12);
		cout<<"0. Quay lai";
		gotoxy(45,14);
		cout<<"1. Dang ki";
		gotoxy(45,16);
		cout<<"2. Dang nhap";
		gotoxy(45,18);
		luachon=getch();
		switch(luachon)
		{
			case 48:
				deleteNodeDK(l1);
				break;
			case 49:
				dangKyTK(l1);
				break;
			case 50:
				system("cls");	
				gotoxy(25,7);
				cout<<"Moi ban dang nhap tai khoan"; // nhap tai khoan
				gotoxy(25,9);
				cout<<"Nhap TK: ";
				fflush(stdin);
				cin>>x.tk;
				gotoxy(25,11);
				cout<<"Nhap MK: "; // nhap mat khau
				passSao(MK);
				x.mk=MK;
				if(dangNhap(l1,x)==0) // kiem tra tai khoan vs mat khau co trong listdk chua
				{
					gotoxy(25,13);
					printf("Dang nhap khong thanh cong");
					Sleep(1500);
				}
				else
				{
					gotoxy(25,13);
					cout<<"Dang nhap thanh cong !!!";
					Sleep(1500);
					chucNangThiSinh(l);
				}
				break;
			default:
				break;
		}
	}
}
//Cap nhat lai noi dung cau hoi, cau tra loi hoac dap an
void capNhatCauHoi(LIST	&l,int maCauHoi)
{
	NODE *p=search(l,maCauHoi);
	system("cls");
	if(p==NULL){
		gotoxy(35,5);
		cout<<"Khong tim thay cau hoi can cap nhat!";
		gotoxy(35,6);
		system("pause");
		return;
	}	
	int y=5;//su dung khi nhap dap an dung
	char c;//Bat su kien ban phim
	string s;//Luu noi dung cau hoi/dap an dung
	char s1[200];//Noi cau hoi voi thu tu cau hoi
	do
	{
		system("cls");
		gotoxy(25,4);
		cout <<"Cap nhat cau hoi:";
		gotoxy(25,5);
		cout <<"0. Quay lai";
		gotoxy(25,6);
		cout <<"1. Cap nhat noi dung cau hoi";
		gotoxy(25,7);
		cout <<"2. Cap nhat dap an A";
		gotoxy(25,8);
		cout <<"3. Cap nhat dap an B";
		gotoxy(25,9);
	 	cout <<"4. Cap nhat dap an C";
	 	gotoxy(25,10);
	 	cout <<"5. Cap nhat dap an D";
	 	gotoxy(25,11);
	 	cout <<"6. Cap nhat dap an dung";
	 	c=getch();
	 	system("cls");
	 	switch(c)
	 	{
	 		case 49:		
	 			fflush(stdin);
	 			gotoxy(25,5);
	 			cout <<"Vui long nhap lai noi dung cau hoi:";	
	 			getline(cin,p->data.cauHoi);
	 			break;
	 		case 50:
	 			fflush(stdin);
	 			gotoxy(25,5);
	 			cout <<"Vui long nhap lai dap an A:";
	 			getline(cin,s);	
	 			sprintf(s1,"a. %s",s.c_str());
	 			p->data.cauA=s1;
	 			break;
	 		case 51:			
	 			fflush(stdin);
	 			gotoxy(25,5);
 				cout <<"Vui long nhap lai dap an B:";
	 			getline(cin,s);
	 			sprintf(s1,"b. %s",s.c_str());
	 			p->data.cauB=s1;
	 			break;
	 		case 52:	
	 			fflush(stdin);
	 			gotoxy(25,5);
				cout <<"Vui long nhap lai dap an C:";
	 			getline(cin,s);
	 			sprintf(s1,"c. %s",s.c_str());
	 			p->data.cauC=s1;
	 			break;
	 		case 53:
	 			fflush(stdin);
	 			gotoxy(25,5);
				cout <<"Vui long nhap lai dap an D:";
	 			getline(cin,s);
				sprintf(s1,"d. %s",s.c_str());
	 			p->data.cauD=s1;
	 			break;
	 		case 54:
	 			fflush(stdin);
	 			gotoxy(25,y++);
				cout <<"Vui long nhap lai dap an dung:";
	 			while(true)
			 	{
	 				getline(cin,s);
	 				if(stricmp(s.c_str(),"a")!=0&&stricmp(s.c_str(),"b")!=0&&stricmp(s.c_str(),"c")!=0&&stricmp(s.c_str(),"d")!=0)
 					{
				 		gotoxy(25,y++);
				 		cout<<"Nhap lai: ";
				 	}
				 	else{
				 		p->data.dapAn=s;
	 					break;	
	 				}
		 				
				}
		 		break;	
			default:
				break;	
 		}		
	}while(c!=48);	
}