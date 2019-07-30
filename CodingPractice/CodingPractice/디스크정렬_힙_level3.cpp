#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
// �켱����ť ����
struct Pred {
	bool operator()(vector<int> a, vector<int> b) {
		return a[1] > b[1];
	}
};

// jobs ����
bool Pred1(vector<int> a, vector<int> b) {
	return a[0] < b[0];
}

//  [�۾��� ��û�Ǵ� ����, �۾��� �ҿ�ð�]
int solution(vector<vector<int>> jobs) {
	int answer = 0;  // ���
	priority_queue<int, vector<vector<int>>, Pred> pq;
	sort(jobs.begin(), jobs.end(), Pred1);


	int work = jobs[0][0];  // ���� ������ �۾��� ����  
	int need_work = 0;
	int i = 0;  // jobs index
	vector<int> tmp;

	while (1) {

		// �۾������� �����͵� �켱����ť�� �ֱ�
		while (i != jobs.size()) {
			if (jobs[i][0] == work) {
				pq.push(jobs[i]);
				i++;
			}
			else {
				break;
			}
		}

		// ���� ������ ����ð��� ª�� ������ ť���� ����
		if (need_work <= 0 && !pq.empty()) {
			tmp = pq.top();
			pq.pop();
			answer += tmp[1];
			need_work = tmp[1];
		}

		answer += pq.size();  // �� pq size����?
		need_work--;
		work++;

		if (pq.empty() && i == jobs.size()) break;
	}


	return answer / jobs.size();
}