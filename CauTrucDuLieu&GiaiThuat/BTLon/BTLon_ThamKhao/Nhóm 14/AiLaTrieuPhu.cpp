#include <stdio.h>
#include<conio.h>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<windows.h>
struct CauHoi{
	char cauHoi[500];
	char dapAnA[100];
	char dapAnB[100];
	char dapAnC[100];
	char dapAnD[100];
	int ketQua;
};
struct Node{
	CauHoi data;
	Node*link;
};
struct List{
	Node*first;
	Node*last;
};
void init(List &l){
	l.last=l.first=NULL;
}
Node*getNode(CauHoi	c){
	Node*p;
	p=new Node;
	if(p==NULL)
		return NULL;
	p->data=c;
	p->link=NULL;
	return p;
}
void addLast(List &l,Node *p){
	if(l.first==NULL){
		l.first=l.last=p;
	}else{
		l.last->link=p;
		l.last=p;
	}
}
void doc_File(CauHoi &c,FILE *f){
	char *ch=new char[1000];
	char *str;
	fgets(ch,1000,f);
	//fgets() doc 1 dong ky tu tu` file (f) da cho truoc
	str= strtok(ch,",");
	//Ham strtok(string token) nhan vao mot chuoi string (ch), trong do no se tim ky tu tach chuoi bat dau tu` ky' tu. dau` tien cua chuoi nhap vao 
	strcpy(c.cauHoi,str);
	//Tu` loi` goi thu 2,ham strtok muon nhan vao NULL de co the tiep tuc tim` kiem' tu` vi tri' ket thuc truoc do.Chu' ko bat dau` lai tu` dau`.
	str=strtok(NULL,",");
	strcpy(c.dapAnA,str);
	str=strtok(NULL,",");
	strcpy(c.dapAnB,str);
	str=strtok(NULL,",");
	strcpy(c.dapAnC,str);
	str=strtok(NULL,",");
	strcpy(c.dapAnD,str);
	str=strtok(NULL,",");
	c.ketQua=atoi(str);		
}
void doc_DS_CauHoi(List &l){
	FILE *f;
	CauHoi c;
	init(l);
	int a;
	srand(time(NULL));
	a=rand()%2;
	if(a==1){
	f=fopen("boCauHoi1.txt","r"); //Doc file voi mode "r": Mo 1 file de doc.File phai ton tai	
	}else{
	f=fopen("boCauHoi2.txt","r");	
	}
	if(f==NULL){
		printf("\nFile khong ton tai");
	}else{
		while(!feof(f))// eof = end of file, khi nao chua gap ki tu ket thuc(eof) thi se con thuc hien doc ky' tu trong file
		{
			doc_File(c,f);
			Node *p = getNode(c);
			addLast(l,p);
		}
	}
	fclose(f);//Dong file
	printf("\n");
}
void hienThiCauHoi(CauHoi c){
	printf("\n|====================================================================================================|");
	printf("\n|%100s|",c.cauHoi);
	printf("\n|====================================================================================================|");
	printf("\n|A.%98s|",c.dapAnA);
	printf("\n|====================================================================================================|");
	printf("\n|B.%98s|",c.dapAnB);
	printf("\n|====================================================================================================|");
	printf("\n|C.%98s|",c.dapAnC);
	printf("\n|====================================================================================================|");
	printf("\n|D.%98s|",c.dapAnD);
	printf("\n|====================================================================================================|");
}
void goiDienNguoiThan(CauHoi c,boolean &tg1)
{
	if(tg1==false)
	{
		printf("\n Quyen tro giup nay da duoc su dung!");
		return;
	}
	else
	{
		printf("\nBan goi dien cho nguoi than va nguoi than tra loi la");
		Sleep(1000);
		printf("\n...");
		Sleep(1000);
		printf("\n...");
		Sleep(1000);
		printf("\n...");
		int a;
		if(strcmp(c.dapAnA,"")!=0&&strcmp(c.dapAnB,"")!=0&&strcmp(c.dapAnC,"")!=0&&strcmp(c.dapAnD,"")!=0)
		{
			srand(time(NULL));
			a=rand()%4;
			
			if(a==1){
				printf("\nToi nghi dap an la A");
			}else if(a==2){
				printf("\nToi nghi dap an la B");
			}else if(a==3){
				printf("\nToi nghi dap an la C");
			}else
				printf("\nToi nghi dap an la D");
				
		}else if(strcmp(c.dapAnA,"")==0&&strcmp(c.dapAnB,"")==0){
			srand(time(NULL));
			a=rand()%2;
			if(a==1){
				printf("\nToi nghi dap an la D");
			}else{
				printf("\nToi nghi dap an la C");}
		}else if(strcmp(c.dapAnA,"")==0&&strcmp(c.dapAnC,"")==0){
			srand(time(NULL));
			a=rand()%2;
			if(a==1){
				printf("\nToi nghi dap an la B");
			}else
				printf("\nToi nghi dap an la D");
		}else if(strcmp(c.dapAnA,"")==0&&strcmp(c.dapAnD,"")==0){
			srand(time(NULL));
			a=rand()%2;
			if(a==1){
				printf("\nToi nghi dap an la C");
			}else
				printf("\nToi nghi dap an la B");
		}else if(strcmp(c.dapAnB,"")==0&&strcmp(c.dapAnC,"")==0){
			srand(time(NULL));
			a=rand()%2;
			if(a==1){
				printf("\nToi nghi dap an la A");
			}else
				printf("\nToi nghi dap an la D");
		}else if(strcmp(c.dapAnB,"")==0&&strcmp(c.dapAnD,"")==0){
			srand(time(NULL));
			a=rand()%2;
			if(a==1){
				printf("\nToi nghi dap an la C");
			}else
				printf("\nToi nghi dap an la A");
		}else if(strcmp(c.dapAnC,"")==0&&strcmp(c.dapAnD,"")==0){
			srand(time(NULL));
			a=rand()%2;
			if(a==1){
				printf("\nToi nghi dap an la B");
			}else
				printf("\nToi nghi dap an la A");
		}
		tg1=false;
	}
}

