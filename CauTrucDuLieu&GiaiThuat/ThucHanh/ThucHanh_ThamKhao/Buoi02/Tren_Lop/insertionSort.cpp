#include <iostream>
using namespace std;

int GhiMangVaoFile(char* filename, int a[], long n);
int DocFileVaoMang(char* filename, int a[], long n);
long viTriChen(int a[], long k);
void Chen(int a[], long k);
void InsertionSort(int a[], long n);
int main()
{
	int a[50000];
	long N;
	DocFileVaoMang("inpMang.txt", a, N);
	InsertionSort(a, N);
	GhiMangVaoFile("outMang_Insert.txt", a, N);
	return 0;
}
int GhiMangVaoFile(char* filename, int a[], long n)
{
	FILE* f = fopen(filename,"w");
	if (!f)
		return 0;
	
	for (long i=0; i<n; i++)
		fprintf(f, "%-10d", a[i]);
	fclose(f);
	return 1;
}
int DocFileVaoMang(char* filename, int a[], long n)
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
long viTriChen(int a[], long k)
{
	if (a[k]<a[0]) return 0;
	for (long i=0; i<k; i++)
		if ((a[i]<=a[k])&&(a[k]<=a[i+1]))
			return i+1;
	return k;
}
void Chen(int a[], long k)
{
	long vt = viTriChen(a, k);
	if (vt != k)
	{
		long j=k;
		int x=a[k];
		while (j>vt)
		{
			a[j]=a[j-1];
			j--;
		}
		a[j]=x;
	}
}
void InsertionSort(int a[], long n)
{
	for (long i=1; i<n; i++)
		Chen(a, i);
}