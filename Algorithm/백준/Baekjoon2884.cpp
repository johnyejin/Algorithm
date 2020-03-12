#include<iostream>
using namespace std;
int main() {
	int h, m;  // ½Ã, ºÐ
	cin >> h >> m;

	m = m - 45;
	if (m < 0) {
		h = h - 1;
		m = m + 60;  // 60-(45-m) + 45

		if (h - 1 < 0) {
			h = 24 - 1;
		}
	}
	cout << h << " " << m;
	system("pause");
}