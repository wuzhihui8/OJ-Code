#include <iostream>
#include <cstdio>
#include <algorithm> 

using namespace std;

int xn, yn, xt, yt; //1 <= ... <= 1000
int n; //1<=N<=100

struct Node
{
	int y;
	int x;
	int l;
	int x1;
	int x2;
	friend bool operator <(Node a, Node b)
	{
		if(a.y == b.y) return a.x < b.x; //��ͬ�߶�����ľ����Ϊ�Ƚϲ��� 
		else return a.y < b.y;
	}
};

Node node[102]; 

int main()
{
	//freopen("input.txt", "r", stdin);
	
	scanf("%d%d%d%d", &xn, &yn, &xt, &yt);
	scanf("%d", &n); 
	
	int min_dz = 0, min_mb = 0;
	for(int i = 0; i < n; ++i)
	{
		scanf("%d%d%d%d%d", &(node[i].y), &(node[i].x), &(node[i].l), &(node[i].x1), &(node[i].x2));
		node[i].x1 += node[i].x;
		node[i].x2 += node[i].x;
		min_dz++;
		min_mb += node[i].l;
	}
	
	sort(node, node+n);
	
//	for(int i = 0; i < n; ++i)
//	{
//		printf("%d %d %d %d %d\n", node[i].y, node[i].x, node[i].l, node[i].x1, node[i].x2);
//	}

	for(int i = 0; i < n; ++i)
	{
		if(node[i].y + yt > yn) break; //�߶ȳ�����ܵ�����
		if(node[i].l < yt) continue; //��̫�̣��޷������鱾 
		for(int j = 0; j <= xn - xt; ++j) //��Ȳ�������ܵ����� 
		{
			//printf("i=%d,j=%d\n", i, j);
			int dz = 0, mb = 0;
			/////Step 1������ײ��мܵĴ���////////////
			
			//��1�����ڰ��ڣ����账��
			if(node[i].x <= j && node[i].x + node[i].l >= j + xt)
			{
				//printf("���ڰ��ڣ����账��\n");
			} 
			
			// (2) �ƶ��� 
			//j >= node[i].x1 - node[i].l / 2.0
			//j >= node[i].x2 - nodel[i].l
			//j + xt <= node[i].x2 + node[i].l / 2.0
			//j + xt <= node[i].x1 + node[i].l 
			else if(2 * (j - node[i].x1) >= node[i].l
				 && j >= node[i].x2 - node[i].l
				 && 2 * (j + xt - node[i].x2) <= node[i].l
				 && j + xt <= node[i].x1 + node[i].l)
			{
				//printf("�ƶ���\n"); 
			}
				 
			// (3) �ƶ�����
			else if(j >= node[i].x1 - node[i].l && j + xt <= node[i].x2 + node[i].l)
			{
				dz++;
				//printf("�ƶ�����,dz=%d\n", dz);
			}
			
			// (4) �����ܵ���� 
			else
			{
				//printf("�����ܵ����\n");
				continue; 
			}
			
			///////////Step 2:���������ľ��///////////////////////////////////////
			for(int k = i + 1; k < n; ++k)
			{
				//printf("k=%d", k);
				
				if(node[i].y + yt <= node[k].y) break; //�߶ȵ��ڰ� 
				//(1)�п�϶
				if(j + xt <= node[k].x || j >= node[k].x + node[k].l)
				{
					//printf("�п�϶\n", k);
					continue;
				}
				//(2)�ƶ���
				
				else if(j + xt <= node[k].x1)
				{
					int mb1 = 0;
					//��̫������Ҫ�ü� 
					if(node[k].l > 2 * (node[k].x2 - (j + xt))) //�ҹ��� 
					{
						mb1 = node[k].l - 2 * (node[k].x2 - (j + xt));
						//printf("�ҹ�����mb1=%d", mb1);
					}
					
					 //�峬��ǽ 
					if(j + xt + node[k].l - mb1 > xn) //�ҹ�ǽ 
					{
						mb1 = j + xt + node[k].l - xn;
						//printf("�ҹ�ǽ ��mb1=%d", mb1);
					}
					
					mb += mb1;
					//printf("�ƶ��壬mb=%d\n", mb);
				}
				
				
				else if(j >= node[k].x2)
				{
					int mb1 = 0;
					//��̫������Ҫ�ü� 
					if(node[k].l > 2 * (j - node[k].x1)) //�����
					{
						mb1 = node[k].l - 2 * (j - node[k].x1);
						//printf("�������mb1=%d", mb1);
					}
					
					 //�峬��ǽ 
					if(xt - (node[k].l - mb1) < 0) //���ǽ 
					{
						mb1 += node[k].l - xt;
						//printf("���ǽ ��mb1=%d", mb1);
					}
					
					mb += mb1;
					//printf("�ƶ��壬mb=%d\n", mb);
				}
				//(3) �ƶ����� 
				else if(node[k].x1 >= j && node[k].x1 <= j + xt && j + xt <= node[k].x2)  //�����鱾�ڲ� 
				{
					dz++;
					//printf("�ƶ����ӣ�dz=%d\n", dz); 
					if(j + xt + node[k].l > xn) //����� 
					{
						mb += j + xt + node[k].l - xn; 
						//printf("�������mb=%d\n", mb);
					}
				} 
				else if(node[k].x1 <= j && j <= node[k].x2 && node[k].x2 <= j + xt) //�Ҷ����鱾�ڲ�
				{
					dz++;
					//printf("�ƶ��Ҷ��ӣ�dz=%d\n", dz); 
					if(j - node[k].l < 0) //����� 
					{
						mb += node[k].l - j;  
						//printf("�������mb=%d\n", mb);
					}
				}
				
				//��4������ȥ��
				else
				{
					dz+=2;
					mb += node[k].l;
					//printf("����ȥ��,dz=%d,mb=%d\n", dz, mb);
				} 
			} 
			
			//printf("\n\n");
			
			if(min_dz > dz)
			{
				min_dz = dz;
				min_mb = mb;
			}
			else if(min_dz == dz && min_mb > mb)
			{
				min_mb = mb;	
			}
		}
	}
	
	printf("%d %d\n", min_dz, min_mb);
	
	//fclose(stdin);
	
	return 0;	
} 
