#include <iostream>
#include "csl.h"
#include "console.h"
#include<conio.h>
#include <time.h>
#include<windows.h>
#include<stdlib.h>
#include <fstream> // READ & WRITE FILE
using namespace std;
#define MAUNEN 11 // MÀU XANH
#define MAUCHU 7    // MÀU XÁM
int da_dung[5];
char player_name[50];
// ĐỌC FILE VÀ GHI VÀO LIST

struct CauHoi
{
	char CauHOi[500];
	char A[200];
	char B[200];
	char C[200];
	char D[200];
	char DAn[5];
	int maSo;
};

struct ALTP
{
	CauHoi CH;
	ALTP *link;
};

struct list
{
	ALTP *first;
	ALTP *last;
};


ALTP *getNode(CauHoi x)
{
	ALTP *p;
	p = new ALTP;
	if(p == NULL) return NULL;
	p->CH = x;
	p->link = NULL;
	return p;
}
void init(list &l)
{
	l.first = l.last = NULL;
}
void addlast(list &l, CauHoi x)
{
	ALTP *p = getNode(x);
	if(p == NULL) return;
	if(l.first == NULL)
	{
		l.first = l.last = p;
	}
	else
	{
		l.last->link = p;
		l.last = p;
	}
}
void LayFILE(list &l,char* filename)
{
	CauHoi x;
	FILE *f;
	int ma_so=0;
	//char i;
	f = fopen(filename, "r");
	if(!f) return;
	while(!feof(f))
	{
		fgets(x.CauHOi,500,(FILE*)f);
		fgets(x.A,200,(FILE*)f);
		fgets(x.B,200,(FILE*)f);
		fgets(x.C,200,(FILE*)f);
		fgets(x.D,200,(FILE*)f);
		fgets(x.DAn,100,(FILE*)f);
		addlast(l,x);
		ma_so++;
		x.maSo=ma_so;

	}
	fclose(f);
}
void XuatFile(list l)
{
	ALTP *K;
	K = l.first;
	printf("\t\t\t..........Thong tin cau hoi...........\n");
	while(K!= NULL)
	{
		printf("Cau hoi %d: %s\n",K->CH.maSo,K->CH.CauHOi);
		printf("A. %s\n",K->CH.A);
		printf("B. %s\n",K->CH.B);
		printf("C. %s\n",K->CH.C);
		printf("D. %s\n",K->CH.D);
		printf("Dan: %s\n",K->CH.DAn);
		K = K->link;
		//getch();
	}
}
void xoa_DSLK(list l)
{
    ALTP *p;
    while(l.first!=NULL)
    {
        p=l.first;
        l.first=p->link;
        free(p);
    }
    l.last=NULL;
}

// KẾT THÚC ĐỌC VÀ GHI FILE VÀO LIST
int TEXT_AILATRIEUPHU()
{ 	char c;
	FILE* f = fopen("D:\\KHA\\AILATRIEUPHU.txt", "r");
	if(!f) // CAN'T OPEN
		return 0;
	while(!feof(f)) // ĐỌC FILE TRONG KHI CHƯA HẾT FILE
	{
 		fscanf(f,"%c",&c);
		printf("%c",c);

	}
	printf("\n\n\n\n");
}

// SỐ TIỀN NHẬN ĐƯỢC
int money(int i)
{
    switch(i)
    {
        case 1: return 0;
        case 2: return 200;
        case 3: return 400;
        case 4: return 600;
        case 5: return 1000;
        case 6: return 2000;
        case 7: return 3000;
        case 8: return 6000;
        case 9: return 10000;
        case 10: return 14000;
        case 11: return 22000;
        case 12: return 30000;
        case 13: return 40000;
        case 14: return 60000;
        case 15: return 85000;
        case 16: return 150000;
    }
}
int money_now(int i)
{
    if(i<6) return 0;
    if(i<11 || i> 5)return 2000;
    if(i<16 || i> 11 ) return 22000;
    if(i>15) return 150000;
}
// RANK



int TEXT_TOPPLAYER()
{ 	char c;
	FILE* f = fopen("D:\\KHA\\code\\TestTV\\TOPPLAYER.txt", "r");
	if(!f) // CAN'T OPEN
		return 0;
	while(!feof(f)) // ĐỌC FILE TRONG KHI CHƯA HẾT FILE
	{
 		fscanf(f,"%c",&c);
		printf("%c",c);

	}
	printf("\n\n\n\n");
}
struct name
{
	char name[50];
	int diem;
	int money;

};
struct rank
{
	name CH;
	rank *link;
};

struct list_rank
{
	rank *first;
	rank *last;
};


rank *getNode_rank(name x)
{
	rank *p;
	p = new rank;
	if(p == NULL) return NULL;
	p->CH = x;
	p->link = NULL;
	return p;
}


void init_rank(list_rank &l)
{
	l.first = l.last = NULL;
}


