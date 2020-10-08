# include <stdio.h>
# include <stdlib.h>
# include <time.h>

   /**BAI THUC HANH SO 1: CAC GIA THUAT TIM KIEM **/
// khai bao ham
void NhapMang(int a[], int n);
void XuatMang(int a[], int n);
int LinearSearch(int a[], int n, int x);
int BinarySearch(int a[], int left, int right, int x);

/**Problem 1: Viet cac ham Nhap/Xuat - Phat sinh- Doc/Ghi Mang  **/
// Ham nhap mang
void NhapMang(int a[], int n){
	for(int i=0; i<n ;i++){
		a[i]=rand()%100;
	}
}
//ham xuat mang
void XuatMang(int a[], int n){
	for(int i=0; i<n; i++){
		printf("%d\t", a[i]);
	}
	
}

/**Problem 2: Thuat toan tim kiem tuyen tinh **/
int LinearSearch(int a[], int n, int x){
	int i =0; 
	while(i<n && a[i]!= x){
		i++;
	}
	if(i<n){
		return i;
	}return -1;
}

/**Problem 3: Thuat toan tim kiem nhi phan **/
//Ham tim kiem nhi phan
int BinarySearch(int a[], int left, int right, int x){
	if(left > right){
		return -1;
	}
	int mid=(left + right)/2;
	if(x == a[mid]){
		return mid;
	}
	if(x < a[mid]){
		return BinarySearch(a,left,mid-1,x);
	}
	if(x > a[mid]){
		return BinarySearch(a,mid+1,right,x);
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
void BubbleSort(int a[], int n){
	int temp;
	for(int i = 0; i<n ;i++){
		for(int j=n-1; j<n; j--){
			if(a[j] < a[j-1]){
				temp = a[j];
				a[j] = a[j-1];
				a[j-1] = a[j];
			}
			
		}
	}
}

/**BTVN: Viet ham BinarySearch khong dung de quy  **/



//Ham chinh
int main(){
	int a[100], n, chon, x, left, right;
	double t = 0;;
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
				printf("\n Xuat Mang \n");
				XuatMang(a,n);
				break;
			}
			case 3:
			{
				printf("Nhap so can tim kiem tuyen tinh:");
				scanf("%d", &x);
				if(LinearSearch(a,n,x)==-1){
					printf("Khong tim thay!\n");
				}else{
					printf("Tim thay %d tai vi tri: %d\n", n,LinearSearch(a,n,x));
				}
			}
			case 4: 
			{
				printf("Nhap so phan tu can phat sinh mang:");
				scanf("%d", &n);
				PhatSinhMangTang(a,n);
				printf("Nhap so can tim kiem nhi phan:");
				scanf("%d", &x);
					if(BinarySearch(a,left,right,x) == -1){
					printf("Khong tim thay!\n");
				}else{
					printf("Tim thay %d tai vi tri: %d\n", n,BinarySearch(a,left,right,x));
				}
				
			}
			case 5:
			{
				printf("Mang sau khi sap xep la: ");
				BubbleSort(a,n);
			}
			default:
				break;
		}
   }while(chon!=0);
		return 0;
}


