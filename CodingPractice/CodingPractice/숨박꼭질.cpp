#include<iostream>
#include<queue>
using namespace std;

int n, k; // n:수빈 k:동생 
bool visit[100001];

int bfs() {
	queue<int> q;
	q.push(n);
	visit[n] = true;
	int answer = 0; // 이동시간

	while (!q.empty()) {

		for (int i = 0; i < q.size(); i++) {
			int a = q.front();
			q.pop();

			if (a == k) return answer;
			//if (a - 1 == k || a + 1 == k || a * 2 == k) return answer;

			if (a - 1 >= 0 && !visit[a - 1]) {
				q.push(a - 1);
				visit[a - 1] = true;
			}
			if (a + 1 <= 100000 && !visit[a + 1]) {
				q.push(a + 1);
				visit[a + 1] = true;
			}
			if (a * 2 <= 100000 && !visit[a * 2]) {
				q.push(a * 2);
				visit[a * 2] = true;
			}

		}

		answer++;
	}
}

int main() {
	cin >> n >> k;

	cout << bfs() << endl;
}