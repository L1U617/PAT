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
		if ((n - n2) % 2 == 0) {
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

