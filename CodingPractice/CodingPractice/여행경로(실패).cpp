// segmentation fault �ֶߴ��� �𸣰���
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> answer;
int visit[10000] = { 0, };
int cnt = 0; // tickets.size ��ŭ ���Ҵ��� Ȯ��

void dfs(string start, vector<vector<string>> tickets) {
	vector<pair<string, int>> depart;  // ������� ���� ��� ���������� ������ ����

	if (cnt == tickets.size()) return;  // �� �������� ������

	for (int i = 0; i < tickets.size(); i++) {
		if (visit[i] == 1) continue;

		// ������� ���� ��� �������� ����
		if (start == tickets[i][0]) {
			depart.push_back(make_pair(tickets[i][1], i));
		}
		else {  // ������� �޶��� ��� 
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