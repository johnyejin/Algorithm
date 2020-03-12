#include<iostream>
#include<queue>
using namespace std;
int main() {
	int n, k; // n:�����, k:���ŵǴ� ����� ��ȣ
	cin >> n >> k;
	queue<int> q;

	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	cout << "<";
	int cnt = 0;
	while (!q.empty()) {
		cnt++;

		if (cnt == k) {
			cnt = 0;
			cout << q.front();
			q.pop();
			if (!q.empty())
				cout << ", ";
			continue;
		}

		int tmp = q.front();
		q.pop();
		q.push(tmp);
	}
	cout << ">" << endl;
	system("pause");
}