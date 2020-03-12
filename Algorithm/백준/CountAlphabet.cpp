/*
 * 문자열 찾기
 * ABCAA -> A 3, B 1, C 1
 */
#include<iostream>
#include<string>
using namespace std;

int main() {
	string str;
	cin >> str;
	int arr[26] = { 0 };

	for (int i = 0; i < str.length(); i++) {
		arr[str[i] - 65] += 1;
	}
	for (int i = 0; i < 26; i++) {
		if (arr[i] > 0) cout << char(65 + i) << " " << arr[i] << endl;
	}

	system("pause");
	return 0;
}