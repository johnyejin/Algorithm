#include<iostream>
using namespace std;
int main() {

	// 입출력 속도 늘리기
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;  // 테스트 케이스 개수
	cin >> t;
	int a, b;

	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		cout << a + b << "\n";
	}
	system("pause");
}