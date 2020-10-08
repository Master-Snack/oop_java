#include <bits/stdc++.h>
using namespace std;
//#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>
#include <iostream>
//#include <conio.h>
#include <Windows.h>
//#include <string.h>
#include <stdlib.h>
#define cao 25
#define rong 118

typedef struct Mean{
	string meanname;
	string exam[10];
}Mean ;
typedef struct Loai{
	string tentuloai;
	Mean mean[10];
} Loai;
typedef struct Word
{
	string wordname;
	Loai Tuloai[10];
	string cachdoc;
	string cachvietkhac;
}Word;

typedef struct Node{
	Word data;
	Node* left;
	Node* right;
}Node;
typedef struct Node * Tree;
//===================== 		GIAO DIEN		=========================
struct Chaychu{
	char s[31];
	int x, y; //y tung x hoanh
};

void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}
void gotoxy(int x, int y)
{
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
}
void xuatchuchay(string a){
	for(int i=0;i<a.length();i++){
		cout << a[i];
		Sleep(50);
	}
	cout<<endl;
 }
void GDmodau(){
	Chaychu C;
	gotoxy(rong/3+2, 10);
	textcolor(12);
	xuatchuchay("Welcome to English-Vietnamese Dictionary");
	Sleep(600);
	system("cls");
	
	
	textcolor(14);
	
	gotoxy(118/4,cao/4-5);
	cout<<"-------------------------------------------------------------\n";
	char a[40]="|       Tu Dien Anh Viet       |";

	//strcpy(C.s, a);
	
	//---------tu dien
	C.x=(rong - strlen(a))/2;
	C.y=cao/2;
	gotoxy(C.x, C.y-9);
	cout<<"+------------------------------+"<<endl;
	C.y++;
	gotoxy(C.x, C.y-9);
	cout<<a<<endl;
	C.y++;
	gotoxy(C.x, C.y-9);
	cout<<"+------------------------------+"<<endl;
	
	gotoxy(118/4,cao/4+1);
	cout<<"-------------------------------------------------------------";
	
	//----------
	textcolor(7);
	
	C.y=cao/4+1;
	//C.y++;
	gotoxy(118/4+24,C.y+1);
	
	textcolor(11);
	xuatchuchay("CHUC NANG");
	
	textcolor(10);
	
	//C.y++;
	gotoxy(118/4,C.y+3);
	xuatchuchay("1.Tra tu");
	//C.y++;
	gotoxy(118/4,C.y+5);
	xuatchuchay("2.Them tu");
	
	//C.y++;
	gotoxy(118/4,C.y+7);
	xuatchuchay("3.Sua tu");
	
	//C.y++;
	gotoxy(118/4,C.y+9);
	xuatchuchay("4.Xoa tu");
	
	gotoxy(118/4,C.y+11);
	xuatchuchay("5.Xem lich su tim kiem");
	
	//C.y++;
	gotoxy(118/4,C.y+13);
	xuatchuchay("Moi ban nhap yeu cau.");
	
	gotoxy(100,27);
	textcolor(15);
	cout<<"0.De thoat";
	//--------------------------
	
	//--------------------------
	cout<<endl;

}
 
