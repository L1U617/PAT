#include "stdafx.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	string n[3];
	int tag;
	long long decimal = 0, j = 0, tmp, radix;
	cin >> n[1] >> n[2] >> tag >> radix;
	for (int i = n[tag].length() - 1; i >= 0; i--) {
		if (n[tag][i] >= 'a' && n[tag][i] <= 'z') {
			tmp = n[tag][i] - 'a' + 10;
		}
		else tmp = n[tag][i] - '0';
		decimal += tmp * pow(radix, j++);
	}
	int max = 0;
	for (int i = n[3 - tag].length() - 1; i >= 0; i--) {
		if (n[3 - tag][i] >= 'a' && n[3 - tag][i] <= 'z') {
			tmp = n[3 - tag][i] - 'a' + 10;
		}
		else tmp = n[3 - tag][i] - '0';
		if (tmp > max) max = tmp;
	}
	int r = max + 1, flag = 0;
	long long d = 0;
	while (r <= decimal) {
		j = 0;
		d = 0;
		for (int i = n[3 - tag].length() - 1; i >= 0; i--) {
			if (n[3 - tag][i] >= 'a' && n[3 - tag][i] <= 'z') {
				tmp = n[3 - tag][i] - 'a' + 10;
			}
			else tmp = n[3 - tag][i] - '0';
			d += tmp * pow(r, j++);
		}
		if (d == decimal) {
			flag = 1;
			break;
		}
		if (d > decimal) break;
		if (n[3 - tag].length() == 1 && d < decimal) break;
		r++;
	}

	if (flag) cout << r;
	else cout << "Impossible";
	system("pause");
    return 0;
}

