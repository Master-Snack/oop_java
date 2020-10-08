#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
//---------------------------------------------------------------------------------------------------------------------------------
struct CauHoi {
	int maCau;
	string noiDung;
	string dapAn_A;
	string dapAn_B;
	string dapAn_C;
	string dapAn_D;
	int dapAn_Dung;
};
struct  Node
{
	CauHoi Key;
	struct Node* pLeft;
	struct Node* pRight;
};

typedef struct CauHoi CAUHOI;
typedef struct Node NODE;
typedef NODE* TREE;

void KhoiTao_Tree(TREE& DSCH) {
	DSCH = NULL;
}

void ThemNodeVaoTree(TREE& DSCH, CAUHOI x) {
	if (DSCH == NULL) {
		NODE* p = new NODE;
		p->Key = x;
		p->pLeft = NULL;
		p->pRight = NULL;
		DSCH = p;
	}
	else {
		if (DSCH->Key.maCau > x.maCau) {
			ThemNodeVaoTree(DSCH->pLeft, x);
		}
		else if (DSCH->Key.maCau < x.maCau) {
			ThemNodeVaoTree(DSCH->pRight, x);
		}
	}
}

void textColor(int x) {
	HANDLE color;
	color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, x);
}
//=================================================================================================================================
int diemGoi(char luaGoi) {
	if (luaGoi == '1') {
		return 100;
	}
	if (luaGoi == '2') {
		return 200;
	}
	if (luaGoi == '3') {
		return 300;
	}
}

void ManHinh_KetQua(char luaGoi, int tongDiem) {
	char dieuHuong = '\n';
	do {
		system("cls");
		cout << "\n\n" << endl;
		cout << "\t\t\t|==============================================================|" << endl;
		cout << "\t\t\t|                    KET QUA THI TRAC NGHIEM                   |" << endl;
		cout << "\t\t\t|==============================================================|" << endl;
		cout << "\t\t\t|                                                              |" << endl;
		cout << "\t\t\t|--------------------------------------------------------------|" << endl;
		cout << "\t\t\t|                             GOI " << luaGoi << "                            |" << endl;
		cout << "\t\t\t|--------------------------------------------------------------|" << endl;
		cout << "\t\t\t|                                                              |" << endl;
		cout << "\t\t\t|--------------------------------------------------------------|" << endl;
		if (tongDiem == 0)
			cout << "\t\t\t|                       SO DIEM: " << tongDiem << " / " << diemGoi(luaGoi) << "                       |" << endl;
		else if (tongDiem < 100)
			cout << "\t\t\t|                       SO DIEM: " << tongDiem << " / " << diemGoi(luaGoi) << "                      |" << endl;
		else
			cout << "\t\t\t|                       SO DIEM: " << tongDiem << " / " << diemGoi(luaGoi) << "                     |" << endl;
		cout << "\t\t\t|--------------------------------------------------------------|" << endl;
		cout << "\t\t\t|                                                              |" << endl;
		cout << "\t\t\t|==============================================================|" << endl;
		cout << "\n\n\t\t\t\tNhan phim bat ki de quay lai!!!\n\n" << endl;
		system("pause");
	} while (dieuHuong != '\n');
}
//---------------------------------------------------------------------------------------------------------------------------------
int bienDoi_KetQua(char x) {
	int dapAn = 0;
	if (x == 'A' || x == 'a' || x == '1') {
		dapAn = 1;
		return dapAn;
	}
	if (x == 'B' || x == 'b' || x == '2') {
		dapAn = 2;
		return dapAn;
	}
	if (x == 'C' || x == 'c' || x == '3') {
		dapAn = 3;
		return dapAn;
	}
	if (x == 'D' || x == 'd' || x == '4') {
		dapAn = 4;
		return dapAn;
	}
	return dapAn;
}

char traVe_KetQua(int x) {
	if (x == 1) {
		return 'A';
	}
	if (x == 2) {
		return 'B';
	}
	if (x == 3) {
		return 'C';
	}
	if (x == 4) {
		return 'D';
	}
	return 'S';
}

