#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0;
	vector<bool> visit(people.size(), 0);
	int i = 0, j;

	// 오름차순 정렬
	sort(people.begin(), people.end());

	// 첫번째꺼랑 마지막꺼랑 비교하면서 점점 좁혀나감
	for (j = people.size() - 1; j > i; j--) {
		if (people[j] + people[i] <= limit) {
			i++;
			answer++;
		}
		else {
			answer++;
		}
	}

	// 마지막 한개 남았을때 
	if (i == j) {
		answer++;
	}

	return answer;
}