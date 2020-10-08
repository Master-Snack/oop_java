#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include<windows.h>
#include<time.h>
#include <conio.h>
using namespace std;
struct CAUHOI
{
	string  stt;
	string cauHoi;
	string  cauA;
	string cauB;
	string cauC;
	string cauD;
	string dapAn;
};

struct NODE
{
	CAUHOI data;
	NODE *link;
};

struct LIST
{
	NODE *first; 
	NODE *last;
	int soLuong;
};
struct BAITHI // khai bao bai thi co cau hoi ngau nhien
{
	int a;//stt ngau nhien
	BAITHI *link;
};
struct LISTBAITHI
{
	BAITHI *first;
	BAITHI *last;
};
void Init(LIST &l);
NODE *getNode(CAUHOI x);
void addLastCauHoi(LIST &l, CAUHOI x);
void InitBAITHI(LISTBAITHI &l);
BAITHI *getNodeBAITHI(int a);
void addLastBAITHI(LISTBAITHI &l, int a);
void STTrandom(LISTBAITHI &l, LIST l1, int soLuong);
bool KTTrungSTT(LISTBAITHI l, int so);
void themVaoList(LIST &l);
void themCauHoiVaoFile(LIST &l);
void thitracnghiem(LIST l);
int StringToInt(string s);
NODE* timkiem(LIST l,int so);
void deletefirst(LIST &l);
void deletelast(LIST &l);
void xoa(LIST &l, int stt);
void capNhatFile(LIST l);
void capNhatSTT(LIST &l);
void taidulieu();
void xacdinhvitri(int x,int y);
void textcolor(int x);
void thanhvien();
void xoadulieu_thoat(LIST &l);
void DanhSachCauHoi(LIST l);
void nhapcauhoisua(CAUHOI &ch);
void Suacauhoi(LIST &l, string s);
void xuatcauhoibisua(CAUHOI dulieu);
int main(int argc, char *argv[])
{
	LIST l;
	Init(l);
	char a='a';
	themVaoList(l);
	while(a!=27)
	{
		system("cls"); 
		printf("              0      0       0   000000   0        0  	    000000    000000    0         0   000000    \n");
		printf("               0    0 0     0    00       0        0       0         0      0   0 0     0 0   00        \n");
		printf("                0   0  0   0     00000    0        0       0         0      0   0  0   0  0   000000    \n");
		printf("                 0 0    0 0      00       0        0       0         0      0   0   0 0   0   00        \n");
		printf("                  0      0       000000   000000   000000   000000    000000    0    0    0   000000    \n");
		textcolor(11);
		xacdinhvitri(40,8);
		printf("CHU DE : Tieng Anh");
		xacdinhvitri(40,10);
		printf("+======================+");
		textcolor(11);
		xacdinhvitri(40,11);
		printf("|     ESC. THOAT       |");
		xacdinhvitri(40,12);
		printf("|======================|");
		textcolor(11);
		xacdinhvitri(40,13);
		printf("|     F1. VAO THI      |" );
		xacdinhvitri(40,14);
		printf("|======================|");
		xacdinhvitri(40,15);
		printf("|     F2. THEM CAU HOI |");
        xacdinhvitri(40,16);
		printf("|======================|");	
		textcolor(11);	
		xacdinhvitri(40,17);
		printf("|     F3. XOA CAU HOI  |");
		xacdinhvitri(40,18);
		printf("|======================|");
		textcolor(11);
		xacdinhvitri(40,19);
		printf("|     F4. SUA CAU HOI  |");
		xacdinhvitri(40,20);
		printf("|======================|");
		textcolor(11);
		xacdinhvitri(40,21);
		printf("|F5. DANH SACH CAU HOI |");
		xacdinhvitri(40,22);
		printf("+======================+");
		xacdinhvitri(40,23);
		a=getch();	
		switch(a)
		{
			
			case 27://thoat
				thanhvien();
				xoadulieu_thoat(l);
				break;
				
			case 59://thi
			{
				LIST l;
				Init(l);
				themVaoList(l);
				system("cls");
				thitracnghiem(l);
				xoadulieu_thoat(l);
				break;
			}
			
			case 60://them
				themCauHoiVaoFile(l);
				break;
				
			case 61://xoa
			system("cls");
				xacdinhvitri(15,5);
				int stt1;
			printf("Nhap vi tri cua cau hoi can xoa: ");
				scanf("%d",&stt1);
				if(stt1>l.soLuong || stt1 <1)
				printf("Xoa khong thanh cong");	
				else
				{
					xoa(l,stt1);
					capNhatSTT(l);
					capNhatFile(l);
					printf("Xoa thanh cong");
					
				}
				break;
				
				case 62://sua
			        {
					system("cls");
					xacdinhvitri(35,5);
					printf( "Nhap cau hoi muon sua: ");
					string s;
					getline(std::cin,s);
					Suacauhoi(l,s);
					system("pause");
					system("cls");
					break;	
					}
				case 63://xuat danh sach
				system("cls");
				
				DanhSachCauHoi(l);
				system("pause");
				break;	
				   
		}
	
	}
	return 0;
}
 // Ham khoi tao gia tri cho phan tu dau va cuoi cua danh sach
