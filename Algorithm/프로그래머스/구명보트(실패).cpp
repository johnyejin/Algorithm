// 35������ �ڵ�
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0;

	// �������� ����
	sort(people.begin(), people.end());

	// ��ó������ �ڿ����� �������� �ִ��� limit�� ������ ã��
	while (!people.empty()) {
		int idx = 1;  // limit�� ���� �ʴ� �ִ� �ε���

		if (people[0] > limit) {
			people.erase(people.begin());
			answer++;
			continue;
		}

		while (people[0] + people[idx] <= limit) {
			idx++;
		}

		if (idx != 1) {
			people.erase(people.begin());
			people.erase(people.begin() + idx);
			answer++;
		}
		else {
			people.erase(people.begin());
			answer++;
		}

	}



	return answer;
}