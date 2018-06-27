#include <iostream>
#include <cstdio>
#include <limits>
#include <cmath>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);
	
	double p, q;
	
	while(scanf("%lf %lf", &p, &q) != EOF)
	{
		p = p * 0.01;
		q = q * 0.01;
		
		int i = 1;
		int res = INT_MAX;
		while(1)
		{
			
			double max = 1.0 * i / p;
			double min = 1.0 * i / q;
			
			if(min > res) break;
			
			int min_i = (int)(min + 1e-8);
			int max_i = (int)(max - 1e-8);
			
			if(min_i < max_i)
			{
				if(res > min_i + 1) res = min_i + 1;
			}
			
			i++;
		}
		
		printf("%d\n", res);
	}
	
	//fclose(stdin);
	
	return 0;
} 
