#include<iostream>
#include<vector>
using namespace std;

bool visit[101];
int answer = 0;  // ���̷����� �ɸ��� �Ǵ� ��ǻ���� ��

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

	int n, m;  // ��ǻ���� ��, ����� ��ǻ�� ���� ��
	cin >> n >> m;
	vector<int> arr[101];

	// ��������Ʈ
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	dfs(arr, 1);  // 1�� ��ǻ�Ͱ� ���̷����� �ɸ� ���
	cout << answer << "\n";

	system("pause");
}