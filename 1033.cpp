/*
- 加油站问题
- 贪心算法 Greedy Algorithm
*/
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int inf = 99999999;
typedef struct node {
	double price, dis;
}Node;
int cmp(Node a, Node b) 
{
	return a.dis < b.dis;
}
vector<Node> GasStation;
double nowdis = 0, maxdis = 0, leftdis = 0.0;
double nowprice = 0.0, totalprice = 0.0;

int main()
{
	double cmax, DIS, davg;
	int n;
	cin >> cmax >> DIS >> davg >> n;
	GasStation.resize(n + 1);
	GasStation[0].price = 0; GasStation[0].dis = DIS;
	for (int i = 1; i <= n; i++) {
		cin >> GasStation[i].price >> GasStation[i].dis;
	}
	sort(GasStation.begin(), GasStation.end(), cmp);
	if (GasStation[0].dis != 0) {
		printf("The maximum travel distance = 0.00");
		return 0;
	}
	else {
		nowprice = GasStation[0].price;
	}
	int i = 0;
	while (nowdis < DIS) {
		maxdis = nowdis + cmax * davg;
		int j = i + 1, flag = 0, minstat;
		double minprice = inf, minpriceDis = 0.0;
		for (j; j <= n && GasStation[j].dis <= maxdis; j++) {
			if (GasStation[j].price < nowprice) {//只用找到第一个更低的价格
				flag = 1;
				totalprice += (GasStation[j].dis - nowdis - leftdis) * nowprice / davg;//刚刚好能到加油站，一分钱都不多花
				leftdis = 0.0;
				nowdis = GasStation[j].dis;
				nowprice = GasStation[j].price;
				i = j;
				break;
			}
			if (GasStation[j].price < minprice) {
				minprice = GasStation[j].price; 
				minpriceDis = GasStation[j].dis;
				minstat = j;
			}
		}
		if (flag == 0 && minprice != inf) {//没有找到比当前加油站更便宜的加油站，但能到达其中某个最便宜的加油站
			totalprice += (nowprice * (cmax - leftdis / davg));// 油箱加满，加满以后，能跑的最大距离内不会再停在任何加油站了，因为现在选的加油站已经是这段距离内最便宜的了
			leftdis = cmax * davg - (minpriceDis - nowdis);//到了加油站以后可能还有残余的油能再跑一段距离
			nowprice = minprice;//把该加油站作为当前加油站，继续循环，找到之后最便宜的加油站
			nowdis = minpriceDis;
			i = minstat;
		}
		if(flag == 0 && minprice == inf)
		{
			nowdis += cmax * davg;
			printf("The maximum travel distance = %.2f", nowdis);
			return 0;			
		}
	}
	printf("%.2f", totalprice);
	system("pause");
    return 0;
}

