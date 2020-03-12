#include<iostream>
#include<queue>
using namespace std;

int m, n, h;  // n*m 행렬, h 높이
int arr[100][100][100]; // 삼차원배열
int dx[6] = { 1,-1,0,0,0,0 }; 
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
int total = 0; // 지금까지 익은 사과의 개수
queue<pair<int, pair<int,int>>> q;

int bfs() {
	int answer = 0;
	int size;

	while (!q.empty()) {
		size = q.size();
		cout << "size " << size << endl;
		total += size;
		cout << "total " << total << endl;

		if (total == h * n * m)
			return answer;

		// 익은 토마토의 개수만큼 돌려야댐
		for (int i = 0; i < size; i++) {
			pair<int, pair<int, int>> cur = q.front();
			q.pop();

			for (int j = 0; j < 6; j++) {
				int nx = cur.first + dx[j];
				int ny = cur.second.first + dy[j];
				int nz = cur.second.second + dz[j];
				if (arr[nx][ny][nz] == 1)
					continue;
				if (nx < 0 || nx >= h 
					|| ny < 0 || ny >= n 
					|| nz < 0 || nz >= m)
					continue;

				if (arr[nx][ny][nz] == 0) {
					arr[nx][ny][nz] = 1;
					q.push(make_pair(nx, make_pair(ny, nz)));
				}

			}
		}
		answer++;
		cout << "answer " << answer << endl<<endl;
	}
	if (total != h * n * m)
		return -1; // 토마토가 모두 익지는 못하는 상황

	return 0; // 토마토가 다 익어있었으면
}

int main() {

	cin >> m >> n >> h;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> arr[i][j][k];

				// 익은 토마토들만 큐에 저장
				if (arr[i][j][k] == 1)
					q.push(make_pair(i,make_pair(j, k)));
				else if (arr[i][j][k] == -1)
					total++;
			}
		}
	}
	
	cout << bfs() << endl;

	system("pause");
}