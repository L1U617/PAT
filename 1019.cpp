/*
- Palindromic number
- in certain numeral system
*/
#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

bool isPalin(vector<int> s)
{
	int k = s.size();
	for (int i = 0; i < k / 2; i++)
		if (s[i] != s[k - i - 1]) return false;
	return true;
}

int main()
{
	int n, b;
	cin >> n >> b;
	vector<int> s;

	while (n != 0) {
		s.push_back(n % b);
		n = n / b;
	}
	if (isPalin(s))  cout << "Yes" << endl;
	else cout << "No" << endl;

	cout << s[s.size() - 1];
	for (int i = s.size() - 2; i >= 0; i--)
		 	cout << " " << s[i];

	system("pause");
    return 0;
}

