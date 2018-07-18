#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const int max_n = 1000000;

int arr[max_n + 2];

int main()
{
	//freopen("input.txt", "r", stdin);
	
	int i, j;
	
//	memset(arr, 0, sizeof(arr));
//	for(i = 2; i <= sqrt(max_n); ++i)
//	{
//		if(!arr[i])
//		{
//			j = i + i;
//			while(j <= max_n)
//			{
//				arr[j] = 1;
//				j += i;
//			}
//		}
//	}
	
//	for(i = 2; i <= max_n; ++i)
//	{
//		if(!arr[i]) printf("%d ", i);
//	}
	
	int x0, y0;
	scanf("%d%d", &x0, &y0);
	if(y0 % x0 != 0)
	{
		printf("0\n");
	}
	else
	{
		y0 /= x0;
		
		//求质因子
		int count = 0;
		while(y0 != 1)
		{
			for(i = 2; i <= y0; ++i)
			{
				if(y0 % i == 0) break;
			}
			if(arr[count - 1] != i) arr[count++] = i;
			y0 = y0 / i;
		}
		
		//for(i = 0; i < count; ++i) printf("%d ", arr[i]);
		printf("%.0lf\n", pow(2, count));
	}
	
	//fclose(stdin);
	
	return 0;
}
