#include<iostream>
using namespace std;

int main() {
	int t; // 테스트 케이스 개수
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n; 
		cin >> n;

		int dp[100] = { 0,1,1,1,2,2, };
		for (int j = 5; j <= n; j++) {
			dp[j] = dp[j - 1] + dp[j - 5];
		}
		cout << dp[n] << endl;
	}
	system("pause");
}