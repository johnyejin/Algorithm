// 채점했는데 6.7점 받음;;
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer;
	int sec = 0;

	for (int i = 0; i < prices.size(); i++) {
		sec = 0;
		for (int j = i + 1; j < prices.size(); j++) {
			if (prices.at(i) > prices.at(j)) {
				sec = 1;
				break;
			}
			else if (prices.at(i) <= prices.at(j)) {
				sec++;
			}
			else {
				sec = 0;
			}
		}
		answer.push_back(sec);
	}

	return answer;
}