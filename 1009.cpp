#include "stdafx.h"
#include <iostream>
#include <vector>

#define MaxSize 1001

using namespace std;

int main()
{
	vector<float> A(MaxSize, 0), B(MaxSize, 0), C(MaxSize * 2, 0);
	int k, exp;
	cin >> k;
	for (int j = 0; j < k; j++) {
		cin >> exp;
		cin >> A[exp];
	}
	cin >> k;
	for (int j = 0; j < k; j++) {
		cin >> exp;
		cin >> B[exp];
	}
	int cnt = 0;
	float prod;
	for (int i = 0; i < MaxSize; i++) {
		if (A[i] == 0.0) continue;
		for (int j = 0; j < MaxSize; j++) {
			prod = A[i] * B[j];
			if (prod != 0) {
				if (C[i + j] == 0) cnt++; 
				C[i + j] += prod;
				if (C[i + j] == 0) cnt--;
			}
		}
	}
	cout << cnt;
	for (int i = 2001; i >= 0; i--)
	{
		if (C[i] != 0) printf(" %d %.1f", i, C[i]);
	}

	system("pause");
	return 0;
}