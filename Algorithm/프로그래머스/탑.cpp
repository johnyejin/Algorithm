#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> heights) {
	vector<int> answer;
	vector<int> answer_back;
	int flag = 0;

	for (int i = heights.size() - 1; i > 0; i--) {
		flag = 0;
		for (int j = i - 1; j >= 0; j--) {
			if (heights[i] < heights[j]) {
				answer_back.push_back(j + 1);
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			answer_back.push_back(0);
	}
	answer_back.push_back(0);

	// for(int i=0; i<answer_back.size(); i++) cout<<answer_back[i];
	for (int i = answer_back.size() - 1; i >= 0; i--) answer.push_back(answer_back[i]);

	return answer;
}