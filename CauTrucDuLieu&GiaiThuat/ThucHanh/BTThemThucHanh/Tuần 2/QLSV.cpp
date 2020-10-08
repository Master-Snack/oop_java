#include <bits/stdc++.h>
using namespace std;

typedef struct sinhvien
{
    string mssv,  sex;
    char tenSV[40], diaChi[40];
    float diemTB;
}SINHVIEN;
void displayMenu();
void them_banghi(struct sinhvien st[],int& biendem);
void find(struct sinhvien st[], int biendem);
int search(struct sinhvien st[], string id,int biendem);
void viewAll(struct sinhvien st[], int biendem);
void SortDiem(struct sinhvien dataset[], int n);
void SortTen(struct sinhvien st[],int n);

int main()
{
    sinhvien st[80];
    int biendem=0;
    int luachon;
    char confirm;
    do
    {
    	system("cls");
    	displayMenu();
        cout<<"\nMoi nhap lua chon (1-5): ";
        cin>>luachon;

        switch(luachon)
        {
            case 1:them_banghi(st, biendem);break;
            case 2:viewAll(st, biendem);break;
            case 3:find(st, biendem);break;
            case 4:SortDiem(st,biendem);break;
            case 5:SortTen(st,biendem);break;
            default:cout<<"Khong hop le";
        }
        cout<<"Nhan y hoac Y de tiep tuc: ";
        cin>>confirm;
    }while(confirm=='y'||confirm=='Y');

    return 0;
}

void displayMenu(){
    cout<<"=========================================="<<"\n";
    cout<<"====================MENU=================="<<"\n";
    cout<<"=========================================="<<"\n";
    cout<<" 1. Them ban ghi sinh vien"<<"\n";
    cout<<" 2. In danh sach sinh vien"<<"\n";
    cout<<" 3. Xuat thong tin cua sinh vien co ma so X"<<"\n";
    cout<<" 4. Sap xep DS sinh vien theo TT tang dan diem TB"<<"\n";
    cout<<" 5. Sap xep DS sinh vien theo TT tang dan ho va ten"<<"\n";
}
void them_banghi(struct sinhvien st[],int& biendem)
{
    again:
    cout<<"\nNhap ID cua sinh vien: ";
    cin>>st[biendem].mssv;
    if (search(st,st[biendem].mssv,biendem)!=-1)
    {
        cout<<"ID nay da ton tai\n";
        goto again;
    }
    fflush(stdin);
    printf("Nhap Ho ten Sinh vien: ");
    gets(st[biendem].tenSV);
    fflush(stdin);
    printf("Nhap Gioi tinh Sinh vien (F hoac M): ");
    cin>>st[biendem].sex;
    fflush(stdin);
    printf("Nhap Dia chi Sinh vien: ");
    gets(st[biendem].diaChi);
    fflush(stdin);
    cout<<"Nhap Diem trung binh Sinh vien: ";
    cin>>st[biendem].diemTB;

    ++biendem;
}
void find(struct sinhvien st[], int biendem)
{
    string id;
    cout<<"Nhap ID cua sinh vien can xuat: ";
    cin>>id;

    int index=search(st,id,biendem);
    if (index != -1)
    {
        cout<<left<<setw(5)<<st[index].mssv<<setw(20)<<st[index].tenSV<<setw(5)<<st[index].sex<<setw(20)<<st[index].diaChi;
        cout<<setw(5)<<st[index].diemTB;
        cout<<"\n";

    }
    else
        cout<<"Ban ghi khong ton tai!\n";

}
int search(struct sinhvien st[], string id,int biendem)
{
    int found =-1;
    for (int i = 0; i < biendem && found==-1; i++)
    {
        if (st[i].mssv == id) found=i;
    }

    return found;
}
void viewAll(struct sinhvien st[], int biendem)
{
    int i=0;
    cout<<left<<setw(10)<<"ID"<<setw(30)<<"TEN"<<setw(15)<<"GIOI TINH"<<setw(20)<<"DIA CHI"<<setw(5)<<"DIEM TB"<<"\n";
    cout<<"=======================================================================================\n";
    fflush(stdin);
    while(i<=biendem)
    {
        if(st[i].mssv!="")
        {
            istringstream is(st[i].tenSV);
            cout<<left<<setw(10)<<st[i].mssv<<setw(30)<<st[i].tenSV<<setw(15)<<st[i].sex<<setw(20)<<st[i].diaChi;
            cout<<setw(5)<<st[i].diemTB;

            cout<<"\n";
        }
        i=i+1;
    }
}
void SortDiem(struct sinhvien dataset[], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = n - 1; j > i; j--)
            if (dataset[j].diemTB < dataset[j - 1].diemTB )
            {
                sinhvien  temp = dataset[j];
                    dataset[j] = dataset[j - 1];
                dataset[j - 1] = temp;
            }

}
void SortTen(struct sinhvien st[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
		   if (strcmp(st[i].tenSV,st[j].tenSV)<0)
		  {
                sinhvien    k=st[i];
                        st[i]=st[j];
                        st[j]=k;
		  }
		}
	}
}