void Xuat_CauHoi(TREE DSCH, int& soCau, int& tongDiem, char luaGoi, int cauHoiGoi) {
	if (DSCH != NULL) {
		int flag = 0;
		char dapAn;
		int kiemTra = 0;
		int goi = 0;
		do {
		LAI: do {
			system("cls");
			cout << "\n\n" << endl;
			cout << "\tSO DIEM HIEN TAI: " << tongDiem << endl;
			cout << endl;
			if (soCau >= 10) {
				cout << "\t|==========================================================================================================|" << endl;
				cout << "\t|------------------------------------------------CAU " << soCau << "----------------------------------------------------|" << endl;
				cout << "\t|==========================================================================================================|" << endl;
			}
			else {
				cout << "\t|==========================================================================================================|" << endl;
				cout << "\t|------------------------------------------------CAU " << soCau << "-----------------------------------------------------|" << endl;
				cout << "\t|==========================================================================================================|" << endl;
			}

			cout << endl;
			cout << "\t\tNoi dung: ";
			cout << DSCH->Key.noiDung << endl;
			cout << "\n" << endl;
			cout << "\n\t\tA.\t";
			cout << DSCH->Key.dapAn_A << endl;
			cout << "\n\t\tB.\t";
			cout << DSCH->Key.dapAn_B << endl;
			cout << "\n\t\tC.\t";
			cout << DSCH->Key.dapAn_C << endl;
			cout << "\n\t\tD.\t";
			cout << DSCH->Key.dapAn_D << endl;
			cout << "\n\n" << endl;
			cout << "\t|==========================================================================================================|" << endl;
			cout << "\n\n\t\t\tCau tra loi cua ban la: ";
			cin >> dapAn;
			kiemTra = bienDoi_KetQua(dapAn);
			goi = bienDoi_KetQua(luaGoi);
			if (kiemTra == 0) {
				cout << "\n\n\t\t\tDap an khong hop le!!!\n\n" << endl;
				Beep(00, 1500);
				cout << "\n\n" << endl;
				goto LAI;
			}

			if (goi == 1) {
				if (kiemTra == DSCH->Key.dapAn_Dung) {
					cout << "\n\t\t\tCau tra loi chinh xac!!!" << endl;
					cout << "\n\t\t\tDap an dung la: \t" << traVe_KetQua(DSCH->Key.dapAn_Dung);
					if (traVe_KetQua(DSCH->Key.dapAn_Dung) == 'A')
						cout << ".\t" << DSCH->Key.dapAn_A << endl;
					if (traVe_KetQua(DSCH->Key.dapAn_Dung) == 'B')
						cout << ".\t" << DSCH->Key.dapAn_B << endl;
					if (traVe_KetQua(DSCH->Key.dapAn_Dung) == 'C')
						cout << ".\t" << DSCH->Key.dapAn_C << endl;
					if (traVe_KetQua(DSCH->Key.dapAn_Dung) == 'D')
						cout << ".\t" << DSCH->Key.dapAn_D << endl;
					tongDiem += 20;
				}
				else {
					cout << "\n\t\t\tCau tra loi khong chinh xac!!!" << endl;
					cout << "\n\t\t\tDap an dung la: \t" << traVe_KetQua(DSCH->Key.dapAn_Dung);
					if (traVe_KetQua(DSCH->Key.dapAn_Dung) == 'A')
						cout << ".\t" << DSCH->Key.dapAn_A << endl;
					if (traVe_KetQua(DSCH->Key.dapAn_Dung) == 'B')
						cout << ".\t" << DSCH->Key.dapAn_B << endl;
					if (traVe_KetQua(DSCH->Key.dapAn_Dung) == 'C')
						cout << ".\t" << DSCH->Key.dapAn_C << endl;
					if (traVe_KetQua(DSCH->Key.dapAn_Dung) == 'D')
						cout << ".\t" << DSCH->Key.dapAn_D << endl;
				}
			}
			if (goi == 2) {
				if (kiemTra == DSCH->Key.dapAn_Dung) {
					cout << "\n\t\t\tCau tra loi chinh xac!!!" << endl;
					cout << "\n\t\t\tDap an dung la: \t" << traVe_KetQua(DSCH->Key.dapAn_Dung);
					if (traVe_KetQua(DSCH->Key.dapAn_Dung) == 'A')
						cout << ".\t" << DSCH->Key.dapAn_A << endl;
					if (traVe_KetQua(DSCH->Key.dapAn_Dung) == 'B')
						cout << ".\t" << DSCH->Key.dapAn_B << endl;
					if (traVe_KetQua(DSCH->Key.dapAn_Dung) == 'C')
						cout << ".\t" << DSCH->Key.dapAn_C << endl;
					if (traVe_KetQua(DSCH->Key.dapAn_Dung) == 'D')
						cout << ".\t" << DSCH->Key.dapAn_D << endl;
					tongDiem += 20;
				}
				else {
					cout << "\n\t\t\tCau tra loi khong chinh xac!!!" << endl;
					cout << "\n\t\t\tDap an dung la: \t" << traVe_KetQua(DSCH->Key.dapAn_Dung);
					if (traVe_KetQua(DSCH->Key.dapAn_Dung) == 'A')
						cout << ".\t" << DSCH->Key.dapAn_A << endl;
					if (traVe_KetQua(DSCH->Key.dapAn_Dung) == 'B')
						cout << ".\t" << DSCH->Key.dapAn_B << endl;
					if (traVe_KetQua(DSCH->Key.dapAn_Dung) == 'C')
						cout << ".\t" << DSCH->Key.dapAn_C << endl;
					if (traVe_KetQua(DSCH->Key.dapAn_Dung) == 'D')
						cout << ".\t" << DSCH->Key.dapAn_D << endl;
				}
			}
			if (goi == 3) {
				if (kiemTra == DSCH->Key.dapAn_Dung) {
					cout << "\n\t\t\tCau tra loi chinh xac!!!" << endl;
					cout << "\n\t\t\tDap an dung la: \t" << traVe_KetQua(DSCH->Key.dapAn_Dung);
					if (traVe_KetQua(DSCH->Key.dapAn_Dung) == 'A')
						cout << ".\t" << DSCH->Key.dapAn_A << endl;
					if (traVe_KetQua(DSCH->Key.dapAn_Dung) == 'B')
						cout << ".\t" << DSCH->Key.dapAn_B << endl;
					if (traVe_KetQua(DSCH->Key.dapAn_Dung) == 'C')
						cout << ".\t" << DSCH->Key.dapAn_C << endl;
					if (traVe_KetQua(DSCH->Key.dapAn_Dung) == 'D')
						cout << ".\t" << DSCH->Key.dapAn_D << endl;
					tongDiem += 20;
				}
				else {
					cout << "\n\t\t\tCau tra loi khong chinh xac!!!" << endl;
					cout << "\n\t\t\tDap an dung la: \t" << traVe_KetQua(DSCH->Key.dapAn_Dung);
					if (traVe_KetQua(DSCH->Key.dapAn_Dung) == 'A')
						cout << ".\t" << DSCH->Key.dapAn_A << endl;
					if (traVe_KetQua(DSCH->Key.dapAn_Dung) == 'B')
						cout << ".\t" << DSCH->Key.dapAn_B << endl;
					if (traVe_KetQua(DSCH->Key.dapAn_Dung) == 'C')
						cout << ".\t" << DSCH->Key.dapAn_C << endl;
					if (traVe_KetQua(DSCH->Key.dapAn_Dung) == 'D')
						cout << ".\t" << DSCH->Key.dapAn_D << endl;
				}
			}

			cout << "\n\n\n\t\t\tNhan bat ki phim nao de tiep tuc!!!\n\n" << endl;
			system("pause");
		} while (kiemTra == 0);
		flag = 1;
		} while (flag == 0);
		soCau++;
		if (soCau < cauHoiGoi + 1)
			Xuat_CauHoi(DSCH->pLeft, soCau, tongDiem, luaGoi, cauHoiGoi);
		if (soCau < cauHoiGoi + 1)
			Xuat_CauHoi(DSCH->pRight, soCau, tongDiem, luaGoi, cauHoiGoi);
	}
}

