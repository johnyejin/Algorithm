#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	vector<int> end;  // 각 기능이 몇일만에 완료됐는지 
	int cnt = 0;

	// cnt: 각 기능이 몇일만에 완료됐는지 -> end vector에 push
	for (int i = 0; i < speeds.size(); i++) {
		cnt = 0;
		while (progresses[i] < 100) {
			progresses[i] += speeds[i];
			cnt++;
		}
		end.push_back(cnt);
		// cout<<progresses[i]<< " " << cnt<< " "<<end.size() <<endl;
	}


	while (!end.empty()) {
		cnt = 1; // 각 배포마다 몇개의 기능이 배포되는지
		int front = end.front();
		// cout<<end.front()<<endl;
		end.erase(end.begin());

		// 내 뒤에꺼랑 다 비교해서 나보다 빨리 끝났으면 vector에서 지우기
		for (int i = 0; i < end.size(); ) {
			if (end.front() <= front) {
				cnt++;
				end.erase(end.begin() + i);
			}
			else {
				i++;
			}
		}
		answer.push_back(cnt);
	}

	return answer;
}