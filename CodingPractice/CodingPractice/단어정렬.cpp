#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	int n; // 단어의 개수
	cin >> n;
	vector<pair<int,string>> arr;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		arr.push_back(make_pair(s.size(), s));
	}

	sort(arr.begin(), arr.end());

	cout << arr[0].second << endl;
	for (int i = 1; i < arr.size(); i++) {
		if (arr[i].second == arr[i - 1].second)
			continue;
		cout << arr[i].second << endl;
	}
		

	system("pause");
}