#include <iostream>
#include <stdio.h>
# include <stdlib.h>
#include<time.h>

using namespace std;


// Ham nhap mang
void NhapMang(int a[], int n){
	for(int i=0; i<n ;i++){
		a[i]=rand()%100;
	}
}
//ham xuat mang
void XuatMang(int a[], int n){
	for(int i=0; i<n; i++){
		printf("[%d]\t", a[i]);
	}
	
}

/**Thuat toan tim kiem tuyen tinh **/
int LinearSearch(int a[], int n, int x){
	int i =0; 
	while(i<n && a[i]!= x){
		i++;
	}
	if(i<n){
		return i+1;
	}return -1;
}

//Ham tim kiem nhi phan
int BinarySearch(int a[], int n, int x){
	
	int left = 0, right = n-1,mid;
	while (left <= right)
	{
		int m (left +right)/2;
		if(x == a[mid]) return m;
		if(x<a[mid])
	}
}

//Phat sinh mang tang
void PhatSinhMangTang(int a[], int n){
	srand(time(NULL));
	a[0] = rand()%50;
	for(int i=0; i<n; i++){
		a[i] = a[i-1] + rand()%10;
	}
}
//xap xep noi bot
void BubbleSort(int a[], int n){
	int temp;
	for(int i = 0; i<n ;i++){
		for(int j=n-1; j<n; j--){
			if(a[j] < a[j-1]){
				swap(a[i],a[j-1]);
	
			}
			
		}
	}
}


int main(){
	int a[1000], n=0, chon=0, x=0;
	do{
		printf("\n**********CHUONG TRINH NHAP MANG**********\n");
		printf("\n Nhap 1: Phat sinh mang.");
		printf("\n Nhap 2: Xuat Mang");
		printf("\n Nhap 3: Tim kiem tuyen tinh");
		printf("\n Nhap 4: Tim kiem nhi phan");
		printf("\n Nhap 5: Sap xep noi bot");
		printf("\n Nhap 0: De thoat!");
		printf("\n Nhap vao mot so: ");
		scanf("%d", &chon);
		switch(chon){
			case 1:
			{
				printf("\n Nhap vao so phan tu mang: ");
				scanf("%d",&n);
				NhapMang(a,n);
				break;
			}
			case 2:
			{
				if(n==0){
						printf("ban phai nhap mang truoc!!!");
						break;
				}
				printf("\n Xuat Mang \n");
				XuatMang(a,n);
				break;
			}
			case 3:
			{
				if(n==0){
						printf("ban phai nhap mang truoc!!!");
						break;
				}
				printf("Nhap so can tim kiem tuyen tinh:");
				scanf("%d", &x);
				if(LinearSearch(a,n,x)==-1)
					printf("Khong tim thay!\n");
				else
					printf("Tim thay %d tai vi tri: %d\n",x,LinearSearch(a,n,x));
				break;
			}
			case 4: 
			{
				if(n==0){
						printf("ban phai nhap mang truoc!!!");
						break;
				}
				int left,right,a1[1000],w;
				for(int i=0; i<n ;i++){
					a[i]=a1[i];
				}
				PhatSinhMangTang(a1,n);
				printf("Nhap so can tim kiem nhi phan:");
				scanf("%d", &x);
				w = BinarySearch(a1,n,x);
				if(w == -1)
					printf("Khong tim thay!\n");
				else{
					
					printf("Tim thay %d tai vi tri: %d \n", n,w+1);
				}
					
				break;
				
			}
			case 5:
			{
				if(n==0){
						printf("ban phai nhap mang truoc!!!");
						break;
				}
				printf("Mang da duoc xap xep ");
				BubbleSort(a,n);
			}
			default:
				break;
		}
   }while(chon!=0);
		return 0;
}