void addlast_rank(list_rank &l, name x)
{
	rank *p = getNode_rank(x);
	if(p == NULL) return;
	if(l.first == NULL)
	{
		l.first = l.last = p;
	}
	else
	{
		l.last->link = p;
		l.last = p;
	}
}
void LayFILE_rank(list_rank &l)
{
	name x;
	FILE *f;
	//char i;
	int ma_so=0;
	f = fopen("D:\\KHA\\code\\TestTV\\RANK.txt","r");
	if(!f) return;
	while(!feof(f))
	{
		fgets(x.name,500,(FILE*)f);
		fscanf(f,"%d\n",&x.diem);
		fscanf(f,"%d\n",&x.money);
		addlast_rank(l,x);
	}
	fclose(f);
}
void XuatFile_rank()
{
    clrscr();
    list_rank l;
    init_rank(l);
    LayFILE_rank(l);
    //TEXT_AILATRIEUPHU();
    printf("\n\n\n\n\n");
    TEXT_TOPPLAYER();
	rank *K;
	K = l.first;
	int i=0;
	//printf("\t\t\t..........Thong tin cau hoi...........\n");
	while(K!= NULL)
	{
        i++;
        if(i==1) setcolor(14);
        if(i==2) setcolor(13);
        if(i==3) setcolor(11);
        if(i!=1 && i!=2 &&i !=3) setcolor(7);

        printf("\t\t\t\t\t\t\t\t\t| TOP %d: %s",i,K->CH.name);
		//printf("%s",K->CH.name);
		printf("\t\t\t\t\t\t\t\t\tĐIỂM: %d\n",K->CH.diem);
		printf("\t\t\t\t\t\t\t\t\tTIỀN NHẬN ĐƯỢC: %d000 VNĐ\n",K->CH.money);
		K = K->link;
		//getch();
	}
}
void xoa_DSLK_rank(list_rank l)
{
    rank *p;
    while(l.first!=NULL)
    {
        p=l.first;
        l.first=p->link;
        free(p);
    }
    l.last=NULL;
}
void xoa_rank(list_rank &l)
{
	rank *p;
	for (rank *k=l.first;k!=NULL;k=k->link)
	{
		if (k==l.last)
		{
			l.last=p;
			l.last->link=NULL;
			delete k;
			return;
		}
		p=k;
	}
}
void top10player(char *a,int die,int tien)
{
    list_rank l;
    init_rank(l);
    LayFILE_rank(l);
	int d = l.last->CH.diem;
	rank *p=l.first;
	rank *q;
	if (d<die)
	{
		while (p->CH.diem > die)
		{
			q=p;
			p=p->link;
		}
		name K;
		strcpy(K.name,a);
		strcat(K.name,"\n");
		K.diem=die;
		K.money=tien;
		rank *tmp = getNode_rank(K);
		q->link=tmp;
		tmp->link=p;
		xoa_rank(l);
		FILE *f;
		int ret=remove("D:\\KHA\\code\\TestTV\\RANK.txt");
		f = fopen("D:\\KHA\\code\\TestTV\\RANK.txt","w");
		fprintf(f,"%s",l.first->CH.name);
		fprintf(f,"%d\n",l.first->CH.diem);
		fprintf(f,"%d",l.first->CH.money);
		for(p=l.first->link;p!=NULL;p=p->link)
		{
		//	fprintf(f,"\n");
			fprintf(f,"\n%s",p->CH.name);
			fprintf(f,"%d",p->CH.diem);
			fprintf(f,"\n%d",p->CH.money);
		}
		xoa_DSLK_rank(l);
		fclose(f);
	}
}
typedef char str[200];
str thaoTac[5]={"                                                                              | BẮT ĐẦU"
,"                                                                              | ADMIN"
,"                                                                              | BẢNG XẾP HẠNG"
,"                                                                              | CÁCH CHƠI?"
,"                                                                              | THOÁT"
};
enum TRANGTHAI{UP,DOWN,LEFT,RIGHT,ENTER,OPTIONS};
TRANGTHAI key(int z)
{
    if(z==224)
    {
        char c;
        c=getch();
        //printf("%d",c);
        if(c==72) return UP;
        if(c==80) return DOWN;
        if(c==75) return LEFT;
        if(c==77) return RIGHT;

    }
    else if(z==13) return ENTER;
    else if(z==32)  return OPTIONS;
}
int menu(str thaoTac[5],int n)
{   int tt=0;
    int mau[n];
    //for(int i=)
    for(int i=0;i<n;i++)
        mau[i]= MAUCHU;
    mau[0]= MAUNEN;
    while(1)
    {
        clrscr();
        setcolor(7);
        TEXT_AILATRIEUPHU();
        setcolor(7);
        //printf("                                                                                AI LÀ TRIỆU PHÚ!!! \n\n\n\n");
        for(int i=0;i<n;i++)
        {

            setcolor(mau[i]);
            cout<<thaoTac[i]<<endl;
        }
        int z= getch();
        TRANGTHAI trangthai=key(z);
        switch(trangthai)
        {
        case UP:
            {
                if(tt==0)
                {
                    tt=n-1;
                }
                    else tt--;
                break;
            }
        case DOWN:
            {
                if(tt==n-1)
                {
                    tt=0;
                }
                    else tt++;
                break;
            }
        case ENTER: return tt;
        }
        for(int i=0;i<n;i++)
        {
            mau[i]=MAUCHU;
            //strlwr(thaoTac[i]);
        }

        mau[tt]=MAUNEN;
        //strupr(thaoTac[tt]);


    }
}
int menu_troGiup(str thaoTac[5],int n)
{
    int tt;
    tt=0;

    int mau[n];
    //for(int i=)
    da_dung[3]=0;
    da_dung[4]=0;
    for(int i=0;i<n;i++)
        mau[i]= MAUCHU;
    if(da_dung[0]==1 && tt==0) mau[3]=MAUNEN;
    else mau[0]= MAUNEN;
    if(da_dung[0]==1 && tt==0) tt=3;
    while(1)
    {
        clrscr();
        setcolor(7);
        TEXT_AILATRIEUPHU();
        setcolor(7);


        //printf("                                                                                AI LÀ TRIỆU PHÚ!!! \n\n\n\n");
        for(int i=0;i<n;i++)
        {

            setcolor(mau[i]);
            cout<<thaoTac[i]<<endl;
        }
        int z= getch();
        TRANGTHAI trangthai=key(z);
        switch(trangthai)
        {
        case UP:
            {
                LOOPtt:
                if(tt==0)
                {

                    tt=n-1;
                    if(da_dung[tt]==1) tt--;
                }
                    else
                    {
                        tt--;
                        if(da_dung[tt]==1)
                        {
                            if(tt==0) goto LOOPtt;
                            tt--;

                        }
                    }
                break;
            }
        case DOWN:
            {
                LOOPtt2:
                if(tt==n-1)
                {

                    tt=0;
                    if(da_dung[tt]==1) tt++;
                }
                    else
                    {
                        tt++;
                        if(da_dung[tt]==1)
                        {
                            if(tt==n-1) goto LOOPtt2;
                            tt++;
                        }
                    }
                break;
            }
        case ENTER:
            da_dung[tt]=1;
            return tt;
        }
        for(int i=0;i<n;i++)
        {

            mau[i]=MAUCHU;

            //strlwr(thaoTac[i]);
        }

        mau[tt]=MAUNEN;
         for(int i=0;i<5;i++)
         {
             if(da_dung[i]==1) mau[i]=12;
         }
        //strupr(thaoTac[tt]);


    }
}
//  TRỢ GIÚP:
        /* HỎI Ý KIẾN KHÁN GIẢ */
        int random(int minN, int maxN)
{
    return minN + rand() % (maxN + 1 - minN);
}
void troGiup_5050(int Dapan)
{
    int a[2];
    do
    {
        a[0]= random(0,3);
        a[1]= random(0,3);
    }
    while(a[0]==Dapan|| a[1]==Dapan|| a[0]==a[1]);
    clrscr();
    TEXT_AILATRIEUPHU();
    printf("\n\t\t\t\t\t\t\t\t\t | 2 ĐÁP ÁN SAI LÀ: ");

        switch(a[0])
        {
            case 0: printf(" A và ");
                    break;
            case 1: printf(" B và ");
                    break;
            case 2: printf(" C và ");
                    break;
            case 3: printf(" D và ");
                    break;
        }
        switch(a[1])
        {
            case 0: printf("A | ");
                    break;
            case 1: printf("B |");
                    break;
            case 2: printf("C |");
                    break;
            case 3: printf("D |");
                    break;
        }
        getch();

}
void goiDienThoai(int Dapan)
{
    int rand=random(50,100);
    printf("\n\n\n");
    setcolor(14);
    switch(Dapan)
    {
        case 0: printf("\t\t\t\t\t\t\t\t\tTôi nghĩ %d%c là phương án A!!!",rand,37);
                getch();
                break;
        case 1: printf("\t\t\t\t\t\t\t\t\t%d%c là phương án B rồi!",rand,37);
                getch();
                break;
        case 2: printf("\t\t\t\t\t\t\t\t\tTôi chắc %d%c là phương án C!!!",rand,37);
                getch();
                break;
        case 3: printf("\t\t\t\t\t\t\t\t\tTin tôi đi, %d%c là phương án D rồi đó. ",rand,37);
                getch();
                break;
    }
}
void  hoiYK_KhanGia(int Dapan)
{
	int a[4];
	a[Dapan]=random(30,100);
	int i=0;
	int tong=100-a[Dapan];
	while(i<2)
	{
		if(i==Dapan) i++;
		else {
				a[i]=random(0,tong);
			 	tong=tong-a[i];
			 	i++;
			 }
	}
	a[i]=tong;
	clrscr();
	TEXT_AILATRIEUPHU();
	setcolor(14);
	printf("\t\t\t\t\t\t\t\t\t BẠN ĐÃ CHỌN SỰ TRỢ GIÚP: HỎI Ý KIẾN KHÁN GIẢ TRONG TRƯỜNG QUAY\n");
	setcolor(11);
	printf("\n\t\t\t\t\t\t\t\t\t | ĐÁP ÁN A: %3d %c",a[0],37);
	printf("\n\t\t\t\t\t\t\t\t\t | ĐÁP ÁN B: %3d %c",a[1],37);
	printf("\n\t\t\t\t\t\t\t\t\t | ĐÁP ÁN C: %3d %c",a[2],37);
	printf("\n\t\t\t\t\t\t\t\t\t | ĐÁP ÁN D: %3d %c",a[3],37);
	setcolor(5);
	printf("\n\n\n\t\t\t\t\t\t\t\t\t ...BẤM PHÍM BẤT KỲ ĐỀ QUAY LẠI...");



}

