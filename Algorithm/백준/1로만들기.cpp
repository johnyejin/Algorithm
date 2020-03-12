// +1 왜하는거지?
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	int dp[1000001];
	dp[1] = 0;
	
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		if (n % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3] + 1);
		if (n % 2 == 0)
			dp[i] = min(dp[i], dp[i / 2] + 1);
	}

	cout << dp[n] << endl;
	system("pause");
}