void Doc_File(TREE& DSCH) {
	ifstream FileData;
	FileData.open("D:\\Data.txt", ios_base::in);
	srand((int)time(0));
	while (!FileData.eof())
	{
		CAUHOI x;

		x.maCau = rand();
		FileData.ignore();
		getline(FileData, x.noiDung);
		getline(FileData, x.dapAn_A);
		getline(FileData, x.dapAn_B);
		getline(FileData, x.dapAn_C);
		getline(FileData, x.dapAn_D);
		FileData >> x.dapAn_Dung;

		ThemNodeVaoTree(DSCH, x);

	}

	FileData.close();
}

void ManHinh_HienThi(char luaGoi, int& tongDiem, int& cauHoiGoi) {
	int soCau = 1;
	TREE DSCH;
	KhoiTao_Tree(DSCH);
	Doc_File(DSCH);
	Xuat_CauHoi(DSCH, soCau, tongDiem, luaGoi, cauHoiGoi);
}
//---------------------------------------------------------------------------------------------------------------------------------
void ChonGoi_CauHoi(char& luaGoi, int& cauHoiGoi) {
	cout << endl;
	int x = 0;
	do {
		system("cls");
		cout << "\n\n" << endl;
		cout << "\t|==========================================================================================================|" << endl;
		cout << "\t|---------------------------------------------CHON GOI CAU HOI---------------------------------------------|" << endl;
		cout << "\t|==========================================================================================================|" << endl;
		cout << endl;
		cout << "\t\t\t\t1. Goi 100 diem: Gom 5 cau hoi !" << endl;
		cout << endl;
		cout << "\t\t\t\t2. Goi 200 diem: Gom 10 cau hoi !" << endl;
		cout << endl;
		cout << "\t\t\t\t3. Goi 300 diem: Gom 15 cau hoi !" << endl;
		cout << endl;
		cout << "\t|==========================================================================================================|" << endl;
		cout << "\n\n\n\t\tMoi dua ra lua chon Goi cau hoi: ";
		cin >> luaGoi;
		switch (luaGoi)
		{
		case '1':
			cout << "\n\n\t\t\tBan da chon: GOI 100 DIEM voi 05 Cau hoi!\n" << endl;
			cauHoiGoi = 5;
			x = 1;
			Beep(00, 1500);
			break;
		case '2':
			cout << "\n\n\t\t\tBan da chon: GOI 200 DIEM voi 10 Cau hoi!\n" << endl;
			cauHoiGoi = 10;
			x = 1;
			Beep(00, 1500);
			break;
		case '3':
			cout << "\n\n\t\t\tBan da chon: GOI 300 DIEM voi 15 Cau hoi!\n" << endl;
			cauHoiGoi = 15;
			x = 1;
			Beep(00, 1500);
			break;
		default:
			cout << "\n\t\t\tLua chon khong hop le!!!" << endl;
			Beep(00, 1500);
			break;
		}
	} while (x != 1);
}

void ManHinh_BatDau() {
	char luaGoi;
	int cauHoiGoi = 0;
	int tongDiem = 0;
	ChonGoi_CauHoi(luaGoi, cauHoiGoi);
	ManHinh_HienThi(luaGoi, tongDiem, cauHoiGoi);
	ManHinh_KetQua(luaGoi, tongDiem);
}

//=================================================================================================================================
void HienThi(string x) {
	for (int i = 0; i < x.length(); i++) {
		cout << x[i];
		Sleep(50);
	}
	cout << endl;
}

