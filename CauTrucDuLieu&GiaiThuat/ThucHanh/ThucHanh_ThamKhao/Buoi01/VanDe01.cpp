#include <iostream>
using namespace std;
void PhatSinhMang(int a[], int n);
void PhatSinhMangTang(long a[], long n);
void XuatMang(long a[], long n);
int GhiMangVaoFile(char* filename, long a[], long n);
int DocFileVaoMang(char* filename, long a[], long n);
int main(int argc, char *argv[])
{
	long n, a[100001];
	printf("Nhap so luong phan tu mang: ");
	scanf("%d",&n);
	PhatSinhMangTang(a, n);
	GhiMangVaoFile("MangRandom.txt", a, n);
	
	return 0;
}
void PhatSinhMang(long a[], long n)
{
	srand(time(NULL));
	for (long i=0; i<n; i++)
		a[i] = rand();
		
}
void XuatMang(long a[], long n)
{
	printf("\n");
	for (long i=0; i<n; i++)
		printf("%10d", a[i]);
}
int GhiMangVaoFile(char* filename, long a[], long n)
{
	FILE* f = fopen(filename,"w");
	if (!f)
		return 0;
	for (long i=0; i<n; i++)
		fprintf(f, "%d\t", a[i]);
	fclose(f);
	return 1;
}
int DocFileVaoMang(char* filename, long a[], long n)
{
	FILE* f = fopen(filename,"r");
	if (!f)
		return 0;
	long i=0;
	while (!feof(f))
	{
		fscanf(f,"%d",&a[i]);
		i++;
	}
	n=i;
}
void PhatSinhMangTang(long a[], long n)
{
	srand(time(NULL));
	a[0] = rand() %50;
	for (long i=1; i<n; i++)
		a[i] = a[i-1]+ rand()%10;
		
}