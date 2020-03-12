#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
	int answer = 0;

	// 내림차순 정렬
	// 배열 인덱스랑 비교하다가 해당값이 배열보다 작으면 return
	sort(citations.begin(), citations.end(), greater<int>());

	for (int i = 0; i < citations.size(); i++) {
		if (i >= citations[i]) break;
		answer++;
	}

	return answer;
}