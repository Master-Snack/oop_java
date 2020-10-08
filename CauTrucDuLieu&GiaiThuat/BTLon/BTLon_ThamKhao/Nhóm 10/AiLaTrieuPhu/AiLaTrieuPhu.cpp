// AiLaTrieuPhu.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "CauHoi.h"
using namespace std;

int* mucDiem;
int diemSan;
int thuTuCauHoiHienTai;
int diemHienTai;
ListCauHoi listCauHoi;
char tem[10];

void KhoiTao()
{
	diemSan = 0;
	thuTuCauHoiHienTai = 0;
	diemHienTai = 0;

	mucDiem = new int[15];
	mucDiem[0] = 200000;
	mucDiem[1] = 400000;
	mucDiem[2] = 600000;
	mucDiem[3] = 1000000;
	mucDiem[4] = 2000000;
	mucDiem[5] = 3000000;
	mucDiem[6] = 6000000;
	mucDiem[7] = 10000000;
	mucDiem[8] = 14000000;
	mucDiem[9] = 22000000;
	mucDiem[10] = 30000000;
	mucDiem[11] = 40000000;
	mucDiem[12] = 60000000;
	mucDiem[13] = 85000000;
	mucDiem[14] = 150000000;
}

void ThemCauHoi()
{
	CauHoi ch;
	cout << "Moi ban nhap ma cau hoi: ";
	cin >> ch.maCauHoi;
	cin.getline(tem, 10, '\n'); //Doc bo ky tu \n

	cout << "Moi ban nhap noi dung cau hoi (ket thuc bang ky tu #): ";
	cin.getline(ch.noiDungCauHoi, 5000, '#');	
	cin.getline(tem, 10, '\n'); //Doc bo ky tu \n

	cout << "Moi ban nhap noi dung dap an A (ket thuc bang dau #): ";
	cin.getline(ch.noiDungDapAn[A], 500, '#');
	cin.getline(tem, 10, '\n'); //Doc bo ky tu \n

	cout << "Moi ban nhap noi dung dap an B (ket thuc bang dau #): ";
	cin.getline(ch.noiDungDapAn[B], 500, '#');
	cin.getline(tem, 10, '\n'); //Doc bo ky tu \n

	cout << "Moi ban nhap noi dung dap an C (ket thuc bang dau #): ";
	cin.getline(ch.noiDungDapAn[C], 500, '#');
	cin.getline(tem, 10, '\n'); //Doc bo ky tu \n

	cout << "Moi ban nhap noi dung dap an D (ket thuc bang dau #): ";
	cin.getline(ch.noiDungDapAn[D], 500, '#');
	cin.getline(tem, 10, '\n'); //Doc bo ky tu \n

	cout << "Moi ban nhap dap an Dung (A = " << A << "; B = " << B << "; C = " << C << "; D = " << D << ")\n";
	cin >> ch.dapAnDung;
	cin.getline(tem, 10, '\n'); //Doc bo ky tu \n

	cout << "Moi ban nhap Muc Do Kho cua Cau Hoi (tu 1 den 15)";
	cin >> ch.thuTuCauHoi;
	ch.thuTuCauHoi--;
	cin.getline(tem, 10, '\n'); //Doc bo ky tu \n

	Node* newNode = new Node(ch);
	listCauHoi.AddFirst(newNode);
}

void LuuCauHoi()
{
	FILE * fout = fopen("dscauhoi.txt", "w");
	if (fout != NULL)
	{
		fprintf(fout, "%d\n", listCauHoi.count);

		Node* p = listCauHoi.first;
		while (p != NULL)
		{
			fprintf(fout, "%s\n", p->data.maCauHoi);
			fprintf(fout, "%d\n", strlen(p->data.noiDungCauHoi));
			fprintf(fout, "%s\n", p->data.noiDungCauHoi);
			for (int i = 0; i < 4; i ++)
			{
				fprintf(fout, "%d\n", strlen(p->data.noiDungDapAn[i]));
				fprintf(fout, "%s\n", p->data.noiDungDapAn[i]);
			}
			fprintf(fout, "%d\n", p->data.dapAnDung);
			fprintf(fout, "%d\n", p->data.thuTuCauHoi);

			p = p->link;
		}

		fclose(fout);
	}
}

void ReadCharacter(FILE * fout, char* strDes, int n)
{
	for (int i = 0; i < n; i ++)
		fscanf(fout, "%c", &strDes[i]);
	strDes[n] = '\0';
}