void GDmenukhongdong(){
	
	Chaychu C;
	textcolor(14);
	
	gotoxy(118/4,cao/4-5);
	cout<<"-------------------------------------------------------------\n\n";
	
	char a[40]="|       Tu Dien Anh Viet       |";

	//strcpy(C.s, a);
	
	//---------tu dien
	C.x=(rong - strlen(a))/2;
	C.y=cao/2+1;
	gotoxy(C.x, C.y-10);
	cout<<"+------------------------------+"<<endl;
	C.y++;
	gotoxy(C.x, C.y-10);
	cout<<a<<endl;
	C.y++;
	gotoxy(C.x, C.y-10);
	cout<<"+------------------------------+"<<endl;
	
	gotoxy(118/4,cao/4+1);
	cout<<"-------------------------------------------------------------";
	
	//----------
	textcolor(7);
	
	C.y=cao/4+1;
	//C.y++;
	gotoxy(118/4+24,C.y+1);
	
	textcolor(11);
	cout<< "CHUC NANG";
	
	textcolor(10);
	
	//C.y++;
	gotoxy(118/4,C.y+3);
	cout<<"1.Tra tu";
	//C.y++;
	gotoxy(118/4,C.y+5);
	cout<<"2.Them tu";
	
	//C.y++;
	gotoxy(118/4,C.y+7);
	cout<<"3.Sua tu";
	
	//C.y++;
	gotoxy(118/4,C.y+9);
	cout<<"4.Xoa tu";
	
	gotoxy(118/4,C.y+11);
	cout<< "5.Xem lich su tim kiem";
	
	//C.y++;
	gotoxy(118/4,C.y+13);
	cout<<"Moi ban nhap yeu cau.";
	
	gotoxy(100,27);
	textcolor(15);
	cout<<"0.De thoat";
	
	cout<<endl;
	
} 

//void GDmenu(int &k){	
//		char key;	
//		key=_getch();
//		textcolor(15);
//		Chaychu C;
//		C.y=cao/4;
//		if(key=='0'){
//			gotoxy(100,25);
//			cout<<"0.De thoat";
//			k=0;
//			return;
//		}	
//		if(key=='1'){
//			gotoxy(118/4,C.y+3);
//			cout<<"1.Tra tu";
//			k=1;
//			return;
//		}
//		if(key=='2'){
//			gotoxy(118/4,C.y+5);
//			cout<<"2.Them tu";
//			k=2;
//			return;
//		}
//		if(key=='3'){
//		gotoxy(118/4,C.y+7);
//		cout<<"3.Sua tu";
//		k=3;
//		return;
//		}
//		if(key=='4'){
//			gotoxy(118/4,C.y+9);
//			cout<<"4.Xoa tu";
//			k=4;
//			return;
//		}
//		else k=10;
//		Sleep(350);			
//}






//=========================================

void xuattungtuloai(Word w, string tentuloai){
	int i=1, j=1 , k=1;
	
	cout << "*Ten tu: " << w.wordname << endl;
	cout << "*Cach doc: " << w.cachdoc << endl;
	if(w.cachvietkhac.compare("")!=0){
			cout<< "\t~Cach viet khac" << w.cachvietkhac <<endl;
	}
		
	while(w.Tuloai[i].tentuloai!= tentuloai) i++;//tim kiem tu loai can xuat
	
		cout << "\t\t+Tu loai: " <<w.Tuloai[i].tentuloai << endl;
		cout<< "-Nghia cua tu loai:" <<endl;
		while((w.Tuloai[i].mean[j].meanname.compare(""))!=0 ){
			k=1;
			cout<< "\t." <<w.Tuloai[i].mean[j].meanname <<endl;
			while((w.Tuloai[i].mean[j].exam[k].compare(""))!=0){
				cout<< "\t   VD " << k << ": " << w.Tuloai[i].mean[j].exam[k] <<endl;
				k++;
			}
			
			j++;
		}
	cout << endl;	
}

Node* getnode(Word x){
	Node* p= new Node;
	if(p==NULL) return NULL;
	p->data=x;
	p->left=NULL;
	p->right=NULL;
	return p;
}

void AddWord(Tree &t,Word x ){
	if(t!=NULL){
		if(t->data.wordname==x.wordname){
			return;
		}
		if(t->data.wordname > x.wordname) 
			AddWord(t->left, x);
		else AddWord(t->right,x);
	}
	else{
		Node *p= new Node;
		p->data=x;
		p->left=p->right=NULL;
		t=p;
	}	
}

Node* search(Tree root, string x){
	Node* p=root;
	
    while(p!=NULL)
    {
    	if(x==p->data.wordname){
    		return p;
		}
    		
    	if(p->data.wordname<x)
			p=p->right;
		else if(x<p->data.wordname)
			p=p->left;
	}
	return NULL;
}

