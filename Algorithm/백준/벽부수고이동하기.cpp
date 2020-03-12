#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

int n, m; // n:행, m:열
vector<vector<int>> arr(n,vector<int>(m));
bool visit[1001][1001];
int dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 };

typedef struct wall {
	int x, y, w; // w: 벽이면 1
};

void bfs(int start, int w) {
	queue<wall> q;
	q.push({start, start, w});
	visit[start][start] = 1;

	while (!q.empty()) {
		wall tmp = q.front();
		q.pop();
		

		for (int i = 0; i < 4; i++) {
			int x = tmp.x + dx[i];
			int y = tmp.y + dy[i];
			int z = tmp.w;

			if (!visit[x][y]) {
				if (x > 0 && y > 0 && x < m && y < n) {
					if (z == 1) {

					}
					else {

					}
				}
				q.push(i);
				visit[i] = 1;
			}
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < m; j++) {
			arr[i][j] = temp[j] - '0';
		}
	}

	bfs(0, arr[0][0]);

	system("pause");
}