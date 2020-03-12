// 시간초과
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> weight) {
	int answer = 1;
	bool flag = false;  // 측정할수 없는 수가 나온 경우 false

	sort(weight.begin(), weight.end());  // 오름차순 정렬

	while (1) {
		int sum = 0;
		for (int i = weight.size() - 1; i >= 0; i--) {
			if (weight[i] > answer) continue;
			if (weight[i] == answer) {
				answer++;
				flag = true;
				break;
			}

			if (sum + weight[i] > answer) continue;
			else if (sum + weight[i] == answer) {
				answer++;
				flag = true;
				break;
			}
			sum += weight[i];
		}

		if (flag == false) {
			return answer;
		}
	}


	return answer;
}