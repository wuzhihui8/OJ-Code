#include <iostream>
#include <cstdio>
#include <cstring>

//char map[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

using namespace std;

int res[100];
int length;

int palindrome()  //判断是否为回文数
{
	int i;
	for(i = 0; i < length / 2; ++i)
	{
		if(res[i] != res[length - 1 - i]) break;
	}
	if(i >= length / 2) return 0;
	else return 1;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	
	int n;
	while(scanf("%d", &n) != EOF)
	{
		char str[30];
		scanf("%s", str);
		
		
		length = strlen(str);
		for(int i = 0; i < length; ++i)
		{
			if(str[length - 1 - i] - '0' < 10)  res[i] = str[length - 1 - i] - '0';
			else res[i] = str[length - 1 - i] - 'A' + 10;
		}
		
//		for(int i = 0;i < length; ++i)
//		{
//			printf("%d ", res[i]);
//		}
//		printf("\n---------------------\n");
				
		int count = 0;
		while(palindrome())
		{
			count++;
			if(count > 30) break;
			
			for(int i = 0; i < (length + 1) / 2; ++i)
			{
				res[i] = res[i] + res[length - 1 - i];
				res[length - 1 - i] = res[i];
			}
			for(int i = 0; i < length - 1; ++i)
			{
				res[i + 1] += res[i] / n;
				res[i] = res[i] % n;
			}
			if(res[length - 1] >= n)
			{
				res[length] = res[length - 1] / n;
				res[length - 1] = res[length - 1] % n;
				length++;
			}
			
//			for(int i = 0; i < length; ++i)
//			{
//				printf("%d ", res[i]);
//			}
//			printf("\n");
		}
		
		if(count <= 30)
		{
			printf("STEP=%d\n", count);
		}
		else
		{
			printf("Impossible!\n");
		}
		 
	}
	
	//fclose(stdin);
	
	return 0;
}
