#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef struct node {
	string name, id;
	int grade;
}Node;
int cmp(Node a, Node b)
{
	return a.grade > b.grade;
}
int main()
{
	vector<Node> F, M;
	int n;
	Node temp;
	char gender;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp.name >> gender >> temp.id >> temp.grade;
		if (gender == 'F') F.push_back(temp);
		else M.push_back(temp);
	}
	sort(F.begin(), F.end(), cmp);
	sort(M.begin(), M.end(), cmp);
	int flag = 0;
	if (F.size() == 0) {
		cout << "Absent" << endl;
		flag = 1;
	}
	else cout << F[0].name << " " << F[0].id << endl;
	if (M.size() == 0) {
		cout << "Absent" << endl;
		flag = 1;
	}
	else cout << M[M.size() - 1].name << " " << M[M.size() - 1].id << endl;
	if (flag == 1) cout << "NA";
	else {
		int high = F[0].grade, low = M[M.size() - 1].grade;
		int diff;
		diff = high > low ? high - low : low - high;
		cout << diff;
	}

	system("pause");
    return 0;
}

