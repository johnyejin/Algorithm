// 시간초과
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer(queries.size());

	for (int i = 0; i < queries.size(); i++) {
		for (int j = 0; j < words.size(); j++) {
			bool flag = false; // true면 다른거

			// words랑 queries 크기가 다르면
			if (words[j].size() != queries[i].size()) continue;

			for (int k = 0; k < words[j].size(); k++) {
				if (queries[i][k] == '?') {
					continue;
				}
				if (queries[i][k] != words[j][k]) {
					flag = true;
					break;
				}
			}

			if (!flag) answer[i]++;
		}
	}

	return answer;
}