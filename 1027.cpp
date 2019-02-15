/*
- decimal to radix 13
*/
#include "stdafx.h"
#include <iostream>
#include <map>
#include <string>
using namespace std;
map<int, char> A = { {10, 'A'}, {11, 'B'}, {12, 'C'} };
void output(int n)
{
	string s;
	int a, b;
	a = n / 13;
	b = n % 13;
	if (a >= 10)
		s.push_back(A[a]);
	else
		s.push_back(a + '0');
	if (b >= 10)
		s.push_back(A[b]);
	else
		s.push_back(b + '0');
	cout << s;
}
int main()
{
	int r, g, b;
	cin >> r >> g >> b;
	cout << "#";
	output(r);
	output(g);
	output(b);
	system("pause");
    return 0;
}

