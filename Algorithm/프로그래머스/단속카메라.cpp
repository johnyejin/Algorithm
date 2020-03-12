#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
	int answer = 1;  // ī�޶�� ������ �Ѵ��̻� ��ġ��

	sort(routes.begin(), routes.end());

	int tmp = routes[0][1];  // ���� �ܼ�ī�޶��� ����
	for (int i = 0; i < routes.size() - 1; i++) {
		// ���� ���� ���������� �� ������ tmp �ٲ��ֱ�
		if (tmp > routes[i][1]) {
			tmp = routes[i][1];
		}
		// �������� ���������� tmp���� ũ�� �ܼ�ī�޶� ++
		if (tmp < routes[i + 1][0]) {
			answer += 1;
			tmp = routes[i + 1][1];
		}
	}

	return answer;
}