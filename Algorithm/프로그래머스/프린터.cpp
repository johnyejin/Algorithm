#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	queue<pair<int, int>> q;
	priority_queue<int> pq;

	// 큐에 <처음순서 / 중요도> 저장
	for (int i = 0; i < priorities.size(); i++) {
		q.push(make_pair(i, priorities[i]));
		pq.push(priorities[i]);
	}

	// 

	while (!q.empty()) {
		int idx = q.front().first;
		int val = q.front().second;
		q.pop();  // 먼저 지우고 시작

		if (pq.top() == val) {  // 우선순위 가장 높은걸 만난경우
			pq.pop();  // 우선순위 젤 높은거 지움
			answer++;
			if (idx == location) {  // 그중 location이랑 같은 경우 바로 리턴
				return answer;
			}
		}
		else {
			q.push(make_pair(idx, val));  // 우선순위 젤 높은게 아니면 맨 뒤에 집어넣기
		}
	}

	return answer;
}