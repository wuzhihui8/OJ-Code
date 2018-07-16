#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

int arr[500002];
int ticket[100002];

int main()
{
	freopen("input.txt", "r", stdin);
	
	int i, j, tmp;
	int n, k;
	
	memset(ticket, 0, sizeof(ticket));
	
	scanf("%d%d", &n, &k);
	
	scanf("%d", &arr[0]);
	arr[0] = arr[0] % k;
	ticket[arr[0]]++;
	for(i = 1; i < n; ++i)
	{
		scanf("%d", &arr[i]);
		arr[i] = (arr[i - 1] + arr[i]) % k;
		ticket[arr[i]]++;
	}
	
//	for(i = 0; i < n; ++i) printf("%d ", arr[i]);
//	printf("\n");
//
//	for(i = 0;i < k; ++i) printf("%d ", ticket[i]);
//	printf("\n");

	long sum = ticket[0] % 1234567;
	for(int i = 0; i < k; ++i)
	{
		sum += ticket[i] * (ticket[i] - 1) / 2;
		sum = sum % 1234567;
	}
	
	printf("%ld\n", sum); 
	
	fclose(stdin);
	
	return 0;
}
