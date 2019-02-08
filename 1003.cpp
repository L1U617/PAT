#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
/*
using namespace std;

typedef struct node Node;
struct node {
	int pathL;
	int teams;
};

int n, m, city1, city2;
vector<int> resTeam;
vector<vector<int>> cityMap;
vector<Node> path;
int minCnt = 0, shortest = 1000000;

void findPath(int c, int pathL, int teams)
{
	if (pathL > shortest) return;
	if (c == city2) {
		Node temp;
		temp.pathL = pathL; temp.teams = teams;
		if (pathL <= shortest) {
			shortest = pathL;
			path.push_back(temp);
		}
		return;
	}
	else {
		for (int i = 0; i < n; i++) {
			if (cityMap[c][i] != -1) {
				int temp = cityMap[c][i];
				cityMap[c][i] = cityMap[i][c] = -1;
				findPath(i, pathL + temp, teams + resTeam[i]);
				cityMap[c][i] = cityMap[i][c] = temp;
			}
		}
	}
}

int main()
{
	cin >> n >> m >> city1 >> city2;
	int tmp, c1, c2, len;
	cityMap.resize(n, vector<int>(n));
	resTeam.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> resTeam[i];
		for (int j = 0; j < n; j++)
			cityMap[i][j] = -1;
	}
	for (int i = 0; i < m; i++) {
		cin >> c1 >> c2 >> len;
		cityMap[c1][c2] = len;
		cityMap[c2][c1] = len;
	}
	
	findPath(city1, 0, resTeam[city1]);

	int max = 0, cnt = 0;
	for (int i = 0; i < path.size(); i++) {
		if (path[i].pathL == shortest) {
			cnt++;
			if (max < path[i].teams) max = path[i].teams;
		}
	}
	cout << cnt << " " << max;
	system("pause");
	return 0;
}*/