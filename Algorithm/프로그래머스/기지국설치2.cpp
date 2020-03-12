#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
	int answer = 0;
	int cnt = 0;  // �߰��߰� ���� ���� �ȵǴ� ����Ʈ ����
	int s = 0;  // stations index

	for (int i = 0; i < n; i++) {
		// ���� ���޵Ǵ� ����Ʈ�� ȸ���κп� �ʿ��� ������ ���
		if (i >= stations[s] - w && i <= stations[s] + w) {
			if (cnt % (w * 2 + 1) == 0)
				answer += cnt / (w * 2 + 1);
			else
				answer += cnt / (w * 2 + 1) + 1;
			cnt = 0;
			if (i == stations[s] + w) s++;  // ���� ���޵Ǵ� �� ������ ����Ʈ�� ���
			continue;
		}

		cnt++;

		// �� �� ����Ʈ�� ���
		if (i == n - 1) {
			if (cnt % (w * 2 + 1) == 0)
				answer += cnt / (w * 2 + 1);
			else
				answer += cnt / (w * 2 + 1) + 1;
		}
	}

	return answer;
}