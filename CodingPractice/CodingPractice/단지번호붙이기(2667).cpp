// 백준 체점할때 cin, cout쓰면 틀림;
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n; // 정사각형 길이
int arr[25][25]; // 지도
bool visit[25][25];
int cnt = 0;  // 단지수
int answer[625];  // 바이러스에 걸리게 되는 컴퓨터의 수
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

void dfs(int x, int y) {
	visit[x][y] = true;
	answer[cnt]++;

	// 상하좌우 비교
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
			scanf("%1d", &arr[i][j]);  // 정수 한개씩 입력받기
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
	sort(answer, answer + cnt);  // 오름차순 정렬
	for (int i = 0; i < cnt; i++) cout << answer[i] << endl;

	system("pause");
}