char c;
void LoadCauHoi()
{
	FILE * fout = fopen("dscauhoi.txt", "r");
	if (fout != NULL)
	{
		listCauHoi.RemoveAllFirst();
		int count = 0, soKyTu;
		fscanf(fout, "%d", &count);

		for (int i = 0; i < count; i++)
		{
			CauHoi ch;
			fscanf(fout, "%s", ch.maCauHoi);
			fscanf(fout, "%d", &soKyTu);
			fscanf(fout, "%c", &c); //Doc bo ky tu ke tiep (ky tu \n)
			ReadCharacter(fout, ch.noiDungCauHoi, soKyTu);
					
			for (int i = 0; i < 4; i++)
			{
				fscanf(fout, "%d", &soKyTu);
				fscanf(fout, "%c", &c); //Doc bo ky tu ke tiep (ky tu \n)
				ReadCharacter(fout, ch.noiDungDapAn[i], soKyTu);
			}
			
			fscanf(fout, "%d", &ch.dapAnDung);
			fscanf(fout, "%d", &ch.thuTuCauHoi);
			Node* newNode = new Node(ch);
			listCauHoi.AddFirst(newNode);
		}
		fclose(fout);
	}
}


int _tmain(int argc, _TCHAR* argv[])
{	
	KhoiTao();
	LoadCauHoi();
	int tl;
	CauHoi cauhoi;
	do
	{
		cout << "Nhap 1 bat dau them cau hoi moi\n";
		cout << "Nhap 4 de luu cau hoi xuong File\n";
		cout << "Nhap 5 de bat dau Game moi\n";
		cout << "Nhap 7 de sua cau hoi\n";
		cin >> tl;
		cin.getline(tem, 10, '\n'); //Doc bo ky tu \n
		if (tl == 1)
			ThemCauHoi();
		if (tl == 4)
			LuuCauHoi();
		if (tl == 5)
		{
			diemSan = 0;
			thuTuCauHoiHienTai = 0;
			diemHienTai = 0;

			do 
			{
				Node* ch = listCauHoi.SearchRandom(thuTuCauHoiHienTai);
				if (ch == NULL)
				{
					cout << "khong tim thay cau hoi\n";
				}
				else
				{
					char da;
					system("CLS");
					cout << "SO DIEM HIEN TAI: " << diemHienTai << endl;
					ch->XuatRaManHinh();
					cout << "\nMoi ban chon dap an A, B, C hoac D\nNhap N de dung cuoc choi\nChon P de su dung quyen tro giup 50/50\n";
					cin >> da;
					if (da == 'n' || da == 'N')
					{
						cout << "BAN DA DUNG CUOC CHOI\nSo diem hien tai cua ban la: " << diemHienTai << endl;
						break;
					}
					else if (da == 'p' || da == 'P')
					{
						ch->XuatRa2DapAnDung();
						cout << "Moi ban chon dap an A, B, C hoac D\nNhap N de dung cuoc choi\n";
						cin >> da;
						if (da == 'n' || da == 'N')
						{
							cout << "BAN DA DUNG CUOC CHOI\nSo diem hien tai cua ban la: " << diemHienTai << endl;
							break;
						}						
					}
					else if (( (da == 'A' || da == 'a') && ch->data.dapAnDung == A)
						|| ((da == 'B' || da == 'b') && ch->data.dapAnDung == B)
						|| ((da == 'C' || da == 'c') && ch->data.dapAnDung == C)
						|| ((da == 'D' || da == 'd') && ch->data.dapAnDung == D))
					{
						diemHienTai = mucDiem[thuTuCauHoiHienTai];
						cout << "Chinh xac. Xin chuc mung\nSo diem hien tai cua ban la: " << diemHienTai << endl;
						thuTuCauHoiHienTai++;
						if (thuTuCauHoiHienTai == 5 || thuTuCauHoiHienTai == 10)
							diemSan = mucDiem[thuTuCauHoiHienTai];
						if (thuTuCauHoiHienTai == 15)
							cout << "*************************CHUC MUNG, BAN DA CHIEN THANG!*************************" << endl;
					}
					else
					{
						if(ch->data.dapAnDung == A)
							cout << "Rat tiec, dap an dung la A" << endl;
						else if (ch->data.dapAnDung == B)
							cout << "Rat tiec, dap an dung la B" << endl;
						else if (ch->data.dapAnDung == C)
							cout << "Rat tiec, dap an dung la C" << endl;
						else if (ch->data.dapAnDung == D)
							cout << "Rat tiec, dap an dung la D" << endl;

						diemHienTai = diemSan;
						cout << "So diem dat duoc cua ban la: " << diemHienTai << endl;
						cout << "*************************GAME OVER!*************************" << endl;
						break;
					}
				}
			} while (thuTuCauHoiHienTai < 15);
		}	
		if (tl == 7) {
			cout << "Moi ban nhap ma cau hoi muon sua: ";
			cin >> cauhoi.maCauHoi;
			cin.getline(tem, 10, '\n'); //Doc bo ky tu \n
			listCauHoi.SuaCauHoi(cauhoi, thuTuCauHoiHienTai);
			cout << "Ban da sua thanh cong!!!!!!!! ";
			//LuuCauHoi();
			break;
		}
	} while (true);
}

