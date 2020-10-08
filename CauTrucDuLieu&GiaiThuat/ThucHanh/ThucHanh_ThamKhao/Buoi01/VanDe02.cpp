#include <iostream>
#include<time.h>
using namespace std;
int DocFileVaoMang(char* filename, long a[], long &n);
long LinearSearch(long a[],long n, long x);
void XuatMang(long a[], long n);

int main(int argc, char *argv[])
{
	long n, a[100005], x;
	clock_t start, end;
	printf("Nhap gia tri can tim: ");
	scanf("%d",&x);
	DocFileVaoMang("MangRandom.txt", a, n);
	
	//XuatMang(a,n);
	
	start= clock();
	long kq = LinearSearch(a, n, x);
	end = clock();
	
	if (kq != -1)
		printf("Tim thay tai vi tri %d\n", kq + 1);
	else
		printf("Khong tim thay\n");
	long long t= end - start;
	printf("Thoi gian TKTT la: %lld\n", t);
	return 0;
}
int DocFileVaoMang(char* filename, long a[], long &n)
{
	FILE* f = fopen(filename,"r");
	if (!f)
		return 0;
	long i=0;
	while (!feof(f))
	{
		fscanf(f,"%ld\t",&a[i]);
		i++;
	}
	
	fclose(f);
	n=i;
}
long LinearSearch(long a[], long n, long x)
{
	long i=0;
	a[n]=x;
	while (a[i]!=x)
		i++;
	if (i<n)
		return i;
	return -1;
}

void XuatMang(long a[], long n)
{
	printf("\n");
	for (long i=0; i<n; i++)
		printf("%10d", a[i]);
}