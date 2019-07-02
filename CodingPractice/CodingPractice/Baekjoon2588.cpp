#include<iostream>
using namespace std;
int main() {
	int a, b;
	int x, y, z;
	cin >> a;
	cin >> b;
	x = a * (b % 10);
	y = a * (b % 100 - b % 10) / 10;
	z = a * (b / 100);
	cout << x << endl;
	cout << y << endl;
	cout << z << endl;
	cout << x + y * 10 + z * 100 << endl;
	system("pause");
}