#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
typedef struct node {
	int add, next;
	char data;
}Node;
vector<Node> word1, word2;
vector<vector <int> > Mem(100000, vector<int>(2));

vector<Node> init(int start)
{
	vector<Node> word;
	Node temp;
	if (start == -1) return word;
	int pre = start;
	int next = Mem[pre][1];
	while (next != -1) {
		temp.add = pre; temp.next = next; temp.data = Mem[pre][0];
		word.push_back(temp);
		pre = next;
		next = Mem[pre][1];
	}
	temp.add = pre; temp.next = -1; temp.data = Mem[pre][0];
	word.push_back(temp);
	return word;
}

int main()
{
	int start1, start2, n;
	int position = -1;
	cin >> start1 >> start2 >> n;
	for (int i = 0; i < n; i++) {
		int add, next; 
		char data;
		cin >> add >> data >> next;
		Mem[add][0] = data;
		Mem[add][1] = next;
	}
	word1 = init(start1);
	word2 = init(start2);
	int i = word1.size() - 1, j = word2.size() - 1;
	while (i >= 0 && j >= 0) {
		if (word1[i].add != word2[j].add) break;
		i--; j--;
	}
	if (i == word1.size() - 1) cout << -1;
	else printf("%05d", word1[i + 1].add);
	system("pause");
    return 0;
}

