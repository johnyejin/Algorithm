#include <string>
#include <vector>
#include <queue>

using namespace std;

// �а��� ����, ���� ����, ����, ���� �������κ��� ���޹������ִ� ����
int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	int answer = 0;
	priority_queue<int, vector<int>, less<int>> temp;  // �ּ������� ���޹������� �ѹ��� ���޹޴� ���� ���ƾ� �ϴϱ� �켱���� ť ���

	int j = 0;  // supplies index
	for (int i = 0; i < k; i++) {
		// �������ڰ� �Ǹ� temp�� ���޷� �ֱ�
		if (dates[j] == i) {
			temp.push(supplies[j]);
			j++;
		}
		// ��� ������ temp�� �ִ� �� ���� ���޷����� ���� �ֱ�
		if (stock == 0) {
			stock += temp.top();
			temp.pop();
			answer++;
		}
		stock--;
	}

	return answer;
}