//  HẾT TRỢ GIÚP
// CREAT MENU PLAY

int menu_PLAY(str thaoTac[5],int n,ALTP* question_now,int &k)
{   //LOOP_play: // bat dau lại
    int tt=0;
    int mau[n];
    int dap_an;
    //
                        printf("\t\t\t\t\t\t\t\t\t CHỌN SỰ TRỢ GIÚP");
                        //---------------------------------------------------------------------------------------------------
                        str help_play[5]={

                        "                                                                              | 50/50",
                        "                                                                              | GỌI ĐIỆN THOẠI CHO NGƯỜI THÂN",
                        "                                                                              | HỎI Ý KIẾN KHÁN GIẢ TRONG TRƯỜNG QUAY",
                        "                                                                              | DỪNG CUỘC CHƠI",
                        "                                                                              | QUAY LẠI"};
                        //------------------------------------------------------------------------------------------------------
    LOOP_play:
    for(int i=0;i<n;i++)
        mau[i]= MAUCHU;
    mau[0]= MAUNEN;
     if(strcmp(question_now->CH.DAn,"1\n")==0) dap_an=0;
     if(strcmp(question_now->CH.DAn,"2\n")==0) dap_an=1;
     if(strcmp(question_now->CH.DAn,"3\n")==0) dap_an=2;
     if(strcmp(question_now->CH.DAn,"4\n")==0) dap_an=3;
    while(1)
    {
        clrscr();
        setcolor(7);
        TEXT_AILATRIEUPHU();
        setcolor(7);
        printf("\t\t--------------------------------------------------------------------------");
        printf("CÂU HỎI SỐ: %d",k);
        printf("--------------------------------------------------------------------------\n");
        setcolor(11);
        printf("\t\t| TRỢ GIÚP: [PHÍM SPACE] \n");
        setcolor(7);
            if(da_dung[0]==1) setcolor(12);
            printf("\t\t- 50/50\n");
            setcolor(7);
            if(da_dung[1]==1) setcolor(12);
            printf("\t\t- GỌI ĐIỆN THOẠI CHO NGƯỜI THÂN");
            setcolor(7);
            printf("\t\t\t\t\t\t\t\t\t\t| ĐIỂM HIỆN TẠI: %d\n",money(k));
            setcolor(7);
            if(da_dung[2]==1) setcolor(12);
            printf("\t\t- HỎI Ý KIẾN KHÁN GIẢ TRONG TRƯỜNG QUAY");
            setcolor(7); printf("\t\t\t\t\t\t\t\t\t| SỐ TIỀN HIỆN TẠI: %d000 VNĐ\n",money_now(k));
            printf("\t\t- DỪNG CUỘC CHƠI");
        printf("\n\n\t\t\t\t\t\t\t\t");
        printf("%s\n\n",question_now->CH.CauHOi);
        //printf("                                                                                AI LÀ TRIỆU PHÚ!!! \n\n\n\n");
        for(int i=0;i<n;i++)
        {

            setcolor(mau[i]);
            printf("\t\t\t\t\t\t\t\t");
            cout<<thaoTac[i]<<endl;
        }
        int z= getch();
        TRANGTHAI trangthai=key(z);
        switch(trangthai)
        {
        case UP:
            {
                if(tt==0)
                {
                    tt=n-1;
                }
                    else tt--;
                break;
            }
        case DOWN:
            {
                if(tt==n-1)
                {

                    tt=0;
                }
                    else tt++;
                break;
            }
        case OPTIONS:
            switch(menu_troGiup(help_play,5))
            {
                case 0: //
                        troGiup_5050(dap_an);
                        //getch();
                        goto LOOP_play;
                        //goto LOOP_play;
                        break;
                case 1: //
                        {
                        clrscr();
                        //---------------------------------------------------------------------------------------------------
                        str menu_call[4]={

                        "                                                                              | Albert Einstein",
                        "                                                                              | Elon Musk",
                        "                                                                              | Shakespeare",
                        "                                                                              | Quay lại"};
                        //------------------------------------------------------------------------------------------------------
                        switch(menu(menu_call,4))
                        {
                            case 5: break;
                            default: goiDienThoai(dap_an);
                            goto LOOP_play;

                        }
                        //printf("\n\n\nUPDATING...");
                        //getch();
                        //goto LOOP_play;
                        break;
                        }
                case 2: //
                        {
                        hoiYK_KhanGia(dap_an);
                        getch();
                        goto LOOP_play;
                        break;
                        }
                case 3: //
                        {


                        clrscr();
                        setcolor(11);
                        printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t| BẠN ĐÃ CHỌN DỪNG CUỘC CHƠI, SỐ TIỀN BẠN NHẬN ĐƯỢC LÀ: %d000 VNĐ|",money_now(k));
                        top10player(player_name,money(k),money_now(k));

                        getch();
                        exit(0);
                        break;
                        }
                case 4: //printf("\n BACKKK");
                        //getch();
                        goto LOOP_play;
                        //getch();
                        break;
            }
            //break;
        case ENTER:
            boolean tra_loi=true;
            if(dap_an!=tt) tra_loi=false;

    // in lại màn hình, không cho chọn nữa

            if(tra_loi==true)
        {
            mau[tt]=14;

            clrscr();
            setcolor(7);
            TEXT_AILATRIEUPHU();
            setcolor(7);
            printf("\t\t--------------------------------------------------------------------------");
            printf("CÂU HỎI SỐ: %d",k);
            printf("--------------------------------------------------------------------------\n");
            setcolor(11);
            printf("\t\t| TRỢ GIÚP: [PHÍM SPACE] \n");
            setcolor(7);
            if(da_dung[0]==1) setcolor(12);
            printf("\t\t- 50/50\n");
            setcolor(7);
            if(da_dung[1]==1) setcolor(12);
            printf("\t\t- GỌI ĐIỆN THOẠI CHO NGƯỜI THÂN");
            setcolor(7);
            printf("\t\t\t\t\t\t\t\t\t\t| ĐIỂM HIỆN TẠI: %d\n",money(k));
            setcolor(7);
            if(da_dung[2]==1) setcolor(12);
            printf("\t\t- HỎI Ý KIẾN KHÁN GIẢ TRONG TRƯỜNG QUAY");
            setcolor(7);
             printf("\t\t\t\t\t\t\t\t\t| SỐ TIỀN HIỆN TẠI: %d000 VNĐ\n",money_now(k));

            printf("\t\t- DỪNG CUỘC CHƠI");
            printf("\n\n\t\t\t\t\t\t\t\t");
            printf("%s\n\n",question_now->CH.CauHOi);
            for(int i=0;i<n;i++)
            {

                setcolor(mau[i]);
                printf("\t\t\t\t\t\t\t\t");
                cout<<thaoTac[i]<<endl;
            }
            setcolor(11);
            printf("\t\t\t\t\t\t\t\t| TRẢ LỜI ĐÚNG, NHẤN PHÍM BẤT KỲ ĐỂ TIẾP TỤC |");

                        // kết thúc
                        getch();
    }
        else // KHI TRẢ LỜI SAI
        {
            mau[tt]=12;

            clrscr();
            setcolor(7);
            TEXT_AILATRIEUPHU();
            setcolor(7);
            printf("\t\t--------------------------------------------------------------------------");
            printf("CÂU HỎI SỐ: %d",k);
            printf("--------------------------------------------------------------------------\n");
            setcolor(11);
            printf("\t\t| TRỢ GIÚP: [PHÍM SPACE] \n");
            setcolor(7);
            setcolor(7);
            if(da_dung[0]==1) setcolor(12);
            printf("\t\t- 50/50\n");
            setcolor(7);
            if(da_dung[1]==1) setcolor(12);
            printf("\t\t- GỌI ĐIỆN THOẠI CHO NGƯỜI THÂN");
            setcolor(7);
             printf("\t\t\t\t\t\t\t\t\t| ĐIỂM HIỆN TẠI: %d\n",money(k));
            setcolor(7);
            if(da_dung[2]==1) setcolor(12);
            printf("\t\t- HỎI Ý KIẾN KHÁN GIẢ TRONG TRƯỜNG QUAY");
            setcolor(7);
            printf("\t\t\t\t\t\t\t\t| SỐ TIỀN HIỆN TẠI: %d000 VNĐ\n",money_now(k));
            printf("\t\t- DỪNG CUỘC CHƠI");
            printf("\n\n\t\t\t\t\t\t\t\t");
            printf("%s\n\n",question_now->CH.CauHOi);

            for(int i=0;i<n;i++)
            {

                setcolor(mau[i]);
                if(i==dap_an){
                    setcolor(14);
                    printf("\t\t\t\t\t\t\t\t");
                cout<<thaoTac[i]<<endl;
                setcolor(mau[i]);
                }
                else
                {
                     printf("\t\t\t\t\t\t\t\t");
                cout<<thaoTac[i]<<endl;
                }

            }
            setcolor(11);
            printf("\t\t\t\t\t\t\t\t| TRẢ LỜI SAI, SỐ TIỀN BẠN NHẬN ĐƯỢC LÀ: %d000 VNĐ|",money_now(k));
             getch();
             top10player(player_name,money(k),money_now(k));

                        // kết thúc
                        getch();

        }
              return tt;
        }
        for(int i=0;i<n;i++)
        {
            mau[i]=MAUCHU;
            //strlwr(thaoTac[i]);
        }

        mau[tt]=MAUNEN;
        //strupr(thaoTac[tt]);
    }
}
void rule_play()// xuất luật chơi
{
    clrscr();
    setcolor(7);
    TEXT_AILATRIEUPHU();
    setcolor(11);
    printf("\n                                                                              | LUẬT CHƠI |\n\n");
    setcolor(7);
    //printf("                                    Người chơi sẽ tham gia trả lời các câu hỏi từ dễ đến khó do chương trình đưa ra. Người chơi\n                               Người chơi sẽ tham gia trả lời các câu hỏi từ dễ đến khó do chương trình đưa ra. Người chơi\n                               không bị giới hạn thời gian suy nghĩ trả lời. Mỗi câu hỏi đều được gắn với một mức tiền thưởng \n                               quy định. Người chơi cần phải vượt qua 3 mốc quan trọng là câu số 5 (mốc quan trọng thứ \n                              nhất), câu số 10 (mốc quan trọng thứ hai) và câu số 15 (mốc TRIỆU PHÚ) mà khi vượt qua \n                               các mốc này, họ chắc chắn có được số tiền thưởng tương ứng của các câu hỏi đó.không bị giới hạn thời gian suy nghĩ trả lời. Mỗi câu hỏi đều được gắn với một mức tiền thưởng \n                                 quy định. Người chơi cần phải vượt qua 3 mốc quan trọng là câu số 5 (mốc quan trọng thứ \n                              nhất), câu số 10 (mốc quan trọng thứ hai) và câu số 15 (mốc TRIỆU PHÚ) mà khi vượt qua \n                               các mốc này, họ chắc chắn có được số tiền thưởng tương ứng của các câu hỏi đó.");
    printf("\t\t\t\tNgười chơi sẽ tham gia trả lời các câu hỏi từ dễ đến khó do chương trình đưa ra. Người chơi không bị giới hạn thời gian suy nghĩ trả lời");
    printf("\n\t\t\t\tMỗi câu hỏi đều được gắn với một mức tiền thưởng quy định. Người chơi cần phải vượt qua 3 mốc quan trọng là câu số 5 (mốc quan trọng ");
    printf("\n\t\t\t\tthứ nhất), câu số 10 (mốc quan trọng thứ hai) và câu số 15 (mốc TRIỆU PHÚ) mà khi vượt qua các mốc này, bạn sẽ có được số tiền thưởng");
    printf("\n\t\t\t\ttương ứng của các câu hỏi đó.");
    printf("\n\t\t\t\tNgười chơi có 3 sự trọ giúp là:");
    printf("\n\t\t\t\t\t – 50/50");
    printf("\n\t\t\t\t\t- Tổ tư vấn tại chỗ");
    printf("\n\t\t\t\t\t- Hỏi ý kiến khán giả trong trường quay");
    printf("\n\n\t\t\t\t\t | Nhấn ENTER để tiếp tục |");
}

