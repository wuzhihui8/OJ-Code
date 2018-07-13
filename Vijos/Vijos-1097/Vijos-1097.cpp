#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int arr[20002];

int main()
{
	//freopen("input.txt", "r", stdin);
	
	int i, j;
	int n;
	while(scanf("%d", &n) != EOF)
	{
		for(i = 0; i < n; ++i)
		{
			scanf("%d", &arr[i]);
		}
		sort(arr, arr + n);
//		for(int i = 0; i < n; ++i) printf("%d ", arr[i]);
//		printf("\n");

		int sum = 0;
		for(i = 1; i < n; ++i)
		{
			int tmp = arr[i - 1] + arr[i];
			sum += tmp;
			for(j = i + 1; j < n; ++j)
			{
				if(arr[j] < tmp) arr[j - 1] = arr[j];
				else break;
			}
			arr[j - 1] = tmp;
		}
		
		printf("%d\n", sum);
	}
	
	//fclose(stdin);
	
	return 0;
} 
