// �ð��ʰ�
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> weight) {
	int answer = 1;
	bool flag = false;  // �����Ҽ� ���� ���� ���� ��� false

	sort(weight.begin(), weight.end());  // �������� ����

	while (1) {
		int sum = 0;
		for (int i = weight.size() - 1; i >= 0; i--) {
			if (weight[i] > answer) continue;
			if (weight[i] == answer) {
				answer++;
				flag = true;
				break;
			}

			if (sum + weight[i] > answer) continue;
			else if (sum + weight[i] == answer) {
				answer++;
				flag = true;
				break;
			}
			sum += weight[i];
		}

		if (flag == false) {
			return answer;
		}
	}


	return answer;
}