void ghi1tuvaofile(Node *t){
	int i=0, j=0, k=0;
	ofstream fileout;
	fileout.open("D:/test1.txt", ios::app);	
	
	//Ghivaofile(t->left);
	
	fileout << "@" << t->data.wordname <<endl;
	if(t->data.cachdoc!="")
		fileout << t->data.cachdoc <<endl;
		
	if(t->data.cachvietkhac.compare("")!=0)
	
			fileout<< t->data.cachvietkhac<<endl;
	
	for(i=1; i<7; i++){
		if(t->data.Tuloai[i].tentuloai!=""){
			
			fileout << "   *" <<t->data.Tuloai[i].tentuloai<<endl;
		}
		
		for(j=1; j<7;j++){
			if(t->data.Tuloai[i].mean[j].meanname!="")
				fileout<< "      -" <<t->data.Tuloai[i].mean[j].meanname<<endl;

			for(k=1;k<7;k++){
				if(t->data.Tuloai[i].mean[j].exam[k]!="")
					fileout<< "\t=$" << k << ": " << t->data.Tuloai[i].mean[j].exam[k] <<endl;
			}
		}
		
	}
	
	//Ghivaofile(t->right);
	

	//cout<<"them vao file!"<<endl;
}

 
void ghicayvaofile(Tree root){
	
	ghicayvaofile(root->right);
	ghi1tuvaofile(root);
	ghicayvaofile(root->left);
	
}
void docfile(Tree &root){
	
	Word w, g ;
	string a;
	int t=0, stl=0, sn=0, svd=0,flag=0;
	ifstream filein;
	filein.open("new.txt");
	if(filein.fail()== true ){
		cout<< "loi doc file :))\n";
		return;
	} 	
	string tach="", tam="";
	while(!filein.eof()){
	while(!filein.eof()){
		//filein.ignore();
		t=0;
		if(tam=="")
			getline(filein, a);
		else if(tam!=""){
			w.wordname=tam;
			tam="";
			//getline(filein, a);
		}
		//=========		ham bo di khoang trang doc file 		==================
		if(a[t]==' '){
			while(a[t]==' '){
				t++;
			}
			while(t!= a.length()){
				tach+=a[t];
				t++;
			
			}
			a=tach;
			t=0;
			tach="";
		}
		//				wordname
		if(a[t]=='@'){
			flag++;
			//=======		kiem tra neu doc toi tu tiep theo se nhap tu truoc vao cay		========
			if(flag>1){
				
				stl=0; svd=0; sn=0;
				flag=0;
				t++;
				while(t!=a.length()){
					tach+=a[t];
					t++;
				}
				tam= tach;
				tach="";
				break;
			}
			t++;
			while(t!=a.length()){
				tach+=a[t];
				t++;
			}
			w.wordname= tach;
			tach="";
			t=0;
		}
		//		cach doc
		if(a[t]=='['){
			while(t!=a.length()){
				tach+=a[t];
				t++;
			}
			w.cachdoc +=" ";
			w.cachdoc += tach;
			tach="";
			t=0;
		}
		
		//		tu loai
		if(a[t]=='*'){
			t++;
			stl++;
			sn=0;
			while(t!=a.length()){
				tach+=a[t];
				t++;
			}
			w.Tuloai[stl].tentuloai = tach;
			t=0;
			tach="";
		}
		
		else if(a[t]=='-'){
			t++;
			svd=0;
			sn++;
			while(t!=a.length()){
				tach+=a[t];
				t++;
			}
			w.Tuloai[stl].mean[sn].meanname= tach;
			//t=0;
			tach="";
		}
		
		else if((a[t]=='='||a[t]=='!')){
			svd++;
			t+=2;
			while(t!=a.length()){
				tach+=a[t];
				t++;
			}
			w.Tuloai[stl].mean[sn].exam[svd]= tach;
			//t==0;
			tach="";
		}
		//====			cai nay con loi 	*****
		else if(a[t]=='~'){
			while(t!=a.length()){
				if(a[t] != '$' && a[t]!= '~' && a[t]!= '+')
					tach += a[t];
				t++;
			}
			
			w.cachvietkhac+=tach;
			w.cachvietkhac+="    ";
			tach="";
		}
		a="";
	}
	AddWord(root, w);
	w=g;
	}
	filein.close();
	
}

