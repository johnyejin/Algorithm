#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
	int answer = 0;

	// �������� ����
	// �迭 �ε����� ���ϴٰ� �ش簪�� �迭���� ������ return
	sort(citations.begin(), citations.end(), greater<int>());

	for (int i = 0; i < citations.size(); i++) {
		if (i >= citations[i]) break;
		answer++;
	}

	return answer;
}