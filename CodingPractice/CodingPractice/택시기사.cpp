#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> P) {
	int answer = 0;

	int cnt = 1;
	int temp = P[0];
	for (int i = 0; i < P.size() - 1; i++) {

		if (temp < P[i + 1]) {
			cnt++;
		}
		else {
			answer += cnt * temp;
			cnt = 1;
			temp = P[i + 1];
		}

	}
	// ¸¶Áö¸· idx
	answer += cnt * temp;

	return answer;
}