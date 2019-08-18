#include<iostream>
using namespace std;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long answer = 0; // 필요한 감독관의 최소 수
	int n; // 시험장 개수
	cin >> n;
	int *a = new int[n]; // 각 시험장에 있는 응시자 수
	int b, c; // 각 감독관이 감시할수 있는 응시자 수
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> b >> c;

	for (int i = 0; i < n; i++) {
		int k = a[i] - b;
		answer++;
		if (k <= 0) {
			continue;
		}
		if (k % c == 0) {
			answer += k / c;
		}
		else {
			answer += k / c + 1;
		}
	}
	cout << answer << endl;

	system("pause");
}