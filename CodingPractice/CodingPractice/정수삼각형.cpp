#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
	int answer = 0;  // 거쳐간 숫자의 최댓값    

	// triangle[i][j]에 더한 값들을 계속 누적
	for (int i = 1; i < triangle.size(); i++) {
		for (int j = 0; j < triangle[i].size(); j++) {
			// 자기자신 위에 대각선에 있는 숫자 2개 비교해서 큰거 더하기
			triangle[i][j] += triangle[i - 1][j - 1] > triangle[i - 1][j] ? triangle[i - 1][j - 1] : triangle[i - 1][j];
		}
	}

	// 바닥에 있는 숫자중 가장 큰값 answer에 저장
	answer = triangle[triangle.size() - 1][0];
	for (int i = 1; i < triangle[triangle.size() - 1].size(); i++) {
		if (triangle[triangle.size() - 1][i] > answer)
			answer = triangle[triangle.size() - 1][i];
	}

	return answer;
}