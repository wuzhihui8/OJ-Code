#include <iostream>
#include <cstring>

using namespace std;

char str[500];

//最大公约数 
int gcd(int a, int b)
{
	int r;
	while(b != 0)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	int i;
	
	while(scanf("%s", str) != EOF)
	{
		//printf("%s\n", str);
		int n[200];
		int ni;
		if(str[0] != '[') //分数 
		{
			//获取分数和分母 
			ni = 0;
			n[0] = 0; n[1] = 0;
			for(i = 0;i < strlen(str); ++i)
			{
				if(str[i] == '/')
				{
					ni++;
					continue;
				}
				n[ni] = n[ni] * 10 + (str[i] - '0');
			}
			//printf("%d / %d\n", n[0], n[1]);
			
			if(n[0] % n[1] != 0)
			{
				printf("[%d;", n[0] / n[1]);
				int tmp = n[0] % n[1];
				n[0] = n[1];
				n[1] = tmp;
				
				while(n[0] % n[1] != 0)
				{
					printf("%d,", n[0] / n[1]);
					tmp = n[0] % n[1];
					n[0] = n[1];
					n[1] = tmp;
				}			
				printf("%d]\n", n[0] / n[1]);
			}
			else
			{
				printf("[%d]\n", n[0] / n[1]);
			}
		}
		else
		{
			//获取分数数组
			ni = 0;
			n[0] = 0;
			for(i = 1; i < strlen(str) - 1; ++i)
			{
				if(str[i] == ',' || str[i] == ';')
				{
					ni++;
					n[ni] = 0;
					continue;
				}
				n[ni] = n[ni] * 10 + (str[i] - '0');
//				printf("n[%d]=%d ", ni, n[ni]);
			}
			
//			for(int i = 0;i <= ni; ++i) printf("%d ", n[i]);
//			printf("\n");

			int r1 = 0, r2 = 1;
			for(int i = ni; i >= 1; --i)
			{
				int tmp = r2 * n[i] + r1;
				r1 = r2;
				r2 = tmp;
			}
			r1 = r2 * n[0] + r1;
			int r = gcd(r1, r2);
			r1 = r1 / r;
			r2 = r2 / r;
			if(r2 == 1) printf("%d\n", r1);
			else printf("%d/%d\n", r1, r2);
		}
	}
	
	//fclose(stdin);
	
	return 0;	
} 
