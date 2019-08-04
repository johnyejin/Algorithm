// 25�� ���� �ڵ�
// max���� ó������ ���ؼ� �����ѵ�
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> costs) {
	int answer = 0;
	int *arr = new int[n];  // �ѹ� ���� �ٸ��� 1 / �ƴϸ� 0

	// arr 0���� �ʱ�ȭ
	for (int i = 0; i < n; i++) {
		arr[i] = 0;
	}

	int max = costs[0][2];  // ��ġ��� �ִ밪
	int idx = 0;  // ��ġ��� �ִ밪�϶� �ε���

	for (int i = 0; i < costs.size(); i++) {
		// ó������ i�� �ϳ��� ������ ��뿡 �߰�
		if (arr[costs[i][0]] == 0 || arr[costs[i][1]] == 0) {
			arr[costs[i][0]] = 1;
			arr[costs[i][1]] = 1;
			answer += costs[i][2];   ////////////////////////
			if (max < costs[i][2]) {
				max = costs[i][2];
				idx = i;
			}
		}
		// �Ѵ� �ѹ����Դ� i�� cost ���ؼ� ũ�� ������ / ������ ���� �����ߴ� �ٸ��� �ٲٱ�
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