#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);
	
	int n;
	int i, j, k;
	scanf("%d", &n);
	
	int num[102];
	for(i = 0; i < n; ++i)
	{
		scanf("%d", &num[i]);
	}
	sort(num, num + n);
	
//	for(int i = 0; i < n; ++i)
//	{
//		printf("%d ", num[i]);
//	}

	int count = 0;
	for(i = n - 1; i >= 2; --i)
	{
		for(j = i - 1; j >= 1; --j)
		{
			for(k =  j - 1; k >= 0; --k)
			{
				if(num[i] > num[j] + num[k]) break;
				if(num[i] == num[j] + num[k])
				{
					count++;
					break;
				}
			}
			if(num[i] == num[j] + num[k]) break;
		}
	}
	
	printf("%d\n", count);
	
	//fclose(stdin);
	
	return 0;
}
