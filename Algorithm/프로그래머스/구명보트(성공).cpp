#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0;
	vector<bool> visit(people.size(), 0);
	int i = 0, j;

	// �������� ����
	sort(people.begin(), people.end());

	// ù��°���� ���������� ���ϸ鼭 ���� ��������
	for (j = people.size() - 1; j > i; j--) {
		if (people[j] + people[i] <= limit) {
			i++;
			answer++;
		}
		else {
			answer++;
		}
	}

	// ������ �Ѱ� �������� 
	if (i == j) {
		answer++;
	}

	return answer;
}