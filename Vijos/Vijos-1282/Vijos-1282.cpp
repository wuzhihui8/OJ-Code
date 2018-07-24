#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int e[10];

struct People
{
	int idx;
	int w;
} arr[50002]; //n<=50 000

int cmp(People a, People b)
{
	//return a.w > b.w;
	if(a.w == b.w) return a.idx < b.idx;
	else return a.w > b.w;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	
	int i, j;
	int n, k;
	scanf("%d %d", &n, &k);
	
	for(i = 0; i < 10; ++i) scanf("%d", &e[i]);
	for(i = 0; i < n; ++i)
	{
		arr[i].idx = i;
		scanf("%d", &arr[i].w);
	}
	
	sort(arr, arr + n, cmp);
//	for(i = 0;i < n; ++i) printf("%d %d,", arr[i].idx, arr[i].w);
//	printf("\n");

	for(i = 0; i < n; ++i)
	{
		arr[i].w += e[i % 10];
	}
	sort(arr, arr + n, cmp);
	
	if(k > 0)
	{
		printf("%d", arr[0].idx + 1);
		for(i = 1; i < k; ++i) printf(" %d", arr[i].idx + 1);
		printf("\n");		
	}
	
	//fclose(stdin);
	
	return 0;
}
