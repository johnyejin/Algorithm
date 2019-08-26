#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n; // 집의 수
	cin >> n;

	int arr[1001][3];
	int dp[1001][3]; // i번째에 i번째 집까지의 최소값 저장
	dp[0][0] = 0, dp[0][1] = 0, dp[0][2] = 0,
		arr[0][0] = 0, arr[0][1] = 0, arr[0][2] = 0;


	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
	}

	cout << min(dp[n][0],min(dp[n][1],dp[n][2])) << endl;

	system("pause");
}