// 66.7점 받은 코드
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	int lcnt = 0; // lost index
	bool flag = false;  // 빌려줬으면 true 아니면 false

	sort(lost.begin(), lost.end());
	sort(reserve.begin(), reserve.end());

	for (int i = 1; i <= n; i++) {
		flag = false;
		if (lost[lcnt] == i) {
			// reserve에 빌려줄수있는게 있으면 빌려주고 벡터에서 지움
			for (int j = 0; j < reserve.size();) {
				if (reserve[j] - 1 == lost[lcnt] || reserve[j] + 1 == lost[lcnt]) {
					reserve.erase(reserve.begin() + j);
					flag = true;
					break;
				}
				else {
					j++;
				}
			}
			lcnt++;
			if (flag == false) {
				continue;
			}
		}
		answer++;
	}

	return answer;
}