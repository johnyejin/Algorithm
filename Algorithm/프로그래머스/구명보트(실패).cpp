// 35점받은 코드
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0;

	// 오름차순 정렬
	sort(people.begin(), people.end());

	// 맨처음꺼랑 뒤에꺼랑 합했을때 최대한 limit에 가까운걸 찾기
	while (!people.empty()) {
		int idx = 1;  // limit를 넘지 않는 최대 인덱스

		if (people[0] > limit) {
			people.erase(people.begin());
			answer++;
			continue;
		}

		while (people[0] + people[idx] <= limit) {
			idx++;
		}

		if (idx != 1) {
			people.erase(people.begin());
			people.erase(people.begin() + idx);
			answer++;
		}
		else {
			people.erase(people.begin());
			answer++;
		}

	}



	return answer;
}