/*
- find the deepest root
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
typedef struct node {
	int root; 
	int height;
} Node;

int n;
vector<vector<int> > G;
vector<int> visited;
vector<Node> ans;
int highest = 0;

void DFS(int v, int height)
{
	visited[v] = 1;
	if (height > highest) highest = height;
	for (int i = 0; i < G[v].size(); i++)
		if (visited[G[v][i]] == 0)
			DFS(G[v][i], height + 1);
}

int main()
{
	cin >> n;
	G.resize(n + 1);
	visited.resize(n + 1, 0);
	int a, b;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int cnt = 0, error = 0;
	for (int i = 1; i <= n; i++) {
		if (visited[i] == 0) {
			DFS(i, 1);	
			cnt++;
		}
	}
	if (cnt > 1) printf("Error: %d components", cnt);
	else {
		int deep = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) 
				visited[j] = 0;
			DFS(i, 1);
			Node temp;
			temp.root = i;
			temp.height = highest;
			if (deep < highest) deep = highest;
			ans.push_back(temp);
			highest = 0;
		}
		for (int i = 0; i < ans.size(); i++)
			if (ans[i].height == deep) cout << ans[i].root << endl;
	}

	system("pause");
	return 0;
}