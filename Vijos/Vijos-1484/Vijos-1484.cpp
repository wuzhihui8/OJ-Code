#include <iostream>
#include <cstring>

using namespace std;

char str[20];
int idx_str[20] = {1, 0, 2, 3, 4, 0, 5, 6, 7, 8, 9};

int main()
{
	//freopen("input.txt", "r", stdin);
	
	while(scanf("%s", str) != EOF)
	{
		//printf("%s\n", str);
		int sum = 0;
		for(int i = 0; i < strlen(str) - 2; ++i)
		{
			sum += idx_str[i] * (str[i] - '0');
			//printf("%c", str[i]);
		}
		//printf("sum=%d\n", sum);	
		
		int idt = sum % 11;
		char idt_c;
		if(idt == 10) idt_c = 'X';
		else idt_c = '0' + idt;
		
		if(idt_c != str[strlen(str) - 1])
		{
			str[strlen(str) - 1] = idt_c;
			printf("%s\n", str);
		}
		else
		{
			printf("Right\n");
		}
	}
	
	//fclose(stdin);
	
	return 0;	
} 
