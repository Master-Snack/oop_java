#include <stdio.h>
#include <stdlib.h>
void Nhapmang(int a[], int n);
void Xuatmang(int a[], int n);
int main(int argc, char *argv[])
{
	int a[100], n, chon;
	do
	{
		printf("\n********* CHUONG TRINH NHAP MANG *********\n");
		printf("\nNhap 1: Phat sinh mang.");
		printf("\nNhap 2: Xuat mang.");
		printf("\nNhap 0: De thoat.");
		printf("\nNhap vao mot so: ");
		scanf("%d",&chon);
		switch(chon)
		{
			case 1:
			{
				printf("\nNhap vao so phan tu mang: ");
				scanf("%d",&n);
				Nhapmang(a,n);
				break;
			}
			case 2:
			{
				printf("\nXuat mang:\n");
				Xuatmang(a,n);	
				break;
			}
			default:
				break;
		}
	}while(chon!=0);
	return 0;
}
void Nhapmang(int a[], int n)
{
	for(int i=0;i<n;i++)
		a[i]=rand()%100;
}
void Xuatmang(int a[], int n)
{
	for(int i=0;i<n;i++)
		printf("%d\t",a[i]);
}