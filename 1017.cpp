#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#define EIGHT 28800
#define FIFTEEN 61200

using namespace std;

typedef struct node {
	int hour, min, sec;
	int arrive;
	int ptime;
}Cus;

int cmp(Cus a, Cus b)
{
	return a.arrive < b.arrive;
}

int main()
{
	int n, k;
	int hour, min, sec, process;
	scanf_s("%d %d", &n, &k);
	vector<Cus> custom(n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d:%d:%d %d", &hour, &min, &sec, &process);
		custom[i].hour = hour; custom[i].min = min; custom[i].sec = sec; custom[i].ptime = process * 60;
		custom[i].arrive = hour * 60 * 60 + min * 60 + sec;
	}
	sort(custom.begin(), custom.end(), cmp);
	vector<int> window(k, EIGHT);
	Cus temp;
	int wait = 0, i;
	int cnt = 0;
	for (i = 0; i < k; i++) {
		if (custom.size() > 0) {
			temp = custom[0];
			custom.erase(custom.begin());
			if (temp.arrive > FIFTEEN) break;
			cnt++;
		}
		else break;

		if (temp.arrive < EIGHT) {
			wait += EIGHT - temp.arrive;
			window[i] = EIGHT + temp.ptime;
		}
		else {
			window[i] = temp.arrive + temp.ptime;
		}
	}

	for (i; i < n; i++) {
		sort(window.begin(), window.end());
		if (custom.size() > 0){
			temp = custom[0];
			custom.erase(custom.begin());
			if (temp.arrive > FIFTEEN) break;
			cnt++;
		}
		else break;

		if (temp.arrive >= window[0]) {
			window[0] = temp.arrive + temp.ptime;
		}
		else {
			wait += window[0] - temp.arrive;
			window[0] += temp.ptime;
		}
	}
	printf("%.1f", wait / 60.0 / cnt);
	system("pause");
    return 0;
}