void ManHinh_TheLe() {
	cout << endl;
	char dieuHuong = '\n';
	do {
		system("cls");
		char cachThi[100] = "1. Cach thi: ";
		char dauTien[300] = "- Dau tien chon 1 trong 3 goi cau hoi voi so diem va do kho khac nhau:";
		char goiCauHoi1[100] = "+ Goi 100 diem: Gom 5 cau hoi !";
		char goiCauHoi2[100] = "+ Goi 200 diem: Gom 10 cau hoi !";
		char goiCauHoi3[100] = "+ Goi 300 diem: Gom 15 cau hoi !";
		char tiepDo[300] = "- Tiep do se tra loi lan luot tat ca cau hoi cua Goi da chon!";
		char cachTinhDiem[100] = "2. Cach tinh diem: ";
		char yTinh1[300] = "- Moi cau tra loi DUNG se duoc 10% so diem cua Goi cau hoi!";
		char yTinh2[300] = "- Truong hop tra loi SAI khong duoc tinh diem va chuyen sang cau hoi moi!";
		cout << "\n\n" << endl;
		cout << "\t|==========================================================================================================|" << endl;
		cout << "\t|--------------------------------------------------THE LE--------------------------------------------------|" << endl;
		cout << "\t|==========================================================================================================|" << endl;
		cout << endl;
		cout << "\t\t\t";
		HienThi(cachThi);
		cout << endl;
		cout << "\t\t";
		HienThi(dauTien);
		cout << endl;
		cout << "\t\t\t";
		HienThi(goiCauHoi1);
		cout << endl;
		cout << "\t\t\t";
		HienThi(goiCauHoi2);
		cout << endl;
		cout << "\t\t\t";
		HienThi(goiCauHoi3);
		cout << endl;
		cout << "\t\t";
		HienThi(tiepDo);
		cout << endl;
		Beep(00, 1500);
		cout << endl;
		cout << "\t\t\t";
		HienThi(cachTinhDiem);
		cout << endl;
		cout << "\t\t";
		HienThi(yTinh1);
		cout << endl;
		cout << "\t\t";
		HienThi(yTinh2);
		cout << endl;
		cout << endl;
		cout << "\t|==========================================================================================================|" << endl;
		cout << "\n\n\t\t\t\tNhan phim bat ki de quay lai!!!\n\n" << endl;
	} while (dieuHuong != '\n');
	system("pause");
}
//=================================================================================================================================
void Duyet_Ghi(TREE DSCH, ofstream& FileData) {
	if (DSCH != NULL) {
		FileData << "\n";
		FileData << DSCH->Key.noiDung;
		FileData << "\n";
		FileData << DSCH->Key.dapAn_A;
		FileData << "\n";
		FileData << DSCH->Key.dapAn_B;
		FileData << "\n";
		FileData << DSCH->Key.dapAn_C;
		FileData << "\n";
		FileData << DSCH->Key.dapAn_D;
		FileData << "\n";
		FileData << DSCH->Key.dapAn_Dung;

		Duyet_Ghi(DSCH->pLeft, FileData);
		Duyet_Ghi(DSCH->pRight, FileData);
	}
}

