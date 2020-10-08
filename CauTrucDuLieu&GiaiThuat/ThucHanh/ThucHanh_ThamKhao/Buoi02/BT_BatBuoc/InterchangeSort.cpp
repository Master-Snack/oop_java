#include <bits/stdc++.h>
using namespace std;

void PhatSinhMang(int a[], long n);
int GhiMangVaoFile(char* filename, int a[], long n);
void Swap(int &a, int &b);
long TimMin(int a[], long dau, long N);
void InterchangeSort(int a[], long n);
int main()
{
	int a[50000];
	long N;
	printf("Nhap so luong phan tu mang: ");
	scanf("%ld",&N);
	PhatSinhMang(a, N);
	GhiMangVaoFile("inpMang.txt", a, N);
	InterchangeSort(a, N);
	GhiMangVaoFile("outMang.txt", a, N);
	return 0;
}
void PhatSinhMang(int a[], long n)
{
	srand(time(NULL));
	for (long i=0; i<n; i++)
		a[i] = rand();

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

void Swap(int &a, int &b)
{
	int tmp = a;
		a	= b;
		b	= tmp;
}
long TimMin(int a[], long dau, long N)
{
	long min = dau;
	for (long i=dau+1; i<N; i++)
		if (a[min]>a[i])
			min = i;
	return min;
}
void InterchangeSort(int a[], long n)
{
   for (int i = 0; i < n-1; i++)
      for (int j = i+1; j < n; j++)
         if (a[i] > a[j])
         {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
         }
}
