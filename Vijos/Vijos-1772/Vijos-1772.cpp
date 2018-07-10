#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	do{
//		for(int i = 0; i < 9; ++i) printf("%d ", arr[i]);
//		printf("\n");

		int num[3];
		for(int i = 0;i < 3; ++i)
		{
			num[i] = arr[3 * i] * 100 + arr[3 * i + 1] * 10 + arr[3 * i + 2]; 
		}
		
		if(num[0] > 333) break;
		
		if(num[0] * 2 == num[1] && num[0] * 3 == num[2]) printf("%d %d %d\n", num[0], num[1], num[2]);
	}while(next_permutation(arr, arr + 9));
	return 0;
}
