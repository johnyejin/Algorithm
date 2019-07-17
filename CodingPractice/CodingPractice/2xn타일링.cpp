#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int answer = 0;
	int dp[600001] = { 0, };
	dp[1] = 1;
	dp[2] = 2;


	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;   // 왜 저 숫자가..?
	}
	answer = dp[n];
	return answer;
}