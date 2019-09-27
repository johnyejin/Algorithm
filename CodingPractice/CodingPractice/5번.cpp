#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	vector<vector<int>> answer;

	for (int i = 0; i < build_frame.size(); i++) {
		int x = build_frame[i][0];
		int y = build_frame[i][1];
		int a = build_frame[i][2];  // ���:0, ��:1
		int b = build_frame[i][3];  // ����:0, ��ġ:1

		// ��� ��ġ, ����
		if (a == 0) {
			if (b == 1) {
				// �ٴڿ� �ִ� ���
				if (y == 0) {
					answer.push_back({ x,y,a });
					continue;
				}
				for (int j = 0; j < answer.size(); j++) {
					int X = answer[j][0];
					int Y = answer[j][1];
					int A = answer[j][2];
					// �ٸ� ������� �ִ� ���
					if (A == 0 && X == x && Y == y - 1) {
						answer.push_back({ x,y,a });
						break;
					}
					// ���� ���� �� �κ� ���� �ִ� ���
					if (A == 1 && X == x - 1 && Y == y) {
						answer.push_back({ x,y,a });
						break;
					}
				}
			}
			else {

			}
		}
		// �� ��ġ, ����
		else {
			if (b == 1) {
				int cnt = 0; // �� ��ġ�Ҷ� ���� ���� ����Ǿ� ������ cnt = 2
				for (int j = 0; j < answer.size(); j++) {
					int X = answer[j][0];
					int Y = answer[j][1];
					int A = answer[j][2];

					// ���� ���� ��տ� ����Ǿ� ������ ��ġ
					if ((X == x && Y == y - 1 && A == 0) || (X == x + 1 && Y == y - 1 && A == 0)) {
						answer.push_back({ x,y,a });
						break;
					}
					// ���� ���� �ٸ� ���� ���ÿ� ����Ǿ� ������ ��ġ
					if ((X == x - 1 && Y == y && A == 1) || (X == x + 1 && Y == y && A == 1)) {
						cnt++;
					}
					if (cnt == 2) {
						answer.push_back({ x,y,a });
						break;
					}
				}
			}
			else { // ����
				for (int j = 0; j < answer.size(); j++) {

				}
			}
		}

	}
	sort(answer.begin(), answer.end());
	return answer;
}