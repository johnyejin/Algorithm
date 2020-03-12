#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	vector<int> student(n, 1);  // �ʱⰪ�� 1�� ����

	for (int i : lost) {
		student[i - 1]--;
	}
	for (int i : reserve) {
		student[i - 1]++;
	}

	// (�޻������) �ջ������ ���
	for (int i = 0; i < student.size(); i++) {
		// �ջ�� ���� ���°��
		if (i != 0 && student[i - 1] == 0) {
			if (student[i] == 2) {
				student[i - 1]++;
				student[i]--;
				continue;
			}
		}
		// �޻�� ���� ���� ���
		if (i != student.size() - 1 && student[i + 1] == 0) {
			if (student[i] == 2) {
				student[i + 1]++;
				student[i]--;
			}
		}
	}

	for (int i = 0; i < student.size(); i++) {
		if (student[i] > 0) answer++;
	}

	return answer;
}