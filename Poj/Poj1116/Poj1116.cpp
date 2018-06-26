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
		if(a.y == b.y) return a.x < b.x; //相同高度则以木板左为比较参数 
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
		if(node[i].y + yt > yn) break; //高度超过书架的限制
		if(node[i].l < yt) continue; //板太短，无法放置书本 
		for(int j = 0; j <= xn - xt; ++j) //宽度不超过书架的限制 
		{
			//printf("i=%d,j=%d\n", i, j);
			int dz = 0, mb = 0;
			/////Step 1：计算底部托架的处理////////////
			
			//（1）书在板内，不需处理
			if(node[i].x <= j && node[i].x + node[i].l >= j + xt)
			{
				//printf("书在板内，不需处理\n");
			} 
			
			// (2) 移动板 
			//j >= node[i].x1 - node[i].l / 2.0
			//j >= node[i].x2 - nodel[i].l
			//j + xt <= node[i].x2 + node[i].l / 2.0
			//j + xt <= node[i].x1 + node[i].l 
			else if(2 * (j - node[i].x1) >= node[i].l
				 && j >= node[i].x2 - node[i].l
				 && 2 * (j + xt - node[i].x2) <= node[i].l
				 && j + xt <= node[i].x1 + node[i].l)
			{
				//printf("移动板\n"); 
			}
				 
			// (3) 移动钉子
			else if(j >= node[i].x1 - node[i].l && j + xt <= node[i].x2 + node[i].l)
			{
				dz++;
				//printf("移动钉子,dz=%d\n", dz);
			}
			
			// (4) 不可能的情况 
			else
			{
				//printf("不可能的情况\n");
				continue; 
			}
			
			///////////Step 2:处理上面的木板///////////////////////////////////////
			for(int k = i + 1; k < n; ++k)
			{
				//printf("k=%d", k);
				
				if(node[i].y + yt <= node[k].y) break; //高度低于板 
				//(1)有空隙
				if(j + xt <= node[k].x || j >= node[k].x + node[k].l)
				{
					//printf("有空隙\n", k);
					continue;
				}
				//(2)移动板
				
				else if(j + xt <= node[k].x1)
				{
					int mb1 = 0;
					//板太长，需要裁剪 
					if(node[k].l > 2 * (node[k].x2 - (j + xt))) //右过长 
					{
						mb1 = node[k].l - 2 * (node[k].x2 - (j + xt));
						//printf("右过长，mb1=%d", mb1);
					}
					
					 //板超过墙 
					if(j + xt + node[k].l - mb1 > xn) //右过墙 
					{
						mb1 = j + xt + node[k].l - xn;
						//printf("右过墙 ，mb1=%d", mb1);
					}
					
					mb += mb1;
					//printf("移动板，mb=%d\n", mb);
				}
				
				
				else if(j >= node[k].x2)
				{
					int mb1 = 0;
					//板太长，需要裁剪 
					if(node[k].l > 2 * (j - node[k].x1)) //左过长
					{
						mb1 = node[k].l - 2 * (j - node[k].x1);
						//printf("左过长，mb1=%d", mb1);
					}
					
					 //板超过墙 
					if(xt - (node[k].l - mb1) < 0) //左过墙 
					{
						mb1 += node[k].l - xt;
						//printf("左过墙 ，mb1=%d", mb1);
					}
					
					mb += mb1;
					//printf("移动板，mb=%d\n", mb);
				}
				//(3) 移动钉子 
				else if(node[k].x1 >= j && node[k].x1 <= j + xt && j + xt <= node[k].x2)  //左钉在书本内部 
				{
					dz++;
					//printf("移动左钉子，dz=%d\n", dz); 
					if(j + xt + node[k].l > xn) //板过长 
					{
						mb += j + xt + node[k].l - xn; 
						//printf("板过长，mb=%d\n", mb);
					}
				} 
				else if(node[k].x1 <= j && j <= node[k].x2 && node[k].x2 <= j + xt) //右钉在书本内部
				{
					dz++;
					//printf("移动右钉子，dz=%d\n", dz); 
					if(j - node[k].l < 0) //板过长 
					{
						mb += node[k].l - j;  
						//printf("板过长，mb=%d\n", mb);
					}
				}
				
				//（4）整块去掉
				else
				{
					dz+=2;
					mb += node[k].l;
					//printf("整块去掉,dz=%d,mb=%d\n", dz, mb);
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
