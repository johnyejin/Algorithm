// 57점 받은 코드 (시간초과뜸)
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	vector<int> v;  // 새로 계산된 값을 저장할 임시벡터        

	while (1) {
		sort(scoville.begin(), scoville.end());

		if (scoville[0] < K) {
			answer++;
			// v에 계산된 값 저장
			int temp = scoville[0] + scoville[1] * 2;
			v.push_back(temp);
			for (int i = 2; i < scoville.size(); i++) {
				v.push_back(scoville[i]);
			}

			scoville.clear();

			while (!v.empty()) {
				scoville.push_back(v.back());
				v.pop_back();
			}
		}
		else {  // scoville[0] >= k 면 return 
			return answer;
		}

	}

	return answer;
}