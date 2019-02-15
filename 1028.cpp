#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef struct node {
	int id, grade;
	string name;
}Node;
int cmp1(Node a, Node b)
{
	return a.id < b.id;
}
int cmp2(Node a, Node b)
{
	return a.name != b.name? a.name < b.name : a.id < b.id;
}
int cmp3(Node a, Node b)
{
	return a.grade != b.grade ? a.grade < b.grade : a.id < b.id;
}
int main()
{
	int n, c;
	cin >> n >> c;
	vector<Node> Record(n);
	for (int i = 0; i < n; i++) 
		cin >> Record[i].id >> Record[i].name >> Record[i].grade;
	switch (c) {
	case 1: sort(Record.begin(), Record.end(), cmp1); break;
	case 2: sort(Record.begin(), Record.end(), cmp2); break;
	case 3: sort(Record.begin(), Record.end(), cmp3); break;
	}
	for (int i = 0; i < n; i++) {
		printf("%06d ", Record[i].id);
		cout << Record[i].name;
		printf(" %d\n", Record[i].grade);
	}

	system("pause");
	return 0;
}