void Ghi_File(TREE& DSCH) {
	ofstream FileData;
	FileData.open("D:\\Data.txt", ios_base::out);

	Duyet_Ghi(DSCH, FileData);

	FileData.close();
}
//---------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------
NODE* Search(TREE& DSCH, int x) {
	if (DSCH == NULL)
		return NULL;
	else {
		if (DSCH->Key.maCau > x)
			Search(DSCH->pLeft, x);
		else if (DSCH->Key.maCau < x)
			Search(DSCH->pRight, x);
		else
			return DSCH;
	}
}
void SuaCauHoi_DapAn(TREE& DSCH) {
	int x;
	int kq = 0;
	system("cls");
	cout << "\n\n\n" << endl;
	cout << "\t\t\t|=======================================================|" << endl;
	cout << "\t\t\t|-------------------SUA MOT CAU HOI---------------------|" << endl;
	cout << "\t\t\t|=======================================================|" << endl;
	cout << "\n\t\t\tNhap maCau x can sua: ";
	cin >> x;
	Node* xyz = Search(DSCH, x);
	if (xyz != NULL) {
		system("cls");
		cout << "\n\n\n" << endl;
		cout << "\t\t\t|=======================================================|" << endl;
		cout << "\t\t\t|-------------------SUA MOT CAU HOI---------------------|" << endl;
		cout << "\t\t\t|=======================================================|" << endl;
		Beep(00, 500);
		cout << "\n\t\t\tNoi dung cau hoi hien tai: " << endl;
		cout << "\n\t\t\tNoi dung: " << xyz->Key.noiDung << endl;
		cout << "\t\t\tDap an A: " << xyz->Key.dapAn_A << endl;
		cout << "\t\t\tDap an B: " << xyz->Key.dapAn_B << endl;
		cout << "\t\t\tDap an C: " << xyz->Key.dapAn_C << endl;
		cout << "\t\t\tDap an D: " << xyz->Key.dapAn_D << endl;
		cout << "\t\t\tDap an Dung: " << xyz->Key.dapAn_Dung << endl;
		cout << endl;
		cout << "\n\t\t\tNhap lai thong tin cau hoi: " << endl;
		cin.ignore();
		cout << "\n\t\t\tNhap noiDung: ";
		getline(cin, xyz->Key.noiDung);
		cout << "\n\t\t\tNhap dapAn_A: ";
		getline(cin, xyz->Key.dapAn_A);
		cout << "\n\t\t\tNhap dapAn_B: ";
		getline(cin, xyz->Key.dapAn_B);
		cout << "\n\t\t\tNhap dapAn_C: ";
		getline(cin, xyz->Key.dapAn_C);
		cout << "\n\t\t\tNhap dapAn_D: ";
		getline(cin, xyz->Key.dapAn_D);
		cout << "\n\t\t\tNhap dapAn_Dung: ";
		cin >> xyz->Key.dapAn_Dung;
		cout << endl;
		kq = 1;
	}
	else {
		system("cls");
		cout << "\n\n\n" << endl;
		cout << "\t\t\t|=======================================================|" << endl;
		cout << "\t\t\t|-------------------SUA MOT CAU HOI---------------------|" << endl;
		cout << "\t\t\t|=======================================================|" << endl;
		Beep(00, 500);
		cout << "\n\t\t\tKhong tim thay cau hoi can sua thong tin !!!" << endl;
		cout << endl;
		Beep(00, 1500);
	}

	if (kq == 1) {
		system("cls");
		cout << "\n\n\n" << endl;
		cout << "\t\t\t|=======================================================|" << endl;
		cout << "\t\t\t|-------------------SUA MOT CAU HOI---------------------|" << endl;
		cout << "\t\t\t|=======================================================|" << endl;
		Beep(00, 500);
		char WIN[50] = "SUA CAU HOI THANH CONG!!!";
		cout << "\n\t\t\t\t\t";
		HienThi(WIN);
		cout << "\n\n\n";
		Beep(00, 1500);
	}
	else {
		system("cls");
		cout << "\n\n\n" << endl;
		cout << "\t\t\t|=======================================================|" << endl;
		cout << "\t\t\t|-------------------SUA MOT CAU HOI---------------------|" << endl;
		cout << "\t\t\t|=======================================================|" << endl;
		Beep(00, 500);
		char LOSE[50] = "SUA CAU HOI THAT BAI!!!";
		cout << "\n\t\t\t\t\t";
		HienThi(LOSE);
		cout << "\n\n\n";
		Beep(00, 1500);

	}
}
//---------------------------------------------------------------------------------------------------------------------------------
void searchStandFor(TREE& p, TREE& q) {
	if (q->pLeft)
		searchStandFor(p, q->pLeft);
	else
	{
		p->Key = q->Key;
		p = q;
		q = q->pRight;
	}
}

int delNode(TREE& DSCH, int X) {
	if (DSCH == NULL)
		return 0;
	if (DSCH->Key.maCau > X)
		return delNode(DSCH->pLeft, X);
	if (DSCH->Key.maCau < X)
		return delNode(DSCH->pRight, X);
	//T->Key == X
	Node* p = DSCH;
	if (DSCH->pLeft == NULL)
		DSCH = DSCH->pRight;
	else
		if (DSCH->pRight == NULL)
			DSCH = DSCH->pLeft;
		else
			searchStandFor(p, DSCH->pRight);
	delete p;
	return 1;
}

