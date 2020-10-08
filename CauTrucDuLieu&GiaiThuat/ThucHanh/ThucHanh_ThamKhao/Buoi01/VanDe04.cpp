#include<time.h>
int main()
{
	clock_t start, end;

	start=clock();
	
	end = clock();
	double t=end - start;
	printf("Thoi gian TKTT la: %f\n", t);
}
