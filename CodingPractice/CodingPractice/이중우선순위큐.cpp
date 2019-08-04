#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
	vector<int> answer;
	deque<int> num;
	string maxDel = "D 1";
	string minDel = "D -1";

	for (int i = 0; i < operations.size(); i++) {
		if (operations[i] == maxDel) {
			if (!num.empty())
				num.pop_back();
		}
		else if (operations[i] == minDel) {
			if (!num.empty())
				num.pop_front();
		}
		else {
			num.push_back(stoi(operations[i].substr(2))); // ���ڸ� �̾Ƽ� ��ť�� �ֱ�
			sort(num.begin(), num.end()); // �������� ����
		}
	}

	answer.push_back(num.empty() ? 0 : num.back());
	answer.push_back(num.empty() ? 0 : num.front());

	return answer;
}