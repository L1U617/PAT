#include "stdafx.h"
#include <iostream>
#include <string>
/*
using namespace std;

int to_second(string s)
{
	int sum = 0;
	string tmp;
	tmp.assign(s, 0, 2);
	sum += stoi(tmp) * 3600;
	tmp.assign(s, 3, 2);
	sum += stoi(tmp) * 60;
	tmp.assign(s, 6, 2);
	sum += stoi(tmp);

	return sum;
}

int main()
{
	int m;
	string id, t1, t2;
	string in, out;
	int min = 86400, max = 0;
	int sin, sout;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> id >> t1 >> t2;
		sin = to_second(t1); sout = to_second(t2);
		if (sin < min) {
			min = sin; in = id;
		}
		if (sout > max) {
			max = sout; out = id;
		}
	}

	cout << in << " " << out;
	system("pause");
	return 0;
}*/