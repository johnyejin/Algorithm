#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
	int answer = 0;
	int map[101][101] = { 0, };
	int dp[101][101];  // dp[i][j] : (i,j)로 가는 최단경로의 개수

	// 물웅덩이가 있는곳은 -1
	for (auto v : puddles) {
		map[v[0]][v[1]] = -1;
	}

	dp[0][1] = 1;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] == -1) {
				dp[i][j] = 0;
			}
			else {
				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
			}
			// cout<<dp[i][j]<<endl;
		}
	}

	return dp[m][n];
}