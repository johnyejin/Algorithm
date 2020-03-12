#include <string>
#include <vector>

using namespace std;

bool visit[200];  // 1이면 true

// 깊이우선탐색
void dfs(int start, vector<vector<int>> computers, int n) {
	visit[start] = 1;

	// 연결된 것들을 끝까지 찾음
	for (int i = 0; i < n; i++) {
		if (!visit[i] && computers[start][i]) {  // 방문하지 않았고 com = 1인 경우
			dfs(i, computers, n);
		}
	}
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;

	for (int i = 0; i < n; i++) {
		if (!visit[i]) {  // 연결된게 끝난 경우 answer++
			answer++;
			dfs(i, computers, n);
		}
	}

	return answer;
}