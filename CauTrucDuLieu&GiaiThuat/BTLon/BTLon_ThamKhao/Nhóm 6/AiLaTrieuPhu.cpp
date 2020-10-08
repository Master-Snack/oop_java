#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <Windows.h>
#include <time.h>
#include <fstream>
#include <cstring>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <mmsystem.h>
HANDLE wHnd;
HANDLE rHnd;
using namespace std;
struct QUESTION
{
	char Question[200];
	char A[50];
	char B[50];
	char C[50];
	char D[50];
};
struct Node
{
	Node* link;
	QUESTION data;
};
struct List
{
	Node* first;
	Node* last;
};
typedef char MENU[100];
MENU menu[10] = {
				"1. CHOI NGAY",
				"2. THEM CAU HOI MOI",
				"3. TIM KIEM",
				"4. CAP NHAT CAU HOI",
				"5. HUONG DAN",
				"6. THOAT",
};
MENU menuphu[10] = {
				"1.            SO CAU HOI",
				"2.         TIM KIEM CAU HOI",
				"3.         DANH SACH CAU HOI",
				"4.  	    THONG TIN GIAI THUONG",
				"0.             QUAY LAI",
};
void resizeConsole(int width, int height);
void textcolor(int x);
void gotoxy(int x, int y);
void xoaManHinh();
void huongDan();
void thongTinGiaiThuong();
int readQuestionfromfile(QUESTION a[], int &n);
int addNewQuestion(int &n);
void Menu(int ViTri);
void MenuPhu(int ViTriphu);
void inputQuestion(char Question[], char A[], char B[], char C[], char D[]);
void cauHoi(List l, int numberqt, int &soCauDung, int &trogiup1, int &trogiup2, int &trogiup3);
void thongTinTroGiup();
void batDau();
void Init(List &l);
Node* getNode(QUESTION x);
int CreateListLast(List &l, int &n);
void InsertLast(List &l, QUESTION x);
void AddLast(List &l, Node* p);
int RandomQT(int cauDaHoi[], int i, int &soPhanTu, int n);
void veKhung();
void loadDing();
void khungQT();
void khungNgoai();
void khungHD();
void khungAddNewQT();
void chooseSearch();

