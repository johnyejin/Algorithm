// 실패한 코드
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	// int answer = 0;
	int dp[5001] = { 0, };
	dp[0] = 1;
	dp[2] = 3;

	for (int i = 4; i <= n; i += 2) {
		dp[i] = 3 * dp[i - 2];
		for (int k = i - 4; k >= 0; k -= 2)
			dp[i] += 2 * dp[k];
	}

	return dp[n] % 100000;
}