#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>

#define RIGHT 100
#define DOWN 115
#define ENTER 13
#define FILENAME "./database.dat"
#define ESC 27
#define LEFT 97
#define UP 119

struct Data{
	int maCH,Correct;
	char cauHoi[255];
	char dapAnA[255];
	char dapAnB[255];
	char dapAnC[255];
	char dapAnD[255];
};
struct TNode{
	Data data;
	TNode *left,*right;
};
typedef TNode *TREE;
void FinishActivity(int point,TREE T);
void AddList(TREE &T);
void createBT(int x,int y,int width,char noidung[],bool key);
void taoManHinhFinish(int key,int point);
void OptionActivity(TREE &T);
void taoManHinhOption(int key);
void FixActivity(TREE &T);
TNode *SearchTNode(TREE T,int x);
void SaveGame(TREE &T,TNode *p,Data temp);
void recursive_Delete(TREE &T, int target);
TNode *GetTNode(Data dt){
	TNode *p = new TNode();
	p->data=dt;
	p->left = p->right=NULL;
	return p;
}
Data Init_data(int x){
	Data dt;
	dt.maCH =x;
	return dt;
}
void InsertTNode(TREE &T,TNode *p){
	if(T==NULL)
		T=p;
	else{
		if(p->data.maCH<T->data.maCH)
			return InsertTNode(T->left,p);
		else return InsertTNode(T->right,p);
	}
}
void xoaTrungTNode(TREE &T){
	if(T!=NULL){
		xoaTrungTNode(T->left);
		xoaTrungTNode(T->right);
		Data dt = T->data;
		recursive_Delete(T,T->data.maCH);
		if(SearchTNode(T,dt.maCH)==NULL)
			InsertTNode(T,GetTNode(dt));
	}
}
void LNR(TREE T){
	if(T==NULL)
		return;
	else
	{
		LNR(T->left);
		printf("|%-8d|%-80s|\n",T->data.maCH,T->data.cauHoi);
		LNR(T->right);
	}
}
void removeNode(TREE &T, int target) {
    TNode *pDel = T;
    if (T->left == NULL)
    {
        T = T->right;
    }
    else if (T->right == NULL)
    {
        T = T->left;
    }
    else
    {
        TNode *parent = pDel;
        pDel = pDel ->left;
        while (pDel->right != NULL)
        {
            parent = pDel;
            pDel = pDel->right;
        }
        T->data = pDel->data;
        if (parent == T)
        {
            parent->left = pDel->left;
        }
        else
        {
            parent->right = pDel->left;
        }
        delete pDel;
    }
    return;
}

void recursive_Delete(TREE &T, int target) {
    if (T == NULL)
        return ;
    else if (target < T->data.maCH)
    {
        return recursive_Delete(T->left, target);
    }
    else if (target > T->data.maCH)
    {
        return recursive_Delete(T->right, target);
    }
    else
    {
        removeNode(T, target);
    }
}
void docFile(TREE &T){
	Data dt;
	FILE *fp = fopen(FILENAME,"rb");
	if(fp==NULL){
		printf("Khong tim thay file!!!");
		exit(0);
	}
	while(!feof(fp)){
		fread(&dt,sizeof(Data),1,fp);
		InsertTNode(T,GetTNode(dt));
	}
	fclose(fp);
}

void ghiFile(TNode *p){
	Data dt; 
	FILE *fp = fopen(FILENAME,"ab");
	if(fp==NULL){
		printf("Khong tim thay file!!!");
		exit(0);
	}
	fwrite(&p->data,sizeof(struct Data),1,fp);
	fclose(fp);
	
}
void ghiTREE(TREE T){
	if(T!=NULL){
		ghiTREE(T->left);
		FILE *fp = fopen(FILENAME,"ab");
		if(fp==NULL){
			printf("Khong tim thay file!!!");
			exit(0);
		}
		fwrite(&T->data,sizeof(struct Data),1,fp);
		fclose(fp);
		ghiTREE(T->right);
	}

}
void updateFile(TREE T){
	FILE *fp = fopen(FILENAME,"wb");
	if(fp==NULL){
		printf("Khong tim thay file!!!");
		exit(0);
	}
	fclose(fp);
	ghiTREE(T);
}
int demTNode(TREE T){
	if(T==NULL)
		return 0;
	else{
		if(T->left!=NULL && T->right==NULL)
			return demTNode(T->left)+1;
		if(T->left==NULL && T->right!=NULL)
			return demTNode(T->right)+1;
		if(T->left!=NULL && T->right!=NULL)
			return demTNode(T->left) + demTNode(T->right)+1;
	}
}
void gotoxy(int x,int y){ //y xuong dong xa x*3 khoang trang
	for(int i=0;i<y;i++)
		printf("\n");
	for(int i=0;i<x;i++)
		printf("   "); // 3 khoang trang
}
void createBT(int x,int y,int width,char noidung[],bool key){
	//Tao nap button
	gotoxy(x,y);
	for(int i=0;i<width;i++)
		printf("___"); 
	//Tao noi dung button
	if(!key){ //Neu khong phai la key
		gotoxy(x,1);
		printf("|  %-*s  |",width*3-6,noidung);	
	}
	else{ //Neu la key  thi them ==> <==
		
		if(x==0){
			gotoxy(x,1);
			printf("|  %-*s  |<==",width*3-6,noidung);
		}
		else{
			gotoxy(x-1,1);
			printf("==>|  %-*s  |<==",width*3-6,noidung);
		}		
	}
	//Tao day button
	gotoxy(x,1);
	for(int i=0;i<width;i++)
	{	
		if(i==0) //Tao dau '|' dau
			printf("|__");
		else {
			if(i==width-1) // Tao dau '|' cuoi
				printf("__|");
			else
				printf("___");
		}	
	}		
}

