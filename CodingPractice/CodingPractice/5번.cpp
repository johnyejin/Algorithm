#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	vector<vector<int>> answer;

	for (int i = 0; i < build_frame.size(); i++) {
		int x = build_frame[i][0];
		int y = build_frame[i][1];
		int a = build_frame[i][2];  // 기둥:0, 보:1
		int b = build_frame[i][3];  // 삭제:0, 설치:1

		// 기둥 설치, 삭제
		if (a == 0) {
			if (b == 1) {
				// 바닥에 있는 경우
				if (y == 0) {
					answer.push_back({ x,y,a });
					continue;
				}
				for (int j = 0; j < answer.size(); j++) {
					int X = answer[j][0];
					int Y = answer[j][1];
					int A = answer[j][2];
					// 다른 기둥위에 있는 경우
					if (A == 0 && X == x && Y == y - 1) {
						answer.push_back({ x,y,a });
						break;
					}
					// 보의 한쪽 끝 부분 위에 있는 경우
					if (A == 1 && X == x - 1 && Y == y) {
						answer.push_back({ x,y,a });
						break;
					}
				}
			}
			else {

			}
		}
		// 보 설치, 삭제
		else {
			if (b == 1) {
				int cnt = 0; // 보 설치할때 양쪽 끝이 연결되어 있으면 cnt = 2
				for (int j = 0; j < answer.size(); j++) {
					int X = answer[j][0];
					int Y = answer[j][1];
					int A = answer[j][2];

					// 한쪽 끝이 기둥에 연결되어 있으면 설치
					if ((X == x && Y == y - 1 && A == 0) || (X == x + 1 && Y == y - 1 && A == 0)) {
						answer.push_back({ x,y,a });
						break;
					}
					// 양쪽 끝이 다른 보와 동시에 연결되어 있으면 설치
					if ((X == x - 1 && Y == y && A == 1) || (X == x + 1 && Y == y && A == 1)) {
						cnt++;
					}
					if (cnt == 2) {
						answer.push_back({ x,y,a });
						break;
					}
				}
			}
			else { // 삭제
				for (int j = 0; j < answer.size(); j++) {

				}
			}
		}

	}
	sort(answer.begin(), answer.end());
	return answer;
}