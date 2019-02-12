#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

bool isPalin(string s)
{
	string tmp = s;
	int len = s.length();
	for (int i = 0; i < len; i++)
		if (s[i] != tmp[len - 1 - i]) return false;
	return true;
}

int main()
{
	string n;
	int k;
	cin >> n >> k;
	int step = 0;
	while (!isPalin(n) && step < k) {
		step++;
		int carry = 0, sum, len = n.length();
		string temp = n, next;
		for (int i = 0; i < len; i++) {
			sum = temp[i] - '0' + n[len - 1 - i] - '0' + carry;
			carry = sum / 10;
			sum = sum % 10 + '0';
			next.push_back(sum);
		}
		if (carry) next.push_back(carry + '0');
		n = next;
	}

	for (int i = n.length() - 1; i >= 0; i--)
		cout << n[i];
	cout << endl;
	cout << step;

	system("pause");
	return 0;
}