#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 모든 요청이 배정될 수 있는 경우에는 요청한 예산의 최댓값을 반환해야 함
int solution(vector<int> budgets, int M) {
	int answer = 0;  // 상한액

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
			answer = mid;  // M보다 작을때만 정답이 될수 있으니까
			left = mid + 1;
		}
	}


	return answer;
}