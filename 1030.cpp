/*
- Djikstra
*/
#include "stdafx.h"
#include <iostream>
#include <vector>
#define INF 0x7fffffff
using namespace std;
typedef struct node {
	int dis, cost;
}Node;
typedef struct costnode {
	int v, cost;
}CNode;
int n, m, s, d;
int visited[510], dis[510];
vector<int> pre[510], path, temppath;
Node Map[510][510];
int minCost = INF;

void DFS(int v)
{
	temppath.push_back(v);
	if (v == s) {
		int minc = 0;
		for (int i = temppath.size() - 1; i >= 1; i--) {
			int v1, v2;
			v1 = temppath[i]; v2 = temppath[i - 1];
			minc += Map[v1][v2].cost;
		}
		if (minc < minCost) {
			minCost = minc;
			path = temppath;
		}
		temppath.pop_back();
		return;
	}
	for (int i = 0; i < pre[v].size(); i++)
		DFS(pre[v][i]);
	temppath.pop_back();
}

int main()
{
	cin >> n >> m >> s >> d;
	Node temp;
	temp.dis = INF; temp.cost = INF;
	fill(Map[0], Map[0] + 510 * 510, temp);
	fill(dis, dis + 510, INF);
	fill(visited, visited + 510, 0);
	for (int i = 0; i < m; i++) {
		int c1, c2;
		Node tmp;
		cin >> c1 >> c2 >> tmp.dis >> tmp.cost;
		Map[c1][c2] = Map[c2][c1] = tmp;
	}
	dis[s] = 0;
	for (int i = 0; i < n; i++) {  //进行n轮 
		int u = -1, minn = INF;	
		for (int j = 0; j < n; j++) {  //找到一轮中距离最短的点
			if (visited[j] == 0 && dis[j] < minn) {
				u = j;
				minn = dis[j];
			}
		}
		if (u == -1) break;
		visited[u] = 1;
		for (int v = 0; v < n; v++) {
			if (visited[v] == 0 && Map[u][v].dis != INF) {
				if (dis[v] > dis[u] + Map[u][v].dis) {       //从s(起点)经过u到v的距离比经过其他点到v的距离短，因此v的前导点更新为u
					dis[v] = dis[u] + Map[u][v].dis;
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if (dis[v] == dis[u] + Map[u][v].dis) { //有两条距离相同的路径，v的前导点中增加u，如果此时s到v的路径更短则不用更新任何东西
					pre[v].push_back(u);
				}
			}
		}
	}
	DFS(d);
	printf("%d", s);
	for (int i = path.size() - 2; i >= 0; i--) 
		printf(" %d", path[i]);
	printf(" %d %d", dis[d], minCost);
	system("pause");
    return 0;
}

