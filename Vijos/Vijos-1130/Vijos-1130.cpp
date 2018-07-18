#include <iostream>

using namespace std;

double arr[1003];

int main()
{
	int i;
	int n;
	scanf("%d", &n);
	
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 2;
	for(i = 4; i <= n / 2; i = i + 2)
	{
		arr[i] = arr[i - 1] + arr[i / 2]; //f(i) = f(i - 1) + f(i / 2)
		arr[i + 1] = arr[i];
	}
//	for(i = 1; i <= n / 2; ++i) printf("%.0lf ", arr[i]);
//	printf("\n");
	
	double sum = 1;
	for(i = 1; i <= n / 2; ++i) sum += arr[i];
	
	printf("%.0lf\n", sum);
	
	
	return 0;	
} 
