#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int n, x;
	
	while(scanf("%d%d", &n , &x) != EOF)
	{
		int idx = 1;
		int num;
		int sum = 0;
		int cur = n;
		while(cur != 0)
		{
			num = cur % 10;
			cur = cur / 10;
			if(x == 0) sum += idx * (cur - 1);
			else sum += idx * cur;
			if(num > x) sum += idx;
			else if(num == x) sum += n % idx + 1;
			idx *= 10;
		}
		printf("%d\n", sum);	
	}
	
}
