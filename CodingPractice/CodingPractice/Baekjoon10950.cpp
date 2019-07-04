#include<iostream>
using namespace std;
int main() {
	int t;  // 테스트 케이스 개수
	cin >> t;
	int a, b;

	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		cout << a + b << endl;
	}
}

//#include<iostream>
//using namespace std;
//int main() {
//	int t;  // 테스트 케이스 개수
//	cin >> t;
//	int a[5], b[5];
//
//	for (int i = 0; i < t; i++)
//		cin >> a[i] >> b[i];
//
//	for (int i = 0; i < t; i++)
//		cout << a[i] + b[i] << endl;
//
//	system("pause");
//}