#include <string>
#include <vector>

using namespace std;

// 한칸 혹은 두칸 뛰고 털어야함
int solution(vector<int> money) {
	int answer = 0;
	vector<int> dp, dp2;  // dp[i]: i번째 집까지 가장 많이 훔칠수 있는 금액

	// 첫번째집부터 훔진경우
	dp.push_back(money[0]);
	dp.push_back(money[0]);
	for (int i = 2; i < money.size() - 1; i++) {  // -2: 맨 마지막 집은 못훔치니까
		dp.push_back(max(dp[i - 2] + money[i], dp[i - 1]));
	}

	// 두번째 집부터 훔친경우
	dp2.push_back(0);
	dp2.push_back(money[1]);
	for (int i = 2; i < money.size(); i++) {  // -2: 맨 마지막 집은 못훔치니까
		dp2.push_back(max(dp2[i - 2] + money[i], dp2[i - 1]));
	}

	return max(dp.back(), dp2.back());
}