// �̰� �� cmdâ �����°���..?
#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int dp[1000000];
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
	}
	cout << dp[n] << endl;

	system("pause");
}