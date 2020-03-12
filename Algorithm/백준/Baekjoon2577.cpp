#include<iostream>
#include<string>
using namespace std;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b, c;
	cin >> a >> b >> c;
	int mul = a * b * c;
	string s = to_string(mul);
	int arr[10] = { 0 };  // 0-9까지 숫자가 몇번 쓰였는지

	for (int i = 0; i < s.length(); i++)
		arr[s.at(i) - '0']++;  // 문자를 숫자로 바꿔줌

	for (int i = 0; i < 10; i++)
		cout << arr[i] << "\n";

	system("pause");
}