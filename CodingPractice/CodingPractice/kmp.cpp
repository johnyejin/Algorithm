#include<iostream>
#include<stdlib.h>
#include<string>
#include <cstdio>
#include <vector>
using namespace std;

void bruteforce(std::string &T, std::string &P)
{
	int n = T.length();
	int m = P.length();

	bool isMatch = true;
	int cnt = 0;
	int num = 0;
	int count = 0;

	for (int i = 0; i < n - m + 1; i++) {
		
		for (int j = 0; j < m; j++) {
			cnt++;

			if (T[i + j] != P[j]) {
				isMatch = false;
				break;
			}
			else {
				num++;
			}
		}
		
		if (num == m)
			count++;
	}
	if (count == 0)
		cout << cnt << endl;
	else
		cout << cnt << endl;
}

vector<int> getPi(string p) {
	int m = (int)p.size(), j = 0;
	vector<int> pi(m, 0);
	for (int i = 1; i< m; i++) {
		while (j > 0 && p[i] != p[j])
			j = pi[j - 1];
		if (p[i] == p[j])
			pi[i] = ++j;
	}
	return pi;
}

vector<int> kmp(string s, string p) {
	vector<int> ans;
	int cnt = 0;

	auto ib = getPi(p);
	int n = (int)s.size(), m = (int)p.size(), j = 0;

	for (int i = 0; i < n; i++) {
		while (j > 0 && s[i] != p[j]) {
			cnt++;
			j = ib[j - 1];
		}
		if (s[i] == p[j]) {
			cnt++;
			if (j == m - 1) {
				ans.push_back(i - m + 1);
				j = ib[j];
			}
			else {
				j++;
			}
		}
	}
	ans.push_back(cnt-1);
	return ans;
}

int main()
{
	int a, b;
	cin >> a >> b;
	cin.ignore();

	string s, p;
	getline(cin, s);
	getline(cin, p);

	if ((int)s.size() == a && (int)p.size() == b) {
		auto matched = kmp(s, p);
		cout << (int)matched.size() - 1 << " ";
		bruteforce(s, p);
		cout << (int)matched.size() - 1 << " " << (int)matched.back() << endl;

	}

	getchar();
	return 0;
}