#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct WORD{
	char Name[15];
	char Meaning[30];
};
const char FILENAME[]="tudienanhviet.txt";
int n;
WORD TDAV[1000];
int DocFileTextVaoMang(WORD a[], int &n);
int GhiMangVaoFileText();
void QuickSort(WORD a[], int l,int r);
void Swap(WORD &a, WORD &b);
void BinarySearch(WORD a[], int l, int r,char* x);
void Menu();
int main()
{
	DocFileTextVaoMang(TDAV,n);
	QuickSort(TDAV,0,n-1);
	Menu();
	return 0;
}
int DocFileTextVaoMang(WORD a[], int &n)
{
	FILE* f=fopen(FILENAME,"r");
	if(!f)
		return 0;
	int i=0;
	while(!feof(f)){
		fscanf(f,"%s",&a[i].Name);
		fgets(a[i].Meaning,30,f);
		i++;
	}
	fclose(f);
	n=i;
}
int GhiMangVaoFileText()
{
	int temp=0;
	char a[15],b[30];
	printf("Moi nhap so tu can them vao tu dien: ");
	scanf("%d",&temp);
	FILE* f = fopen(FILENAME, "a");
	if(!f)
		return 0;
	for(int i=0;i<temp;i++)
	{
		fflush(stdin);
		printf("Vocabunary %d: ", i+1);
		gets(a);
		fflush(stdin);
		printf("Meaning %d: ", i+1);
		gets(b);
		printf("\n");
		fprintf(f,"\n%s %s",a,b);
	}
	fclose(f);
	DocFileTextVaoMang(TDAV,n);
	return 1;
}
void QuickSort(WORD a[], int l,int r)
{
	int i=l, j=r;
	char x[15];
	strcpy(x,a[(l+r)/2].Name);
	do
	{
		while(stricmp(a[i].Name,x)<0)
			i++;
		while(stricmp(a[j].Name,x)>0)
			j--;
		if(i<=j)
		{
			Swap(a[i],a[j]);
			i++;
			j--;
		}
	}while(i<j);
	if(l<j)
		QuickSort(a,l,j);
	if(r>i)
		QuickSort(a,i,r);
}
void Swap(WORD &a, WORD &b)
{
	WORD c=a;
	a=b;
	b=c;
}
void BinarySearch(WORD a[], int l, int r, char* x)
{
	if(l>r)
	{
		printf("Khong tim thay!!!\n\n");
		getchar();
		return;
	}
	int m=(l+r)/2;
	if(!stricmp(a[m].Name,x))
	{
		printf("Nghia cua tu %s la: %s\n", x, a[m].Meaning);
		getchar();
		return;		
	}
	else if(stricmp(a[m].Name,x)<0)
		BinarySearch(a,m+1,r,x);
	else
		BinarySearch(a,l,m-1,x);
}
void Menu()
{
	system("cls");
	int LC;
	printf("\n------------------------------------------------------\n");
	printf("\n---------------------Dictionary-----------------------\n");
	printf("\n------------------------------------------------------\n");
	printf("\t1/Them tu vung moi!\n\t2/Tra tu!\n\t3/Thoat!\n\t-->Moi nhap lua chon cua ban: ");
	scanf("%d", &LC);
	switch (LC)
	{
	case 1:
		GhiMangVaoFileText();
		QuickSort(TDAV, 0, n - 1);
		break;
	case 2:
		char word[15];
		printf("Moi nhap tu can tra nghia: ");
		fflush(stdin);
		gets(word);
		fflush(stdin);
		BinarySearch(TDAV, 0, n - 1, word);
		break;
	default:
		return;
	}
	Menu();
}