﻿/*
- problem station --> perfect
- all the stations on the way will be adjusted as well
- choose the one that requires the least number of bikes sent from PBMC

我的方法：找出所有的可达路径，从中再选出最短路径并求出每条路径对应所需新增的车辆和回收的车辆
别人的方法：DJIKSTRA + DFS
*/
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct node {
	int length;
	vector<int> path;
	int send, back;
}Node;

vector<vector<int> > G;
vector<int> visited;
vector<Node> P;
int cmax, n, sp, m;
int shortest = 1000000;
void findPath(int c, int length, vector<int> path) 
{
	visited[c] = 1;
	if (length > shortest) return;
	if (c == sp) {
		Node temp;
		temp.length = length;
		temp.path = path;
		if (length <= shortest) {
			shortest = length;
			P.push_back(temp);
		}
		return;
	}
	else {
		for (int i = 0; i <= n; i++) {
			if (G[c][i] != -1 && visited[i] != 1) {
				int tmp = G[c][i];
				path.push_back(i);
				findPath(i, length + tmp, path);
				visited[i] = 0;
				path.pop_back();
			}
		}
	}
}

int cmp(Node a, Node b)
{
	return a.send != b.send? a.send < b.send : a.back < b.back;
}

int main()
{
	cin >> cmax >> n >> sp >> m;
	int perfect = cmax / 2;
	vector<int> SBikes(n + 1);
	G.resize(n + 1, vector<int>(n + 1));
	visited.resize(n + 1, 0);
	for (int i = 1; i <= n; i++)
		cin >> SBikes[i];
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			G[i][j] = G[j][i] = -1;
	for (int i = 1; i <= m; i++) {
		int si, sj, tij;
		cin >> si >> sj >> tij;
		G[si][sj] = G[sj][si] = tij;
	}
	vector<int> path;
	path.push_back(0);
	findPath(0, 0, path);
	vector<Node> ans;
	for (int i = 0; i < P.size(); i++) {
		if (P[i].length == shortest) {
			int send = 0, collect = 0;
			vector<int> temp = P[i].path;
			for (int j = 1; j < temp.size(); j++) {
				if (SBikes[temp[j]] < perfect) {
					if (collect >= perfect - SBikes[temp[j]])
						collect -= perfect - SBikes[temp[j]];
					else {
						send += perfect - SBikes[temp[j]] - collect;
						collect = 0;
					}
				}
				else {
					collect += SBikes[temp[j]] - perfect;
				}
			}
			P[i].send = send;
			P[i].back = collect;
			ans.push_back(P[i]);
		}
	}
	sort(ans.begin(), ans.end(), cmp);

	cout << ans[0].send << " ";
	for (int i = 0; i < ans[0].path.size(); i++) {
		if (i != 0) cout << "->";
		cout << ans[0].path[i];
	}
	cout << " " << ans[0].back;

	system("pause");
    return 0;
}

