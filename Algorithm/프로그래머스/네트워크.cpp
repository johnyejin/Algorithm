#include <string>
#include <vector>

using namespace std;

bool visit[200];  // 1�̸� true

// ���̿켱Ž��
void dfs(int start, vector<vector<int>> computers, int n) {
	visit[start] = 1;

	// ����� �͵��� ������ ã��
	for (int i = 0; i < n; i++) {
		if (!visit[i] && computers[start][i]) {  // �湮���� �ʾҰ� com = 1�� ���
			dfs(i, computers, n);
		}
	}
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;

	for (int i = 0; i < n; i++) {
		if (!visit[i]) {  // ����Ȱ� ���� ��� answer++
			answer++;
			dfs(i, computers, n);
		}
	}

	return answer;
}