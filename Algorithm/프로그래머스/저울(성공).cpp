#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> weight) {
	int answer = 0;

	sort(weight.begin(), weight.end());

	// (이전 추들의 무게 합 + 1)이 i번째 추의 무게보다 크면
	// (이전 추들의 무게 합 + 1)이상의 무게는 측정불가
	for (int i = 0; i < weight.size(); i++) {
		if (answer + 1 < weight[i]) return answer + 1;
		answer += weight[i];
	}


	return answer + 1;
}