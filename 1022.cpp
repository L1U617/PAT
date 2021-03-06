/*
*/
#include "stdafx.h"
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
map<string, vector<int> > title, author, keyword, publisher, year;
int main()
{
	int n, m;
	cin >> n;
	int id;
	string t, a, k, p, y;
	for (int i = 0; i < n; i++) {
		scanf_s("%d\n", &id);
		getline(cin, t);
		title[t].push_back(id);
		getline(cin, a);
		author[a].push_back(id);
		getline(cin, k);
		int start = 0, cnt = 0;
		string key;
		for (int j = 0; j < k.length(); j++) {			
			if (k[j] == ' ') {
				key = k.substr(start, cnt);
				keyword[key].push_back(id);
				start = j + 1;
				cnt = 0;
			}
			else
				cnt++;
		}
		key = k.substr(start, cnt);
		keyword[key].push_back(id);
		getline(cin, p);
		publisher[p].push_back(id);
		getline(cin, y);
		year[y].push_back(id);
	}
	cin >> m;
	getchar();
	for (int i = 0; i < m; i++) {
		string query, s;
		getline(cin, query);
		cout << query << endl;
		s = query.substr(3, query.length() - 3);
		switch (query[0]) {
		case '1':
			if (title.find(s) == title.end())
				cout << "Not Found" << endl;
			else {
				sort(title[s].begin(), title[s].end());
				for (int j = 0; j < title[s].size(); j++)
					printf("%07d\n", title[s][j]);
			}
			break;
		case '2':
			if (author.find(s) == author.end())
				cout << "Not Found" << endl;
			else {
				sort(author[s].begin(), author[s].end());
				for (int j = 0; j < author[s].size(); j++)
					printf("%07d\n", author[s][j]);
			}
			break;
		case '3':
			if (keyword.find(s) == keyword.end())
				cout << "Not Found" << endl;
			else {
				sort(keyword[s].begin(), keyword[s].end());
				for (int j = 0; j < keyword[s].size(); j++)
					printf("%07d\n", keyword[s][j]);
			}
			break;
		case '4':
			if (publisher.find(s) == publisher.end())
				cout << "Not Found" << endl;
			else {
				sort(publisher[s].begin(), publisher[s].end());
				for (int j = 0; j < publisher[s].size(); j++)
					printf("%07d\n", publisher[s][j]);
			}
			break;
		case '5':
			if (year.find(s) == year.end())
				cout << "Not Found" << endl;
			else {
				sort(year[s].begin(), year[s].end());
				for (int j = 0; j < year[s].size(); j++)
					printf("%07d\n", year[s][j]);
			}
			break;
		}
	}
	system("pause");
    return 0;
}

