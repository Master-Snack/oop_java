#include <iostream>
#include<time.h>
using namespace std;
int DocFileVaoMang(char* filename, int a[], int &n);
int BinarySearchDQ(int a[], int L, int R, int x);
int BinarySearchNoDQ(int a[], int n, int x);
int main(int argc, char *argv[])
{
	int n, a[100005], x;
	clock_t start, end;
	printf("Nhap gia tri can tim: ");
	scanf("%d",&x);
	DocFileVaoMang("MangRandom.txt", a, n);
	//int kq = BinarySearchDQ(a, 0, n-1, x);
	
	start= clock();
	int kq = BinarySearchNoDQ(a, n, x);
	end= clock();
	if (kq != -1)
		printf("Tim thay tai vi tri %d\n", kq + 1);
	else
		printf("Khong tim thay\n");
	
	long long t= end - start;
	printf("Thoi gian TKTT la: %lld\n", t);
	return 0;
}
int DocFileVaoMang(char* filename, int a[], int &n)
{
	FILE* f = fopen(filename,"r");
	if (!f)
		return 0;
	int i=0;
	while (!feof(f))
	{
		fscanf(f,"%d",&a[i]);
		i++;
	}
	n=i;
}
int BinarySearchDQ(int a[], int L, int R, int x)
{
	if (L>R) 
			return -1;
	int mid = (L+R)/2;
	if (x== a[mid]) 
			return mid;
	if (x< a[mid])
			return BinarySearchDQ(a, L, mid-1, x);
	else
			return BinarySearchDQ(a, mid+1, R, x);
	
	
}
int BinarySearchNoDQ(int a[], int n, int x)
{
	int L=0, R=n-1, mid;
	while (L<=R)
	{
		mid = (L+R)/2;
		if (x== a[mid]) 
				return mid;
		if (x< a[mid])
				R= mid-1;
		else
				L=mid+1;

	}
	return -1;
}