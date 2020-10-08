#include<iostream>
using namespace std;
#include <fstream>
#include <string>
#include <Windows.h>
#define boxx 12 //Vi tri x bat dau cua box
#define boxy 6 //Vi tri y bat dau cua box
#define boxs 54 //Box size
#define boxw 10 //So tu hien thi trong khung ket qua tim kiem
struct word{
	string tu;
	string tuloai;
	string nghia[3];
	string dongnghia;
	string vidu[3];
};
struct node{
	word data;
	node *l;
	node *r;
};
typedef node *Tree;
node* TaoNode(word X) 
{ 
    node* p = new node; 
    if (p == NULL) 
        return NULL; 
    p->l = NULL; 
    p->r = NULL; 
    p->data=X; 
    return p;   
} 
void ThemNodeVaoCay(node* p, Tree &c) 
{ 
    if (c == NULL)
        c = p; 
    else 
    { 
        if (p->data.tu.compare(c->data.tu)<0) 
             ThemNodeVaoCay(p,c->l); 
        else if (p->data.tu.compare(c->data.tu)>0) 
             ThemNodeVaoCay(p,c->r); 
        else 
            return ; 
    } 
} 
void Nhap(Tree &c) 
{ 
    int chon = 0; 
    do 
    { 
    	int a;
        word x; 
        cout<<"\nNhap  tu: "; 
        fflush(stdin);
        cin>> x.tu;
        cout<<"\nNhap tu loai: ";
        fflush(stdin);
       	cin>> x.tuloai;
       	do
       	{
       	cout<<"nhap vao so nghia";
       	cin>>a;	
	}while(a<0||a>3);
	for(int j=1;j<=a;j++){
		cout<<"Nghia thu  :"<<j;
		cin>>x.nghia[j];
		}
			do
       	{
       	cout<<"nhap vao vi du";
       	cin>>a;	
	}while(a<0||a>3);
	for(int j=1;j<=a;j++){
		cout<<"vi du thu :"<<j;
		fflush(stdin);
		cin>>x.vidu[j];
		}
        node* p = TaoNode(x); 
        ThemNodeVaoCay(p,c); 
        printf("Muon nhap thong tin tiep ko? 1: co, 0: ko ~~>"); 
        scanf("%d",&chon); 
    }while(chon); 
} 
void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}
void setcolor(int x) { //Ham thay doi textcolor va backgroundcolor
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, x);
}
// Hàm d?ch chuy?n con tr? d?n t?a d? x, y.
void gotoxy(int x,int y)
{    
	HANDLE hConsoleOutput;    
	COORD Cursor_an_Pos = {x-1,y-1};   
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);    
	SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}
void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
void ToMau(int x, int y, string a, int color)
{
	gotoxy(x, y);
	textcolor(color);
	cout<<a;
	textcolor(7);
}
void tachchuoi(string line, word &xxx) { //Ham tach chuoi ra thanh va gan vao nhung vi tri phu hop
	int d = 0, i = 0;
	string tach = "";
	while(line[i] != '@') {
		tach += line[i];
		i++;
	}
	i++;
	xxx.tu = tach;
	tach = "";
	while(line[i] != '@') {
		tach += line[i];
		i++;
	}
	i++;
	xxx.tuloai = tach;
	tach = "";
	while(line[i] != '@') {
		tach += line[i];
		i++;
	}
	i++;
	xxx.nghia[0] = tach;
	tach = "";

	while(line[i] != '@') {
		tach += line[i];
		i++;
	}
	i++;
	xxx.nghia[1] = tach;
	tach = "";
	while(line[i] != '@') {
		tach += line[i];
		i++;
	}
	i++;
	xxx.nghia[2] = tach;
	tach = "";
	while(line[i] != '@') {
		tach += line[i];
		i++;
	}
	i++;
	xxx.vidu[0] = tach;
	tach = "";
	while(line[i] != '@') {
		tach += line[i];
		i++;
	}
	i++;
	xxx.vidu[1] = tach;
	tach = "";
	while(line[i] != '@') {
		tach += line[i];
		i++;
	}
	i++;
	xxx.vidu[2] = tach;
}
void Doc_file_tu(ifstream &filein ,node *&T )
{
	string aaaa;
	word newword ;
	getline(filein,aaaa);
	tachchuoi(aaaa,newword);
	T->data=newword;
	T->l=NULL;
	T->r=NULL;
}

