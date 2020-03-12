#include<iostream>
using namespace std;
int main() {
	double a, b;
	cin >> a >> b;
	cout.precision(11);  // 소수점 이하 11자리까지 출력
	cout << a/b;
	system("pause");
}