#include <iostream>
#include <cstdio>
#include <map>
#include <queue>
#include <limits>
#include <cstring>

using namespace std;

#define MAX_MAVE_SIZE 54
const int idx_x[4] = {0, -1, 0, 1};
const int idx_y[4] = {-1, 0, 1, 0};

const int maxInt = numeric_limits<int>::max();

//Prime Data
const int MAX_N = 54 * 54;
int n;
int dist[102][102];
int sum_dist;

//BFS Data
int row, col;
char mave[51][51];
int path[51][51];
//map<int, int> map_vertex;
int arr_vertex[51][51];

struct Point
{
	int i;
	int j;
};

//int bfs()
//{
//	for(map<int, int>::iterator it = map_vertex.begin(); it != map_vertex.end(); ++it)
//	{
//		int key = it->first;
//		int value = it->second;
//		dist[value][value] = 0;
//		
//		for(int i = 0; i < row; ++i)
//		{
//			for(int j = 0;  j < col; ++j)
//			{
//				path[i][j] = -1;
//			}
//		}
//		path[key / col][key % col] = 0;
//		
//		queue<int> queue_vertex;
//		queue_vertex.push(key);
//		
//		while(!queue_vertex.empty())
//		{
//			int cur = queue_vertex.front();
//			queue_vertex.pop();
//			//int cur_idx = map_vertex[cur];
//			
//			int cur_x = cur / col;
//			int cur_y = cur % col;
//			
//			for(int i = 0; i < 4; ++i)
//			{
//				int next_x = cur_x + idx_x[i];
//				int next_y = cur_y + idx_y[i];
//				
//				if(path[next_x][next_y] == -1)
//				{
//					path[next_x][next_y] = path[cur_x][cur_y] + 1;
//					if(mave[next_x][next_y] != '#')
//					{
//						if(mave[next_x][next_y] == 'A' || mave[next_x][next_y] == 'S')
//						{
//							dist[value][map_vertex[next_x * col + next_y]] = path[next_x][next_y];
//							//printf("dist[%d][%d]=%d\n", value, map_vertex[next_x * col + next_y], path[next_x][next_y]);
//						}
//						queue_vertex.push(next_x * col + next_y);
//					}
//				}
//			}
//		}
//		
////		printf("idx=%d\n", value);
////		for(int i = 0; i < row; ++i)
////		{
////			for(int j = 0; j < col; ++j)
////			{
////				printf("%d", path[i][j]);
////			}
////			printf("\n");
////		}
//		
//		
//	}
//}

int bfs2()
{
	int count = 0;
	for(int i = 0; i < row; ++i)
	{
		for(int j = 0; j < col; ++j)
		{
			if(arr_vertex[i][j])
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
	
	for(int i = 0; i < t ;++t)
	{
		scanf("%d%d", &col, &row);
		char tmp[51];
		gets(tmp);
		
//		char ch;
//		ch = getchar();
//		while(ch != '\n') ch = getchar();
		//map_vertex.clear();
		memset(arr_vertex, 0, sizeof(arr_vertex));
		
		n = 0;
//		for(int j = 0; j < row; ++j)
//		{
//			for(int k = 0; k < col; ++k)
//			{
//				ch = getchar();
//				mave[j][k] = ch;
//				if(ch == 'A' || ch == 'S')
//				{
//					//map_vertex[j * col + k] = n;
//					arr_vertex[j][k] = ++n;
//				}
//			}
//			ch = getchar();
//			//while(ch != '\n') ch = getchar();
//		}
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
		
//		printf("****************************\n");
//		for(int j = 0; j < row; ++j)
//		{
//			for(int k = 0; k < col; ++k)
//			{
//				printf("%c", mave[j][k]);
//			}
//			printf("\n");
//		}
//		printf("****************************\n");

//		for(int j = 0; j < row; ++j)
//		{
//			for(int k = 0; k < col; ++k)
//			{
//				if(arr_vertex[j][k])
//				{
//					printf("arr_vertex[%d][%d]=%d\n", j, k, arr_vertex[j][k]);
//				}
//			}
//		}
		bfs2();
		
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
