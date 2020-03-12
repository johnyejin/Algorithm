// 테스트는 다 통과했는데 시간초과뜬 코드
#include <iostream>
#include <vector>
using namespace std;
// n: 아파트 개수 / station: 기지국 설치 아파트 번호 / w: 전파 도달거리
int solution(int n, vector<int> stations, int w)
{
	int answer = 0;  // 증설해야할 기지국 개수의 최솟값
	int *arr = new int[n];  // 전파 전달되면 1

	for (int i = 0; i < n; i++) arr[i] = 0;  // arr 0으로 초기화

	// 맨 첨에 전파 전달되는 아파트에 +1
	for (int i = 0; i < stations.size(); i++) {
		for (int j = 0; j <= w; j++) {  // 도달거리만큼 양쪽으로 +1
			if (stations[i] - j - 1 < 0) { // 왼쪽 예외
				arr[stations[i] + j - 1]++;
			}
			else if (stations[i] + j - 1 >= n) { // 오른쪽 예외
				arr[stations[i] - j - 1]++;
			}
			else {
				arr[stations[i] - j - 1]++;
				arr[stations[i] + j - 1]++;
			}
		}
	}

	// for (int i = 0; i < n; i++) cout << arr[i] << " ";
	// cout << "\n";

	int cnt = 0;  // 중간중간 전파 전달안되는 아파트 수
	int k = 0;    // 중간중간 설치가 필요한 기지국 수
	for (int i = 0; i < n; i++) {
		if (arr[i] == 0) {
			cnt++;
			if (i == n - 1) {  // 예외처리
				if (cnt % (w * 2 + 1) == 0) k = cnt / (w * 2 + 1);
				else k = cnt / (w * 2 + 1) + 1;
				answer += k;
			}
		}
		else {
			if (cnt % (w * 2 + 1) == 0) k = cnt / (w * 2 + 1);
			else k = cnt / (w * 2 + 1) + 1;
			answer += k;
			// cout << cnt << " / " << k << " / " << answer << endl;
			cnt = 0;
			k = 0;
		}
	}

	return answer;
}