#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool comp(string a, string b) {
	if (a.size() == b.size())  // ������ ������ ������
		return a < b;
	return a.size() < b.size(); // ������ �ٸ��� ������ ������ ����
}

int main() {
	int n; // �ܾ��� ����
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
	end_it = unique(arr.begin(), arr.end());  // �ߺ�����

	for (it = arr.begin(); it != end_it; it++)
		cout << *it << endl;


	system("pause");
}