void giaoDienChoi(list l)
{
    int i=0;
    ALTP* question_now= l.first;
    str menu_dapan[4];

    boolean tra_loi= true;
    while(tra_loi==true)
    {
    char edit_DanB[205]="| B: ";
    char edit_DanA[205]="| A: ";
    char edit_DanC[205]="| C: ";
    char edit_DanD[205]="| D: ";


    strcat(edit_DanA,question_now->CH.A);
    strcpy(menu_dapan[0],edit_DanA);

    strcat(edit_DanB,question_now->CH.B);
    strcpy(menu_dapan[1],edit_DanB);

    strcat(edit_DanC,question_now->CH.C);
    strcpy(menu_dapan[2],edit_DanC);

    strcat(edit_DanD,question_now->CH.D);
    strcpy(menu_dapan[3],edit_DanD);
    //printf("%s",question_now->CH.DAn);
    //printf("AAAA");
    i++;
    //clrscr();
    //TEXT_AILATRIEUPHU();
    switch(menu_PLAY(menu_dapan,4,question_now,i))
    {
        case 0: if(strcmp(question_now->CH.DAn,"1\n")!=0) tra_loi=false;
                //printf("Có thể chạy đến dòng này");
                break;
        case 1: if(strcmp(question_now->CH.DAn,"2\n")!=0) tra_loi=false;
                break;
        case 2: if(strcmp(question_now->CH.DAn,"3\n")!=0) tra_loi=false;
                break;
        case 3: if(strcmp(question_now->CH.DAn,"4\n")!=0) tra_loi=false;
                break;
    }

        question_now=question_now->link;
    }


}