int main()
{
	SetConsoleOutputCP(65001);
//	resizeConsole(900, 650);
	int choose, n, money = 0, numberqt, soCauDung = 0, read, dem = 0, cauDaHoi[100], soPhanTu = 1, ViTri = 1, ViTriPhu = 1;
	char s[100], c;
	QUESTION question[200];
	List l;
	read = CreateListLast(l, n);
	srand(time(NULL));
	if (read == 0)
		cout << "ERROR GAME!!!";
	else
	{
	quaylai:
		do
		{
			int dem0 = 0;
			system("cls");
			system("color b9");
			textcolor(14);
			cout << "\n\n\n\n\n\n+----------------------------------------------------------------------------------------------------------+\n";
			cout << "¦                                         WELCOME TO AI LA TRIEU PHU ^_^                                   ¦\n";
			cout << "¦----------------------------------------------------------------------------------------------------------¦\n";
			cout << "¦----------------------------------------------------------------------------------------------------------¦\n";
			cout << "¦                                             1. CHOI NGAY                                                 ¦\n";
			cout << "¦----------------------------------------------------------------------------------------------------------¦\n";
			cout << "¦                                             2. THÊM CÂU HOI MOI                                          ¦\n";
			cout << "¦----------------------------------------------------------------------------------------------------------¦\n";
			cout << "¦                                             3. TÌM KIEM                                                  ¦\n";
			cout << "¦----------------------------------------------------------------------------------------------------------¦\n";
			cout << "¦                                             4. CAP NHAT CÂU HOI                                          ¦\n";
			cout << "¦----------------------------------------------------------------------------------------------------------¦\n";
			cout << "¦                                             5. HUONG DAN                                                 ¦\n";
			cout << "¦----------------------------------------------------------------------------------------------------------¦\n";
			cout << "¦                                             6. THOAT                                                     ¦\n";
			cout << "+----------------------------------------------------------------------------------------------------------+\n";
			do
			{
				Menu(ViTri);
				c = _getch();
				switch (c)
				{
				case 72:
					ViTri--;
					if (ViTri == 0)
						ViTri = 6;
					break;
				case 80:
					ViTri++;
					if (ViTri == 7)
						ViTri = 1;
					break;
				case 27:
					exit(0);
				}
			} while (c != 13);
			switch (ViTri)
			{
			case 1:
			{
				int trogiup1 = 1, trogiup2 = 1, trogiup3 = 1;
				for (int i = 1; i <= soPhanTu; i++)
				{
					cauDaHoi[i] = 0;
				}
				soPhanTu = 0;
				system("color b9");
				system("cls");
				textcolor(178);
				loadDing();
				Sleep(1000);
				system("cls");
				system("color b9");
				textcolor(178);
				batDau();
				Sleep(2000);
				system("cls");
				system("color b9");
				textcolor(178);
				thongTinGiaiThuong();
				Sleep(2000);
				system("cls");
				system("color b9");
				textcolor(14);
				veKhung();
				textcolor(178);
				srand(time(NULL));
				char ten[30];
				gotoxy(15, 15);
				printf("Nhap ten nguoi choi: ");
				cin >> ten;
				strupr(ten);
				SetConsoleOutputCP(65001);
				Sleep(2000);
				system("cls");
				system("color b9");
				textcolor(14);
				veKhung();
				textcolor(2);
				int i = 0;
				do
				{
					i++;
					system("color b9");
					textcolor(14);
					veKhung();
					gotoxy(2, 2);
					cout << "Câu " << i << ": \n";
					numberqt = RandomQT(cauDaHoi, i, soPhanTu, n);
					cauHoi(l, numberqt, soCauDung, trogiup1, trogiup2, trogiup3);
					if (soCauDung == 1)
					{
						textcolor(14);
						if (i == 1)
							dem = dem + 200000;
						if (i == 2)
							dem = dem + 200000;
						if (i == 3)
							dem = dem + 200000;
						if (i == 4)
							dem = dem + 400000;
						if (i == 5)
							dem = dem + 1000000;
						if (i == 6)
							dem = dem + 1000000;
						if (i == 7)
							dem = dem + 3000000;
						if (i == 8)
							dem = dem + 4000000;
						if (i == 9)
							dem = dem + 4000000;
						if (i == 10)
							dem = dem + 8000000;
						if (i == 11)
							dem = dem + 8000000;
						if (i == 12)
							dem = dem + 10000000;
						if (i == 13)
							dem = dem + 20000000;
						if (i == 14)
							dem = dem + 25000000;
						if (i == 15)
							dem = dem + 65000000;
						if (i == 15)
						{
							textcolor(14);
							veKhung();
							textcolor(2);
							system("color 5E");
							gotoxy(44, 3);
							cout << "+-----------------+";
							gotoxy(44, 4);
							cout << "¦  S U C C E S S  ¦";
							gotoxy(44, 5);
							cout << "+-----------------+";
							gotoxy(28, 10);
							cout << "CHUC MUNG BAN \"" << ten << "\" ÐÃ TRO THANH TRIEU PHU!!! ^_^";
							gotoxy(28, 11);
							cout << "TIEN THUONG BAN CHAC CHAN NHAN ÐUOC LA: " << dem << " VNÐ";
							gotoxy(32, 14);
							cout << "XIN CHUC MUNG BAN!!!";
							Sleep(3000);
							gotoxy(32, 24);
							cout << "NHAN 1 PHIM BAT KI DE TIEP TUC!!!";
							gotoxy(32, 25);
							system("pause");
						}
						else
						{
							system("cls");
							textcolor(14);
							veKhung();
							textcolor(189);
							gotoxy(85, 2);
							cout << "TEN NGUOI CHOI: ";
							gotoxy(85, 3);
							cout << ten;
							gotoxy(85, 5);
							cout << "SO TIEN HIEN TAI: ";
							gotoxy(85, 6);
							cout << dem << " VNÐ";
						}
					}
					else
					{
						textcolor(14);
						veKhung();
						textcolor(2);
						system("color 3e");
						textcolor(16);
						gotoxy(44, 3);
						cout << "+-----------------+";
						gotoxy(44, 4);
						cout << "¦ G A M E O V E R ¦";
						gotoxy(44, 5);
						cout << "+-----------------+";
						gotoxy(32, 10);
						cout << "PHAN THUONG BAN NHAN DUOC LA: " << dem << " VNÐ.";
						Sleep(2000);
						gotoxy(39, 23);
						cout << "NHAN 1 PHIM BAT KY ÐE TIEP TUC";
						gotoxy(39, 24);
						system("pause");
					}
					if (i == 15)
						goto quaylai;
				} while (soCauDung != 0);
			}break;
			case 2:
			{
				system("cls");
				textcolor(14);
				khungNgoai();
				textcolor(2);
				khungAddNewQT();
				gotoxy(36, 6);
				cout << " (NHAP VAO TIENG VIET KHONG DAU) ";
				gotoxy(31, 7);
				cout << " (Dap an dung phai ghi them dau \"*\" o cuoi) ";
				gotoxy(29, 8);
				cout << " (Cac dap an khac them dau khoang trong o cuoi) ";
				int t;
				t = addNewQuestion(n);
				if (t == 0)
				{
					gotoxy(39, 22);
					cout << "FAIL!";;
					gotoxy(39, 23);
					cout << "THEM KHONG THANH CONG!!!";
				}
				else
				{
					gotoxy(39, 22);
					cout << "SUCCESS";;
					gotoxy(39, 23);
					cout << "THEM THANH CONG!!!";
				}
				gotoxy(39, 24);
				Sleep(2000);
				cout << "NHAN MOT PHIM BAT KY DE TIEP TUC";
				gotoxy(39, 25);
				system("pause");
			}break;
			case 3:
			{
			case3:
				do
				{
					system("cls");
					textcolor(14);
					khungNgoai();
					textcolor(2);
					chooseSearch();
					do
					{
						MenuPhu(ViTriPhu);
						c = _getch();
						switch (c)
						{
						case 72:
							ViTriPhu--;
							if (ViTriPhu == 0)
								ViTriPhu = 5;
							break;
						case 80:
							ViTriPhu++;
							if (ViTriPhu == 6)
								ViTriPhu = 1;
							break;
						case 27:
							exit(0);
						}
					} while (c != 13);
					if (ViTriPhu == 5)
						break;
					if (ViTriPhu == 1)
					{
						system("cls");
						textcolor(14);
						khungNgoai();
						textcolor(2);
						gotoxy(6, 9);
						cout << "SO CAU HOI HIEN TAI LA: " << n << endl;
					}
					if (ViTriPhu == 2)
					{
						system("cls");
						textcolor(14);
						khungNgoai();
						textcolor(2);
						gotoxy(6, 9);
						cout << "NHAP THU TU CAU HOI BAN MUON TIM KIEM: ";
						int thuTu;
						do
						{
							cin >> thuTu;
							if (thuTu > 30 || thuTu < 1)
								cout << "NHAP LAI: ";
						} while (thuTu > 30 || thuTu < 1);
						Node* p = l.first;
						int i = 0;
						while (p != NULL)
						{
							if (i == thuTu)
								break;
							p = p->link;
							i++;
						}
						char Question[200];
						char A[50];
						char B[50];
						char C[50];
						char D[50];
						fflush(stdin);
						strncpy(A, p->data.A, strlen(p->data.A) - 1);
						fflush(stdin);
						strncpy(B, p->data.B, strlen(p->data.B) - 1);
						fflush(stdin);
						strncpy(C, p->data.C, strlen(p->data.C) - 1);
						fflush(stdin);
						strncpy(D, p->data.D, strlen(p->data.D) - 1);
						khungQT();
						gotoxy(5, 4);
						cout << p->data.Question;
						gotoxy(5, 6);
						cout << "1. " << A;
						gotoxy(45, 6);
						cout << "2. " << B;
						gotoxy(5, 8);
						cout << "3. " << C;
						gotoxy(45, 8);
						cout << "4. " << D;
					}
					if (ViTriPhu == 3)
					{
						system("cls");
						textcolor(2);
						gotoxy(6, 9);
						Node* p = l.first;
						int i = 1, j = 2;
						while (p)
						{
							j++;
							gotoxy(2, j);
							cout << "Cau " << i << " :";
							j++;
							gotoxy(2, j);
							cout << p->data.Question;
							j++;
							gotoxy(2, j);
							cout << p->data.A;
							j++;
							gotoxy(2, j);
							cout << p->data.B;
							j++;
							gotoxy(2, j);
							cout << p->data.C;
							j++;
							gotoxy(2, j);
							cout << p->data.D;
							j++;
							gotoxy(2, j);
							p = p->link;
							i++;
						}
						Sleep(2000);
						cout << "\t\t\t\t NHAN 1 PHIM BAT KY DE TIEP TUC\n";
						system("pause");
						goto case3;
					}
					if (ViTriPhu == 4)
					{
						system("cls");
						textcolor(14);
						khungNgoai();
						textcolor(2);
						thongTinGiaiThuong();
						Sleep(2000);
						gotoxy(76, 15);
						cout << "NHAN 1 PHIM BAT KY DE TIEP TUC";
						gotoxy(76, 16);
						system("pause");
						goto case3;
					}
					Sleep(2000);
					gotoxy(39, 23);
					cout << "NHAN 1 PHIM BAT KY DE TIEP TUC ";
					gotoxy(39, 24);
					system("pause");
				} while (ViTriPhu != 5);

			}break;
			case 4:
			{
				read = CreateListLast(l, n);
				gotoxy(35, 30);
				if (read == 0)
					cout << "CAP NHAT THAT BAI";
				else
					cout << "CAP NHAT THANH CONG";
				gotoxy(35, 31);
				system("pause");
			}break;
			case 5:
			{
				system("cls");
				textcolor(14);
				khungNgoai();
				textcolor(2);
				khungHD();
				gotoxy(10, 8);
				for (int i = 0; i < strlen("VUOT QUA TAT CA 15 CÂU HOI "); i++)
				{
					printf("%c", "VUOT QUA TAT CA 15 CÂU HOI "[i]);
					Sleep(30);
				}
				gotoxy(10, 9);
				for (int i = 0; i < strlen("BAN SE NHAN ÐUOC 150 TRIEU ÐONG CUA CHUONG TRINH!!!"); i++)
				{
					printf("%c", "BAN SE NHAN ÐUOC 150 TRIEU ÐONG CUA CHUONG TRINH!!!"[i]);
					Sleep(30);
				}
				Sleep(3000);
				system("cls");
				textcolor(14);
				khungNgoai();
				textcolor(2);
				khungHD();
				gotoxy(10, 8);
				for (int i = 0; i < strlen("TA CO CAC QUYEN TRO GIUP: "); i++)
				{
					printf("%c", "TA CO CAC QUYEN TRO GIUP:: "[i]);
					Sleep(30);
				}
				gotoxy(10, 10);
				for (int i = 0; i < strlen("1. GOI DIEN CHO NGUOI THAN: "); i++)
				{
					printf("%c", "1. GOI DIEN CHO NGUOI THAN: "[i]);
					Sleep(30);
				}
				gotoxy(10, 11);
				for (int i = 0; i < strlen("Ban co quyen goi dien cho 1 nguoi than nhan quyen tro giup vua hoi vua tra loi"); i++)
				{
					printf("%c", "Ban co quyen goi dien cho 1 nguoi than nhan quyen tro giup vua hoi vua tra loi"[i]);
					Sleep(30);
				}
				gotoxy(10, 12);
				for (int i = 0; i < strlen("trong khoang thoi gian 30s."); i++)
				{
					printf("%c", "trong khoang thoi gian 30s."[i]);
					Sleep(30);
				}
				Sleep(1000);
				gotoxy(10, 14);
				for (int i = 0; i < strlen("2. 50:50"); i++)
				{
					printf("%c", "2. 50:50"[i]);
					Sleep(30);
				}
				gotoxy(10, 15);
				for (int i = 0; i < strlen("Khi nguoi choi chon quyen tro giup nay may tinh se bo di 2 phuong an sai."); i++)
				{
					printf("%c", "Khi nguoi choi chon quyen tro giup nay may tinh se bo di 2 phuong an sai."[i]);
					Sleep(30);
				}
				Sleep(1000);
				gotoxy(10, 17);
				for (int i = 0; i < strlen("3. Hoi y kien khan gia:"); i++)
				{
					printf("%c", "3. Hoi y kien khan gia:"[i]);
					Sleep(30);
				}
				gotoxy(10, 18);
				for (int i = 0; i < strlen("Khan gia se tro giup cho ban bang cach chon 1 trong 4 dap an cua chuong trinh"); i++)
				{
					printf("%c", "Khan gia se tro giup cho ban bang cach chon 1 trong 4 dap an cua chuong trinh"[i]);
					Sleep(30);
				}
				gotoxy(10, 19);
				for (int i = 0; i < strlen("la chinh xac."); i++)
				{
					printf("%c", "la chinh xac."[i]);
					Sleep(30);
				}
				Sleep(2000);
				gotoxy(32, 23);
				cout << "NHAN 1 PHIM BAT KY DE TIEP TUC";
				gotoxy(32, 24);
				system("pause");
			}
			case 6: break;
			default: break;
			}
		} while (ViTri != 6);
	}

	system("pause");
	return 0;
}

