#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int bucket[20003];

int main()
{
	//freopen("input.txt", "r", stdin);
	
	int i, j, k;
	int n;
	int x, y;
	//while(scanf("%d", &n) != EOF)
	//{
	scanf("%d", &n);
		memset(bucket, 0, sizeof(bucket));
		for(i = 0; i < n; ++i)
		{
			scanf("%d%d", &x, &y);
			bucket[y + 10000]++;
		}
		
		//求中位数
		int idx1 = (n - 1) / 2;
		int idx2 = n / 2;
		int y1, y2;
		int count = 0;
		for(i = 0; i < 20003; ++i)
		{
			count += bucket[i];
			if(count > idx1) y1 = i;
			if(count > idx2)
			{
				y2 = i;
				break;
			}
		}
		y = (y1 + y2) / 2; //两个数中间的任意数值均可，因此无需求实数的平均数
		
		//求最小距离
		int sum = 0;
		for(i = 0; i < 20003; ++i)
		{
			sum += abs(y - i) * bucket[i];	
		} 
		printf("%d\n", sum);
	//}
	
	//fclose(stdin);
	
	return 0;
}