void tao_DSLK(list &l, list &l1)
{
	int dem=0;
	ALTP *p=l1.first;
	int rand=3;
	while(dem<5)
    {
        rand= random(0,1);
        if(rand==1)
        {
            dem++;
            addlast(l,p->CH);
        }
        p=p->link;

    }
    xoa_DSLK(l1);
}
void playing_game(list l)
{
    //printf("\nStart");
	//LayFILE(l);
	giaoDienChoi(l);

	//XuatFile(l);

}
int new_game(list l)
{
    clrscr();
    setcolor(7);
    TEXT_AILATRIEUPHU();
    printf("                                                                              | NHẬP TÊN CỦA BẠN: ");
    setcolor(11);
    gets(player_name);
    playing_game(l);
}
// menu
// THÊM SỬA XOÁ

void them(char *linkfile)
{
	FILE *f;
	CauHoi cau;
	f=fopen(linkfile,"a");
	// cau hoi
	char khoa='3';
	while (khoa !='0')
	{
	    printf("NHẬP CÂU HỎI: ");
		setcolor(11);
		fflush(stdin);
		gets(cau.CauHOi);
        fflush(stdin);
		fprintf(f,"\n%s",cau.CauHOi);
		//a
		setcolor(7);
		printf("NHẬP ĐÁP ÁN A: ");
		setcolor(11);
		gets(cau.A);
		fflush(stdin);
		fprintf(f,"\n%s",cau.A);
		//b
		setcolor(7);
		printf("NHẬP ĐÁP ÁN B: ");
		setcolor(11);
		gets(cau.B);
		fflush(stdin);
		fprintf(f,"\n%s",cau.B);
		//c
		setcolor(7);
		printf("NHẬP ĐÁP ÁN C: ");
		setcolor(11);
		gets(cau.C);
		fflush(stdin);
		fprintf(f,"\n%s",cau.C);
		//d
		setcolor(7);
		printf("NHẬP ĐÁP ÁN D: ");
		setcolor(11);
		gets(cau.D);
		fflush(stdin);
		fprintf(f,"\n%s",cau.D);
		// dap an
		setcolor(7);
		printf("NHẬP ĐÁP ÁN ĐÚNG : ");
		setcolor(11);
		gets(cau.DAn);
		fflush(stdin);
		fprintf(f,"\n%s",cau.DAn);
		setcolor(14);
	 	printf("| NHẤN 0 ĐỂ DỪNG, PHÍM BẤT KỲ ĐỂ TIẾP TỤC : ");
	 	fflush(stdin);
		scanf("%c",&khoa);
	}
	fclose(f);
}
// SỬA
void Sua(char *linkfile) // nap vao list roi ghi lai vo file, ko ghi câu c?n xóa
{

	CauHoi x,cau;
	FILE *f;
	list l;
	init(l);
	LayFILE(l,linkfile);
	XuatFile(l);
	char i;
//	if(dem<suacau) ADDInFile(l,linkfile);
	//n?p l?i vào file
	int suacau;
	printf("NHẬP CÂU CẦN SỬA: ");
	scanf("%d",&suacau);
	fflush(stdin);
	int ret=remove(linkfile);
	f = fopen(linkfile,"w");
	ALTP *p;
	int dem=0;
	for(p=l.first;p!=NULL;p=p->link)
		{
			dem++;
			if(suacau!=dem+1)
				{
					fprintf(f,"%s",p->CH.CauHOi);
					fprintf(f,"%s",p->CH.A);
					fprintf(f,"%s",p->CH.B);
					fprintf(f,"%s",p->CH.C);
					fprintf(f,"%s",p->CH.D);
					fprintf(f,"%s",p->CH.DAn);
				}
			else
			{
				setcolor(7);
		printf("NHẬP CÂU HỎI: ");
		setcolor(11);
		fflush(stdin);
		gets(cau.CauHOi);
        fflush(stdin);
		fprintf(f,"%s",cau.CauHOi);
		//a
		setcolor(7);
		printf("NHẬP ĐÁP ÁN A: ");
		setcolor(11);
		gets(cau.A);
		fflush(stdin);
		fprintf(f,"\n%s",cau.A);
		//b
		setcolor(7);
		printf("NHẬP ĐÁP ÁN B: ");
		setcolor(11);
		gets(cau.B);
		fflush(stdin);
		fprintf(f,"\n%s",cau.B);
		//c
		setcolor(7);
		printf("NHẬP ĐÁP ÁN C: ");
		setcolor(11);
		gets(cau.C);
		fflush(stdin);
		fprintf(f,"\n%s",cau.C);
		//d
		setcolor(7);
		printf("NHẬP ĐÁP ÁN D: ");
		setcolor(11);
		gets(cau.D);
		fflush(stdin);
		fprintf(f,"\n%s",cau.D);
		// dap an
		setcolor(7);
		printf("NHẬP ĐÁP ÁN ĐÚNG : ");
		setcolor(11);
		gets(cau.DAn);
		fflush(stdin);
		fprintf(f,"\n%s\n",cau.DAn);
		setcolor(14);
	 	//printf("| NHẤN 0 ĐỂ DỪNG, PHÍM BẤT KỲ ĐỂ TIẾP TỤC |");
	 	//fflush(stdin);
		//scanf("%c",&khoa);
			}
		}
		xoa_DSLK(l);
	fclose(f);
}
    // XOÁ
