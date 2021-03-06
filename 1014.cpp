#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct clientnode Clt;
typedef struct banknode Bank;
struct clientnode {
	int id, time;
};
struct banknode {
	vector<Clt> quene;
	int startTime, finTime;
};
int client[1010];

void format(int s)
{
	int hour, min;
	if (s != -1) {
		hour = s / 60 + 8;
		min = s % 60;
		printf("%02d:%02d\n", hour, min);
	}
	else
		printf("Sorry\n");

}

int main()
{
	int n, m, k, q;
	cin >> n >> m >> k >> q;
	Bank init; init.startTime = 0; init.finTime = 0;
	vector<Bank> B(n, init);
	int cnt = 0, flag = 0;
	for (int i = 1; i <= k; i++) {
		Clt tmp;
		cin >> tmp.time;
		tmp.id = i;		
		if (i <= n * m) {
			if (i > n) flag = 1;
			int line = (i - 1) % n;
			B[line].quene.push_back(tmp);

			if (B[line].finTime >= 540) client[i] = -1;
			else {
				B[line].finTime += tmp.time;	
				client[i] = B[line].finTime;	
			}

			if (flag == 0) B[line].startTime += B[line].quene[0].time;
		}
		else {
			int j;
			int min = 100000;
			for (j = 0; j < n; j++)
				if (B[j].startTime < min) min = B[j].startTime;
			for (j = 0; j < n; j++)
				if (B[j].startTime == min) break;
			B[j].quene.push_back(tmp);
			B[j].quene.erase(B[j].quene.begin());
			B[j].startTime += B[j].quene[0].time;

			if (B[j].finTime >= 540) client[i] = -1;
			else {
				B[j].finTime += tmp.time;
				client[i] = B[j].finTime;
			}

		}
	}
	int c;
	for (int i = 0; i < q; i++) {
		cin >> c;
		format(client[c]);
	}

	system("pause");
    return 0;
}

