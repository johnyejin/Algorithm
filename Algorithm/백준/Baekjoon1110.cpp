#include<iostream>
using namespace std;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int a, b;  // a=10�� �ڸ���, b=1�� �ڸ���
	int newN = n;  // ���ο� n
	int l = 0; // ����Ŭ ����

	do {
		b = newN % 10;
		a = (newN % 100 - b) / 10;
		
		if (a + b >= 10) {
			newN = b * 10 + ((a + b) % 10);
		}
		else {
			newN = b * 10 + a + b;
		}
		//cout << newN << endl;
		l++;
	} while (newN != n);
	cout << l << "\n";

	system("pause");
}