void xoa(char *linkfile) // nap vao list roi ghi lai vo file, ko ghi câu c?n xóa
{
	CauHoi x,cau;
	int xoacau;
	FILE *f;
	list l;
	init(l);
	LayFILE(l,linkfile);
	XuatFile(l);
	printf("NHẬP CÂU CẦN XOÁ :");
	scanf("%d",&xoacau);
	xoacau++;
	fflush(stdin);
	//char i;
//	if(dem<xoacau) ADDInFile(l,linkfile);
	//n?p l?i vào file
	int ret=remove(linkfile);
	f = fopen(linkfile,"w");
	ALTP *p;
	int dem=0;
	for(p=l.first;p!=NULL;p=p->link)
		{
			dem++;
			if(xoacau !=dem)
				{
					fprintf(f,"%s",p->CH.CauHOi);
					fprintf(f,"%s",p->CH.A);
					fprintf(f,"%s",p->CH.B);
					fprintf(f,"%s",p->CH.C);
					fprintf(f,"%s",p->CH.D);
					fprintf(f,"%s",p->CH.DAn);
				}
		}
    xoa_DSLK(l);
	fclose(f);
}
// KẾT THÚC THÊM SỬA XOÁ

int howToPlay()
{
    clrscr();
    setcolor(7);
    printf("                                                                                  || bấm ENTER để trở lại MENU ||");
    printf("\n                                                                                HƯỚNG DẪN CHƠI GAME ");
    setcolor(11);
    printf("AI LÀ TRIỆU PHÚ\n\n\n\n");
    setcolor(7);
    printf("                                1/ Sử dụng phím UP (mũi tên hướng lên ) và DOWN (mũi tên hướng xuống) trên bàn phím để di chuyển. Nhấn ENTER để chọn.");
    printf("\n                                2/ Dùng các phím 1 2 và 3 để sử dụng những sự trợ giúp tương ứng. Mỗi lần chỉ được dùng 1 sự trợ giúp.");

    int c;
    do
    {
        c=getch();
    if(c==13) return ENTER;
    }
    while(c!=13);

}

