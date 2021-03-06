#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

bool isPrime(int n)
{
	if (n <= 1) return false;
	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0) return false;
	return true;
}

int reverse(int n, int d)
{
	string s;
	while (n!= 0) {
		s.push_back(n % d);
		n = n / d;
	}
	int i, sum = 0, j = 0;
	for (i = s.length() - 1; i >= 0; i--) {
		sum += s[i] * pow(d, j++);
	}
	return sum;
}

int main()
{
	int n, d;
	while (1) {
		scanf_s("%d", &n);
		if (n < 0) break;
		scanf_s("%d\n", &d);
		int r = reverse(n, d);
		if (isPrime(n) && isPrime(r)) printf("Yes\n");
		else printf("No\n");
	}
	system("pause");
    return 0;
}

