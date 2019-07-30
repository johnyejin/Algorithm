#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	priority_queue<int, vector<int>, greater<int>> temp;  // �������� �켱����ť
	int a, b;

	// temp�� ������������ ���ں� ����
	for (int i = 0; i < scoville.size(); i++)
		temp.push(scoville[i]);

	// temp.top�� k���� ũ�� break
	while (temp.top() < K && temp.size() > 1) {  // size�� 1 ���ϸ� segment fault��
		answer++;
		a = temp.top();
		temp.pop();
		b = temp.top();
		temp.pop();

		temp.push(a + b * 2);

	}
	// ���ѻ���
	if (temp.top() < K) return -1;

	return answer;
}