int main()
{
    //---------------------------------------------------------------------------------------------------
    str admin[4]={

    "                                                                              | Thêm câu hỏi",
    "                                                                              | Sửa câu hỏi",
    "                                                                              | Xoá câu hỏi",
    "                                                                              | Quay lại"};
    //------------------------------------------------------------------------------------------------------
    //---------------------------------------------------------------------------------------------------
    str admin_1[4]={

    "                                                                              | Thêm câu hỏi mức dễ",
    "                                                                              | Thêm câu hỏi mức trung bình",
    "                                                                              | Thêm câu hỏi mức khó",
    "                                                                              | Quay lại"};
    //------------------------------------------------------------------------------------------------------
     str admin_2[4]={

    "                                                                              | Sửa câu hỏi mức dễ",
    "                                                                              | Sửa câu hỏi mức trung bình",
    "                                                                              | Sửa câu hỏi mức khó",
    "                                                                              | Quay lại"};
    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------
     str admin_3[4]={

    "                                                                              | Xoá câu hỏi mức dễ",
    "                                                                              | Xoá câu hỏi mức trung bình",
    "                                                                              | Xoá câu hỏi mức khó",
    "                                                                              | Quay lại"};
    //------------------------------------------------------------------------------------------------------
    SetConsoleOutputCP(65001);
    srand((int)time(0));
    resizecsl(100,50);
    for(int i=0;i<5;i++) da_dung[i]=0;
    settitle("AI LA TRIEU PHU");
    printf("LOANDING...");
    // TAO DSLK
    list l1,l2,l3;
    init(l1);
    init(l2);
    init(l3);
    LayFILE(l1,"D:\\KHA\\code\\TestTV\\cauhoi.txt");
    list l;
    init(l);
    tao_DSLK(l,l1);
    LayFILE(l2,"D:\\KHA\\code\\TestTV\\cauhoiTB.txt");
    tao_DSLK(l,l2);
    LayFILE(l3,"D:\\KHA\\code\\TestTV\\cauhoiKho.txt");
    tao_DSLK(l,l3);
    printf("DONE!");

        //menu(thaoTac,4);
    LOOP: // dung goto LOOP de quay lai vi tri nay
    switch(menu(thaoTac,5))
    {
    case 0: //
    //LayFILE(l,"D:\\KHA\\code\\TestTV\\cauhoiTB.txt");
    rule_play();
    getch();
    clrscr();
    new_game(l);
            break;
    case 1: //ADMIN                                                                              | ADMIN OPTIONS");
            LOOP2:
            switch(menu(admin,4)) // menu admin
                {
                    case 0: //them
                            switch(menu(admin_1,4))
                            {
                                case 0: //
                                        them("D:\\KHA\\code\\TestTV\\cauhoi.txt");
                                        printf("\n THÊM THÀNH CÔNG");
                                        getch();
                                        goto LOOP2;
                                        break;
                                case 1: //
                                        them("D:\\KHA\\code\\TestTV\\cauhoiTB.txt");
                                        printf("\n THÊM THÀNH CÔNG");
                                        getch();
                                        goto LOOP2;
                                        break;
                                case 2: //
                                        them("D:\\KHA\\code\\TestTV\\cauhoiKho.txt");
                                        printf("\n THÊM THÀNH CÔNG");
                                        getch();
                                        goto LOOP2;
                                        break;
                                case 3: //

                                        goto LOOP2;
                                        break;
                            }

                            break;
                    case 1: // sua
                             switch(menu(admin_2,4))
                            {
                                case 0: //
                                        clrscr();
                                        Sua("D:\\KHA\\code\\TestTV\\cauhoi.txt");
                                        goto LOOP2;
                                        //break;
                                case 1: //
                                        clrscr();
                                        //XuatFile(l2);
                                        Sua("D:\\KHA\\code\\TestTV\\cauhoiTB.txt");
                                         goto LOOP2;
                                        //break;
                                case 2: //
                                        clrscr();
                                        //XuatFile(l3);
                                        Sua("D:\\KHA\\code\\TestTV\\cauhoiKho.txt");
                                         goto LOOP2;
                                        //break;
                                case 3: //
                                        goto LOOP2;
                                        break;
                            }

                            break;
                    case 2: // xoa
                             switch(menu(admin_3,4))
                            {
                                case 0: //
                                        clrscr();
                                        //XuatFile(l1);
                                        xoa("D:\\KHA\\code\\TestTV\\cauhoi.txt");
                                        goto LOOP2;

                                        //break;
                                case 1: //
                                        clrscr();
                                        //XuatFile(l1);
                                        xoa("D:\\KHA\\code\\TestTV\\cauhoiTB.txt");
                                        goto LOOP2;
                                        //break;
                                case 2: //
                                        clrscr();
                                        XuatFile(l1);
                                        xoa("D:\\KHA\\code\\TestTV\\cauhoiKho.txt");
                                        goto LOOP2;
                                        //break;
                                case 3: //

                                        goto LOOP2;
                                        //break;
                            }

                            break;
                    case 3: //
                            goto LOOP;
                            break;



                }
            break;
    case 2: //
            //list_rank lr;
            //init_rank(lr);
           // LayFILE_rank(lr,"D:\\KHA\\code\\TestTV\\RANK.txt");
            XuatFile_rank();
            getch();
            //Top10Player(player_name,money(0),money_now(0));
            goto LOOP;


            break;
    case 3: //
            switch(howToPlay())
            {
                case ENTER: goto LOOP;
            }
            break;
    case 4:
            return 0;
    }
    //cout<<"sss";
    system("pause");
    return 0;
}
