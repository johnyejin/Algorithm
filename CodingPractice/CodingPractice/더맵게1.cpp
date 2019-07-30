// 57�� ���� �ڵ� (�ð��ʰ���)
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	vector<int> v;  // ���� ���� ���� ������ �ӽú���        

	while (1) {
		sort(scoville.begin(), scoville.end());

		if (scoville[0] < K) {
			answer++;
			// v�� ���� �� ����
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
		else {  // scoville[0] >= k �� return 
			return answer;
		}

	}

	return answer;
}