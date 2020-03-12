#include<iostream>
using namespace std;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int a, b;  // a=10의 자리수, b=1의 자리수
	int newN = n;  // 새로운 n
	int l = 0; // 사이클 길이

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