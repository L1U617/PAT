#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	string origin;
	cin >> origin;
	vector<int> o, d;
	int carry = 0;
	for (int i = origin.length() - 1; i >= 0; i--) {
		int a = origin[i] - '0';
		o.push_back(a);
		a = a * 2 + carry;
		carry = a / 10;		
		d.push_back(a % 10);
	}
	if (carry) d.push_back(carry);
	vector<int> result = d;
	sort(o.begin(), o.end());
	sort(d.begin(), d.end());
	int flag = 1;
	if (o.size() != d.size()) flag = 0;
	else {
		for(int i = 0; i < o.size(); i++)
			if (o[i] != d[i]) {
				flag = 0; 
				break;
			}
	}
	if (flag) cout << "Yes" << endl;
	else cout << "No" << endl;
	for (int i = result.size() - 1; i >= 0; i--)
		cout << result[i];
	system("pause");
	return 0;
}