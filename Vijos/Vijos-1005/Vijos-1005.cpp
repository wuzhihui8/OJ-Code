#include <iostream>
#include <cstring>

using namespace std;

char p[202];
int next[202];

char t[10000];  //使用循环数组 
int n; //数组长度 
int count;

int get_next()
{
	int q, k;
	int m = strlen(p);
	for(q = 1, k = 0; q < m; ++q)
	{
		while(k > 0 && p[q] != p[k]) k = next[k - 1];
		if(p[q] == p[k]) ++k;
		next[q] = k; 
	}
	return 0;
}

int kmp()
{
	int n, m;
	int i, q;
	n = strlen(t);
	m = strlen(p);
	get_next(p, next);
	for(i = 0, q = 0; i < n; ++i)
	{
		while(q > 0 && p[q] != t[i]) q = next[q - 1];
		if(p[q] == t[i]) q++;
		if(q == m) printf("Pattern occurs with shift:%d\n",(i-m+1));
	}
}

int add_t()
{
	
}

int kmp2()
{
	get_next(p);
	
	n =0;
	int i = 0;
	
	do
	{
		if(i >= n) add_t();
	}
}


int main()
{
	freopen("input.txt", "r", stdin);
	
	while(scanf("%s", p) != EOF)
	{
		
		
	}
	
	fclose(stdin);	
	
	return 0;
} 
