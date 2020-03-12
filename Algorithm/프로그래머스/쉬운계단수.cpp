// 왜 3번이나 1000000000이거로 나눠야댐?
#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<vector<int>> dp(n, vector<int>(10, 0));
	dp[0] = { 0,1,1,1,1,1,1,1,1,1 };

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0)
				dp[i][j] = dp[i - 1][1];
			else if (j == 9)
				dp[i][j] = dp[i - 1][8];
			else
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
		}
	}

	int sum = 0;
	for (int i = 0; i < 10; i++)
		sum = (sum + dp[n - 1][i]) % 1000000000;

	cout << sum % 1000000000 << endl;
}