void xuattuloai(Word w){
	int dem=0;
	textcolor(11);
	for(int i=0; i< 10; i++){
		if(w.Tuloai[i].tentuloai!="") {
			cout << "\t\t+Tu loai: " <<w.Tuloai[i].tentuloai << endl;
			dem++;
		}
		
	}
	textcolor(9);
	if(dem==0) cout<<"chua cap nhat tu loai\n";
}

void xuatNgia(Word w){
	int dem=0;
	textcolor(11);
	for(int i=0; i< 10; i++){
		
		for(int j=0;j<10;j++){
			if(w.Tuloai[i].mean[j].meanname!=""){
				cout<< "\t." <<w.Tuloai[i].mean[j].meanname <<endl;
				dem++;
			}
			
		}
	}
	textcolor(9);
	if(dem==0) cout<<"Chua cap nhat nghia\n";
}

void xuatexam(Word w){
	int dem=0;
	textcolor(11);
	for(int i=0; i< 10; i++){
	
		for(int j=0;j<10;j++){
		
			for(int k=1;k<10;k++){
				if(w.Tuloai[i].mean[j].exam[k]!=""){
					cout<< "\t   VD " << ": " << w.Tuloai[i].mean[j].exam[k] <<endl;
					dem++;
				}
					
				
			}
		}
		
	}
	if(dem==0) cout<<"khong co vi du\n";
}

void xuat1tu(Word w){
	int i, j ,k ;
	textcolor(11);
	cout << "*Ten tu: " << w.wordname << endl;
	if(w.cachdoc!="")
		cout << "*Cach doc: " << w.cachdoc << endl;
	if(w.cachvietkhac.compare("")!=0){
			cout<< "\t" << w.cachvietkhac <<endl;
		}
	for(int i=0; i< 10; i++){
		if(w.Tuloai[i].tentuloai!=""){
			cout << "\t\t+Tu loai: " <<w.Tuloai[i].tentuloai << endl;
		}
		j=0;
		if(w.Tuloai[i].mean[j].meanname!="")
				cout<< "-Nghia cua tu loai:" <<endl;
		for(int j=0;j<10;j++){
			if(w.Tuloai[i].mean[j].meanname!=""){
				cout<< "\t." <<w.Tuloai[i].mean[j].meanname <<endl;
			}
				
			for(int k=0;k<10;k++){
				if(w.Tuloai[i].mean[j].exam[k]!="")
				cout<< "\t   VD " << k << ": " << w.Tuloai[i].mean[j].exam[k] <<endl;
			}
		}
		
	}
}

void xuattheoluachon(Word w){
	int lc=99;
	Chaychu C;
	while(lc!=0){
		textcolor(15);
		cout << "\t\t\t\t\t<<Press any key to continue>>";
		char k = _getch();
		system("cls");
		textcolor(14);
		cout<<"\t\t---------------------------------Ban muon xem ?---------------------------------\n\t\t--------------------------------------------------------------------------------\n";
		
		textcolor(10);
		cout<<"                        1. Phat am.\n";
		cout<<"                        2. Tu loai.\n";
		cout<<"                        3. Nghia.\n";
		cout<<"                        4. Vi du.\n";
		cout<<"                        5. In toan bo tu.\n";
		cout<<"                        \t\t0. De thoat\n";
		textcolor(14);
		cout<<"\t\t--------------------------------------------------------------------------------\n";
		cout<<"\t\t--------------------------------Moi nhap lua chon-------------------------------\n";
		cin>>lc;
		textcolor(11);
				if(lc==1) cout<<"*Phat am:	" << w.cachdoc<<endl;
    			else if(lc==2){
    				xuattuloai(w);
					cout<<endl;
			
				} 
    			else if(lc==3){
    				xuatNgia(w);
					 cout<<endl;
					
				} 
    			else if(lc==4){
    				 xuatexam(w);
					  cout<<endl;
				
				}
    			else if(lc==5){
    				xuat1tu(w);
    				cout<<endl;
    				
				}
				else if(lc==0){
					system("cls");
					return;
				}
				else{
    				system("cls");
    				textcolor(15);
    				cout<<"Lua chon khong hop le"<<endl<<"Moi nhap lai lua chon\n";
    				
    			}
	}
	textcolor(15);
	
}

