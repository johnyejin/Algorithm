#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> weight) {
	int answer = 0;

	sort(weight.begin(), weight.end());

	// (���� �ߵ��� ���� �� + 1)�� i��° ���� ���Ժ��� ũ��
	// (���� �ߵ��� ���� �� + 1)�̻��� ���Դ� �����Ұ�
	for (int i = 0; i < weight.size(); i++) {
		if (answer + 1 < weight[i]) return answer + 1;
		answer += weight[i];
	}


	return answer + 1;
}