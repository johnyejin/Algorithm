#include <string>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 1;
	int cnt[30] = { 0, };
	vector<string> type;

	// 2번째 원소만 따로 저장
	for (int i = 0; i < clothes.size(); i++) {
		type.push_back(clothes[i][1]);
	}
	sort(type.begin(), type.end());

	int k = 0;  // cnt index 증가
	for (int i = 0; i < type.size(); i++) {
		// 마지막 원소인 경우
		if (i == type.size() - 1) {
			cnt[k]++;
			break;
		}

		if (type[i] != type[i + 1]) {
			cnt[k]++;
			k++;
			continue;
		}
		cnt[k]++;
	}

	// 경우의수 계산
	for (int i = 0; i < 30; i++) {
		if (cnt[i] == 0) break;
		answer *= (cnt[i] + 1);
	}
	return answer - 1;
}