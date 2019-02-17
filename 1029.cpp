/*
- fing median of two nondecreasing sequences;
*/
#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n1, n2;
	cin >> n1;
	vector<int> s1(n1 + 1);
	for (int i = 0; i < n1; i++) 
		scanf("%d", &s1[i]);
	s1[n1] = 0x7fffffff; //加了就通过，不加就不通过……
	cin >> n2;
	int cnt = 0, mid = (n1 + n2 - 1) / 2, j = 0;
	int temp;
	int flag = 0;
	for (int i = 0; i < n2; i++) {
		scanf("%d", &temp);
		while (temp > s1[j]) {
			if (cnt == mid) {
				cout << s1[j];
				flag = 1;
				break;
			}
			j++;
			cnt++;
		}
		if (flag) break;
		if (cnt == mid) {
			cout << temp;
			flag = 1;
			break;
		}
		cnt++;
	}
	while (flag == 0) {
		if (cnt == mid) {
			cout << s1[j];
			flag = 1;
			break;
		}
		j++;
		cnt++;
	}
	system("pause");
	return 0;
}