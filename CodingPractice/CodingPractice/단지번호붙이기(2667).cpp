// ���� ü���Ҷ� cin, cout���� Ʋ��;
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n; // ���簢�� ����
int arr[25][25]; // ����
bool visit[25][25];
int cnt = 0;  // ������
int answer[625];  // ���̷����� �ɸ��� �Ǵ� ��ǻ���� ��
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

void dfs(int x, int y) {
	visit[x][y] = true;
	answer[cnt]++;

	// �����¿� ��
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < n && 0 <= ny && ny < n) {
			if (!visit[nx][ny] && arr[nx][ny] == 1) {
				dfs(nx, ny);
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &arr[i][j]);  // ���� �Ѱ��� �Է¹ޱ�
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visit[i][j] && arr[i][j] == 1) {
				dfs(i, j);
				cnt++;
			}
		}
	}

	cout << cnt << endl;
	sort(answer, answer + cnt);  // �������� ����
	for (int i = 0; i < cnt; i++) cout << answer[i] << endl;

	system("pause");
}