void taoManHinhMenu(int key){
	system("cls");
	gotoxy(4,3);
	printf("AI LA TRIEU PHU");
	switch(key){
		case 0: //Khong co key nao
			createBT(4,4,5,"START",0);
			createBT(4,1,5,"OPTION",0);
			createBT(4,1,5,"QUIT",0);
			break;
		case 1: //Key nam o nut start
			createBT(4,4,5,"START",1);
			createBT(4,1,5,"OPTION",0);
			createBT(4,1,5,"QUIT",0);
			break;
		case 2: // Key nam o nut opption
			createBT(4,4,5,"START",0);
			createBT(4,1,5,"OPTION",1);
			createBT(4,1,5,"QUIT",0);
			break;
		case 3: // Key nam o nut quit
			createBT(4,4,5,"START",0);
			createBT(4,1,5,"OPTION",0);
			createBT(4,1,5,"QUIT",1);
			break;
				
	}
}
char *tinhTien(int point){
	switch(point){
		case 0:
			return "0";
		case 1:
			return "100.000 VND";
		case 2:
			return "200.000 VND";
		case 3:
			return "500.000 VND";
		case 4:
			return "1.000.000 VND";
		case 5:
			return "2.000.000 VND";
		case 6:
			return "5.000.000 VND";
		case 7:
			return "10.000.000 VND";
		case 8:
			return "20.000.000 VND";
		case 9:
			return "50.000.000 VND";
		case 10:
			return "100.000.000 VND";
		default:
			return 0;
	}
}
void taoManHinhGP(int key,TNode *boCH,int point){
	system("cls");
	
	//Tao cau hoi
	char a[255]="A. ";
	char b[255]="B. ";
	char c[255]="C. ";
	char d[255]="D. ";
	char *A = strcat(a,boCH->data.dapAnA);
	char *B = strcat(b,boCH->data.dapAnB);
	char *C = strcat(c,boCH->data.dapAnC);
	char *D = strcat(d,boCH->data.dapAnD);
	switch(key){
		case -1:
			createBT(2,0,5,"TRO GIUP",1);
			//Tao Title ai la trieu phu
			gotoxy(6,3);
			printf("AI LA TRIEU PHU");
			createBT(5,1,7,tinhTien(point),0);
			
			gotoxy(2,4);
			printf("Cau hoi %d: %s?",boCH->data.maCH,boCH->data.cauHoi);
			createBT(2,1,10,A,0);
			createBT(2,1,10,B,0);
			createBT(2,1,10,C,0);
			createBT(2,1,10,D,0);
			break;
		case 0:
			createBT(2,0,5,"TRO GIUP",0);
			//Tao Title ai la trieu phu
			gotoxy(6,3);
			printf("AI LA TRIEU PHU");
			createBT(5,1,7,tinhTien(point),0);
			
			gotoxy(2,4);
			printf("Cau hoi %d: %s?",boCH->data.maCH,boCH->data.cauHoi);
			createBT(2,1,10,A,0);
			createBT(2,1,10,B,0);
			createBT(2,1,10,C,0);
			createBT(2,1,10,D,0);
			break;
		case 1:
			createBT(2,0,5,"TRO GIUP",0);
			//Tao Title ai la trieu phu
			gotoxy(6,3);
			printf("AI LA TRIEU PHU");
			createBT(5,1,7,tinhTien(point),0);
			
			gotoxy(2,4);
			printf("Cau hoi %d: %s?",boCH->data.maCH,boCH->data.cauHoi);
			createBT(2,1,10,A,1);
			createBT(2,1,10,B,0);
			createBT(2,1,10,C,0);
			createBT(2,1,10,D,0);
			break;
		case 2:
			createBT(2,0,5,"TRO GIUP",0);
			//Tao Title ai la trieu phu
			gotoxy(6,3);
			printf("AI LA TRIEU PHU");
			createBT(5,1,7,tinhTien(point),0);
			
			gotoxy(2,4);
			printf("Cau hoi %d: %s?",boCH->data.maCH,boCH->data.cauHoi);
			createBT(2,1,10,A,0);
			createBT(2,1,10,B,1);
			createBT(2,1,10,C,0);
			createBT(2,1,10,D,0);
			break;
		case 3:
			createBT(2,0,5,"TRO GIUP",0);
			//Tao Title ai la trieu phu
			gotoxy(6,3);
			printf("AI LA TRIEU PHU");
			createBT(5,1,7,tinhTien(point),0);
			
			gotoxy(2,4);
			printf("Cau hoi %d: %s?",boCH->data.maCH,boCH->data.cauHoi);
			createBT(2,1,10,A,0);
			createBT(2,1,10,B,0);
			createBT(2,1,10,C,1);
			createBT(2,1,10,D,0);
			break;
		case 4:
			createBT(2,0,5,"TRO GIUP",0);
			//Tao Title ai la trieu phu
			gotoxy(6,3);
			printf("AI LA TRIEU PHU");
			createBT(5,1,7,tinhTien(point),0);
			
			gotoxy(2,4);
			printf("Cau hoi %d: %s?",boCH->data.maCH,boCH->data.cauHoi);
			createBT(2,1,10,A,0);
			createBT(2,1,10,B,0);
			createBT(2,1,10,C,0);
			createBT(2,1,10,D,1);
			break;
	}
}
int ngauNhien(int n){
	srand(time(NULL));
	return rand()%(n+1);
}
TNode *randomTNode(TREE &T){
	TNode *p=T;
	srand(time(NULL));
	int number;
	number= ngauNhien(demTNode(T));
		for(int i=0;i<number;i++){
			if(ngauNhien(10)%2==0){
				if(p->left!=NULL)
					p=p->left;
			}	
			else {
				if(p->right!=NULL)
					p=p->right;
			}
		}
	
	return p;
}
void CopyTree(TREE T,TREE &TT){
	if(T!=NULL){
		CopyTree(T->left,TT);
		InsertTNode(TT,GetTNode(T->data));
		CopyTree(T->right,TT);
	}
}

