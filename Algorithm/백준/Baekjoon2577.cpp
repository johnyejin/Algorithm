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
	int arr[10] = { 0 };  // 0-9���� ���ڰ� ��� ��������

	for (int i = 0; i < s.length(); i++)
		arr[s.at(i) - '0']++;  // ���ڸ� ���ڷ� �ٲ���

	for (int i = 0; i < 10; i++)
		cout << arr[i] << "\n";

	system("pause");
}