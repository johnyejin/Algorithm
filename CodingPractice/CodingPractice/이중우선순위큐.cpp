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
			num.push_back(stoi(operations[i].substr(2))); // 숫자만 뽑아서 데큐에 넣기
			sort(num.begin(), num.end()); // 오름차순 정렬
		}
	}

	answer.push_back(num.empty() ? 0 : num.back());
	answer.push_back(num.empty() ? 0 : num.front());

	return answer;
}