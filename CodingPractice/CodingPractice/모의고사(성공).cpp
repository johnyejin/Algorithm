#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	int arr1[5] = { 1, 2, 3, 4, 5 };
	int arr2[8] = { 2, 1, 2, 3, 2, 4, 2, 5 };
	int arr3[10] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
	int count[3] = { 0, };
	int m;  // �ִ밪

	for (int i = 0; i < answers.size(); i++) {
		if (arr1[i % 5] == answers[i]) count[0]++;
		if (arr2[i % 8] == answers[i]) count[1]++;
		if (arr3[i % 10] == answers[i]) count[2]++;
	}

	m = max(count[0], count[1]);
	m = max(m, count[2]);

	for (int i = 0; i < 3; i++)
		if (count[i] == m) answer.push_back(i + 1);


	return answer;
}