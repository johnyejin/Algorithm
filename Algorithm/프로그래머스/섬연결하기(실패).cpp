// 25점 받은 코드
// max값을 처리하지 못해서 실패한듯
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> costs) {
	int answer = 0;
	int *arr = new int[n];  // 한번 나온 다리면 1 / 아니면 0

	// arr 0으로 초기화
	for (int i = 0; i < n; i++) {
		arr[i] = 0;
	}

	int max = costs[0][2];  // 설치비용 최대값
	int idx = 0;  // 설치비용 최대값일때 인덱스

	for (int i = 0; i < costs.size(); i++) {
		// 처음보는 i가 하나라도 있으면 비용에 추가
		if (arr[costs[i][0]] == 0 || arr[costs[i][1]] == 0) {
			arr[costs[i][0]] = 1;
			arr[costs[i][1]] = 1;
			answer += costs[i][2];   ////////////////////////
			if (max < costs[i][2]) {
				max = costs[i][2];
				idx = i;
			}
		}
		// 둘다 한번나왔던 i면 cost 비교해서 크면 버리고 / 작으면 원래 연결했던 다리랑 바꾸기
		else {
			if (costs[i][2] > max) {
				continue;
			}
			else {
				answer += costs[i][2] - max;    ///////////////////
				max = costs[i][2];
				idx = i;
				arr[costs[idx][0]] = 0;
				arr[costs[idx][1]] = 0;
				arr[costs[i][0]] = 1;
				arr[costs[i][0]] = 1;
			}
		}
	}


	return answer;
}