#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <limits>
#include <map>

using namespace std;

#define MAX_MAVE_SIZE 54
const int idx_x[4] = {0, -1, 0, 1};
const int idx_y[4] = {-1, 0, 1, 0};

const int maxInt = numeric_limits<int>::max();

//Prime Data
const int MAX_N = 54 * 54;
int n;
int dist[MAX_N][MAX_N];
int sum_dist;

//BFS Data
int row, col;
char mave[MAX_MAVE_SIZE][MAX_MAVE_SIZE];
int path[MAX_MAVE_SIZE][MAX_MAVE_SIZE];
//map<int, int> map_vertex;
int arr_vertex[54][54];

struct Point
{
	int i;
	int j;
};

int bfs()
{
	int count = 0;
	for(int i = 0; i < row; ++i)
	{
		for(int j = 0; j < col; ++j)
		{
			if(arr_vertex[i][j]) //为有效点 
			{
				count++;
				int idx = arr_vertex[i][j] - 1;
				dist[idx][idx] = 0;
				
				for(int k = 0; k < row; ++k)
				{
					for(int p = 0;  p < col; ++p)
					{
						path[k][p] = -1;
					}
				}
				path[i][j] = 0;
				
				queue<Point> queue_vertex;
				Point point;
				point.i = i;
				point.j = j;
				queue_vertex.push(point);
				
				while(!queue_vertex.empty())
				{
					point = queue_vertex.front();
					queue_vertex.pop();
					
					for(int k = 0; k < 4; ++k)
					{
						int next_i = point.i + idx_x[k];
						int next_j = point.j + idx_y[k];
						
						if(path[next_i][next_j] == -1)
						{
							path[next_i][next_j] = path[point.i][point.j] + 1;
							if(mave[next_i][next_j] != '#')
							{
								Point point2;
								point2.i = next_i;
								point2.j = next_j;
								queue_vertex.push(point2);
								
								if(arr_vertex[next_i][next_j])
								{
									dist[idx][arr_vertex[next_i][next_j] - 1] = path[next_i][next_j];
								}
							}
						}
					}
				}
			}
			if(count == n - 1) break;
		}
		if(count == n - 1) break;
	}
	for(int i = 0; i < n - 1; ++i) dist[n-1][i] = dist[i][n-1];
	dist[n-1][n-1] = 0;	
}

int prime()
{	
	int min_dis[MAX_N];
	for(int i = 0; i < n; ++i) min_dis[i] = maxInt;
	
	int visited[MAX_N];
	for(int i = 0; i < n; ++i) visited[i] = 0;
	
	int cur_vertex = 0;	
	sum_dist = 0;
	for(int i = 1; i < n; ++i)
	{
		visited[cur_vertex] = 1;
		int min = maxInt;
		int min_idx;
		for(int j = 0; j < n; ++j)
		{
			if(!visited[j] && min_dis[j] > dist[cur_vertex][j])
			{
				min_dis[j] = dist[cur_vertex][j];
			}
			if(!visited[j] && min > min_dis[j])
			{
				min = min_dis[j];
				min_idx = j;
			}
		}
		//cout << "i:" << min_idx << ",dis:" << min << endl;
		sum_dist += min;
		cur_vertex = min_idx;
	}
	return 0;
}

int main()
{
	int t;
	scanf("%d", &t);
	
	char ch;
	for(int i = 0; i < t; ++i)
	{
		memset(arr_vertex, 0, sizeof(arr_vertex));
		
		scanf("%d%d", &col, &row);
		
		char ches[51];
		gets(ches); //去除多余的空格
		
		n = 0;
		for(int j = 0; j < row; ++j)
		{
			gets(mave[j]);
			for(int k = 0; k < col; ++k)
			{
				if(mave[j][k] == 'A' || mave[j][k] == 'S')
				{
					arr_vertex[j][k] = ++n;
				}
			}
		}
		
		bfs();
		
//		for(int j = 0; j < n; ++j)
//		{
//			for(int k = 0; k < n; ++k)
//			{
//				printf("%d ", dist[j][k]);
//			}
//			printf("\n");
//		}

		prime();
		
		printf("%d\n", sum_dist);
	}
	
	return 0;
}
