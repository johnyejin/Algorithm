#include <string>
#include <vector>

using namespace std;

// ��ĭ Ȥ�� ��ĭ �ٰ� �о����
int solution(vector<int> money) {
	int answer = 0;
	vector<int> dp, dp2;  // dp[i]: i��° ������ ���� ���� ��ĥ�� �ִ� �ݾ�

	// ù��°������ �������
	dp.push_back(money[0]);
	dp.push_back(money[0]);
	for (int i = 2; i < money.size() - 1; i++) {  // -2: �� ������ ���� ����ġ�ϱ�
		dp.push_back(max(dp[i - 2] + money[i], dp[i - 1]));
	}

	// �ι�° ������ ��ģ���
	dp2.push_back(0);
	dp2.push_back(money[1]);
	for (int i = 2; i < money.size(); i++) {  // -2: �� ������ ���� ����ġ�ϱ�
		dp2.push_back(max(dp2[i - 2] + money[i], dp2[i - 1]));
	}

	return max(dp.back(), dp2.back());
}