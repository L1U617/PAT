#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef struct node {
	string id;
	int grade;
	int location;
}Node;

int cmp(Node a, Node b)
{
	return a.grade != b.grade ? a.grade > b.grade : a.id < b.id;
}

int main()
{
	int n, k, grade, cnt = 0;
	string id;
	vector<Node> stu;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		for (int j = 0; j < k; j++) {
			Node temp;
			cin >> temp.id >> temp.grade;
			temp.location = i + 1;
			stu.push_back(temp);
			cnt++;
		}
	}
	cout << cnt << endl;
	sort(stu.begin(), stu.end(), cmp);
	vector<int> rank(n + 1, 0);
	vector<int> num(n + 1, 1);
	vector<int> pre(n + 1, -1);
	for (int i = 0; i < cnt; i++) {
		int loc = stu[i].location;
		if (stu[i].grade != pre[loc]) {
			pre[loc] = stu[i].grade;
			rank[loc] += num[loc];
			num[loc] = 1;
		}
		else num[loc]++;
		if (stu[i].grade != pre[0]) {
			pre[0] = stu[i].grade;
			rank[0] += num[0];
			num[0] = 1;
		}
		else num[0]++;
		cout << stu[i].id;
		printf(" %d %d %d\n", rank[0], loc, rank[loc]);
	}

	system("pause");
	return 0;
}