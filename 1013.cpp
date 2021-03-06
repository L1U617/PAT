#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;
int cityMap[1001][1001];
int visited[1001];
int n;
void DFS(int c1)
{
	visited[c1] = 1;
	for (int i = 1; i <= n; i++) {
		if (visited[i] == 0 && cityMap[i][c1] == 1)
			DFS(i);
	}
}
void BFS(int c1, int n, vector<vector<int> > A, vector<int> &visited)
{
	vector<int> q;
	vector<vector<int> > temp = A;
	q.push_back(c1);
	visited[c1] = 1;
	while (q.size() != 0) {
		int city = q[0];
		q.erase(q.begin());
		for (int i = 1; i <= n; i++) {
			if (temp[city][i] == 1 && visited[i] != 1) {
				visited[i] = 1;
				q.push_back(i);
			}
		}
	}
	return;
}

/*void BFS(int c1, int n, vector<vector<int> > A, vector<int> &adj)
{
	vector<int> q;
	vector<vector<int> > temp = A;
	q.push_back(c1);
	while (q.size() != 0) {
		int city = q[0];
		q.erase(q.begin());
		for (int i = 1; i <= n ; i++) {
			if (temp[city][i] == 1) {
				temp[city][i] = temp[i][city] = -1;
				for (vector<int> ::iterator it = adj.begin(); it != adj.end(); ++it) {
					if (*it == i) it = adj.erase(it);
					if (it == adj.end()) break;
				}
				if (adj.size() == 0) return;
				q.push_back(i);
			}
		}
	}
	return;
}*/

int main()
{
	int m, k;
	cin >> n >> m >> k;
	//Init
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			cityMap[i][j] = -1;
	//Read
	int city1, city2;
	for (int i = 1; i <= m; i++) {
		cin >> city1 >> city2;
		cityMap[city1][city2] = cityMap[city2][city1] = 1;
	}
	//Process
	int check;
	for (int i = 1; i <= k; i++) {
		cin >> check;
		//vector<int> adj;
		for (int j = 0; j <= 1001; j++) visited[j] = 0;
		visited[check] = 1;
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (visited[j] == 0) {
				DFS(j);
				cnt++;
			}
		}
		cout << cnt - 1<< endl;
	}

	system("pause");
	return 0;
}

/*======================
#include <cstdio>
#include <algorithm>
using namespace std;
int v[1010][1010];
bool visit[1010];
int n;
void dfs(int node) {
	visit[node] = true;
	for (int i = 1; i <= n; i++) {
		if (visit[i] == false && v[node][i] == 1)
			dfs(i);
	}
}
int main() {
	int m, k, a, b;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		v[a][b] = v[b][a] = 1;
	}
	for (int i = 0; i < k; i++) {
		fill(visit, visit + 1010, false);
		scanf("%d", &a);
		int cnt = 0;
		visit[a] = true;
		for (int j = 1; j <= n; j++) {
			if (visit[j] == false) {
				dfs(j);
				cnt++;
			}
		}
		printf("%d\n", cnt - 1);
	}
	return 0;
}*/