void textcolor(int x)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
}
void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x - 1,y - 1 };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
void xoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}
void huongDan()
{

}
void thongTinGiaiThuong()
{
	gotoxy(34, 3);
	cout << "+---------------------------------------+";
	gotoxy(34, 4);
	cout << "¦  THONG TIN GIAI THUONG QUA TONG MUC   ¦";
	gotoxy(34, 5);
	cout << "¦---------------------------------------¦";
	gotoxy(34, 6);
	cout << "¦        CAU 15: 150,000,000 VNÐ        ¦";
	gotoxy(34, 7);
	cout << "¦---------------------------------------¦";
	gotoxy(34, 8);
	cout << "¦        CAU 14: 85,000,000 VNÐ         ¦";
	gotoxy(34, 9);
	cout << "¦---------------------------------------¦";
	gotoxy(34, 10);
	cout << "¦        CAU 13: 60,000,000 VNÐ         ¦";
	gotoxy(34, 11);
	cout << "¦---------------------------------------¦";
	gotoxy(34, 12);
	cout << "¦        CAU 12: 40,000,000 VNÐ         ¦";
	gotoxy(34, 13);
	cout << "¦---------------------------------------¦";
	gotoxy(34, 14);
	cout << "¦        CAU 11: 30,000,000 VNÐ         ¦";
	gotoxy(34, 15);
	cout << "¦---------------------------------------¦";
	gotoxy(34, 16);
	cout << "¦        CAU 10: 22,000,000 VNÐ         ¦";
	gotoxy(34, 17);
	cout << "¦---------------------------------------¦";
	gotoxy(34, 18);
	cout << "¦        CAU 09: 14,000,000 VNÐ         ¦";
	gotoxy(34, 19);
	cout << "¦---------------------------------------¦";
	gotoxy(34, 20);
	cout << "¦        CAU 08: 10,000,000 VNÐ         ¦";
	gotoxy(34, 21);
	cout << "¦---------------------------------------¦";
	gotoxy(34, 22);
	cout << "¦        CAU 07: 6,000,000 VNÐ          ¦";
	gotoxy(34, 23);
	cout << "¦---------------------------------------¦";
	gotoxy(34, 24);
	cout << "¦        CAU 06: 3,000,000 VNÐ          ¦";
	gotoxy(34, 25);
	cout << "¦---------------------------------------¦";
	gotoxy(34, 26);
	cout << "¦        CAU 05: 2,000,000 VNÐ          ¦";
	gotoxy(34, 27);
	cout << "¦---------------------------------------¦";
	gotoxy(34, 28);
	cout << "¦        CAU 04: 1,000,000 VNÐ          ¦";
	gotoxy(34, 29);
	cout << "¦---------------------------------------¦";
	gotoxy(34, 30);
	cout << "¦        CAU 03: 600,000 VNÐ            ¦";
	gotoxy(34, 31);
	cout << "¦---------------------------------------¦";
	gotoxy(34, 32);
	cout << "¦        CAU 02: 400,000 VNÐ            ¦";
	gotoxy(34, 33);
	cout << "¦---------------------------------------¦";
	gotoxy(34, 34);
	cout << "¦        CAU 01: 200,000 VNÐ            ¦";
	gotoxy(34, 35);
	cout << "+---------------------------------------+";
}
int addNewQuestion(int &n)
{
	char Question[300], A[50], B[50], C[50], D[50];
	ofstream outfile;
	outfile.open("ailatrieuphu.txt", ios::app);
	if (outfile.fail())
		return 0;
	inputQuestion(Question, A, B, C, D);
	outfile << "\n";
	outfile << Question << endl;
	outfile << A << endl;
	outfile << B << endl;
	outfile << C << endl;
	outfile << D;
	outfile.close();
	n++;
	return 1;
}
void Menu(int ViTri)
{
	int i, j = 0;
	for (i = 1; i <= 6; i++)
	{
		if (i == ViTri)
			textcolor(4);
		else
			textcolor(14);
		gotoxy(47, 10 + i + j);
		printf(menu[i - 1]);
		j++;
	}
}
void MenuPhu(int ViTriphu)
{
	int i, j = 0;
	for (i = 1; i <= 5; i++)
	{
		if (i == ViTriphu)
			textcolor(4);
		else
			textcolor(2);
		gotoxy(36, 11 + i + j);
		printf(menuphu[i - 1]);
		j += 2;
	}
}
void inputQuestion(char Question[], char A[], char B[], char C[], char D[])
{
	cin.ignore(32767, '\n');
	gotoxy(6, 9);
	cout << "NHAP VÀO CÂU HOI: ";
	fflush(stdin);
	cin.getline(Question, 100);
	gotoxy(6, 11);
	cout << "NHAP VAO DAP AN: ";
	fflush(stdin);
	gotoxy(6, 12);
	cout << "A: ";
	fflush(stdin);
	cin.getline(A, 100);
	gotoxy(6, 13);
	cout << "B: ";
	fflush(stdin);
	cin.getline(B, 100);
	gotoxy(6, 14);
	cout << "C: ";
	fflush(stdin);
	cin.getline(C, 100);
	gotoxy(6, 15);
	cout << "D: ";
	fflush(stdin);
	cin.getline(D, 100);
}
void cauHoi(List l, int numberqt, int &soCauDung, int &trogiup1, int &trogiup2, int &trogiup3)
{
	int dapan, rd, cauDung, dem = 1, ViTri = 1;
	Node *p = l.first;
	while (p != NULL && dem <= numberqt)
	{
		p = p->link;
		dem++;
	}
	char Question[200];
	char A[50];
	char B[50];
	char C[50];
	char D[50];
	char c, c1, c2, c3, c4, dapan1, trogiup;
	if (p->data.A[strlen(p->data.A) - 1] == '*'){
		cauDung = 1;
		fflush(stdin);
		strncpy(A, p->data.A, strlen(p->data.A)-1);
		khungQT();
		gotoxy(5, 4);
		cout << p->data.Question;
		gotoxy(5, 6);
		cout << "A. " << A;
		gotoxy(45, 6);
		cout << "B. " << p->data.B;
		gotoxy(5, 8);
		cout << "C. " << p->data.C;
		gotoxy(45, 8);
		cout << "D. " << p->data.D;
	}else if (p->data.B[strlen(p->data.B) - 1] == '*'){
		cauDung = 2;
		fflush(stdin);
		strncpy(B, p->data.B, strlen(p->data.B)-1);
		khungQT();
		gotoxy(5, 4);
		cout << p->data.Question;
		gotoxy(5, 6);
		cout << "A. " << p->data.A;
		gotoxy(45, 6);
		cout << "B. " << B;
		gotoxy(5, 8);
		cout << "C. " << p->data.C;
		gotoxy(45, 8);
		cout << "D. " << p->data.D;
	}else if (p->data.C[strlen(p->data.C) - 1] == '*'){
		cauDung = 3;
		fflush(stdin);
		strncpy(C, p->data.C, strlen(p->data.C)-1);
		khungQT();
		gotoxy(5, 4);
		cout << p->data.Question;
		gotoxy(5, 6);
		cout << "A. " << p->data.A;
		gotoxy(45, 6);
		cout << "B. " << p->data.B;
		gotoxy(5, 8);
		cout << "C. " << C;
		gotoxy(45, 8);
		cout << "D. " << p->data.D;
	}else {
		cauDung = 4;
		fflush(stdin);
		strncpy(D, p->data.D, strlen(p->data.D)-1);
		khungQT();
		gotoxy(5, 4);
		cout << p->data.Question;
		gotoxy(5, 6);
		cout << "A. " << p->data.A;
		gotoxy(45, 6);
		cout << "B. " << p->data.B;
		gotoxy(5, 8);
		cout << "C. " << p->data.C;
		gotoxy(45, 8);
		cout << "D. " << D;
	}
	
	gotoxy(24, 31);
	cout << "<<TRA LOI BANG CACH NHAP 1 TRONG 4 PHIM A, B, C, D>>";
	gotoxy(30, 32);
	cout << "<<BAM PHIM H (HELP) DE SU DUNG QUYEN TRO GIUP>>";
	quaylai:
	do
	{
		dapan1 = toupper(_getch());
		switch (dapan1)
		{
			case 65:
				dapan1 = 'A';
				break;
			case 66:
				dapan1 = 'B';
				break;
			case 67:
				dapan1 = 'C';
				break;
			case 68: 
				dapan1 = 'D';
				break;
			case 72:
				dapan1 = 'H';
				break;
			case 27: 
				exit(0);
		}
	} while (dapan1 != 'A' && dapan1 != 'B' && dapan1 != 'C' && dapan1 != 'D' && dapan1 != 'H');
	if (dapan1 == 'H')
	{
		system("cls");
		textcolor(14);
		veKhung();
		textcolor(2);
		khungQT();
		gotoxy(5, 4);
	if (p->data.A[strlen(p->data.A) - 1] == '*'){
		cauDung = 1;
		fflush(stdin);
		strncpy(A, p->data.A, strlen(p->data.A)-1);
		khungQT();
		gotoxy(5, 4);
		cout << p->data.Question;
		gotoxy(5, 6);
		cout << "A. " << A;
		gotoxy(45, 6);
		cout << "B. " << p->data.B;
		gotoxy(5, 8);
		cout << "C. " << p->data.C;
		gotoxy(45, 8);
		cout << "D. " << p->data.D;
	}else if (p->data.B[strlen(p->data.B) - 1] == '*'){
		cauDung = 2;
		fflush(stdin);
		strncpy(B, p->data.B, strlen(p->data.B)-1);
		khungQT();
		gotoxy(5, 4);
		cout << p->data.Question;
		gotoxy(5, 6);
		cout << "A. " << p->data.A;
		gotoxy(45, 6);
		cout << "B. " << B;
		gotoxy(5, 8);
		cout << "C. " << p->data.C;
		gotoxy(45, 8);
		cout << "D. " << p->data.D;
	}else if (p->data.C[strlen(p->data.C) - 1] == '*'){
		cauDung = 3;
		fflush(stdin);
		strncpy(C, p->data.C, strlen(p->data.C)-1);
		khungQT();
		gotoxy(5, 4);
		cout << p->data.Question;
		gotoxy(5, 6);
		cout << "A. " << p->data.A;
		gotoxy(45, 6);
		cout << "B. " << p->data.B;
		gotoxy(5, 8);
		cout << "C. " << C;
		gotoxy(45, 8);
		cout << "D. " << p->data.D;
	}else {
		cauDung = 4;
		fflush(stdin);
		strncpy(D, p->data.D, strlen(p->data.D)-1);
		khungQT();
		gotoxy(5, 4);
		cout << p->data.Question;
		gotoxy(5, 6);
		cout << "A. " << p->data.A;
		gotoxy(45, 6);
		cout << "B. " << p->data.B;
		gotoxy(5, 8);
		cout << "C. " << p->data.C;
		gotoxy(45, 8);
		cout << "D. " << D;
	}
		if (trogiup1 == 0 && trogiup2 == 0 && trogiup3 == 0)
		{
			gotoxy(33, 32);
			cout << "BAN DA SU DUNG HET TAT CA QUYEN TRO GIUP!!!" << endl;
			gotoxy(33, 33);
			cout << "DAP AN CUA BAN LA: ";
			goto quaylai;
		}
		thongTinTroGiup();
		gotoxy(3, 32);
		cout << "BAN SU DUNG QUYEN TRO GIUP LA : ";
		do
		{
			trogiup = toupper(_getch());
			switch (trogiup)
			{
			case 49:
				trogiup = '1';
				break;
			case 50:
				trogiup = '2';
				break;
			case 51:
				trogiup = '3';
				break;
			case 27:
				exit(0);
			}
		} while (trogiup != '1' && trogiup != '2' && trogiup != '3');
		gotoxy(32, 32);
		if (trogiup == '1')
			cout << "GOI DIEN CHO NGUOI THAN.";
		if (trogiup == '2')
			cout << "50/50.";
		if (trogiup == '3')
			cout << "HOI Y KIEN KHAN GIA TRONG TRUONG QUAY.";
		if ((trogiup1 == 0 && trogiup == '1') || (trogiup2 == 0 && trogiup == '2') || (trogiup3 == 0 && trogiup == '3'))
		{
			cout << "BAN DA SU DUNG HET QUYEN TRO GIUP NAY!!! " << endl;
			cout << "DAP AN CUA BAN LA: ";
			goto quaylai;
		}
		if (trogiup == '1' && trogiup1 != 0)
		{

			trogiup1 = 0;
			srand(time(NULL));
			do
			{
				rd = rand() % 4 + 1;
			} while (rd != cauDung);
			if (rd == 1)
				c = 'A';
			if (rd == 2)
				c = 'B';
			if (rd == 3)
				c = 'C';
			if (rd == 4)
				c = 'D';
			gotoxy(3, 33);
			cout << "NGUOI THAN DA TRO GIUP BAN DAP AN LA:  " << c << endl;
			gotoxy(3, 34);
			cout << "DAP AN CUA BAN LA: ";
			goto quaylai;
		}
		if (trogiup == '2' && trogiup2 != 0)
		{
			trogiup2 = 0;
			srand(time(NULL));
			do
			{
				rd = rand() % 4 + 1;
			} while (rd == cauDung);
			int rd1;
			do
			{
				rd1 = rand() % 4 + 1;
			} while (rd == rd1 || rd1 == cauDung);
			if (rd == 1)
				c = 'A';
			if (rd == 2)
				c = 'B';
			if (rd == 3)
				c = 'C';
			if (rd == 4)
				c = 'D';
			if (rd1 == 1)
				c1 = 'A';
			if (rd1 == 2)
				c1 = 'B';
			if (rd1 == 3)
				c1 = 'C';
			if (rd1 == 4)
				c1 = 'D';
			gotoxy(3, 33);
			cout << "LOAI BO DAP AN " << c << "  VA " << c1 << endl;
			gotoxy(3, 34);
			cout << "DAP AN CUA BAN LA: ";
			goto quaylai;
		}
		if (trogiup == '3' && trogiup3 != 0)
		{
			trogiup3 = 0;
			int rd1, rd2, rd3;
			srand(time(NULL));
			do
			{
				rd = rand() % 80 + 1;
				rd1 = rand() % (100 - rd) + 1;
				int r = rd + rd1;
				rd2 = rand() % (100 - r) + 1;
				r = rd + rd1 + rd2;
				rd3 = 100 - r;
			} while (rd < 50 || rd + rd1 + rd2 + rd3 != 100);
			if (cauDung == 1)
			{
				gotoxy(3, 33);
				cout << rd << "% khan gia lua chon  A, " << rd1 << "% khan gia lua chon  B, " << rd2 << "% khan gia lua chon  C, " << rd3 << "% khan gia lua chon  D!";
				gotoxy(3, 34);
				cout << "DAP AN CUA BAN LA: ";
			}
			if (cauDung == 2)
			{
				gotoxy(3, 33);
				cout << rd1 << "% khan gia lua chon  A, " << rd << "% khan gia lua chon  B, " << rd2 << "% khan gia lua chon  C, " << rd3 << "% khan gia lua chon  D!";
				gotoxy(3, 34);
				cout << "DAP AN CUA BAN LA: ";
			}
			if (cauDung == 3)
			{
				gotoxy(3, 33);
				cout << rd1 << "% khan gia lua chon  A, " << rd2 << "% khan gia lua chon  B, " << rd << "% khan gia lua chon  C, " << rd3 << "% khan gia lua chon  D!";
				gotoxy(3, 34);
				cout << "DAP AN CUA BAN LA: ";
			}
			if (cauDung == 4)
			{
				gotoxy(3, 33);
				cout << rd1 << "% khan gia lua chon  A, " << rd2 << "% khan gia lua chon  B, " << rd3 << "% khan gia lua chon  C, " << rd << "% khan gia lua chon  D!";
				gotoxy(3, 34);
				cout << "DAP AN CUA BAN LA: ";
			}
			goto quaylai;
		}
	}
	if (dapan1 == 'A') {
		if (cauDung == 1)
			soCauDung = 1;
		else {
			textcolor(26);
			gotoxy(3, 33);
			cout << "SAI ROI!!!\n";
			gotoxy(3, 34);
			if (cauDung == 2)
				cout << "DAP AN DUNG LA: " << B;
			if (cauDung == 3)
				cout << "DAP AN DUNG LA: " << C;
			if (cauDung == 4)
				cout << "DAP AN DUNG LA: " << D;
			soCauDung = 0;
			Sleep(3000);
		}
	}
	if (dapan1 == 'B') {
		if (cauDung == 2)
			soCauDung = 1;
		else {
			textcolor(26);
			gotoxy(3, 33);
			cout << "SAI ROI!!!\n";
			gotoxy(3, 34);
			if (cauDung == 1)
				cout << "DAP AN DUNG LA: " << A;
			if (cauDung == 3)
				cout << "DAP AN DUNG LA: " << C;
			if (cauDung == 4)
				cout << "DAP AN DUNG LA: " << D;
			soCauDung = 0;
			Sleep(3000);
		}
	}
	if (dapan1 == 'C') {
		if (cauDung == 3)
			soCauDung = 1;
		else {
			textcolor(26);
			gotoxy(3, 33);
			cout << "SAI ROI!!!\n";
			gotoxy(3, 34);
			if (cauDung == 1)
				cout << "DAP AN DUNG LA: " << A;
			if (cauDung == 2)
				cout << "DAP AN DUNG LA: " << B;
			if (cauDung == 4)
				cout << "DAP AN DUNG LA: " << D;
			soCauDung = 0;
			Sleep(3000);
		}
	}
	if (dapan1 == 'D') {
		if (cauDung == 4)
			soCauDung = 1;
		else {
			textcolor(26);
			gotoxy(3, 33);
			cout << "SAI ROI!!!\n";
			gotoxy(3, 34);
			if (cauDung == 1)
				cout << "DAP AN DUNG LA: " << A;
			if (cauDung == 2)
				cout << "DAP AN DUNG LA: " << B;
			if (cauDung == 3)
				cout << "DAP AN DUNG LA: " << C;
			soCauDung = 0;
			Sleep(3000);
		}
	}
}
void thongTinTroGiup()
{
	gotoxy(30, 23);
	cout << "+-----------------------------------------+\n";
	gotoxy(30, 24);
	cout << "¦ 1.  GOI DIEN CHO NGUOI THAN             ¦\n";
	gotoxy(30, 25);
	cout << "¦-----------------------------------------¦\n";
	gotoxy(30, 26);
	cout << "¦-----------------------------------------¦\n";
	gotoxy(30, 27);
	cout << "¦ 2.  50/50                               ¦\n";
	gotoxy(30, 28);
	cout << "¦-----------------------------------------¦\n";
	gotoxy(30, 29);
	cout << "¦-----------------------------------------¦\n";
	gotoxy(30, 30);
	cout << "¦ 3.  HOI Y KIEN KHAN GIA TRUONG QUAY     ¦\n";
	gotoxy(30, 31);
	cout << "+-----------------------------------------+\n";

}
void batDau()
{
	system("cls");
	cout << "\n\n";
	cout << "                                |||\n";
	cout << "                              |||\n";
	cout << "                            |||\n";
	cout << "                       ||||    |||\n";
	cout << "                        ||||||||\n";
	cout << "                                                            \n";
	cout << "||||||||||||||           |||||||       |||||||||||||||||||||\n";
	cout << "|||||        ||         |||||||||       |||||||||||||||||||\n";
	cout << "|||||        |||       |||||   |||             |||||\n";
	cout << "|||||        ||       |||||     |||            |||||\n";
	cout << "|||||||||||||        |||||       |||           |||||\n";
	cout << "|||||        ||     |||||||||||||||||          |||||\n";
	cout << "|||||        |||   |||||           |||         |||||\n";
	cout << "|||||        ||   |||||             |||        |||||\n";
	cout << "|||||||||||||    |||||               |||       |||||\n";
	cout << "||||||||||||   ||||||||             ||||||    |||||||\n";
	cout << "____________________________________________________________\n";
	cout << "\t\t\t\t\t                                  ||||\n";
	cout << "\t\t\t\t\t                              |||   ||||\n";
	cout << "\t\t\t\t\t                            |||  ||   ||||\n";
	cout << "\t\t\t\t\t                          |||      ||\n";
	cout << "\t\t\t\t\t                        |||||      ||||\n";
	cout << "\t\t\t\t\t   |||||||||||              |||||||            |||||||       |||||\n";
	cout << "\t\t\t\t\t   |||||      ||           |||||||||            |||||         |||\n";
	cout << "\t\t\t\t\t   |||||       ||         |||||   |||           |||||         |||\n";
	cout << "\t\t\t\t\t   |||||        ||       |||||     |||          |||||         |||\n";
	cout << "\t\t\t\t\t   ||||||||     ||      |||||       |||         |||||         |||\n";
	cout << "\t\t\t\t\t   |||||        ||     |||||||||||||||||        |||||         |||\n";
	cout << "\t\t\t\t\t   |||||       ||     |||||           |||       |||||         |||\n";
	cout << "\t\t\t\t\t   |||||      ||     |||||             |||      |||||         |||\n";
	cout << "\t\t\t\t\t   ||||||||||||     |||||               |||     |||||||||||||||||\n";
	cout << "\t\t\t\t\t   |||||||||||    ||||||||             ||||||    |||||||||||||||\n";
	cout << "\t\t\t\t\t   _______________________________________________________________\n";
}
void Init(List &l) {
	l.first = l.last = NULL;
}
Node* getNode(QUESTION x) {
	Node* p;
	p = new Node;
	if (p == NULL)
		return NULL;
	else {
		p->data = x;
		p->link = NULL;
	}
	return p;
}
int CreateListLast(List &l, int &n) {
	Init(l);
	QUESTION x;
	int i = 0;
	ifstream infile;
	infile.open("ailatrieuphu.txt"); ///////////////
	if (infile.fail())
		return 0;
	while (!infile.eof())
	{
		infile.getline(x.Question, 200);
		infile.getline(x.A, 50);
		infile.getline(x.B, 50);
		infile.getline(x.C, 50);
		infile.getline(x.D, 50);
		i++;
		InsertLast(l, x);
	}
	n = i;
	return 1;
}
void InsertLast(List &l, QUESTION x) {
	Node *p = getNode(x);
	if (p == NULL)
		return;
	AddLast(l, p);
}
void AddLast(List &l, Node* p) {
	if (l.first == NULL)
		l.first = l.last = p;
	else {
		l.last->link = p;
		l.last = p;
	}
}
int RandomQT(int cauDaHoi[], int i, int &soPhanTu, int n) {
	int numberqt, dem;
	srand(time(NULL));
	if (i <= 5)
	{
		do
		{
			dem = 0;
			numberqt = rand() % 10 + 1;
			for (int j = 1; j <= soPhanTu; j++)
			{
				if (cauDaHoi[j] == numberqt)
				{
					dem++;
					break;
				}
			}
		} while (dem != 0);
	}
	if (i > 5 && i <= 10)
	{
		do
		{
			dem = 0;
			numberqt = rand() % 11 + 10;
			for (int j = 1; j <= soPhanTu; j++)
			{
				if (cauDaHoi[j] == numberqt)
				{
					dem++;
					break;
				}
			}
		} while (dem != 0);
	}
	if (i > 10 && i <= 15)
	{
		do
		{
			dem = 0;
			numberqt = rand() % 11 + 20;
			for (int j = 1; j <= soPhanTu; j++)
			{
				if (cauDaHoi[j] == numberqt)
				{
					dem++;
					break;
				}
			}
		} while (dem != 0);
	}
	cauDaHoi[++soPhanTu] = numberqt;
	return numberqt;
}
void loadDing()
{
	gotoxy(44, 4);
	cout << "+-----------------+";
	gotoxy(44, 5);
	cout << "¦ L O A D D I N G ¦";
	gotoxy(44, 6);
	cout << "+-----------------+";
	gotoxy(4, 33);
	char c[] = "¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦";
	for (int i = 0; i < strlen(c); i++)
	{
		textcolor(10);
		printf("%c", c[i]);
		if (i > strlen(c) / 4 && i < strlen(c) / 4 + 6)
			Sleep(200);
		else
		{
			if (i > strlen(c) / 2 && i < strlen(c) / 2 + 6)
				Sleep(100);
			else
				Sleep(20);
		}

	}
}
void veKhung()
{
	gotoxy(1, 1);
	for (int i = 0; i < 108; i++)
	{
		cout << "¦";
	}
	int i = 2;
	do
	{
		gotoxy(1, i);
		cout << "¦";
		i++;
	} while (i < 38);
	i = 2;
	do
	{
		gotoxy(84, i);
		cout << "¦";
		i++;
	} while (i < 30);
	i = 2;
	do
	{
		gotoxy(108, i);
		cout << "¦";
		i++;
	} while (i < 38);
	gotoxy(2, 30);
	for (int i = 0; i < 107; i++)
	{
		cout << "¦";
	}
	gotoxy(1, 38);
	for (int i = 0; i < 108; i++)
	{
		cout << "¦";
	}
}
void khungQT()
{
	gotoxy(2, 3);
	cout << "+--------------------------------------------------------------------------------+";
	gotoxy(2, 4);
	cout << "¦                                                                                ¦";
	gotoxy(2, 5);
	cout << "¦--------------------------------------------------------------------------------¦";
	gotoxy(2, 6);
	cout << "¦                                       ¦                                        ¦";
	gotoxy(2, 7);
	cout << "¦--------------------------------------------------------------------------------¦";
	gotoxy(2, 8);
	cout << "¦                                       ¦                                        ¦";
	gotoxy(2, 9);
	cout << "+--------------------------------------------------------------------------------+";
}
void khungNgoai()
{
	gotoxy(1, 1);
	for (int i = 0; i < 108; i++)
	{
		cout << "¦";
	}
	int i = 2;
	do
	{
		gotoxy(1, i);
		cout << "¦";
		i++;
	} while (i < 38);
	i = 2;
	do
	{
		gotoxy(108, i);
		cout << "¦";
		i++;
	} while (i < 38);
	gotoxy(1, 38);
	for (int i = 0; i < 108; i++)
	{
		cout << "¦";
	}
}
void khungHD()
{
	gotoxy(44, 3);
	cout << "+-----------------+";
	gotoxy(44, 4);
	cout << "¦ H U O N G D A N ¦";
	gotoxy(44, 5);
	cout << "+-----------------+";
}
void khungAddNewQT()
{
	gotoxy(43, 3);
	cout << "+------------------+";
	gotoxy(43, 4);
	cout << "¦ THEM CAU HOI MOI ¦";
	gotoxy(43, 5);
	cout << "+------------------+";
}
void chooseSearch()
{
	gotoxy(34, 11);
	cout << "+------------------------------------------+";
	gotoxy(34, 12);
	cout << "¦ 1.           SO CAU HOI                  ¦";
	gotoxy(34, 13);
	cout << "¦------------------------------------------¦";
	gotoxy(34, 14);
	cout << "¦------------------------------------------¦";
	gotoxy(34, 15);
	cout << "¦ 2.         TIM KIEM CAU HOI              ¦";
	gotoxy(34, 16);
	cout << "¦------------------------------------------¦";
	gotoxy(34, 17);
	cout << "¦------------------------------------------¦";
	gotoxy(34, 18);
	cout << "¦ 3.         DANH SACH CAU HOI             ¦";
	gotoxy(34, 19);
	cout << "¦------------------------------------------¦";
	gotoxy(34, 20);
	cout << "¦------------------------------------------¦";
	gotoxy(34, 21);
	cout << "¦ 4.  	    THÔNG TIN GI?I THU?NG           ¦";
	gotoxy(34, 22);
	cout << "¦------------------------------------------¦";
	gotoxy(34, 23);
	cout << "¦------------------------------------------¦";
	gotoxy(34, 24);
	cout << "¦ 0.             QUAY LAI                  ¦";
	gotoxy(34, 25);
	cout << "+------------------------------------------+";
}