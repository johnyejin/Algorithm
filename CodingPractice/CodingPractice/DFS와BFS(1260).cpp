#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

bool visit[1001];

// 방문할 수 있는 정점이 여러개인 경우 번호가 작은거 먼저 방문
void dfs(vector<int> *arr, int start) {
	visit[start] = 1;
	cout << start << " ";

	for (int i : arr[start]) {
		if (!visit[i]) {
			dfs(arr, i);
		}
	}
} 

void bfs(vector<int> *arr, int start) {
	queue<int> q;
	q.push(start);
	visit[start] = 1;

	while (!q.empty()) {
		int a = q.front();
		q.pop();
		cout << a << " ";

		for (int i : arr[a]) {
			if (!visit[i]) {
				q.push(i);
				visit[i] = 1;
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, v; // 정점의 개수, 간선의 개수, 탐색 시작 번호
	cin >> n >> m >> v;
	vector<int> arr[1001];  // [n][2]의 이차원벡터

	// 인접리스트로 저장
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	// 작은 번호부터 방문해야 되니까 정렬
	for (int i = 1; i <= n; i++) {
		sort(arr[i].begin(), arr[i].end());
	}

	dfs(arr, v);
	cout << endl;
	memset(visit, 0, sizeof(visit));
	bfs(arr, v);
	cout << endl;

	system("pause");
}