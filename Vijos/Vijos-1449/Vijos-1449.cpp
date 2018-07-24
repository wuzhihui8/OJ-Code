#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

char arr[3][10002];
char res[10002];

int main()
{
	//freopen("input.txt", "r", stdin);
	
	int i, j, k;
	int n;
	scanf("%d", &n);
	
	for(i = 0; i < 3; ++i)
	{
		scanf("%s", arr[i]);
	}
	
	//for(i = 0; i < 3; ++i) printf("%s\n", arr[i]);
	int order[3] = {0, 1, 2};
	do
    {
    	//printf("%s\n%s\n%s\n", arr[order[0]], arr[order[1]], arr[order[2]]);
    	
    	//情况（1）
		for(i = 0; i < n; ++i) res[i] = arr[order[0]][n - 1 - i];
		
		//情况（2）
		k = (arr[order[1]][0] - res[0] + 26) % 26;
		for(j = 1; j < n; ++j)
		{
			if((arr[order[1]][j] - res[j] + 26) % 26 != k) break;
		}
		if(j < n) continue;
		
		//情况（3）
		for(j = 0; j < n; ++j)
		{
			if((res[j] - arr[order[2]][j] + 26) % 26 != k) break; 
		} 
		if(j < n) continue;
		break;
    }
    while(next_permutation(order, order + 3));
    
    printf("%s\n", res);
	
	//fclose(stdin);
	
	return 0;
}
