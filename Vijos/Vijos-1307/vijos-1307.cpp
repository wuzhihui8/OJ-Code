#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	double n;
	scanf("%lf", &n);
	printf("%.0lf", n * (n + 1) * (2 * n + 1) / 6);
	return 0;
}
