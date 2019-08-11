#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// ��� ��û�� ������ �� �ִ� ��쿡�� ��û�� ������ �ִ��� ��ȯ�ؾ� ��
int solution(vector<int> budgets, int M) {
	int answer = 0;  // ���Ѿ�

	sort(budgets.begin(), budgets.end());

	int left = 0, right = budgets[budgets.size() - 1];

	while (left <= right) {
		int mid = (left + right) / 2;
		int sum = 0;


		for (int i = 0; i < budgets.size(); i++) {
			if (mid > budgets[i])
				sum += budgets[i];
			else
				sum += mid;
		}

		if (sum > M) {
			right = mid - 1;
		}
		else {
			answer = mid;  // M���� �������� ������ �ɼ� �����ϱ�
			left = mid + 1;
		}
	}


	return answer;
}