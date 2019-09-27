#include<iostream>
#include<queue>
using namespace std;
int main() {
	int n;
	cin >> n;
	queue<int> q;

	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	while (!q.empty()) {
		if (q.size() == 1) {
			cout << q.front() << endl;
			break;
		}

		q.pop();
		int tmp = q.front();
		q.pop();
		q.push(tmp);
	}

	system("pause");
}