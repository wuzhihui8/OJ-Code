#include <iostream>
#include <cstdio>

using namespace std;

int arr[102];

int main()
{
	//freopen("input.txt", "r", stdin);
	
	int i, j, k;
	int n;
	while(scanf("%d", &n) != EOF)
	{
		int sum = 0;
		for(i = 0;i < n; ++i)
		{
			scanf("%d", &arr[i]);
			sum += arr[i];
		}
		int avg = sum / n;
		int count = 0;
		for(i = 0;i < n - 1; ++i)
		{
			if(arr[i] != avg)
			{
				++count;
				if(arr[i] > avg) arr[i + 1] += arr[i] - avg;
				else arr[i + 1] -= avg - arr[i];
			}
		}
		printf("%d\n", count);
	}
	
	//fclose(stdin);
	
	return 0;
}
