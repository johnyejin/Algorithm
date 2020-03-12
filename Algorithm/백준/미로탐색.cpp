#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int n, m;  // n*m 행렬
int arr[100][100]; // 이차원배열
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x,y));

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
			if (arr[nx][ny] == 1) {
				q.push(make_pair(nx, ny));
				arr[nx][ny] = arr[x][y] + 1;
			}
		}
	}
}

int main() {
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}

	arr[0][0] = 1;
	bfs(0, 0);
	cout << arr[n-1][m-1] << endl;
	

	system("pause");
}