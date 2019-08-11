// segmentation fault 왜뜨는지 모르겠음
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> answer;
int visit[10000] = { 0, };
int cnt = 0; // tickets.size 만큼 돌았는지 확인

void dfs(string start, vector<vector<string>> tickets) {
	vector<pair<string, int>> depart;  // 출발지가 같은 경우 도착지들을 저장할 벡터

	if (cnt == tickets.size()) return;  // 다 돌았으면 끝내기

	for (int i = 0; i < tickets.size(); i++) {
		if (visit[i] == 1) continue;

		// 출발지가 같은 경우 도착지들 저장
		if (start == tickets[i][0]) {
			depart.push_back(make_pair(tickets[i][1], i));
		}
		else {  // 출발지가 달라진 경우 
			break;
		}
	}

	sort(depart.begin(), depart.end());
	visit[depart[0].second] = 1;
	answer.push_back(depart[0].first);
	cnt++;
	dfs(depart[0].first, tickets);

}

vector<string> solution(vector<vector<string>> tickets) {

	answer.push_back(tickets[0][0]);
	dfs(tickets[0][0], tickets);

	return answer;
}