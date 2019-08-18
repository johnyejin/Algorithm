#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

bool visit[1001];

// �湮�� �� �ִ� ������ �������� ��� ��ȣ�� ������ ���� �湮
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

	int n, m, v; // ������ ����, ������ ����, Ž�� ���� ��ȣ
	cin >> n >> m >> v;
	vector<int> arr[1001];  // [n][2]�� ����������

	// ��������Ʈ�� ����
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	// ���� ��ȣ���� �湮�ؾ� �Ǵϱ� ����
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