#include<stdio.h>
#include<string.h>
struct WORD{
	char Name[15];
	char Meaning[40];
};
const char FILENAME[]="tudien.txt";
int n;
WORD dic[1000];
int DocFileTextVaoMang(WORD a[], int &n);
int GhiMangVaoFileText();
void QuickSort(WORD a[], int l,int r);
void Swap(WORD &a, WORD &b);
void BinarySearch(WORD a[], int l, int r,char* x);
void menu();
int main(){
	printf("\n---------------------Dictionary-----------------------\n");
	DocFileTextVaoMang(dic,n);
	QuickSort(dic,0,n-1);
	menu();
	return 0;
}
int DocFileTextVaoMang(WORD a[], int &n){
	FILE* f=fopen(FILENAME,"r");
	if(!f)
		return 0;
	int i=0;
	while(!feof(f)){
		fscanf(f,"%s",&a[i].Name);
		fgets(a[i].Meaning,40,f);
		i++;
	}
	fclose(f);
	n=i;
}
int GhiMangVaoFileText(){
	int temp=2;
	char a[20],b[30];
	FILE* f = fopen(FILENAME,"a");
	printf("Nhap so tu can them: ");
	scanf("%d",&temp);
	if(!f)
		return 0;
	for(int i=0;i<temp;i++){

		fflush(stdin);
		printf("Vocabunary: ");
		gets(a);
		fflush(stdin);
		printf("\nMeaning: ");
		gets(b);
		printf("\n");
		fprintf(f,"\n%s %s",a,b);
	}

	fclose(f);
	DocFileTextVaoMang(dic,n);
	return 1;
}
void QuickSort(WORD a[], int l,int r){
	int i=l, j=r;
	char x[15];
	strcpy(x,a[(l+r)/2].Name);
	do{
		while(stricmp(a[i].Name,x)<0)
			i++;
		while(stricmp(a[j].Name,x)>0)
			j--;
		if(i<=j){
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
void Swap(WORD &a, WORD &b){
	WORD c=a;
	a=b;
	b=c;
}
void BinarySearch(WORD a[], int l, int r, char* x){
	if(l>r){
		printf("Unsupported\n\n");
		return;
	}
	int m=(l+r)/2;
	if(!stricmp(a[m].Name,x)){
		printf("Nghia cua %s la: %s\n", x, a[m].Meaning);
		return;
	}
	else if(stricmp(a[m].Name,x)<0)
		BinarySearch(a,m+1,r,x);
	else
		BinarySearch(a,l,m-1,x);
}
int menu(){
	char var;
	printf("1.Them tu vung\n2.Tra tu.\n3.Thoat.\nNhap moi lua chon!: ");
	scanf("%d",&var);
	switch(var){
		case 1:
			GhiMangVaoFileText();
			QuickSort(dic,0,n-1);
			break;
		case 2:
			char word[15];
			printf("Nhap tu can tra: ");
			fflush(stdin);
			gets(word);
			fflush(stdin);
			BinarySearch(dic,0,n-1,word);
			break;
		default:
			return;
	}
	menu();
}