void nhap1tu(Word &w){
	
	textcolor(14);
	string q;
	cout << "\n---------------------------------------------------------------------------------------\n";
	cout << "   Moi nhap ten tu         |		";
	cin >> q;
	w.wordname = q ;
	cout << "---------------------------------------------------------------------------------------\n";
	cout << "   Moi nhap cach doc       |		";
	cin >> q;
	w.cachdoc = q;
	cout << "---------------------------------------------------------------------------------------\n";
	cout<< "   Moi nhap tu loai        |		";
	cin >> q;
	w.Tuloai[1].tentuloai = q;
	cout << "---------------------------------------------------------------------------------------\n";
	cout<< "   Moi nhap nghia          |		";
	cin >>q;
	w.Tuloai[1].mean[1].meanname=q;
	cout << "---------------------------------------------------------------------------------------\n";
	cout<< "   Moi nhap vi du          |		\n";
	
	cout << "---------------------------------------------------------------------------------------\n";
	gotoxy(40,10);
	cin >>q;
	w.Tuloai[1].mean[1].exam[1]=q;
	gotoxy(0,13);
		
	
	
}

void editkey(Tree &root, string x){
	char k;
	Word g;
	Tree p= search(root, x);
	if(search(root, x)==NULL){
		textcolor(15);
		cout<< "Tu khong ton tai" <<endl;
		return;
	}
	
	else{
		string q;
		int lc=99;
		
    	while(lc!=0){
    		system("cls");
			textcolor(11);
			cout<<"\tDang sua tu:\t"<<x<<endl;
    		textcolor(10);
    		cout<<"Ban muon thay doi:"<<endl<<"\t1. Phat am."<<endl<<"\t2. Tu loai."<<endl<< "\t3. Nghia."<<endl<<"\t4. Vi du."<<endl<<"0. De thoat"<<endl<<"Moi nhap lua chon"<<endl;
    		cin>>lc;
    		textcolor(14);
    		if(lc==0) break;
			if(lc==1){
				cout<<"Moi nhap cach phat am moi:	";
				textcolor(9);
				cin.ignore();
				getline(cin,q);
				p->data.cachdoc=q;
				textcolor(15);
				cout << "\t\t\t\t\t<<Press any key to continue>>";
				k=_getch();
				
			} 
    		else if(lc==2){
    			cout<<"Moi nhap tu loai moi:	";
    			textcolor(9);
    			cin.ignore();
				getline(cin,q);
				p->data.Tuloai[1].tentuloai+="   ";
    			p->data.Tuloai[1].tentuloai+=q;
    			textcolor(15);
    			cout << "\t\t\t\t\t<<Press any key to continue>>";
				k=_getch();
				
			} 
    		else if(lc==3){
    			cout<<"Moi nhap nghia moi:    ";
    			textcolor(9);
    			cin.ignore();
				getline(cin,q);
				for(int i=0; i< 10; i++){
		
					for(int j=0;j<10;j++){
						if(p->data.Tuloai[i].mean[j].meanname=="")
							break;
						p->data.Tuloai[i].mean[j].meanname="";
					
					}
				}
				p->data.Tuloai[1].mean[1].meanname=q;
				textcolor(15);
				
				cout << "\t\t\t\t\t<<Press any key to continue>>";
				k=_getch();
			}
    		else if(lc==4){
    			textcolor(9);
    			cout<<"Moi nhap vi du moi:	  ";
    			cin.ignore();
				getline(cin,q);
				
				for(int i=0; i< 10; i++){
	
					for(int j=0;j<10;j++){
				
						for(int k=1;k<10;k++){
							if(p->data.Tuloai[i].mean[j].exam[k]=="")
								break;
							p->data.Tuloai[i].mean[j].exam[k]="";
					
						}
					}
		
				}
				
    			p->data.Tuloai[1].mean[1].exam[1] = q;
    			textcolor(15);
				
				cout << "\t\t\t\t\t<<Press any key to continue>>";
				k=_getch();
			}
    		
    		else lc=0;
		}
	}
}