void XoaMotCauHoi(TREE& DSCH, int& soCau) {
	int x;
	int kq = 0;
	char luaChon;
	system("cls");
	cout << "\n\n\n" << endl;
	cout << "\t\t\t|=======================================================|" << endl;
	cout << "\t\t\t|-------------------XOA MOT CAU HOI---------------------|" << endl;
	cout << "\t\t\t|=======================================================|" << endl;
	cout << "\n\t\t\tNhap maCau x can xoa: ";
	cin >> x;
	NODE* xyz = Search(DSCH, x);
	if (xyz != NULL) {
		char X[50] = "BAN DA CHON XOA CAU HOI !!!";
		char KX[50] = "BAN DA CHON KHONG XOA CAU HOI !!!";
		system("cls");
		cout << "\n\n\n" << endl;
		cout << "\t\t\t|=======================================================|" << endl;
		cout << "\t\t\t|-------------------XOA MOT CAU HOI---------------------|" << endl;
		cout << "\t\t\t|=======================================================|" << endl;
		Beep(00, 500);
		cout << "\n\t\t\tNoi dung cau hoi can xoa: " << endl;
		cout << "\n\t\t\tNoi dung: " << xyz->Key.noiDung << endl;
		cout << "\t\t\t\tDap an A: " << xyz->Key.dapAn_A << endl;
		cout << "\t\t\t\tDap an B: " << xyz->Key.dapAn_B << endl;
		cout << "\t\t\t\tDap an C: " << xyz->Key.dapAn_C << endl;
		cout << "\t\t\t\tDap an D: " << xyz->Key.dapAn_D << endl;
		cout << "\t\t\t\tDap an Dung: " << xyz->Key.dapAn_Dung << endl;
		cout << endl;
		cout << "\n\t\t\tChac chan Ban muon xoa (Y/N)? : ";
		cin >> luaChon;
		if (luaChon == 'Y' || luaChon == 'y') {
			cout << "\n\t\t\t";
			HienThi(X);
			cout << endl;
			Beep(00, 500);
			kq = delNode(DSCH, x);
			soCau--;
		}
		else {
			cout << "\n\t\t\t";
			HienThi(KX);
			cout << endl;
			Beep(00, 500);
		}

	}
	else {
		system("cls");
		cout << "\n\n\n" << endl;
		cout << "\t\t\t|=======================================================|" << endl;
		cout << "\t\t\t|-------------------XOA MOT CAU HOI---------------------|" << endl;
		cout << "\t\t\t|=======================================================|" << endl;
		Beep(00, 1500);
		cout << "\n\t\t\tKhong tim thay cau hoi can xoa !!!" << endl;
		cout << endl;
		Beep(00, 1500);
	}

	if (kq == 1) {
		system("cls");
		cout << "\n\n\n" << endl;
		cout << "\t\t\t|=======================================================|" << endl;
		cout << "\t\t\t|-------------------XOA MOT CAU HOI---------------------|" << endl;
		cout << "\t\t\t|=======================================================|" << endl;
		Beep(00, 500);
		char ketQua[50] = "XOA CAU HOI THANH CONG!!!";
		cout << "\n\t\t\t\t\t";
		HienThi(ketQua);
		cout << "\n\n\n";
		Beep(00, 1500);
	}
	else {
		system("cls");
		cout << "\n\n\n" << endl;
		cout << "\t\t\t|=======================================================|" << endl;
		cout << "\t\t\t|-------------------XOA MOT CAU HOI---------------------|" << endl;
		cout << "\t\t\t|=======================================================|" << endl;
		Beep(00, 500);
		char ketQua[50] = "XOA CAU HOI THAT BAI!!!";
		cout << "\n\t\t\t\t\t";
		HienThi(ketQua);
		cout << "\n\n\n";
		Beep(00, 1500);
	}
}
//---------------------------------------------------------------------------------------------------------------------------------
void nhapCauHoi(CauHoi& x) {
	cout << "\t\t\tNhap maCau: ";
	cin >> x.maCau;
	cin.ignore();
	cout << "\n\t\t\tNhap noiDung: ";
	getline(cin, x.noiDung);
	cout << "\n\t\t\tNhap dapAn_A: ";
	getline(cin, x.dapAn_A);
	cout << "\n\t\t\tNhap dapAn_B: ";
	getline(cin, x.dapAn_B);
	cout << "\n\t\t\tNhap dapAn_C: ";
	getline(cin, x.dapAn_C);
	cout << "\n\t\t\tNhap dapAn_D: ";
	getline(cin, x.dapAn_D);
	cout << "\n\t\t\tNhap dapAn_Dung: ";
	cin >> x.dapAn_Dung;
}

int Insert_CauHoi(TREE& DSCH, CauHoi x) {
	if (DSCH) {
		if (DSCH->Key.maCau == x.maCau)
			return 0;
		if (DSCH->Key.maCau > x.maCau)
			return Insert_CauHoi(DSCH->pLeft, x);
		else
			return Insert_CauHoi(DSCH->pRight, x);
	}
	DSCH = new Node;
	if (DSCH == NULL)
		return -1;
	DSCH->Key = x;
	DSCH->pLeft = NULL;
	DSCH->pRight = NULL;
	return 1;
}

void ThemCauHoi(TREE& DSCH, int& flag, int& soCau) {
	CauHoi x;
	system("cls");
	cout << "\n\n\n" << endl;
	cout << "\t\t\t|=======================================================|" << endl;
	cout << "\t\t\t|-------------------THEM CAU HOI MOI--------------------|" << endl;
	cout << "\t\t\t|=======================================================|" << endl;
	Beep(00, 500);
	char HT[50] = "Moi ban nhap cau hoi can them: ";
	cout << "\n\t\t\t\t";
	HienThi(HT);
	cout << endl;
	nhapCauHoi(x);
	int kq = 0;
	kq = Insert_CauHoi(DSCH, x);
	if (kq == 1) {
		soCau++;
		flag = 1;
	}
}

void ThemCauHoiMoi(TREE& DSCH, int& soCau) {
	int flag = 0;
	ThemCauHoi(DSCH, flag, soCau);
	if (flag == 1) {
		system("cls");
		cout << "\n\n\n" << endl;
		cout << "\t\t\t|=======================================================|" << endl;
		cout << "\t\t\t|-------------------THEM CAU HOI MOI--------------------|" << endl;
		cout << "\t\t\t|=======================================================|" << endl;
		Beep(00, 500);
		char ketQua[50] = "THEM CAU HOI THANH CONG!!!";
		cout << "\n\t\t\t\t\t";
		HienThi(ketQua);
		cout << "\n\n\n";
		Beep(00, 1500);
	}
	if (flag == 0) {
		system("cls");
		cout << "\n\n\n" << endl;
		cout << "\t\t\t|=======================================================|" << endl;
		cout << "\t\t\t|-------------------THEM CAU HOI MOI--------------------|" << endl;
		cout << "\t\t\t|=======================================================|" << endl;
		Beep(00, 500);
		char ketQua[50] = "THEM CAU HOI THAT BAI!!!";
		cout << "\n\t\t\t\t\t";
		HienThi(ketQua);
		cout << "\n\n\n";
		Beep(00, 1500);
	}
}
//---------------------------------------------------------------------------------------------------------------------------------
void ManHinh_XuatDSCH() {
	system("cls");
	cout << "\n\n\n" << endl;
	cout << "\t\t\t|=======================================================|" << endl;
	cout << "\t\t\t|-------------------DANH SACH CAU HOI-------------------|" << endl;
	cout << "\t\t\t|=======================================================|" << endl;
	cout << "\n" << endl;
}

