#include<iostream>
#include<vector>
using namespace std;

bool visit[101];
int answer = 0;  // 바이러스에 걸리게 되는 컴퓨터의 수

void dfs(vector<int> *arr, int start) {
	visit[start] = 1;

	for (int i : arr[start]) {
		if (!visit[i]) {
			answer++;
			dfs(arr, i);
		}
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;  // 컴퓨터의 수, 연결된 컴퓨터 쌍의 수
	cin >> n >> m;
	vector<int> arr[101];

	// 인접리스트
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	dfs(arr, 1);  // 1번 컴퓨터가 바이러스에 걸린 경우
	cout << answer << "\n";

	system("pause");
}