int taptudien(string tu) { 
	if(tu != "") {
		char x = tu[0];
		if((x < 123) && (x > 96)) {
			return x - 97;
		}
	}
	return -1;
}
void Doc_file(Tree a[])
{

	ifstream filein("D:\\hien.txt");
		while(filein.eof()==false)
		{
			node *p=new node;
			if(p==NULL)
				cout<<"khong du bo nho";
				
			Doc_file_tu(filein,p);
			ThemNodeVaoCay(p,a[taptudien(p->data.tu)]);
		}	
	filein.close();  
}
void xuat1node(node *c)
{
			textcolor(117);
			gotoxy(45,7);
			cout<<"tu vung:"<<c->data.tu<<endl; 
			gotoxy(45,8);
			cout<<"tu loai:"<<c->data.tuloai<<endl;
			for(int i=0;i<3;i++)
			{
				gotoxy(45,9+i);
				cout<<"nghia:"<<c->data.nghia[i]<<endl;
			}	
			for(int i=0;i<3;i++)
			{
				gotoxy(45,12+i);
				cout<<"vi du:"<<c->data.vidu[i]<<endl;
			}	
}   
	
void Xuat(Tree c) 
{ 
    if (c!=NULL) 
    { 
        if (c->l != NULL) 
        	Xuat(c->l);
        {
        	
        	textcolor(117);
			cout<<"tu vung:"<<c->data.tu<<endl; 
			cout<<"tu loai:"<<c->data.tuloai<<endl;
			for(int i=0;i<3;i++)
			{
				
				cout<<"nghia:"<<c->data.nghia[i]<<endl;
				
			}	
			for(int i=0;i<3;i++)
			{
				
				cout<<"vi du:"<<c->data.vidu[i]<<endl;
				
			}
		}     
        
        if (c->r != NULL) 
    
            Xuat(c->r); 
    } 
} 
int SuaTu(Tree &root,string tuCanTim){		
	
	if(root==NULL)
	return 0;
	else if(root->data.tu.compare(tuCanTim)>0)
		return SuaTu(root->l,tuCanTim);
	else if(root->data.tu.compare(tuCanTim)<0)
		return SuaTu(root->r,tuCanTim);
	else 
		{
			int choice;
			
			do{
			system("color 70");
			ToMau(50,3,"Tu Dien Anh-Viet",112);
			textcolor(113);
			gotoxy(45,7);
			cout<<"1.them Nghia ";
			gotoxy(45,8);
			cout<<"2.Sua Tu Loai";
			gotoxy(45,9);
			cout<<"3.them vi du";
			gotoxy(45,10);
			cout<<"0.dung viec sua tu";
			gotoxy(45,11);
			cout<<"nhap lua chon:";
			cin>>choice;
			system("cls");
			switch(choice){		
			case 1:
				{
					ToMau(50,3,"Tu Dien Anh-Viet",112);	
					gotoxy(45,12);
					textcolor(113);
					cout<<"Nghia goc moi muon them:";
					string nghiamoi;
					fflush(stdin);
					getline(cin,nghiamoi);
					for(int i=0;i<3;i++)
						{
						if(root->data.nghia[i]=="")
						root->data.nghia[i]=nghiamoi;					
						}
					gotoxy(45,13);
					textcolor(116);
					cout<<"da sua tu thanh cong";
					textcolor(119);
					gotoxy(45,14);
					system("pause");
					system("cls");	
					return 1;	
				}	
			
			break;					
			case 2:	
			{
				ToMau(50,3,"Tu Dien Anh-Viet",112);
				gotoxy(45,12);
			textcolor(113);
				cout<<"Tu loai moi muon thay the:";
				string tuloaimoi;
				fflush(stdin);
				getline(cin,tuloaimoi);
					root->data.tuloai=tuloaimoi;
					gotoxy(45,13);
					textcolor(116);
				cout<<"da sua tu thanh cong";
				textcolor(119);
				gotoxy(45,14);
				system("pause");
				system("cls");	
				return 1;	
			}
			
			break;
			case 3:
				{
					ToMau(50,3,"Tu Dien Anh-Viet",112);
					string vi;
					gotoxy(45,12);
					textcolor(113);
					cout<<" vi du muon them:";
					fflush(stdin);
					getline(cin,vi);
					for(int i=0;i<3;i++)
						{
					if(root->data.vidu[i]=="")
						{
							root->data.vidu[i]=vi;
						}
						textcolor(116);
					gotoxy(45,13);	
					cout<<"da sua tu thanh cong";
					textcolor(119);
					gotoxy(45,14);	
							
				}	
				system("pause");
				return 1;	
				}
		
			break;
			}
			}while(choice!=0);
		}	
	return 1;
}
node *TimKiem(Tree &root,string tuCanTim){		
	
	if(root==NULL)
	return NULL;
	else if(root->data.tu.compare(tuCanTim)>0)
		return	TimKiem(root->l,tuCanTim);
	else if(root->data.tu.compare(tuCanTim)<0)
		return	TimKiem(root->r,tuCanTim);
	else 
	return root;
}
void DiTimNodeTheMang(Tree &X, Tree &Y) 
{
	if (Y->l != NULL)
	{
		DiTimNodeTheMang(X, Y->l);
	}
	else 
	{
		X->data = Y->data; 
		X = Y;
		Y = Y->r; 	
	}
}	
void XoaNode(Tree &t, string data) 
{
	
	if (t == NULL)
	{
		return; 
	}
	else
	{
		
		if (data.compare(t->data.tu) < 0)
		{
			XoaNode(t->l, data);  
		}
		else if (data.compare(t->data.tu) > 0)
		{
			XoaNode(t->r, data); 
		}
		else 
		{
			node *X = t; 
			if (t->l == NULL)
			{
				t = t->r; 
			}
			else if (t->r == NULL)
			{
				t = t->l;
			}
			else 
			{
				DiTimNodeTheMang(X, t->r);
			}
			delete X; 
		}
	}
}
void themTu(Tree a[])
{
	int b,c;
        word x; 
        cout<<"\nNhap  tu: "; 
        fflush(stdin);
        cin>> x.tu;
        cout<<"\nNhap tu loai: ";
        fflush(stdin);
       	cin>> x.tuloai;
       	do
       	{
       	cout<<"nhap vao so nghia";
       	cin>>b;	
		}while(b<0||b>3);
		for(int j=1;j<=b;j++){
		cout<<"Nghia thu  :"<<j;
		cin>>x.nghia[j];
		}
			do
       	{
       	cout<<"nhap vao vi du";
       	cin>>c;	
		}while(c<0||c>3);
		for(int j=1;j<=c;j++){
		cout<<"vi du thu :"<<j;
		fflush(stdin);
		cin>>x.vidu[j];
		}
        node* p = TaoNode(x); 
        ThemNodeVaoCay(p,a[taptudien(p->data.tu)]); 
}
 void	 luachon(Tree t[]){
    	int lc;
		
		do{	
		ToMau(50,3,"Tu Dien Anh-Viet",112);
		gotoxy(45,6);
		setcolor(113);
		cout<<"1. them tu moi vao tu dien\n";
		gotoxy(45,7);
		cout<<"2. xuat ra tap tu dien muon xuat\n";
		gotoxy(45,8);
		cout<<"3. tim kiem tu vung\n";
		gotoxy(45,9);
		cout<<"4. xoa 1 tu bat ky trong cay\n";
		gotoxy(45,10);
		cout<<"5. sua tu vung trong tu dien\n";
		gotoxy(45,11);
		cout<<"nhap lua chon cua ban :";
		cin>>lc;	
		system("cls");
		textcolor(153);
		switch(lc){
		case 1:
			{
				ToMau(50,3,"Tu Dien Anh-Viet",112);
			int n,m;
      		word x; 
      		gotoxy(45,6);
      		textcolor(113);
      		cout<<"Nhap  tu: "; 
       		fflush(stdin);
       		getline(cin,x.tu);
       		node *g=TimKiem(t[taptudien(x.tu)],x.tu);
				if(g!=NULL)
					{
						ToMau(50,3,"Tu Dien Anh-Viet",112);
					gotoxy(45,7);
					textcolor(116);
					cout<<"tu nay da co trong tu dien\n";	
					textcolor(119);
					system("pause");
					break;
					}	
				else
				{	
				ToMau(50,3,"Tu Dien Anh-Viet",112);
					gotoxy(45,7);
					textcolor(113);
					cout<<"Nhap tu loai: ";
       				fflush(stdin);
      	 			getline(cin,x.tuloai);
     	  			do
      	 			{
      	 				gotoxy(45,8);
      	 			cout<<"nhap vao so nghia:";
     	 		 	cin>>n;	
					}while(n<0||n>3);
					for(int i=1;i<=n;i++){
						gotoxy(45,8+i);
					cout<<"Nghia thu "<<i<<":";
					fflush(stdin);
					getline(cin,x.nghia[i]);
					}
					do
      				{
      					gotoxy(45,12);
      	 			cout<<"nhap vao so vi du:";
     	  			cin>>m;	
					}while(m<0||m>3);
					for(int j=1;j<=m;j++){
						gotoxy(45,12+j);
					cout<<"vi du thu "<<j<<":";
					fflush(stdin);
					getline(cin,x.vidu[j]);
					}
        			node* p = TaoNode(x); 
        			ThemNodeVaoCay(p,t[taptudien(x.tu)]);
				}
				textcolor(124);
				gotoxy(45,16);
				cout<<"nhap thanh cong\n";
				textcolor(119);
				system("pause");
			}	
			system("cls");		
		break;	
		case 2:	
		{
			ToMau(50,3,"Tu Dien Anh-Viet",112);
			gotoxy(45,6);
			textcolor(113);
			char l;
			cout<<"nhap vao bo tu dien can hien ra:";
			cin>>l;
			Xuat(t[l-97]);
			textcolor(119);
			system("pause");
		}
		system("cls");
		break;
		case 3:
			{
				ToMau(50,3,"Tu Dien Anh-Viet",112);
				gotoxy(45,6);
				string k;
				textcolor(113);
				cout<<"nhap vao tu can tim: ";
				fflush(stdin);
				getline(cin,k);
				node *o=TimKiem(t[taptudien(k)],k);
				if(o==NULL)
				{
					gotoxy(45,7);
					textcolor(116);
					cout<<"khong tim thay tu nay";
					textcolor(119);
					system("pause");
				}	
					
				else
				{
					ToMau(50,3,"Tu Dien Anh-Viet",112);
					xuat1node(o);
					gotoxy(45,16);
					textcolor(113);
					cout<<"1.xoa tu nay";
					gotoxy(45,17);
					cout<<"2.sua tu nay";
					gotoxy(45,18);
					cout<<"0.tro ve cua so chinh";
					gotoxy(45,19);
					cout<<"lua chon cua ban la :";
					int ss;
					cin>>ss;
					switch(ss){
						case 1:
						{
						system("cls");
						system("color 70");	
						ToMau(50,3,"Tu Dien Anh-Viet",112);
						textcolor(116);
						gotoxy(45,7);
						cout<<"da xoa thanh cong\n";
						gotoxy(45,8);
						XoaNode(t[taptudien(k)],k);
						textcolor(119);
						system("pause");
						system("cls");	
						
						}
						break;
						case 2:
							{
								system("cls");
								system("color 70");
								ToMau(50,3,"Tu Dien Anh-Viet",112);
								int ee=SuaTu(t[taptudien(k)],k);
							}
							break;	
					}
				}
			system("cls");		
			}
			break;
			
		case 4:
			{
				ToMau(50,3,"Tu Dien Anh-Viet",112);
				gotoxy(45,6);
				string h;
				textcolor(113);
				cout<<"nhap tu can xoa: ";
				fflush(stdin);
				getline(cin,h);
				node *s=TimKiem(t[taptudien(h)],h);
				if(s==NULL)
				{
					textcolor(116);
					gotoxy(45,7);
					cout<<"khong co tu nay trong tu dien\n";
					gotoxy(45,8);
					textcolor(119);
					
				}
				else
				{
					ToMau(50,3,"Tu Dien Anh-Viet",112);
					textcolor(116);
					gotoxy(45,7);
					cout<<"da xoa thanh cong\n";
					gotoxy(45,8);
					XoaNode(t[taptudien(h)],h);
					textcolor(119);
				}				
			}
			system("pause");
			system("cls");
			break;	
		case 5:
			{
				ToMau(50,3,"Tu Dien Anh-Viet",112);
				gotoxy(45,6);
				string u;
				textcolor(113);
				cout<<"nhap tu can sua:";
				fflush(stdin);
				getline(cin,u);
				node *y=TimKiem(t[taptudien(u)],u);
				if(y!=NULL)
				{
				int a=SuaTu(t[taptudien(u)],u);
				}
				else
				{
					ToMau(50,3,"Tu Dien Anh-Viet",112);
				gotoxy(45,7);
				textcolor(116);
				cout<<"khong tim thay tu nay";
				textcolor(119);	
				system("pause");
				}
			}
			system("cls");
			break;		
		}
	}while(lc!=0);
	cout<<"ket thuc chuong trinh";
}
int main()
{
	system("color 70");
	Tree a[26];
	for (int i=0;i<26;i++)
	{
		a[i]=NULL;	
	}	
	Doc_file(a);
	luachon(a);
}