void GamePlayActivity(TREE T){ //Man hinh game play
	TREE TT=NULL;
	CopyTree(T,TT);
	system("cls");
	int point=0;
	int key=0;
	TNode *p=randomTNode(TT);
	taoManHinhGP(0,p,point);
	char c;
	int flag[]={0,0,0,0};
	do{
		c=getch();
		if(c==ENTER){
			if(key==p->data.Correct){
				if(point == 10)
				{
					system("cls");
					FinishActivity(point,T);
					return;
				}
				point++;
				recursive_Delete(TT,p->data.maCH);
				p=randomTNode(TT);
			}	
			else {
				if(key==-1){
					system("cls");
						createBT(0,0,5,"TRO LAI",0);
						gotoxy(6,2);
						printf("CAI DAT");
						if(flag[0]==1) createBT(4,4,10,"",0);
						else createBT(4,4,10,"50/50",0);
						if(flag[1]==1) createBT(4,1,10,"",0);
						else createBT(4,1,10,"Hoi y kien truong quay",0);
						if(flag[2]==1) createBT(4,1,10,"",0);
						else createBT(4,1,10,"Goi dien cho nguoi than",0);
						if(flag[3]==1) createBT(4,1,10,"",0);
						else createBT(4,1,10,"Doi cau hoi khac",0);
					char chon;
					int key2=0;
					
					do{
						chon = getch();
						if((chon==DOWN || chon==RIGHT)&& key2!=4 && key2!=-1)
							key2++;
						if((chon==DOWN || chon==RIGHT)&& key2==-1)
							key2+=2;
						if((chon==UP || chon==LEFT)&& key2>1)
							key2--; 
						else if((chon==UP || chon==LEFT)&& key2==1)
							key2-=2; 
						
						if(chon==ENTER){
							if(key2==-1)
								break;
							if(key2==1 && flag[0]==0){
								flag[0]=1;
								srand(time(NULL));
								int num[2];
								do{
									num[0] = 1+rand()%4;
									num[1] = 1+rand()%4;
								}while(num[0]==p->data.Correct || num[1]==p->data.Correct || num[1]==num[0]);
								for(int i=1;i<=4;i++){
									if(i==num[0] || i==num[1])
									switch(i){
										case 1:
											strcpy(p->data.dapAnA,"");
											break;
										case 2:
											strcpy(p->data.dapAnB,"");
											break;
										case 3:
											strcpy(p->data.dapAnC,"");
											break;
										case 4:
											strcpy(p->data.dapAnD,"");
											break;
									}
								}
								break;
							}
							
							if(key2==2 && flag[1]==0){
								system("cls");
								flag[1]=1;
								int num[]={10,12,6,9};
								for(int i=1;i<=4;i++){
									
									if(i!=p->data.Correct){
										switch(i){
											case 1:
												createBT(1,1,num[i],"Dap an A",0);
												break;
											case 2:
												createBT(1,1,num[i],"Dap an B",0);
												break;
											case 3:
												createBT(1,1,num[i],"Dap an C",0);
												break;
											case 4:
												createBT(1,1,num[i],"Dap an D",0);
												break;
										}
									}
									else{
										switch(i){
											case 1:
												createBT(1,1,15,"Dap an A",0);
												break;
											case 2:
												createBT(1,1,15,"Dap an B",0);
												break;
											case 3:
												createBT(1,1,15,"Dap an C",0);
												break;
											case 4:
												createBT(1,1,15,"Dap an D",0);
												break;
										}
									}	
								}
								getch();
								break;
							}
							if(key2==3 && flag[2]==0){
								system("cls");
								gotoxy(4,0);
								printf("KET NOI DIEN THOAI!!!");
							
								flag[2]=1;
								createBT(0,1,8,"Tit tit tit tit...",0);
								createBT(5,1,15,"Xin chao, toi den tu chuong trinh ALTP",0);
								createBT(0,1,16,"Xin chao, toi la giao su Phan Boi Chau!!!",0);
								createBT(0,1,11,"Toi co the giup gi cho ban?",0);
								createBT(5,1,15,"Giao su vui long giup toi cau hoi:",0);
								gotoxy(2,2);
								printf("=>|%s|<=",p->data.cauHoi);
								createBT(8,1,12,"Chung ta co 30s de trao doi!",0);
								switch(p->data.Correct){
									case 1:
										createBT(0,1,15,"Toi nghi rang dap an dung la: A",0);
										break;
									case 2:
										createBT(0,1,15,"Toi nghi rang dap an dung la: B",0);
										break;
									case 3:
										createBT(0,1,15,"Toi nghi rang dap an dung la: C",0);
										break;
									case 4:
										createBT(0,1,15,"Toi nghi rang dap an dung la: D",0);
										break;
								}
								createBT(0,1,9,"Chuc ban may man ^^",0);
								getch();
								break;
							}
							if(key2==4 && flag[3]==0){
								system("cls");
								flag[3]=1;
								recursive_Delete(TT,p->data.maCH);
								p=randomTNode(TT);
								break;
							}
							
						}
						switch(key2){
							case -1:
								system("cls");
								createBT(0,0,5,"TRO LAI",1);
								gotoxy(6,2);
								printf("CAI DAT");
								if(flag[0]==1) createBT(4,4,10,"",0);
								else createBT(4,4,10,"50/50",0);
								if(flag[1]==1) createBT(4,1,10,"",0);
								else createBT(4,1,10,"Hoi y kien truong quay",0);
								if(flag[2]==1) createBT(4,1,10,"",0);
								else createBT(4,1,10,"Goi dien cho nguoi than",0);
								if(flag[3]==1) createBT(4,1,10,"",0);
								else createBT(4,1,10,"Doi cau hoi khac",0);
								break;
							case 1:
								system("cls");
								createBT(0,0,5,"TRO LAI",0);
								gotoxy(6,2);
								printf("CAI DAT");
								if(flag[0]==1) createBT(4,4,10,"",1);
								else createBT(4,4,10,"50/50",1);
								if(flag[1]==1) createBT(4,1,10,"",0);
								else createBT(4,1,10,"Hoi y kien truong quay",0);
								if(flag[2]==1) createBT(4,1,10,"",0);
								else createBT(4,1,10,"Goi dien cho nguoi than",0);
								if(flag[3]==1) createBT(4,1,10,"",0);
								else createBT(4,1,10,"Doi cau hoi khac",0);
								break;
							case 2:
								system("cls");
								createBT(0,0,5,"TRO LAI",0);
								gotoxy(6,2);
								printf("CAI DAT");
								if(flag[0]==1) createBT(4,4,10,"",0);
								else createBT(4,4,10,"50/50",0);
								if(flag[1]==1) createBT(4,1,10,"",1);
								else createBT(4,1,10,"Hoi y kien truong quay",1);
								if(flag[2]==1) createBT(4,1,10,"",0);
								else createBT(4,1,10,"Goi dien cho nguoi than",0);
								if(flag[3]==1) createBT(4,1,10,"",0);
								else createBT(4,1,10,"Doi cau hoi khac",0);
								break;
							case 3:
								system("cls");
								createBT(0,0,5,"TRO LAI",0);
								gotoxy(6,2);
								printf("CAI DAT");
								if(flag[0]==1) createBT(4,4,10,"",0);
								else createBT(4,4,10,"50/50",0);
								if(flag[1]==1) createBT(4,1,10,"",0);
								else createBT(4,1,10,"Hoi y kien truong quay",0);
								if(flag[2]==1) createBT(4,1,10,"",1);
								else createBT(4,1,10,"Goi dien cho nguoi than",1);
								if(flag[3]==1) createBT(4,1,10,"",0);
								else createBT(4,1,10,"Doi cau hoi khac",0);
								break;
							case 4:
								system("cls");
								createBT(0,0,5,"TRO LAI",0);
								gotoxy(6,2);
								printf("CAI DAT");
								if(flag[0]==1) createBT(4,4,10,"",0);
								else createBT(4,4,10,"50/50",0);
								if(flag[1]==1) createBT(4,1,10,"",0);
								else createBT(4,1,10,"Hoi y kien truong quay",0);
								if(flag[2]==1) createBT(4,1,10,"",0);
								else createBT(4,1,10,"Goi dien cho nguoi than",0);
								if(flag[3]==1) createBT(4,1,10,"",1);
								else createBT(4,1,10,"Doi cau hoi khac",1);
								break;
						}
						
					}while(true);
					
				}
				else{
					system("cls");
					FinishActivity(point,T);
					return;	
				}	
			}
		}
		if((c==DOWN || c==RIGHT)&& key!=4 && key!=-1)
			key++;
		if((c==DOWN || c==RIGHT)&& key==-1)
			key+=2;
		if((c==UP || c==LEFT)&& key>1)
			key--; 
		else if((c==UP || c==LEFT)&& key==1)
			key-=2; 
		
		taoManHinhGP(key,p,point);
	}while(c!=ESC);
	
}
void MenuActivity(TREE &T){ // Man hinh menu
	int key=0;
	taoManHinhMenu(key);
	char c;
	do{
		c=getch();
		if(c==ENTER){
			if(key==1){
				GamePlayActivity(T);
				return;	
			}
			if(key==2)
			{
				OptionActivity(T);
				return;
			}
			if(key==3){
				system("cls");
				exit(0);
			}
		}
		if((c==DOWN || c==RIGHT)&& key!=3)
			key++;
		if((c==UP || c==LEFT)&& key>1)
			key--;
		taoManHinhMenu(key);
	}while(c!=ESC);
}
void FinishActivity(int point,TREE T){
	int key=0;
	taoManHinhFinish(key,point);
	char c;
	do{
		c=getch();
		if(c==ENTER){
			if(key==1){
				MenuActivity(T);
				return;	
			}
			if(key==2){
				system("cls");  
				exit(0);
			}
		}
		if((c==DOWN || c==RIGHT)&& key!=2)
			key++;
		if((c==UP || c==LEFT)&& key>1)
			key--;
		taoManHinhFinish(key,point);
	}while(c!=ESC);
	
}
void taoManHinhFinish(int key,int point){
	system("cls");
	gotoxy(4,4);
	printf("TONG SO TIEN DAT DUOC: %s",tinhTien(point));
	switch(key){
		case 0:
			createBT(6,4,5,"RESTART",0);
			createBT(6,1,5,"QUIT",0);
			break;
		case 1:
			createBT(6,4,5,"RESTART",1);
			createBT(6,1,5,"QUIT",0);
			break;
		case 2:
			createBT(6,4,5,"RESTART",0);
			createBT(6,1,5,"QUIT",1);
			break;
	}
}
int KiemTraTrungMa(TREE T,int x)
{
	TNode *p;
	p=T;
	while(p!=NULL)
	{
		if(p->data.maCH==x) return 0;
		if(p->data.maCH>x)
	 		p=p->left;
		else
			p=p->right;
	} 
	return 1;  
}
void OptionActivity(TREE &T){
	int key=-1;
	taoManHinhOption(key);
	char c;
	do{
		c=getch();
		if(c==ENTER){
			if(key==0){
				MenuActivity(T);
				return;	
			}
			if(key==1){
				AddList(T);
			}
			if(key==2){
				FixActivity(T);
				updateFile(T);
			}
			if(key==3){
				system("cls");
				printf("Nhap ma cau hoi can xoa: ");
				int ma;
				scanf("%d",&ma);
				recursive_Delete(T,ma);
				updateFile(T);
				printf("\nRemove question successfully!!!");
				getch();
				
			}
			if(key==4){
				system("cls");
				printf("__________________________________________________________________________________________\n");
				printf("|%-8s|%-80s|\n","Ma CH","Noi dung cau hoi");
				printf("__________________________________________________________________________________________\n");
				LNR(T);
				printf("__________________________________________________________________________________________\n");
				getch();
			}
		}
		if(c==DOWN || c==RIGHT){
			if(key==-1)
				key=1;
			else if(key != 4)
				key++;
		}
		
		if((c==UP || c==LEFT)&& key>0)
			key--;
		taoManHinhOption(key);
	}while(c!=ESC);
}
void taoManHinhOption(int key){
	system("cls");
	switch(key){
		case -1:
			createBT(0,0,5,"TRO LAI",0);
			gotoxy(6,2);
			printf("CAI DAT");
			createBT(4,4,6,"THEM CAU HOI",0);
			createBT(4,1,6,"SUA CAU HOI",0);
			createBT(4,1,6,"XOA CAU HOI",0);
			createBT(4,1,6,"DANH SACH",0);
			break;
		case 0:
			createBT(0,0,5,"TRO LAI",1);
			gotoxy(6,2);
			printf("CAI DAT");
			createBT(4,4,6,"THEM CAU HOI",0);
			createBT(4,1,6,"SUA CAU HOI",0);
			createBT(4,1,6,"XOA CAU HOI",0);
			createBT(4,1,6,"DANH SACH",0);
			break;
		case 1:
			createBT(0,0,5,"TRO LAI",0);
			gotoxy(6,2);
			printf("CAI DAT");
			createBT(4,4,6,"THEM CAU HOI",1);
			createBT(4,1,6,"SUA CAU HOI",0);
			createBT(4,1,6,"XOA CAU HOI",0);
			createBT(4,1,6,"DANH SACH",0);
			break;
		case 2:
			createBT(0,0,5,"TRO LAI",0);
			gotoxy(6,2);
			printf("CAI DAT");
			createBT(4,4,6,"THEM CAU HOI",0);
			createBT(4,1,6,"SUA CAU HOI",1);
			createBT(4,1,6,"XOA CAU HOI",0);
			createBT(4,1,6,"DANH SACH",0);
			break;
		case 3:
			createBT(0,0,5,"TRO LAI",0);
			gotoxy(6,2);
			printf("CAI DAT");
			createBT(4,4,6,"THEM CAU HOI",0);
			createBT(4,1,6,"SUA CAU HOI",0);
			createBT(4,1,6,"XOA CAU HOI",1);
			createBT(4,1,6,"DANH SACH",0);
			break;
		case 4:
			createBT(0,0,5,"TRO LAI",0);
			gotoxy(6,2);
			printf("CAI DAT");
			createBT(4,4,6,"THEM CAU HOI",0);
			createBT(4,1,6,"SUA CAU HOI",0);
			createBT(4,1,6,"XOA CAU HOI",0);
			createBT(4,1,6,"DANH SACH",1);
			break;
	}	
}
void AddList(TREE &T){
	system("cls");
	TNode *p = new TNode();
	
	printf("Ma Cau Hoi(number): ");
	do{	
		scanf("%d",&p->data.maCH);
		if(KiemTraTrungMa(T,p->data.maCH)==0)
			printf("\nTrung Ma!!!\nNhap lai Ma Cau Hoi khac: ");
		else break;
	}while(true);
	printf("\nNoi dung cau hoi: ");
	fflush(stdin);
	gets(p->data.cauHoi);
	printf("\nDap an A: ");
	fflush(stdin);
	gets(p->data.dapAnA);
	if(strlen(p->data.dapAnA)>30){
		do{
			printf("\nDo dai qua muc cho phep (30 ki tu)!!!: ");
			gets(p->data.dapAnA);
		}while(strlen(p->data.dapAnA)>30);
	}
	printf("\nDap an B: ");
	fflush(stdin);
	gets(p->data.dapAnB);
	if(strlen(p->data.dapAnB)>30){
		do{
			printf("\nDo dai qua muc cho phep (30 ki tu)!!!: ");
			gets(p->data.dapAnB);
		}while(strlen(p->data.dapAnB)>30);
	}
	printf("\nDap an C: ");
	fflush(stdin);
	gets(p->data.dapAnC);
	if(strlen(p->data.dapAnC)>30){
		do{
			printf("\nDo dai qua muc cho phep (30 ki tu)!!!: ");
			gets(p->data.dapAnC);
		}while(strlen(p->data.dapAnC)>30);
	}
	printf("\nDap an D: ");
	fflush(stdin);
	gets(p->data.dapAnD);
	if(strlen(p->data.dapAnD)>30){
		do{
			printf("\nDo dai qua muc cho phep (30 ki tu)!!!: ");
			gets(p->data.dapAnD);
		}while(strlen(p->data.dapAnD)>30);
	}
	printf("\nDap an dung(1->4): ");
	do{
		scanf("%d",&p->data.Correct);
		if(p->data.Correct<=4 && p->data.Correct>0)
			break;
		else	printf("\nNhap sai!!!");
	}while(true);
	system("cls");
	gotoxy(4,3);
	printf("SAVE");
	createBT(3,3,3,"YES",0);
	createBT(3,1,3,"NO",0);
	int key=0;
	char c;
	do{
		c=getch();
		if((c==DOWN || c==RIGHT)&&key!=2)
			key++;
		if((c==UP || c==LEFT)&&key!=1)
			key--;
		if(c==ENTER){
			if(key==1){
				InsertTNode(T,p);
				ghiFile(p);
			}
			OptionActivity(T);
			return;
		}
		switch(key){
			case 1:
				system("cls");
				gotoxy(4,3);
				printf("SAVE");
				createBT(3,3,3,"YES",1);
				createBT(3,1,3,"NO",0);
				break;
			case 2:
				system("cls");
				gotoxy(4,3);
				printf("SAVE");
				createBT(3,3,3,"YES",0);
				createBT(3,1,3,"NO",1);
				break;
		}
	}while(true);
	
}
TNode *SearchTNode(TREE T,int x){
	if(T==NULL) return NULL;
	if(T->data.maCH==x) 
		return T;
	if(T->data.maCH>x) 
		return SearchTNode(T->left,x);
	else
		return SearchTNode(T->right,x);
}
void taoManHinhFix(TREE T,TNode *boCH,int key){
	system("cls");
	
	//Tao cau hoi
	char a[255]="A. ";
	char b[255]="B. ";
	char c[255]="C. ";
	char d[255]="D. ";
	char *A = strcat(a,boCH->data.dapAnA);
	char *B = strcat(b,boCH->data.dapAnB);
	char *C = strcat(c,boCH->data.dapAnC);
	char *D = strcat(d,boCH->data.dapAnD);
	
	switch(key){
		case -1: 
			createBT(0,0,5,"TRO VE",1);
			gotoxy(4,4);
			printf("Cau hoi %d: %s",boCH->data.maCH,boCH->data.cauHoi);
			createBT(4,1,10,A,0);
			createBT(4,1,10,B,0);
			createBT(4,1,10,C,0);
			createBT(4,1,10,D,0);
			gotoxy(4,1);
			printf("Dap dung la(1->4): %d",boCH->data.Correct);
			break;
		case 0: 
			createBT(0,0,5,"TRO VE",0);
			gotoxy(3,4);
			printf("==>Cau hoi %d: %s",boCH->data.maCH,boCH->data.cauHoi);
			createBT(4,1,10,A,0);
			createBT(4,1,10,B,0);
			createBT(4,1,10,C,0);
			createBT(4,1,10,D,0);
			gotoxy(4,1);
			printf("Dap dung la(1->4): %d",boCH->data.Correct);
			break;
		case 1: 
			createBT(0,0,5,"TRO VE",0);
			gotoxy(4,4);
			printf("Cau hoi %d: %s",boCH->data.maCH,boCH->data.cauHoi);
			createBT(4,1,10,A,1);
			createBT(4,1,10,B,0);
			createBT(4,1,10,C,0);
			createBT(4,1,10,D,0);
			gotoxy(4,1);
			printf("Dap dung la(1->4): %d",boCH->data.Correct);
			break;
		case 2: 
			createBT(0,0,5,"TRO VE",0);
			gotoxy(4,4);
			printf("Cau hoi %d: %s",boCH->data.maCH,boCH->data.cauHoi);
			createBT(4,1,10,A,0);
			createBT(4,1,10,B,1);
			createBT(4,1,10,C,0);
			createBT(4,1,10,D,0);
			gotoxy(4,1);
			printf("Dap dung la(1->4): %d",boCH->data.Correct);
			break;
		case 3: 
			createBT(0,0,5,"TRO VE",0);
			gotoxy(4,4);
			printf("Cau hoi %d: %s",boCH->data.maCH,boCH->data.cauHoi);
			createBT(4,1,10,A,0);
			createBT(4,1,10,B,0);
			createBT(4,1,10,C,1);
			createBT(4,1,10,D,0);
			gotoxy(4,1);
			printf("Dap dung la(1->4): %d",boCH->data.Correct);
			break;
		case 4:	
			createBT(0,0,5,"TRO VE",0);
			gotoxy(4,4);
			printf("Cau hoi %d: %s",boCH->data.maCH,boCH->data.cauHoi);
			createBT(4,1,10,A,0);
			createBT(4,1,10,B,0);
			createBT(4,1,10,C,0);
			createBT(4,1,10,D,1);
			gotoxy(4,1);
			printf("Dap dung la(1->4): %d",boCH->data.Correct);
			break;
		case 5:
			createBT(0,0,5,"TRO VE",0);
			gotoxy(4,4);
			printf("Cau hoi %d: %s",boCH->data.maCH,boCH->data.cauHoi);
			createBT(4,1,10,A,0);
			createBT(4,1,10,B,0);
			createBT(4,1,10,C,0);
			createBT(4,1,10,D,0);
			gotoxy(3,1);
			printf("==>Dap dung la(1->4): %d",boCH->data.Correct);
			break;
	}
}

