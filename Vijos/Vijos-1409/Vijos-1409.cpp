#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int arr[30002];

int main()
{
	//freopen("input.txt", "r", stdin);
	
	int i, j, k;
	int n, w;
	
	while(scanf("%d%d", &w, &n) != EOF)
	{
		for(i = 0; i < n; ++i) scanf("%d", &arr[i]);
		sort(arr, arr + n);
//		for(i = 0; i < n; ++i) printf("%d ", arr[i]);
//		printf("\n");

		int count = 0;
		for(i = n - 1; i >= 0; --i)
		{
			for(j = i - 1; j >= 0; --j)
			{
				if(arr[i] + arr[j] <= w)
				{
					for(k = j + 1; k <= i - 1; ++k) arr[k - 1] = arr[k];
					--i;
					break;
				}
			}
			++count;
		}
		
		printf("%d\n", count);
	}
	
	//fclose(stdin);
	
	return 0;
} 
