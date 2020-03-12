// memset���� �ʱ�ȭ ���ִϱ� ������;;
#include<iostream>
#include<string.h>
using namespace std;

int m, n, k; // ���߹� ����(���α���, ���α���), k: ���� ����
int arr[50][50] = { 0 }; // �������迭
bool visit[50][50] = { 0 };
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void dfs(int y, int x) {

	// �����¿� ��
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < m && 0 <= ny && ny < n) {
			if (!visit[ny][nx] && arr[ny][nx] == 1) {
				visit[ny][nx] = true;
				dfs(ny, nx);
			}
		}
	}
}

int main() {
	int t; // �׽�Ʈ ���̽� ����
	cin >> t;


	for (int i = 0; i < t; i++) {
		scanf("%d %d %d", &m, &n, &k);

		memset(arr, 0, sizeof(arr));
		memset(visit, 0, sizeof(visit));

		for (int j = 0; j < k; j++) {
			int a, b;
			scanf("%d %d", &a, &b);
			arr[b][a] = 1;
		}

		int cnt = 0; // ������ ����
		for (int a = 0; a < n; a++) {
			for (int b = 0; b < m; b++) {
				if (!visit[a][b] && arr[a][b] == 1) {
					visit[a][b] = true;
					dfs(a, b);
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
}