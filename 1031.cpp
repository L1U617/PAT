/*
n1 + n2 + n3 - 2 = n
n1 = n3 = max{ k | k≤n2 for all 3 ≤ n2 ≤ N } 
*/
#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s; 
	cin >> s;
	int n = s.length();
	int n1 = 0, n2 = 3;
	for(n2; n2 <= n; n2++) {
		int k;
		if ((n - n2) % 2 == 0) {  //取满足条件的最大的n1，首先要满足n - n2后能被2整除，然后找到满足题目条件的最大值，因此n2从小到大遍历
			k = (n - n2) / 2;
			if (k + 1 <= n2) {
				n1 = k + 1;
				break;
			}
		}
	}
	int i;
	for (i = 0; i < n1 - 1; i++) {
		cout << s[i];
		for (int j = 0; j < n2 - 2; j++)
			cout << " ";
		cout << s[n - 1 - i] << endl;
	}
	for (int j = 0; j < n2; j++)
		cout << s[i++];
	system("pause");
    return 0;
}

