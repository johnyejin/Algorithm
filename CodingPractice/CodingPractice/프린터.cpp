#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	queue<pair<int, int>> q;
	priority_queue<int> pq;

	// ť�� <ó������ / �߿䵵> ����
	for (int i = 0; i < priorities.size(); i++) {
		q.push(make_pair(i, priorities[i]));
		pq.push(priorities[i]);
	}

	// 

	while (!q.empty()) {
		int idx = q.front().first;
		int val = q.front().second;
		q.pop();  // ���� ����� ����

		if (pq.top() == val) {  // �켱���� ���� ������ �������
			pq.pop();  // �켱���� �� ������ ����
			answer++;
			if (idx == location) {  // ���� location�̶� ���� ��� �ٷ� ����
				return answer;
			}
		}
		else {
			q.push(make_pair(idx, val));  // �켱���� �� ������ �ƴϸ� �� �ڿ� ����ֱ�
		}
	}

	return answer;
}