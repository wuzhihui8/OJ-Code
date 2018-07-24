#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

//int arr[102];
int bucket[1002]; //N个1到1000之间的随机整数

int main()
{
	//freopen("input.txt", "r", stdin);
	
	int i, j;
	int n;
	int tmp;
	scanf("%d", &n); //N≤100
	
	memset(bucket, 0, sizeof(bucket));
	int count = 0;
	for(i = 0; i < n; ++i)
	{
		scanf("%d", &tmp);
		if(!bucket[tmp])
		{
			count++;
			bucket[tmp]++;
		}
	}
	
	printf("%d\n", count);
	int flag = 1;
	for(i = 1; i <= 1000; ++i)
	{
		if(bucket[i])
		{
			if(flag)
			{
				printf("%d" , i);
				flag = 0;
			}
			else
			{
				printf(" %d", i);
			}
		}
	}
	printf("\n");
	
	//fclose(stdin);
	
	return 0;
}
