#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
	int answer = 0;
	int cnt = 0;  // 중간중간 전파 전달 안되는 아파트 개수
	int s = 0;  // stations index

	for (int i = 0; i < n; i++) {
		// 전파 전달되는 아파트면 회색부분에 필요한 기지국 계산
		if (i >= stations[s] - w && i <= stations[s] + w) {
			if (cnt % (w * 2 + 1) == 0)
				answer += cnt / (w * 2 + 1);
			else
				answer += cnt / (w * 2 + 1) + 1;
			cnt = 0;
			if (i == stations[s] + w) s++;  // 전파 전달되는 맨 오른쪽 아파트인 경우
			continue;
		}

		cnt++;

		// 맨 끝 아파트인 경우
		if (i == n - 1) {
			if (cnt % (w * 2 + 1) == 0)
				answer += cnt / (w * 2 + 1);
			else
				answer += cnt / (w * 2 + 1) + 1;
		}
	}

	return answer;
}