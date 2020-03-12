#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
	int answer = 1;  // 카메라는 무조건 한대이상 설치됨

	sort(routes.begin(), routes.end());

	int tmp = routes[0][1];  // 현재 단속카메라의 범위
	for (int i = 0; i < routes.size() - 1; i++) {
		// 다음 차의 진출지점이 더 작으면 tmp 바꿔주기
		if (tmp > routes[i][1]) {
			tmp = routes[i][1];
		}
		// 다음차의 진입지점이 tmp보다 크면 단속카메라 ++
		if (tmp < routes[i + 1][0]) {
			answer += 1;
			tmp = routes[i + 1][1];
		}
	}

	return answer;
}