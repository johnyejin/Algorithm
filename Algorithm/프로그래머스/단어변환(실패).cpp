// 40점 받은 코드
#include <string>
#include <vector>

using namespace std;

int answer = 0;
int visit[50] = { 0, };

void dfs(int start, string begin, string target, vector<string> words, int count) {
	if (count == 2) return;  // 타겟이랑 1글자만 다르면 걍 return

	for (int i = 0; i < words.size(); i++) {
		if (visit[i] == 1) continue;

		int cnt = 0;  // 현재 begin이랑 맞는게 몇개인지
		int tcnt = 0;  // 타겟이랑 맞는게 몇개인지
		// 맞는 단어 몇개인지 카운트
		for (int j = 0; j < words[0].size(); j++) {
			if (begin[j] == words[i][j]) cnt++;
			if (target[j] == words[i][j]) tcnt++;
		}
		
		// 맞는 단어가 2개면 방문했다고 표시하고 ans++ 
		if (cnt == 2) {
			visit[i] = 1;
			answer++;
			if (tcnt == 2) {
				return;
			}

			dfs(i, words[i], target, words, tcnt);
		}
	}
}

int solution(string begin, string target, vector<string> words) {

	bool flag = false;  // 타겟 있는지 없는지

	// 처음에 target이 있는지부터 검사
	for (int i = 0; i < words.size(); i++) {
		if (words[i] == target) {
			flag = true;
			break;
		}
	}
	if (!flag) return 0;


	dfs(0, begin, target, words, 0);

	return answer - 1;
}