void loaiBo_2_DapAnSai(CauHoi &c, boolean &tg2)
{
	if(tg2==false)
	{
		printf("\n Quyen tro giup nay da duoc su dung!");
		return;
	}
	else
	{
		int a, b;
		printf("\n Hai dap an sai la: ");
		do
		{
			srand(time(NULL));
			a=rand()%4;
			b=rand()%4;
		}while(a==0||a==c.ketQua||b==0||b==c.ketQua||b==a);
		if(a==1&&b==2)
			printf("A va B");
		if(a==1&&b==3)
			printf("A va C");
		if(a==1&&b==4)
			printf("A va D");
		if(a==2&&b==1)
			printf("A va B");
		if(a==3&&b==1)
			printf("A va C");
		if(a==4&&b==1)
			printf("A va D");
		//=============================
		if(a==2&&b==3)
			printf("B va C");
		if(a==2&&b==4)
			printf("B va D");
		if(a==3&&b==2)
			printf("B va C");
		if(a==4&&b==2)
			printf("B va D");
		//=============================
		if(a==3&&b==4)
			printf("C va D");
		if(a==4&&b==3)
			printf("C va D");
		//=============================
		if(a==1||b==1)
			strcpy(c.dapAnA, "");
		if(a==2||b==2)
			strcpy(c.dapAnB, "");
		if(a==3||b==3)
			strcpy(c.dapAnC, "");
		if(a==4||b==4)
			strcpy(c.dapAnD, "");
		tg2=false;
	}
}
void hoiYKienKhanGiaTruongQuay(CauHoi c,boolean &tg3)
{
	if(tg3==false)
	{
		printf("\n Quyen tro giup nay da duoc su dung!");
		return;
	}
	else
	{
		printf("\nChung toi xin hoi y kien khan gia trong truong quay");
			Sleep(1000);
			printf("\n...");
			Sleep(1000);
			printf("\n...");
			Sleep(1000);
			printf("\n...");
			Sleep(1000);
		if(strcmp(c.dapAnA,"")!=0&&strcmp(c.dapAnB,"")!=0&&strcmp(c.dapAnC,"")!=0&&strcmp(c.dapAnD,"")!=0)
		{
			int a, b , c, d;
			srand(time(NULL));
			a=rand()%100;
			b=rand()%(100-a);
			c=rand()%(100-a-b);
			d=100-a-b-c;
			printf("\n Y kien khan gia trong truong quay la:\n A: %d\n B: %d\n C: %d\n D: %d", a, b, c, d);		
		}else if(strcmp(c.dapAnA,"")==0&&strcmp(c.dapAnB,"")==0){
			int a, b;
			srand(time(NULL));
			a=rand()%100;
			b=100-a;
			printf("\n Y kien khan gia trong truong quay la:\n C: %d\n D: %d", a, b);
			tg3=false;
		}else if(strcmp(c.dapAnA,"")==0&&strcmp(c.dapAnC,"")==0){
			int a, b;
			srand(time(NULL));
			a=rand()%100;
			b=100-a;
			printf("\n Y kien khan gia trong truong quay la:\n B: %d\n D: %d", a, b);
		}else if(strcmp(c.dapAnA,"")==0&&strcmp(c.dapAnD,"")==0){
			int a, b;
			srand(time(NULL));
			a=rand()%100;
			b=100-a;
			printf("\n Y kien khan gia trong truong quay la:\n B: %d\n C: %d", a, b);
		}else if(strcmp(c.dapAnB,"")==0&&strcmp(c.dapAnC,"")==0){
			int a, b;
			srand(time(NULL));
			a=rand()%100;
			b=100-a;
			printf("\n Y kien khan gia trong truong quay la:\n A: %d\n D: %d", a, b);
		}else if(strcmp(c.dapAnB,"")==0&&strcmp(c.dapAnD,"")==0){
			int a, b;
			srand(time(NULL));
			a=rand()%100;
			b=100-a;
			printf("\n Y kien khan gia trong truong quay la:\n A: %d\n C: %d", a, b);
		}else if(strcmp(c.dapAnC,"")==0&&strcmp(c.dapAnD,"")==0){
			int a, b;
			srand(time(NULL));
			a=rand()%100;
			b=100-a;
			printf("\n Y kien khan gia trong truong quay la:\n A: %d\n B: %d", a, b);
		}
		tg3=false;
	}
}
void toTuVanTaiCho(CauHoi c,boolean &tg4){
	if(tg4==false)
	{
		printf("\n Quyen tro giup nay da duoc su dung!");
		return;
	}else{
		if(strcmp(c.dapAnA,"")!=0&&strcmp(c.dapAnB,"")!=0&&strcmp(c.dapAnC,"")!=0&&strcmp(c.dapAnD,"")!=0){
			int a,b,d;
			char da_n1[5],da_n2[5],da_n3[5];
	 		srand(time(NULL));
			a=rand()%4;
			b=rand()%4;
			d=rand()%4;
			if(a==1) strcpy(da_n1,"A");else if(a==2) strcpy(da_n1,"B");else if(a==3) strcpy(da_n1,"C");else strcpy(da_n1,"D");
			if(b==1) strcpy(da_n2,"A");else if(b==2) strcpy(da_n2,"B");else if(b==3) strcpy(da_n2,"C");else strcpy(da_n2,"D");
			if(d==1) strcpy(da_n3,"A");else if(d==2) strcpy(da_n3,"B");else if(d==3) strcpy(da_n3,"C");else strcpy(da_n3,"D");
			printf("\nNguoi so 1 chon dap an la: %s",da_n1);
		Sleep(1000);
		printf("\nNguoi so 2 chon dap an la: %s",da_n2);
		Sleep(1000);
		printf("\nNguoi so 3 chon dap an la: %s",da_n3);
		Sleep(1000);			
		}else if(strcmp(c.dapAnA,"")==0&&strcmp(c.dapAnB,"")==0){
			int a,b,d;
			char da_n1[5],da_n2[5],da_n3[5];
			srand(time(NULL));
			a=rand()%2;
			b=rand()%2;
			d=rand()%2;
			if(a==1) strcpy(da_n1,"C");else strcpy(da_n1,"D");
			if(b==1) strcpy(da_n2,"C");else strcpy(da_n2,"D");
			if(d==1) strcpy(da_n3,"C");else strcpy(da_n3,"D");
			printf("\nNguoi so 1 chon dap an la: %s",da_n1);
		Sleep(1000);
		printf("\nNguoi so 2 chon dap an la: %s",da_n2);
		Sleep(1000);
		printf("\nNguoi so 3 chon dap an la: %s",da_n3);
		Sleep(1000);
		}else if(strcmp(c.dapAnA,"")==0&&strcmp(c.dapAnC,"")==0){
			int a,b,d;
			char da_n1[5],da_n2[5],da_n3[5];
			srand(time(NULL));
			a=rand()%2;
			b=rand()%2;
			d=rand()%2;
			if(a==1) strcpy(da_n1,"B");else strcpy(da_n1,"D");
			if(b==1) strcpy(da_n2,"B");else strcpy(da_n2,"D");
			if(d==1) strcpy(da_n3,"B");else strcpy(da_n3,"D");
			printf("\nNguoi so 1 chon dap an la: %s",da_n1);
		Sleep(1000);
		printf("\nNguoi so 2 chon dap an la: %s",da_n2);
		Sleep(1000);
		printf("\nNguoi so 3 chon dap an la: %s",da_n3);
		Sleep(1000);
		}else if(strcmp(c.dapAnA,"")==0&&strcmp(c.dapAnD,"")==0){
			int a,b,d;
			char da_n1[5],da_n2[5],da_n3[5];
			srand(time(NULL));
			a=rand()%2;
			b=rand()%2;
			d=rand()%2;
			if(a==1) strcpy(da_n1,"B");else strcpy(da_n1,"C");
			if(b==1) strcpy(da_n2,"B");else strcpy(da_n2,"C");
			if(d==1) strcpy(da_n3,"B");else strcpy(da_n3,"C");
			printf("\nNguoi so 1 chon dap an la: %s",da_n1);
		Sleep(1000);
		printf("\nNguoi so 2 chon dap an la: %s",da_n2);
		Sleep(1000);
		printf("\nNguoi so 3 chon dap an la: %s",da_n3);
		Sleep(1000);
		}else if(strcmp(c.dapAnB,"")==0&&strcmp(c.dapAnC,"")==0){
			int a,b,d;
			char da_n1[5],da_n2[5],da_n3[5];
			srand(time(NULL));
			a=rand()%2;
			b=rand()%2;
			d=rand()%2;
			if(a==1) strcpy(da_n1,"A");else strcpy(da_n1,"D");
			if(b==1) strcpy(da_n2,"A");else strcpy(da_n2,"D");
			if(d==1) strcpy(da_n3,"A");else strcpy(da_n3,"D");
			printf("\nNguoi so 1 chon dap an la: %s",da_n1);
		Sleep(1000);
		printf("\nNguoi so 2 chon dap an la: %s",da_n2);
		Sleep(1000);
		printf("\nNguoi so 3 chon dap an la: %s",da_n3);
		Sleep(1000);
		}else if(strcmp(c.dapAnB,"")==0&&strcmp(c.dapAnD,"")==0){
			int a,b,d;
			char da_n1[5],da_n2[5],da_n3[5];
			srand(time(NULL));
			a=rand()%2;
			b=rand()%2;
			d=rand()%2;
			if(a==1) strcpy(da_n1,"A");else strcpy(da_n1,"C");
			if(b==1) strcpy(da_n2,"A");else strcpy(da_n2,"C");
			if(d==1) strcpy(da_n3,"A");else strcpy(da_n3,"C");
			printf("\nNguoi so 1 chon dap an la: %s",da_n1);
		Sleep(1000);
		printf("\nNguoi so 2 chon dap an la: %s",da_n2);
		Sleep(1000);
		printf("\nNguoi so 3 chon dap an la: %s",da_n3);
		Sleep(1000);
		}else if(strcmp(c.dapAnC,"")==0&&strcmp(c.dapAnD,"")==0){
			int a,b,d;
			char da_n1[5],da_n2[5],da_n3[5];
			srand(time(NULL));
			a=rand()%2;
			b=rand()%2;
			d=rand()%2;
			if(a==1) strcpy(da_n1,"A");else strcpy(da_n1,"B");
			if(b==1) strcpy(da_n2,"A");else strcpy(da_n2,"B");
			if(d==1) strcpy(da_n3,"A");else strcpy(da_n3,"B");
			printf("\nNguoi so 1 chon dap an la: %s",da_n1);
		Sleep(1000);
		printf("\nNguoi so 2 chon dap an la: %s",da_n2);
		Sleep(1000);
		printf("\nNguoi so 3 chon dap an la: %s",da_n3);
		Sleep(1000);
		}
		
		tg4=false;
	}
}
void yeuCauTroGiup(CauHoi &c, boolean &tg1, boolean &tg2, boolean &tg3, boolean &tg4)
{
    Beep(3000,200);
    int a;
    do
    {
  	 	printf("\n\n");
		printf("|======================================|\n");
	    printf("|                TRO GIUP              |\n");
    	printf("|======================================|\n");
    	printf("| 1.  GOI DIEN THOAI CHO NGUOI THAN    |\n");
		printf("|======================================|\n");
   	 	printf("|======================================|\n");
	 	printf("| 2.  LOAI BO 50/50                    |\n");
    	printf("|======================================|\n");
    	printf("|======================================|\n");
    	printf("| 3.  HOI Y KIEN KHAN GIA TRUONG QUAY  |\n");
    	printf("|======================================|\n");
    	printf("|======================================|\n");
    	printf("| 4.  TO TU VAN TAI CHO                |\n");
    	printf("|======================================|\n");
    	printf("|======================================|\n");
    	printf("| 0.  QUAY LAI CAU HOI                 |\n");
    	printf("|======================================|\n");
    	do
    	{
	    	printf("\n Lua chon: "); scanf("%d", &a);
	    }while(a<0||a>4);
	    switch(a)
	    {
    		case 1:
    			goiDienNguoiThan(c,tg1);
    			a=0;
				break;
			case 2:
				loaiBo_2_DapAnSai(c, tg2);
				a=0;
				break;
			case 3:
				hoiYKienKhanGiaTruongQuay(c,tg3);
				a=0;
				break;
			case 4:
				toTuVanTaiCho(c,tg4);
				a=0;
				break;  
    	}
    }while(a!=0);
}
int goicauhoi(List l, int x, boolean &tg1, boolean &tg2, boolean &tg3,boolean &tg4)
{
	int a;
	CauHoi c=l.first->data;
quaylai:
	if(x<10){
	printf("\n|====================================================================================================|");
	printf("\n|                                            Cau hoi so %d                                            |", x);	
	}else{
	printf("\n|====================================================================================================|");
	printf("\n|                                           Cau hoi so %d                                            |", x);	
	}
	hienThiCauHoi(c);
	do
	{
		printf("\n De xem quyen tro giup: Nhan 0");
		printf("\n De chon A: Nhan 1");
		printf("\n De chon B: Nhan 2");
		printf("\n De chon C: Nhan 3");
		printf("\n De chon D: Nhan 4");
		printf("\n De dung cuoc choi: Nhan 5"); 
		printf("\n Lua chon: "); 
		scanf("%d", &a);
		if(tg1==false && tg2== false && tg3==false &&tg4==false&& a==0){
			printf("\nBan da su dung het quyen tro giup cua minh!");
			goto quaylai;	
		}
	}while(a<0||a>5);
	switch(a)
	{
		case 0:
			yeuCauTroGiup(c, tg1, tg2, tg3,tg4);
			goto quaylai;
			break;
		case 1:
		case 2:
		case 3:
		case 4:
			if(a==c.ketQua)
				return 1;
			else
				return 0;
			break;
		case 5:
			return -1;
			break;
	}
}
void tienthuong()
{
	Beep(3000,200);
    printf("\t\t\t|===========================|\n");
    printf("\t\t\t| SO TIEN QUA MOI CAU HOI   |\n");
    printf("\t\t\t|===========================|\n\n");
    printf("\t\t\t|===========================|\n");
    printf("\t\t\t| Cau 15: 150,000,000 DONG  |\n");
    printf("\t\t\t|===========================|\n");
    printf("\t\t\t|  Cau 14: 85,000,000 DONG  |\n");
    printf("\t\t\t|===========================|\n");
    printf("\t\t\t|  Cau 13: 60,000,000 DONG  |\n");
    printf("\t\t\t|===========================|\n");
    printf("\t\t\t|  Cau 12: 40,000,000 DONG  |\n");
    printf("\t\t\t|===========================|\n");
    printf("\t\t\t|  Cau 11: 30,000,000 DONG  |\n");
    printf("\t\t\t|===========================|\n");
    printf("\t\t\t|  Cau 10: 22,000,000 DONG  |\n");
    printf("\t\t\t|===========================|\n");
    printf("\t\t\t|  Cau 9:  14,000,000 DONG  |\n");
    printf("\t\t\t|===========================|\n");
    printf("\t\t\t|  Cau 8:  10,000,000 DONG  |\n");
    printf("\t\t\t|===========================|\n");
    printf("\t\t\t|  Cau 7:  6,000,000 DONG   |\n");
    printf("\t\t\t|===========================|\n");
    printf("\t\t\t|  Cau 6:  3,000,000 DONG   |\n");
    printf("\t\t\t|===========================|\n");
    printf("\t\t\t|  Cau 5:  2,000,000 DONG   |\n");
    printf("\t\t\t|===========================|\n");
    printf("\t\t\t|  Cau 4:  1,000,000 DONG   |\n");
    printf("\t\t\t|===========================|\n");
    printf("\t\t\t|  Cau 3:  600,000  DONG    |\n");
    printf("\t\t\t|===========================|\n");
    printf("\t\t\t|  Cau 2:  400,000  DONG    |\n");
    printf("\t\t\t|===========================|\n");
    printf("\t\t\t|  Cau 1:  200,000  DONG    |\n");
    printf("\t\t\t|===========================|\n");
}
void tinhdiem(int x, int &diem)
{
	switch(x)
	{
		case 1:
			diem+=200000;
			break;
		case 2:
			diem+=200000;
			break;
		case 3:
			diem+=200000;
			break;
		case 4:
			diem+=400000;
			break;
		case 5:
			diem+=1000000;
			break;
		case 6:
			diem+=1000000;
			break;
		case 7:
			diem+=3000000;
			break;
		case 8:
			diem+=4000000;
			break;
		case 9:
			diem+=4000000;
			break;
		case 10:
			diem+=8000000;
			break;
		case 11:
			diem+=8000000;
			break;
		case 12:
			diem+=10000000;
			break;
		case 13:
			diem+=20000000;
			break;
		case 14:
			diem+=25000000;
			break;
		case 15:
			diem+=65000000;
			break;
	}
}
void intienthuong(int diem)
{
		printf("\n Tien thuong cua ban la: %d", diem);
		Sleep(2000);
}
void batdauchoi(List l,boolean &tg1, boolean &tg2, boolean &tg3,boolean &tg4)
{
	system("cls");
	doc_DS_CauHoi(l);
	tienthuong();
	Sleep(4000);
	system("cls");
	int x=1, diem=0, a, b, o;
	while(l.first!=NULL)
	{
		srand(time(NULL));
		o=rand()%2;
		if(o==1){
			l.first=l.first->link;
		}
		int kq=goicauhoi(l, x, tg1, tg2, tg3,tg4);
		if(kq==1)
		{
			printf("\nDo la cau tra loi...");
			Sleep(1000);
			printf("\n...");
			Sleep(1000);
			printf("\n...");
			Sleep(1000);
			Beep(2000,50);
			Beep(3000,50);
			Beep(4000,500);
			printf("\nChinh xac, xin chuc mung!");
			tinhdiem(x, diem);
			Sleep(1000);
			printf("\n SO TIEN HIEN TAI CUA BAN LA: %d", diem);
			Sleep(3000);
			if(x>=5)
			{
				 do
				{
					printf("\n Nhan 1 de choi tiep hoac 0 de dung cuoc choi: "); scanf("%d", &a);
				}while(a<0||a>1);
				if(a==0)
				{
					intienthuong(diem);
					printf("\n Nhan so bat ki de thoat!!"); scanf("%d", &b);
					goto end;
				}
			}
			if(x==15)
			{
				printf("\n               THANG CUOC                   ");
				intienthuong(diem);
				printf("\n Nhan so bat ki de thoat!!"); scanf("%d", &b);
				goto end;
			}
			x++;         
		}
		else if(kq==0)
		{
			printf("\nDo la cau tra loi...");
			Sleep(1000);
			printf("\n...");
			Sleep(1000);
			printf("\n...");
			Sleep(1000);
			Beep(100,300);
			Beep(100,900);
			printf("\nKhong chinh xac");
			Sleep(2000);
			if(x<=5)
			{
				diem = 0;
				intienthuong(diem);
				printf("\n Nhan so bat ki de thoat!!"); scanf("%d", &b);
				goto end;
			}
			else if(x<=10)
			{
				diem = 2000000;
				intienthuong(diem);
				printf("\n Nhan so bat ki de thoat!!"); scanf("%d", &b);
				goto end;
			}
			else
			{
				diem = 22000000;
				intienthuong(diem);
				printf("\n Nhan so bat ki de thoat!!"); scanf("%d", &b);
				goto end;
			}
		}
		else
		{
			intienthuong(diem);
			printf("\n Nhan so bat ki de thoat!!"); scanf("%d", &b);
			goto end;
		}
		system("cls");
		l.first=l.first->link;
	}
end:;
}
void nhapCauHoi(CauHoi &c)
{
	printf("Nhap cau hoi: ");
	fflush(stdin);
	gets(c.cauHoi);
	printf("Nhap dap an A: ");
	fflush(stdin);
	gets(c.dapAnA);
	printf("Nhap dap an B: ");
	fflush(stdin);
	gets(c.dapAnB);
	printf("Nhap dap an C: ");
	fflush(stdin);
	gets(c.dapAnC);
	printf("Nhap dap an D: ");
	fflush(stdin);
	gets(c.dapAnD);
	printf("Nhap dap an dung(1-4 tuong ung voi dap an A-B-C-D): ");
	scanf("%d", &c.ketQua); 
}
void themCauHoi()
{
	system("cls");
	CauHoi ch;
	int a;
	FILE *fp;
	fp=fopen("boCauHoi1.txt","a"); //Mode "a" hoat dong ghi, phu. them du lieu lai cuoi file. File duoc tao neu no chua ton tai
	
	while(true)
	{
		nhapCauHoi(ch);
		fprintf(fp,"\n");
		fprintf(fp, "%s,%s,%s,%s,%s,%d", ch.cauHoi, ch.dapAnA, ch.dapAnB, ch.dapAnC, ch.dapAnD, ch.ketQua);
		do
		{
			printf("\n Nhap tiep: nhan 1\n Thoat: nhan 0");scanf("%d", &a);
		}while(a<0||a>1);
		if(a==0)
			break;		
	}
	fclose(fp);
}
void huongDan()
{
	system("cls");
 	printf("\t\t|============================================|\n");
  	printf("\t\t|\t\t HUONG DAN                   |\n");
 	printf("\t\t|============================================|\n\n");
  	printf("VUOT QUA DUOC 15 CAU HOI CUA CHUONG TRINH BAN SE NHAN DUOC 150 TRIEU DONG |");
  	printf("BAN CO CAC QUYEN TRO GIUP                                                 |\n");
  	printf("|=========================================================================|\n");
  	printf("|1. GOI DIEN THOAI CHO NGUOI THAN                                         |\n");
  	printf("|  BAN CO 30S DE GOI DIEN THOAI NHO SU GIUP SO CUA NGUOI THAN             |\n");
 	printf("|=========================================================================|\n");
 	printf("|=========================================================================|\n");
  	printf("|2. TRO GIUP 50/50 MAY TINH SE TU DONG LOAI BO HAI PHUONG AN SAI          |\n");
  	printf("|=========================================================================|\n");
  	printf("|=========================================================================|\n");
  	printf("|3. HOI Y KIEN KHAN GIA : KHAN GIA TRONG TRUONG QUAY SE DUA RA            |\n|NHUNG DAP AN MA HO CHO LA CHINH XAC NHAT                                 |\n");
  	printf("|=========================================================================|");
  	printf("\n|=========================================================================|\n");
  	printf("|4. TO TU VAN TAI CHO:HOI Y KIEN 3 KHAN GIA TRONG TRUONG QUAY             |\n");
  	printf("|=========================================================================|\n\n");
  	Sleep(20000);
}
int main(int argc, char *argv[])
{	
	boolean tg1=true;
	boolean tg2=true;
	boolean tg3=true;
	boolean tg4=true;
	List l;
	init(l);
	int chon;
	do
    {

        printf("\n\n\n|==============================================================================|\n");
        printf("|               CHAO MUNG BAN DEN VOI TRO CHOI AI LA TRIEU PHU                 |\n");
        printf("|==============================================================================|\n\n\n");
        printf("|==============================================================================|\n");
        printf("|                               1. BAT DAU                                     |\n");
        printf("|==============================================================================|\n");
        printf("|==============================================================================|\n");
        printf("|                               2. HUONG DAN                                   |\n");
        printf("|==============================================================================|\n");
        printf("|==============================================================================|\n");
        printf("|                               3. THEM CAU HOI                                |\n");
        printf("|==============================================================================|\n");
        printf("|==============================================================================|\n");
        printf("|                               4. THOAT                                       |\n");
        printf("|==============================================================================|\n");
        do
        {
            printf("\n CHON MUC : ");
            scanf("%d", &chon);
            if(chon<1||chon>4)
                printf(" Lua chon khong phu hop vui long chon lai \n");
        }while(chon<1 && chon>4);
        switch(chon)
        {
        	case 1:
        		Beep(3000,200);
        		tg1=true;
				tg2=true;
			 	tg3=true;
			 	tg4=true;
        		batdauchoi(l,tg1,tg2,tg3,tg4);
        		break;
       		case 2:
       			Beep(3000,200);
       			huongDan();
       			break;
       		case 3:
				Beep(3000,200);
				themCauHoi();
				break;
        }
        system("cls");
    }while(chon!=4);
	return 0;
}