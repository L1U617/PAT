/*
- postorder + inorder --> level order
*/

#include "stdafx.h" 
#include <iostream>
#include <vector>

using namespace std;
int n, le = 0;
vector<int> post, in;
vector<vector<int> >level;

void levelOrder(int layer, int inst, int inend, int postst, int postend)
{
	if (inst > inend) return;
	int root = post[postend];
	level[layer++].push_back(root);
	if (le < layer) le = layer;
	int i, right = -1;
	for (i = inst; i <= inend; i++) {
		right++;
		if (in[i] == root) break;
	}
	int left = inend - inst - right;
	levelOrder(layer, inst, i - 1, postst, postst + right - 1);
	levelOrder(layer, i + 1, inend, postst + right, postst + right + left - 1);
}

int main() {
	cin >> n;
	post.resize(n), in.resize(n), level.resize(n);
	int root, left, right;
	for (int i = 0; i < n; i++)
		cin >> post[i];
	for (int i = 0; i < n; i++)
		cin >> in[i];

	levelOrder(0, 0, n - 1, 0, n - 1);

	for (int j = 0; j < level[0].size(); j++) {
		if (j != 0) cout << " ";
		cout << level[0][j];
	}

	for (int i = 1; i < le; i++) {
		for (int j = 0; j < level[i].size(); j++)
			cout << " " << level[i][j];
	}
	system("pause");
	return 0;
}