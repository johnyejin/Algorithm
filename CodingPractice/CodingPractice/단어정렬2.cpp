#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool comp(string a, string b) {
	if (a.size() == b.size())  // 사이즈 같으면 사전순
		return a < b;
	return a.size() < b.size(); // 사이즈 다르면 사이즈 작은거 먼저
}

int main() {
	int n; // 단어의 개수
	cin >> n;
	vector<string> arr;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		arr.push_back(s);
	}

	sort(arr.begin(), arr.end(), comp);

	vector<string>::iterator it;
	vector<string>::iterator end_it;
	end_it = unique(arr.begin(), arr.end());  // 중복제거

	for (it = arr.begin(); it != end_it; it++)
		cout << *it << endl;


	system("pause");
}