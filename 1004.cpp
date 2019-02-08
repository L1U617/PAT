#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, m;
	int id, k, tmp;
	cin >> n >> m;	
	if (n == 0) return 0;
	vector<vector<int> > Pedi(n + 1);
	vector<vector<int> > level;
	for (int i = 0; i < m; i++) {
		cin >> id >> k;		
		vector<int> child;
		for (int j = 0; j < k; j++) {
			cin >> tmp;
			child.push_back(tmp);
		}
		Pedi[id] = child;
	}
	vector<int> l1;
	l1.push_back(1);
	level.push_back(l1);
	int l = 0, cnt = 1;
	while (cnt < n) {
		vector<int> temp;
		for (int i = 0; i < level[l].size(); i++) {
			for (int j = 0; j < Pedi[level[l][i]].size(); j++) {
				temp.push_back(Pedi[level[l][i]][j]);
				cnt++;
				}
		}
		level.push_back(temp);
		l++;
	}
	int count = 0, flag = 0;
	for (int i = 0; i < level.size(); i++) {
		for (int j = 0; j < level[i].size(); j++)
			if (Pedi[level[i][j]].size() == 0) count++;
		if (flag != 0) cout << " ";
		else flag = 1;
		cout << count;
		count = 0;
	}
	system("pause");
	return 0;
}