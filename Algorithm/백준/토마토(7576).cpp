#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
using namespace std;

int n, m;  // m*n ���
int arr[1000][1000]; // �������迭
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
int total = 0; // 0�� ����
queue<pair<int, int>> q;

int bfs() {
	int answer = 0;
	int size;

	while (!q.empty()) {
		size = q.size();
		total += size;

		if (total == n * m)
			return answer;

		// ���� �丶���� ������ŭ �����ߴ�
		for (int i = 0; i < size; i++) {
			pair<int, int> cur = q.front();
			q.pop();

			for (int j = 0; j < 4; j++) {
				int nx = cur.first + dx[j];
				int ny = cur.second + dy[j];
				if (arr[nx][ny] == 1)
					continue;
				if (nx < 0 || nx >= n || ny < 0 || ny >= m)
					continue;

				if (arr[nx][ny] == 0) {
					arr[nx][ny] = 1;
					q.push(make_pair(nx, ny));
				}

			}
		}
		answer++;
	}
	if(total != n*m)
		return -1; // �丶�䰡 ��� ������ ���ϴ� ��Ȳ
	
	return 0; // �丶�䰡 �� �;�����
}

int main() {

	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);

			// ���� �丶��鸸 ť�� ����
			if (arr[i][j] == 1)
				q.push(make_pair(i, j));
			else if (arr[i][j] == -1)
				total++;
		}
	}

	
	cout << bfs() << endl;

	system("pause");
}