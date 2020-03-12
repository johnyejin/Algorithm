#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
// 우선순위큐 정렬
struct Pred {
	bool operator()(vector<int> a, vector<int> b) {
		return a[1] > b[1];
	}
};

// jobs 정렬
bool Pred1(vector<int> a, vector<int> b) {
	return a[0] < b[0];
}

//  [작업이 요청되는 시점, 작업의 소요시간]
int solution(vector<vector<int>> jobs) {
	int answer = 0;  // 평균
	priority_queue<int, vector<vector<int>>, Pred> pq;
	sort(jobs.begin(), jobs.end(), Pred1);


	int work = jobs[0][0];  // 현재 수행할 작업의 시점  
	int need_work = 0;
	int i = 0;  // jobs index
	vector<int> tmp;

	while (1) {

		// 작업시점이 같은것들 우선순위큐에 넣기
		while (i != jobs.size()) {
			if (jobs[i][0] == work) {
				pq.push(jobs[i]);
				i++;
			}
			else {
				break;
			}
		}

		// 같은 시점에 수행시간이 짧은 순으로 큐에서 빼기
		if (need_work <= 0 && !pq.empty()) {
			tmp = pq.top();
			pq.pop();
			answer += tmp[1];
			need_work = tmp[1];
		}

		answer += pq.size();  // 왜 pq size더함?
		need_work--;
		work++;

		if (pq.empty() && i == jobs.size()) break;
	}


	return answer / jobs.size();
}