void FixActivity(TREE &T){
	system("cls");
	int key=-1;
	int macauhoi;
	printf("Ma cau hoi muon sua: ");
	do{
		scanf("%d",&macauhoi);
		if(KiemTraTrungMa(T,macauhoi)==1)
			printf("Ma khong ton tai!!!\nNhap lai: ");
		else break;
	}while(true);
	
	TNode *p = SearchTNode(T,macauhoi);
	Data temp = p->data;
	//p->data=boCH->data;
	taoManHinhFix(T,p,key);
	char c;
	do{
		c=getch();
		if(c==ENTER){
			if(key==-1){
				break;
			}
			if(key==0){
				system("cls");
				printf("Noi dung cau hoi muon sua: ");
				fflush(stdin);
				gets(p->data.cauHoi);
			}
			if(key==1)
			{
				system("cls");
				printf("Sua lai dap an A: ");
				fflush(stdin);
				gets(p->data.dapAnA);
			}
			if(key==2){
				system("cls");
				printf("Sua lai dap an B: ");
				fflush(stdin);
				gets(p->data.dapAnB);
			}
			if(key==3){
				system("cls");
				printf("Sua lai dap an C: ");
				fflush(stdin);
				gets(p->data.dapAnC);
			}
			if(key==4){
				system("cls");
				printf("Sua lai dap an D: ");
				fflush(stdin);
				gets(p->data.dapAnD);
			}
			if(key==5){
				system("cls");
				printf("Sua lai dap an dung: ");
				fflush(stdin);
				scanf("%d",&p->data.Correct);
			}
		}
		if((c==DOWN || c==RIGHT) && key!=5)
			key++;
		if((c==UP || c==LEFT)&& key>-1)
			key--;
		taoManHinhFix(T,p,key);
	}while(c!=ESC);
	//p->data.maCH=517;
	SaveGame(T,p,temp);
}

void SaveGame(TREE &T,TNode *p,Data temp){
	system("cls");
	gotoxy(4,3);
	printf("SAVE");
	createBT(3,3,3,"YES",0);
	createBT(3,1,3,"NO",0);
	int key=0;
	char c;
	do{
		c=getch();
		if((c==DOWN || c==RIGHT)&&key!=2)
			key++;
		if((c==UP || c==LEFT)&&key!=1)
			key--;
		if(c==ENTER){
			if(key==1){
				InsertTNode(T,GetTNode(p->data));
				recursive_Delete(T,p->data.maCH);
				updateFile(T);
			}
			else{
				p->data=temp;
			}
				
			OptionActivity(T);
			return;
		}
		switch(key){
			case 1:
				system("cls");
				gotoxy(4,3);
				printf("SAVE");
				createBT(3,3,3,"YES",1);
				createBT(3,1,3,"NO",0);
				break;
			case 2:
				system("cls");
				gotoxy(4,3);
				printf("SAVE");
				createBT(3,3,3,"YES ",0);
				createBT(3,1,3,"NO",1);
				break;
		}
	}while(true);	
	
}
int main()
{
	TREE T=NULL;
	docFile(T);
	xoaTrungTNode(T);
	MenuActivity(T);
	return 0;
}
