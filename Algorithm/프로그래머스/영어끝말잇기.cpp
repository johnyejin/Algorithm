#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
	vector<int> answer;  // 탈락하는 사람의 번호, 몇번째 차례에 탈락
	int flag = 0;

	for (int i = 1; i < words.size(); i++) {
		// 시작문자가 틀린 경우
		if (words[i - 1].back() != words[i].front()) {
			flag = 1;
		}

		// 같은 단어인 경우
		for (int j = 0; j < i; j++) {
			if (words[i].compare(words[j]) == 0) {
				flag = 1;
				break;
			}
		}
		if (flag) {
			answer.push_back(i % n + 1);  // 번호
			answer.push_back(i / n + 1);  // 차례
			return answer;
		}
	}
	// 탈락자가 없는 경우
	answer.push_back(0);
	answer.push_back(0);
	return answer;
}