void SSF(Tree &p,Tree &q)
{
	if(q->left)
		SSF(p,q->left);
	else{
		p->data=q->data;
		p=q;
		q=q->right;
	}
}
int delNode(Tree &root, string x){
	if(root==NULL) return 0;
	if(root->data.wordname>x)
		return delNode(root->left,x);
	if(root->data.wordname<x)
		return delNode(root->right,x);
	Node* p=root;
	if(root->left==NULL)
		root=root->right;
	else{
		if(root->right==NULL)
			root=root->left;
		else SSF(p,root->right);
	}
	delete p;
	return 1;
}
int main(){
	
	Word w, g ;
	stack<string> history;
	Tree root=NULL;
	docfile(root);
	char key;
	GDmodau();
	int choose=0;
	do
	{

	GDmenukhongdong();
	cin>>choose;	
		switch (choose)
		{
			
			case 1:
			{
				system("cls");
				textcolor(9);
				cout<<"Nhap tu can tra:    ";
				textcolor(11);
				string x;
				cin.ignore();
				getline(cin,x);
				Node *p=search(root, x);
				if(p==NULL){
					textcolor(12);
					cout<< "Khong ton tai tu\n";
					textcolor(15);
					cout << "\t\t\t\t\t<<Press any key to continue>>";
					key=_getch();
					system("cls");
					break;
				}
				xuattheoluachon(p->data);
				history.push(x);
				break;
			}
			case 2:
			{
				system("cls");
				textcolor(9);
				cout<<"Nhap tu can them:	 ";
				textcolor(11);
				Word s;
				nhap1tu(s);
				AddWord(root,s);
				textcolor(15);
				cout<<"Da them tu"<<endl;
				//system("pause");
				cout << "\t\t\t\t\t<<Press any key to continue>>";
				key=_getch();
				system("CLS");
				break;
			}
			case 3:
			{
				system("cls");
				textcolor(9);
				cout<<"Nhap tu can sua:		";
				textcolor(11);
				string s;
				cin.ignore();
				getline(cin,s);
				editkey(root, s);
				//system("pause");
				textcolor(15);
				cout << "\t\t\t\t\t<<Press any key to continue>>";
				key=_getch();
				system("CLS");
				break;
			}
			case 4:
			{
				system("cls");
				textcolor(9);
				cout<<"Nhap tu can xoa:		";
				textcolor(11);
				string s;
				cin.ignore();
				getline(cin,s);
				if(delNode(root,s)==1)
				textcolor(12);
				cout<<"Da xoa tu"<<endl;
				//system("pause");
				textcolor(15);
				cout << "\t\t\t\t\t<<Press any key to continue>>";
				key=_getch();
				system("CLS");
				break;
			}
			case 5:
			{
				textcolor(9);
				cout<<"Lich su tim kiem:"<<endl;
				if(history.empty()){
					textcolor(11);
					cout<<"Ban chua tra tu nao ca @@\n";
					break;
				}
				system("cls");
				while(!history.empty())
				{
					textcolor(11);
					Sleep(50);
					cout<<history.top()<<endl;
					history.pop();
				}
				textcolor(15);
				cout << "\t\t\t\t\t<<Press any key to continue>>";
				key=_getch();
				system("CLS");
				break;
			}
		}
		if(choose<0||choose>5){
			system("cls");
			textcolor(12);
			cout << "Lua chon khong hop le\nMoi nhap lai.\n";
			textcolor(15);
			cout << "\t\t\t\t\t<<Press any key to continue>>";
			key=_getch();
			system("CLS");
		}
	}while(choose!=0);
	
	system("cls");
	textcolor(11);
	cout<<"\t\t\t\t\tDA KET THUC CHUONG TRINH.\n\n\n\n\n\n";
	textcolor(15);
	/**/
	
	
	
	
	
	
	
	return 0;
}