void Init(LIST &l)
{
	l.first=l.last=NULL;
	l.soLuong=0;
}
//khoi tao 1 node trong dslk
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
	fp.open("cauhoi.txt",ios_base::in);   //mo file de doc
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
void thitracnghiem(LIST l)
{
	NODE *q;
	LIST l1;
	LISTBAITHI l2;
	InitBAITHI(l2);
	Init(l1);
	int a=0, STT=1;
	int soLuong;
	clock_t t1,t2;
	while(true)
	{   system("cls");
        xacdinhvitri(40,4);
        printf("+------------------------------ +");
		xacdinhvitri(40,5);
		printf("|ban chon goi cau hoi 10 hay 20 |");
		xacdinhvitri(40,6);
        printf("+------------------------------ +\n");
       	xacdinhvitri(49,7);
                    printf("+========+");
        xacdinhvitri(53,8);
	            	scanf("%d",&soLuong);
       	xacdinhvitri(49,9);
                    printf("+========+");
		if(soLuong!=10&&soLuong!=20){
			printf("Nhap sai,moi chon lai goi cau hoi");
		}		
		else break;
	}
	taidulieu();
	STTrandom(l2,l,soLuong);//tao list cau hoi ngau nhien theo stt
	BAITHI *p=l2.first;
	t1=clock();//bat dau dem thoi gian
	while(p!=NULL)
	{
		q = timkiem(l,p->a);
		   //tim kiem dia chi cua stt tuong ung
		system("cls");
        xacdinhvitri(25,1);
		printf("|---------------------------------------|");
		xacdinhvitri(25,2);
		printf("| Nhap  a, b, c, d  de chon dap an      |");
		xacdinhvitri(25,3);
		printf("|---------------------------------------|");
		xacdinhvitri(25,6);
		cout<<"Cau "<<STT<<" :"<<q->data.cauHoi<<endl;
		xacdinhvitri(25,9);
		cout<<q->data.cauA<<endl;
		xacdinhvitri(25,12);
		cout<<q->data.cauB<<endl;
		xacdinhvitri(25,15);
		cout<<q->data.cauC<<endl;
		xacdinhvitri(25,18);
		cout<<q->data.cauD<<endl;
		printf("       ===========================================================================================================");
	
		string s;//kiem tra dap an nhap vao cua thi sinh
		char s1[5];
		int y=20;
		while(true)
		{
			xacdinhvitri(25,y);
			fflush(stdin);
			s=getch();
			strcpy(s1,s.c_str());
			if(stricmp(s1,"a")!=0 && stricmp(s1,"b")!=0 && stricmp(s1,"c")!=0 && stricmp(s1,"d")!=0)
			{
				y++;
				xacdinhvitri(25,y);
				printf("Nhap lai\n");
			}	
			else
				break;	
		}
		  //check dap an
		char s3[q->data.dapAn.size()];
		strcpy(s3,q->data.dapAn.c_str());//copy dap an vao s3
		if(stricmp(s1,s3)==0)//dap an dung
			a++;
  	        STT++;//tang stt cau hoi
            p=p->link;
	}t2=clock();//ket thuc dem thoi gian
	system("cls");
	double t=t2-t1;//tinh thoi gian thi
	float diem;
	if(soLuong==10)
	diem=10.0*a;
	else if(soLuong==20)
	diem =5*a;
	xacdinhvitri(40,15);
	printf("+--------------------------------------------+");
	xacdinhvitri(40,16);
	printf("|            Ban da lam dung :               |");
	xacdinhvitri(40,17);
	printf("|%d cau                                       |",a);
	xacdinhvitri(40,18);
	printf("|Diem : %.2f diem                           |",diem);
	xacdinhvitri(40,19);
	printf("|thoi gian la %.1lf s                          |",t/1000);
	xacdinhvitri(40,20);
	printf("+--------------------------------------------+");
	Sleep(3000);
}
//them 1 cau hoi vao cuoi file
void themCauHoiVaoFile(LIST &l)
{
	system("cls");
	CAUHOI x;
	char tmp[20];
	sprintf(tmp,"%d",l.soLuong+1);x.stt=tmp;//tao stt cho cau moi,output chuoi da dinh dang den temp[]
	xacdinhvitri(10,3);
	printf("+==================+");
	xacdinhvitri(10,4);
	printf("|Nhap cau hoi:     |");
	xacdinhvitri(10,5);
	printf("+==================+");
	xacdinhvitri(30,4);
	getline(cin,x.cauHoi);
	xacdinhvitri(10,6);
	printf("+==================+");
	xacdinhvitri(10,7);
	printf("|Nhap dap an:      |");
	xacdinhvitri(10,8);
	printf("+==================+");
	xacdinhvitri(30,7);
	printf("a. ");
	getline(cin,x.cauA);
	fflush(stdin);
	xacdinhvitri(30,9);
	printf("b. ");
	getline(cin,x.cauB);
	fflush(stdin);
	xacdinhvitri(30,11);
	printf("c. ");
	getline(cin,x.cauC);
	fflush(stdin);
	xacdinhvitri(30,13);
	printf("d. ");
	getline(cin,x.cauD);
	//check dap an
	char s[10];
	while(true)
	{
	xacdinhvitri(10,15);
	printf("+==================+");
	xacdinhvitri(10,16);
	printf("|Dap an dung:      |");
	xacdinhvitri(10,17);
	printf("+==================+");
		fflush(stdin);
		xacdinhvitri(30,16);
		gets(s);
		if(strcmp(s,"a")!=0 && strcmp(s,"b")!=0 && strcmp(s,"c")!=0 && strcmp(s,"d")!=0)
		{
			xacdinhvitri(40,18);
			printf("|      Nhap lai    |");
			xacdinhvitri(40,19);
			printf("+==================+");
		}	
		else
			break;	
	}
	x.dapAn=s;
	addLastCauHoi(l,x);
	ofstream fp;//ofstream tao va ghi thong tin toi file
	fp.open("cauhoi.txt",ios_base::app);      //mo file de viet du lieu vao cuoi file 
	fp<<"\n";
	fp<<x.stt<<endl;
	fp<<x.cauHoi<<endl;
	fp<<"a. ";
	fp<<x.cauA<<endl;
	fp<<"b. ";
	fp<<x.cauB<<endl;
	fp<<"c. ";
	fp<<x.cauC<<endl;
	fp<<"d. ";
	fp<<x.cauD<<endl;
	fp<<x.dapAn;
	fp.close();   
}
void InitBAITHI(LISTBAITHI &l)
{
	l.first=l.last=NULL;
}
BAITHI *getNodeBAITHI(int a)
{
	BAITHI *p=new BAITHI;
	if(p==NULL)
		return NULL;
	p->a=a;
	p->link=NULL;
	return p;
}
void addLastBAITHI(LISTBAITHI &l, int a)
{
	BAITHI *p=getNodeBAITHI(a);
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
bool KTTrungSTT(LISTBAITHI l, int so)//kiem tra trung stt
{
	if(l.first==NULL)
		return true;
	else
	{
		BAITHI *p=l.first;
		while(p!=NULL)
		{
			if(p->a==so)
				return false;
			p=p->link;
		}
		
	}
	return true;
}
void STTrandom(LISTBAITHI &l,LIST l1, int soLuong)
{
	srand(time(NULL));
	for(int i=0;i<soLuong;i++)
	{
		int x=1+ rand()%l1.soLuong;
		if(KTTrungSTT(l,x)==false)
			i--;
		else
			addLastBAITHI(l,x);
	}
}
NODE *timkiem(LIST l, int so)
{
	NODE *p=l.first;	
	while(p!=NULL)
	{
		if(so==StringToInt(p->data.stt)){
			return p;
		}
		p=p->link;
	}
	return NULL;
}
int StringToInt(string s)
{
	char s1[s.size()];
	strcpy(s1,s.c_str()); //copy s vao s1
	int a=atof(s1); //atof chuyen doi string thanh so  thap phan
	return a;
}
void deletefirst(LIST &l)
{
	NODE *p=l.first;
	l.first=p->link;
	delete p;
}
void deletelast(LIST &l)
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

void xoa(LIST &l, int stt)
{
	NODE *p=l.first;
	NODE *q=new NODE;
	if(stt==StringToInt(l.first->data.stt))
	{
		deletefirst(l);
		l.soLuong--;
		return;
	}
	if(stt==StringToInt(l.last->data.stt))
	{
		deletelast(l);
		l.soLuong--;
		return;
	}
	while(p!=NULL)
	{
		q=p;
		p=p->link;
		if(stt==StringToInt(p->data.stt))
		{
			q->link=p->link;
			delete p;
			l.soLuong--;
			return;
		}
	}	
}
void capNhatFile(LIST l)//cap nhap cauhoi.txt
{
	ofstream fp;
	fp.open("cauhoi.txt",ios_base::trunc);//mo file de viet,neu file da ton tai,noi dung se duoc cat
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
void capNhatSTT(LIST &l)//sau khi xoa
{
	NODE *p=l.first;
	for(int i=1;i<=l.soLuong;i++)
	{
		char s[5];
		itoa(i,s,10);  //chuyen tu so nguyen thah chuoi
		p->data.stt=s;
		p=p->link;
	}
}
void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}
void xacdinhvitri(int x, int y)
{
  HANDLE h = NULL;  
  if(!h)
  	h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
}
void taidulieu()
{
	system("cls");
	xacdinhvitri(51,12);cout << "TAI DU LIEU...";
	for( int i = 0 ; i <= 50 ; i++ ){
		xacdinhvitri(34 + i,13);cout << char(219);
		xacdinhvitri(55,14);cout << i * 2 << "%";
			Sleep(30);
		}
}
void thanhvien()
{
		system("cls");
		xacdinhvitri(20,10);
		printf("Danh Sach Thanh Vien Nhom:");
		xacdinhvitri(20,11);
		printf("1.Van Khai");
		xacdinhvitri(20,12);
		printf("2.Dinh Linh");
		xacdinhvitri(20,13);
		printf("3.Hoang Cam");
		xacdinhvitri(20,14);
		printf("4.Duc Hung\n");
		Sleep(10);
			return;		
	
}
void xoadulieu_thoat(LIST &l)
{
	NODE *p=l.first;
	while(p!=NULL)
	{
		l.first=p->link;
		delete p;
		p=l.first;
	}
}
void nhapcauhoisua(CAUHOI &ch){
	
	xacdinhvitri(65,12);
	printf("Nhap cau hoi: ");
	getline(std::cin,ch.cauHoi);
	xacdinhvitri(65,15);
	printf("Nhap dap an A: ");
	getline(std::cin,ch.cauA);	
	xacdinhvitri(65,18);
	printf("Nhap dap an B: ");
	getline(std::cin,ch.cauB);
	xacdinhvitri(65,21);
	printf("Nhap dap an C: ");
	getline(std::cin,ch.cauC);
	xacdinhvitri(65,24);
	printf("Nhap dap an D: ");
	getline(std::cin,ch.cauD);
	xacdinhvitri(65,27);
	printf("Nhap dap an chinh xac: ");
	getline(std::cin,ch.dapAn);
	printf("\n \n \n");
	
}

void xuatcauhoibisua(CAUHOI dulieu)
{
    xacdinhvitri(2,7);
	printf("+==========================+");
	xacdinhvitri(2,8);
	printf("|Cau Hoi Can Sua :         |");
	xacdinhvitri(2,9);
	printf("+==========================+");
	xacdinhvitri(66,7);
	printf("+==========================+");
	xacdinhvitri(66,8);
	printf("|Sua Thanh Cau Hoi:        |");
	xacdinhvitri(66,9);
	printf("+==========================+");
	xacdinhvitri(2,12);
	cout<<dulieu.cauHoi;
	xacdinhvitri(2,15);
	cout<<dulieu.cauA;
	xacdinhvitri(2,18);
	cout<<dulieu.cauB;
	xacdinhvitri(2,21);
	cout<<dulieu.cauC;
	xacdinhvitri(2,24);
	cout<<dulieu.cauD;
	xacdinhvitri(2,27);
	cout<<"Dap an: "<<dulieu.dapAn<<endl<<endl;
}
void  Suacauhoi(LIST &l, string s)
{
	CAUHOI x;
		for(NODE *k= l.first; k!=NULL; k=k->link)
		{
			if(s == k->data.stt)
			{
			system("cls");
			xuatcauhoibisua(k->data);
			x.stt = s;
			nhapcauhoisua(x);
			NODE *sua = getNode(x);
			k->data= sua->data;			
			}
		}
	capNhatFile(l);
}
/*void Suacauhoi(LIST	&l,int maCauHoi)
{
	NODE *p=timkiem(l,maCauHoi);
	if(p==NULL)return;
	int luachon;
	int y=22;
	system("cls");
	
	 			fflush(stdin);
	 			xacdinhvitri(10,8);
	 			printf("+===================================+");
	 			xacdinhvitri(10,9);
	 			printf("|Vui long nhap lai noi dung cau hoi:|");	
	 			xacdinhvitri(10,10);
                printf("+===================================+");
                xacdinhvitri(60,9);
	 			getline(cin,p->data.cauHoi);
	 			xacdinhvitri(10,11);
	 			printf("+===================================+");
	 			xacdinhvitri(10,12);
	 			printf("|Vui long nhap lai dap an A:        |");
	 			xacdinhvitri(10,13);
	 			printf("+===================================+");
	 			xacdinhvitri(60,12);
	 			getline(cin,p->data.cauA);
	 			xacdinhvitri(10,14);
	 			printf("+===================================+");
	 			xacdinhvitri(10,15);
 				printf("|Vui long nhap lai dap an B:        |");
 				xacdinhvitri(10,16);
	 			printf("+===================================+");
	 			xacdinhvitri(60,15);
	 			getline(cin,p->data.cauB);
	 			xacdinhvitri(10,17);
	 			printf("+===================================+");
	 			xacdinhvitri(10,18);
 				printf("|Vui long nhap lai dap an C:        |");
 				xacdinhvitri(10,19);
	 			printf("+===================================+");
	 			xacdinhvitri(60,18);
	 			getline(cin,p->data.cauC);
	 			xacdinhvitri(10,20);
	 			printf("+===================================+");
	 			xacdinhvitri(10,21);
 				printf("|Vui long nhap lai dap an D:        |");
 				xacdinhvitri(10,22);
	 			printf("+===================================+");
	 			xacdinhvitri(60,21);
	 			getline(cin,p->data.cauD);
	 			fflush(stdin);
	 			xacdinhvitri(66,y++);
				printf("dap an dung:");
	 			while(true)
			 	{
	 				getline(cin,p->data.dapAn);
	 				char s[p->data.dapAn.size()];
	 				strcpy(s,p->data.dapAn.c_str());
	 				if(stricmp(s,"a")!=0&&stricmp(s,"b")!=0&&stricmp(s,"c")!=0&&stricmp(s,"d")!=0)
 					{
				 		xacdinhvitri(25,y++);
				 		printf("Nhap lai: ");
				 	}
				 	else
				 		break;
				}
 				system("cls");	
				 			capNhatFile(l);

}*/
void DanhSachCauHoi(LIST l)
{   system("cls");
	xacdinhvitri(20,1);
				printf("DANH SACH CAU HOI TRAC NGHIEM ");
	if(l.first==NULL)
		return;
		int x=4;
	NODE *p=l.first;
	
	while(p!=NULL)
	{   x++;
		xacdinhvitri(20,x);
		cout<<"Cau "<<p->data.stt<<": "<<p->data.cauHoi<<endl;
		p=p->link;
	}
}
