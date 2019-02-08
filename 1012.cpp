#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define Max 1000000
using namespace std;
map<int, char> course = { { 0,'A' },{ 1, 'C' },{ 2, 'M' },{ 3, 'E' } };
typedef struct node Node;
struct node {
	int id;
	int rank[4];
};
typedef struct snode SubNode;
struct snode {
	int id;
	float grade;
};
bool cmp(SubNode a, SubNode b)
{
	return a.grade > b.grade;
}
int main()
{
	int n, m;
	int id;
	float cs, math, eng, ave;
	Node init;
	init.id = -1;
	vector<Node> L(Max, init);
	vector<SubNode> C, M, E, A;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> id >> cs >> math >> eng;
		ave = (math + eng + cs) / 3.0;
		SubNode tmp; tmp.id = id;
		L[id].id = id;
		tmp.grade = cs; C.push_back(tmp);
		tmp.grade = math; M.push_back(tmp);
		tmp.grade = eng; E.push_back(tmp);
		tmp.grade = ave; A.push_back(tmp);
	}
	sort(C.begin(), C.end(), cmp);
	sort(M.begin(), M.end(), cmp);
	sort(E.begin(), E.end(), cmp);
	sort(A.begin(), A.end(), cmp);
	if (C.size() != 0){
	L[A[0].id].rank[0] = 1;
	L[C[0].id].rank[1] = 1;
	L[M[0].id].rank[2] = 1;
	L[E[0].id].rank[3] = 1;}
	int ra = 1, rc = 1, rm = 1, re = 1;
	for (int i = 1; i < C.size(); i++) {
		if (A[i].grade != A[i - 1].grade) ra = i + 1;
		L[A[i].id].rank[0] = ra;
		if (C[i].grade != C[i - 1].grade) rc = i + 1;
		L[C[i].id].rank[1] = rc;
		if (M[i].grade != M[i - 1].grade) rm = i + 1;;
		L[M[i].id].rank[2] = rm;
		if (E[i].grade != E[i - 1].grade) re = i + 1;
		L[E[i].id].rank[3] = re;
	}
	int request;
	for (int i = 0; i < m; i++) {
		cin >> request;
		if (L[request].id == -1) {
			cout << "N/A" << endl;
			continue;
		}
		int min = Max;
		int j;
		for (j = 0; j < 4; j++) if (min > L[request].rank[j]) min = L[request].rank[j];
		for (j = 0; j < 4; j++) if (min == L[request].rank[j]) break;
		cout << min << " " << course[j] << endl;;
	}
	system("pause");
	return 0;
}
/*
#include <cstdio>
#include <algorithm>
using namespace std;
struct node {
	int id, best;
	int score[4], rank[4];
}stu[2005];
int exist[1000000], flag = -1;
bool cmp1(node a, node b) { return a.score[flag] > b.score[flag]; }
int main() {
	int n, m, id;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &stu[i].id, &stu[i].score[1], &stu[i].score[2], &stu[i].score[3]);
		stu[i].score[0] = (stu[i].score[1] + stu[i].score[2] + stu[i].score[3]) / 3.0 + 0.5;
	}
	for (flag = 0; flag <= 3; flag++) {
		sort(stu, stu + n, cmp1);
		stu[0].rank[flag] = 1;
		for (int i = 1; i < n; i++) {
			stu[i].rank[flag] = i + 1;
			if (stu[i].score[flag] == stu[i - 1].score[flag])
				stu[i].rank[flag] = stu[i - 1].rank[flag];
		}
	}
	for (int i = 0; i < n; i++) {
		exist[stu[i].id] = i + 1;
		stu[i].best = 0;
		int minn = stu[i].rank[0];
		for (int j = 1; j <= 3; j++) {
			if (stu[i].rank[j] < minn) {
				minn = stu[i].rank[j];
				stu[i].best = j;
			}
		}
	}
	char c[5] = { 'A', 'C', 'M', 'E' };
	for (int i = 0; i < m; i++) {
		scanf("%d", &id);
		int temp = exist[id];
		if (temp) {
			int best = stu[temp - 1].best;
			printf("%d %c\n", stu[temp - 1].rank[best], c[best]);
		}
		else {
			printf("N/A\n");
		}
	}
	return 0;
}*/