void Xuat_DSCH(TREE& DSCH, int& cauThu) {
	if (DSCH != NULL) {
		Xuat_DSCH(DSCH->pLeft, cauThu);
		cout << "\tCau " << cauThu << "\t(Ma cau: "<< DSCH->Key.maCau << ") :"  << endl;
		cout << "\t\tNoi dung: " << DSCH->Key.noiDung << endl;
		cout << "\t\t\tDap an A: " << DSCH->Key.dapAn_A << endl;
		cout << "\t\t\tDap an B: " << DSCH->Key.dapAn_B << endl;
		cout << "\t\t\tDap an C: " << DSCH->Key.dapAn_C << endl;
		cout << "\t\t\tDap an D: " << DSCH->Key.dapAn_D << endl;
		cout << endl;
		cauThu++;
		Beep(00, 100);
		Xuat_DSCH(DSCH->pRight, cauThu);
	}
}
//---------------------------------------------------------------------------------------------------------------------------------
void Doc_File_Admin(TREE& DSCH, int& soCau) {
	ifstream FileData;
	FileData.open("D:\\Data.txt", ios_base::in);
	while (!FileData.eof())
	{
		CAUHOI x;
		x.maCau = rand();
		FileData.ignore();
		getline(FileData, x.noiDung);
		getline(FileData, x.dapAn_A);
		getline(FileData, x.dapAn_B);
		getline(FileData, x.dapAn_C);
		getline(FileData, x.dapAn_D);
		FileData >> x.dapAn_Dung;

		ThemNodeVaoTree(DSCH, x);
		soCau++;
	}

	FileData.close();
}

void ManHinh_MenuAdmin(char& luaChon) {
	system("cls");
	cout << "\n\n" << endl;
	cout << "\t\t\t|==============================================================|" << endl;
	cout << "\t\t\t|                CHUONG TRINH MENU QUYEN ADMIN                 |" << endl;
	cout << "\t\t\t|==============================================================|" << endl;
	cout << "\t\t\t|                                                              |" << endl;
	cout << "\t\t\t|--------------------------------------------------------------|" << endl;
	cout << "\t\t\t|        Chon '1':  HIEN THI DANH SACH CAU HOI !!!             |" << endl;
	cout << "\t\t\t|--------------------------------------------------------------|" << endl;
	cout << "\t\t\t|                                                              |" << endl;
	cout << "\t\t\t|--------------------------------------------------------------|" << endl;
	cout << "\t\t\t|        Chon '2':  THEM CAU HOI MOI !!!                       |" << endl;
	cout << "\t\t\t|--------------------------------------------------------------|" << endl;
	cout << "\t\t\t|                                                              |" << endl;
	cout << "\t\t\t|--------------------------------------------------------------|" << endl;
	cout << "\t\t\t|        Chon '3':  XOA MOT CAU HOI !!!                        |" << endl;
	cout << "\t\t\t|--------------------------------------------------------------|" << endl;
	cout << "\t\t\t|                                                              |" << endl;
	cout << "\t\t\t|--------------------------------------------------------------|" << endl;
	cout << "\t\t\t|        Chon '4':  SUA NOI DUNG MOT CAU HOI !!!               |" << endl;
	cout << "\t\t\t|--------------------------------------------------------------|" << endl;
	cout << "\t\t\t|                                                              |" << endl;
	cout << "\t\t\t|--------------------------------------------------------------|" << endl;
	cout << "\t\t\t|        Chon '0':  KET THUC !!!                               |" << endl;
	cout << "\t\t\t|--------------------------------------------------------------|" << endl;
	cout << "\t\t\t|                                                              |" << endl;
	cout << "\t\t\t|==============================================================|" << endl;
	cout << "\t\t\t\t\tMoi nhap lua chon: ";
	cin >> luaChon;
}

int KiemTra_Admin() {
	int flag = 0;
	string id = "Admin";
	string password = "H4cker";

	string ID = "";
	string PASSWORD = "";
	char TB[45] = "MOI BAN DIEN THONG TIN: ";
	char WIN[45] = "DANG NHAP THANH CONG VOI QUYEN ADMIN !!!";
	char LOSE[45] = "DANG NHAP THAT BAI VOI QUYEN ADMIN !!!";

	while (true)
	{
		system("cls");
		cout << "\n\n\n" << endl;
		cout << "\t\t\t|=======================================================|" << endl;
		cout << "\t\t\t|---------YEU CAU DANG NHAP VOI QUYEN ADMIN-------------|" << endl;
		cout << "\t\t\t|=======================================================|" << endl;
		cout << "\n\n\t\t\t\t";
		HienThi(TB);
		cout << "\n\n\n\t\t\t\tNhap ID: ";
		cin >> ID;
		if (ID.compare(id) == 0) {
			cout << "\n\n\t\t\t\tNhap PASSWORD: ";
			cin >> PASSWORD;
			if (PASSWORD.compare(password) == 0) {
				system("cls");
				cout << "\n\n\n" << endl;
				cout << "\t\t\t|=======================================================|" << endl;
				cout << "\t\t\t|---------YEU CAU DANG NHAP VOI QUYEN ADMIN-------------|" << endl;
				cout << "\t\t\t|=======================================================|" << endl;
				cout << "\n\n\t\t\t\t";
				HienThi(WIN);
				cout << endl;
				flag = 1;
				Beep(00, 1500);
				break;
			}
			else {
				system("cls");
				cout << "\n\n\n" << endl;
				cout << "\t\t\t|=======================================================|" << endl;
				cout << "\t\t\t|---------YEU CAU DANG NHAP VOI QUYEN ADMIN-------------|" << endl;
				cout << "\t\t\t|=======================================================|" << endl;
				cout << "\n\n\t\t\t\t";
				HienThi(LOSE);
				cout << endl;
				Beep(00, 1500);
				break;
			}

		}
		else {
			cout << "\n\n\t\t\t\tID Admin sai! Kiem tra lai!" << endl;
			Beep(00, 1500);
		}
	}
	return flag;
}

