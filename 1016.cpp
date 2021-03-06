/*
- 按字母表顺序输出用户姓名
- on-line off-line 要配对
- 通话记录按时间排序
*/

#include "stdafx.h"

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef struct node Node;
struct node {
	string time;
	int min;
	bool on;
};
typedef struct cus {
	vector<Node> rec;
	string name;
	string month;
}Custom;
vector<int> rate(25);

int toMin(string s)
{
	int day, hour, min;
	day = stoi(s.substr(0, 2)) * 24 * 60;
	hour = stoi(s.substr(3, 2)) * 60;
	min = stoi(s.substr(6, 2));
	return day + hour + min;
}
/*
float Fee(string a, string b)
{
	int start, end, sum = 0, aday = 0;
	int day1, day2;
	day1 = stoi(a.substr(0, 2));
	day2 = stoi(b.substr(0, 2));
	start = stoi(a.substr(3, 2));
	end = stoi(b.substr(3, 2));
	if (day1 == day2) {
		sum +=(60 -  stoi(a.substr(6, 2))) * rate[start];
		for (int i = start + 1; i < end; i++)
			sum += rate[i] * 60;
		sum += stoi(b.substr(6, 2)) * rate[end];
	}
	else {
		sum += (60 - stoi(a.substr(6, 2))) * rate[start];
		for (int i = 0; i < 24; i++) aday += rate[i];
		for (int i = start + 1; i < 24; i++)
			sum += rate[i] * 60;
		for (int i = day1 + 1; i < day2; i++)
			sum += aday * 60;
		for (int i = 0; i < end; i++)
			sum += rate[i] * 60;
		sum += stoi(b.substr(6, 2)) * rate[end];
	}
	return sum / 100.0;
}*/

float Fee(string a, string b)
{
	int start, end, sum1 = 0, sum2 = 0;
	int day1, day2;
	day1 = stoi(a.substr(0, 2));
	day2 = stoi(b.substr(0, 2));
	start = stoi(a.substr(3, 2));
	end = stoi(b.substr(3, 2));
	sum1 = rate[start] * stoi(a.substr(6, 2)) + rate[24] * 60 * day1;
	for (int i = 0; i < start; i++)
		sum1 += rate[i] * 60;
	sum2 = rate[end] * stoi(b.substr(6, 2)) + rate[24] * 60 * day2;
	for (int i = 0; i < end; i++)
		sum2 += rate[i] * 60;
	return sum2 / 100.0 - sum1 / 100.0;
}

int cmp1(Custom a, Custom b)
{
	return a.name < b.name;
}
int cmp2(Node a, Node b)
{
	return a.min < b.min;
}

int main()
{
	map<string, int> mapp;

	int n;
	string s;
	string month;
	rate[24] = 0;
	for (int i = 0; i < 24; i++) {
		cin >> rate[i];
		rate[24] += rate[i];
	}

	cin >> n;
	vector<Custom> Rec;
	int order = 0;
	for (int i = 0; i < n; i++) {
		string name, date, line, day;
		cin >> name >> date >> line;
		month = date.substr(0, 2);
		day = date.substr(3, 8);
		Node ntemp;
		Custom ctemp;
		ctemp.name = name;
		ctemp.month = month;
		ntemp.min = toMin(day);
		ntemp.time = day;
		if (line == "on-line")
			ntemp.on = true;
		else ntemp.on = false;
		int j;
		if (mapp.find(name) != mapp.end()) {
			j = mapp[name];
			Rec[j].rec.push_back(ntemp);
		}
		else {
			mapp[name] = order++;	
			ctemp.rec.push_back(ntemp);
			Rec.push_back(ctemp);

		}
	}
	sort(Rec.begin(), Rec.end(), cmp1);
	for (int i = 0; i < Rec.size(); i++) {

		sort(Rec[i].rec.begin(), Rec[i].rec.end(), cmp2);
		int j = 0;
		float total = 0.0;
		int flag1 = 0, flag2 = 0;
		while (j < Rec[i].rec.size()) {
			if (j + 1 < Rec[i].rec.size()) {
				if (Rec[i].rec[j].on == true && Rec[i].rec[j + 1].on == false) {
					float fee = Fee(Rec[i].rec[j].time, Rec[i].rec[j + 1].time);
					total += fee;	
					flag2 = 1;
					if (flag1 == 0) {
						cout << Rec[i].name << " " << Rec[i].month << endl;
						flag1 = 1;
					}
					cout << Rec[i].rec[j].time << " " << Rec[i].rec[j + 1].time;				
					printf(" %d $%.2f\n",  Rec[i].rec[j + 1].min - Rec[i].rec[j].min, fee);
					j += 2;
				}
				else j++;
			}
			else j++;
		}
		if(flag2 == 1)
			printf("Total amount: $%.2f\n", total);
	}

	system("pause");
    return 0;
}
/*
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
struct node {
	string name;
	int status, month, time, day, hour, minute;
};
bool cmp(node a, node b) {
	return a.name != b.name ? a.name < b.name : a.time < b.time;
}
double billFromZero(node call, int *rate) {
	double total = rate[call.hour] * call.minute + rate[24] * 60 * call.day;
	for (int i = 0; i < call.hour; i++)
		total += rate[i] * 60;
	return total / 100.0;
}
int main() {
	int rate[25] = { 0 }, n;
	for (int i = 0; i < 24; i++) {
		scanf_s("%d", &rate[i]);
		rate[24] += rate[i];
	}
	scanf_s("%d", &n);
	vector<node> data(n);
	for (int i = 0; i < n; i++) {
		cin >> data[i].name;
		scanf_s("%d:%d:%d:%d", &data[i].month, &data[i].day, &data[i].hour, &data[i].minute);
		string temp;
		cin >> temp;
		data[i].status = (temp == "on-line") ? 1 : 0;
		data[i].time = data[i].day * 24 * 60 + data[i].hour * 60 + data[i].minute;
	}
	sort(data.begin(), data.end(), cmp);
	map<string, vector<node> > custom;
	for (int i = 1; i < n; i++) {
		if (data[i].name == data[i - 1].name && data[i - 1].status == 1 && data[i].status == 0) {
			custom[data[i - 1].name].push_back(data[i - 1]);
			custom[data[i].name].push_back(data[i]);
		}
	}
	for (auto it : custom) {
		vector<node> temp = it.second;
		cout << it.first;
		printf(" %02d\n", temp[0].month);
		double total = 0.0;
		for (int i = 1; i < temp.size(); i += 2) {
			double t = billFromZero(temp[i], rate) - billFromZero(temp[i - 1], rate);
			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", temp[i - 1].day, temp[i - 1].hour, temp[i - 1].minute, temp[i].day, temp[i].hour, temp[i].minute, temp[i].time - temp[i - 1].time, t);
			total += t;
		}
		printf("Total amount: $%.2f\n", total);
	}
	system("pause");
	return 0;
}*/