void LuaChon_Khac() {
	if (KiemTra_Admin() == true) {
		char luaChon;
		TREE DSCH;
		int soCau = 1;
		int cauThu = 1;
		KhoiTao_Tree(DSCH);
		Doc_File_Admin(DSCH, soCau);
		char ketThuc[50] = "KET THUC CHUONG TRINH ADMIN !!!";
		int flag = 0;
		do {
			ManHinh_MenuAdmin(luaChon);
			switch (luaChon)
			{
			case '1':
				ManHinh_XuatDSCH();
				Xuat_DSCH(DSCH, cauThu);
				cauThu = 1;
				cout << "\n\n\t\tTong so cau hoi la: " << soCau - 1 << " !!!" << "\n\n" << endl;
				cout << "\n\n\t\tNhan phim bat ky de quay lai !!!" << "\n\n" << endl;
				system("pause");
				break;
			case '2':
				ThemCauHoiMoi(DSCH, soCau);
				flag = 1;
				break;
			case '3':
				XoaMotCauHoi(DSCH, soCau);
				flag = 1;
				break;
			case '4':
				SuaCauHoi_DapAn(DSCH);
				flag = 1;
				break;
			case '0':
				cout << "\n\t\t\t\t\t";
				HienThi(ketThuc);
				cout << "\n\n\n" << endl;
				Ghi_File(DSCH);
				Beep(00, 1500);
				break;
			default:
				cout << "\n\t\t\t\t\tLua chon khong hop le!\n\n\n" << endl;
				Beep(00, 1500);
				break;
			}
		} while (luaChon != '0');
	}
}

//=================================================================================================================================
void ManHinh_MenuChinh(char& luaChon) {
	system("cls");
	cout << "\n\n" << endl;
	cout << "\t\t\t|==============================================================|" << endl;
	cout << "\t\t\t|                 CHUONG TRINH THI TRAC NGHIEM                 |" << endl;
	cout << "\t\t\t|==============================================================|" << endl;
	cout << "\t\t\t|                                                              |" << endl;
	cout << "\t\t\t|--------------------------------------------------------------|" << endl;
	cout << "\t\t\t|                   Chon '1':  BAT DAU  !!!                    |" << endl;
	cout << "\t\t\t|--------------------------------------------------------------|" << endl;
	cout << "\t\t\t|                                                              |" << endl;
	cout << "\t\t\t|--------------------------------------------------------------|" << endl;
	cout << "\t\t\t|                   Chon '2':  THE LE   !!!                    |" << endl;
	cout << "\t\t\t|--------------------------------------------------------------|" << endl;
	cout << "\t\t\t|                                                              |" << endl;
	cout << "\t\t\t|--------------------------------------------------------------|" << endl;
	cout << "\t\t\t|                   Chon '3':  CHUC NANG KHAC!!!               |" << endl;
	cout << "\t\t\t|--------------------------------------------------------------|" << endl;
	cout << "\t\t\t|                                                              |" << endl;
	cout << "\t\t\t|--------------------------------------------------------------|" << endl;
	cout << "\t\t\t|                   Chon '0':  KET THUC !!!                    |" << endl;
	cout << "\t\t\t|--------------------------------------------------------------|" << endl;
	cout << "\t\t\t|                                                              |" << endl;
	cout << "\t\t\t|==============================================================|" << endl;
	cout << "\t\t\t\t\tMoi nhap lua chon: ";
	cin >> luaChon;
}

void ChuongTrinhChinh() {
	char luaChon;
	char ketThuc[50] = "KET THUC CHUONG TRINH THI TRAC NGHIEM!!!";
	do {
		textColor(12);
		ManHinh_MenuChinh(luaChon);
		switch (luaChon)
		{
		case '1':
			textColor(14);
			ManHinh_BatDau();
			break;
		case '2':
			textColor(10);
			ManHinh_TheLe();
			break;
		case '3':
			textColor(11);
			LuaChon_Khac();
			break;
		case '0':
			cout << "\n\t\t\t\t\t";
			HienThi(ketThuc);
			cout << "\n\n\n" << endl;
			Beep(00, 1500);
			break;
		default:
			cout << "\n\t\t\t\t\tLua chon khong hop le!!!\n\n\n" << endl;
			Beep(00, 1500);
			break;
		}
	} while (luaChon != '0');

}
//=================================================================================================================================
//=================================================================================================================================
//=================================================================================================================================
int main()
{
	ChuongTrinhChinh();

	return 0;
}