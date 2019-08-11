// 40�� ���� �ڵ�
#include <string>
#include <vector>

using namespace std;

int answer = 0;
int visit[50] = { 0, };

void dfs(int start, string begin, string target, vector<string> words, int count) {
	if (count == 2) return;  // Ÿ���̶� 1���ڸ� �ٸ��� �� return

	for (int i = 0; i < words.size(); i++) {
		if (visit[i] == 1) continue;

		int cnt = 0;  // ���� begin�̶� �´°� �����
		int tcnt = 0;  // Ÿ���̶� �´°� �����
		// �´� �ܾ� ����� ī��Ʈ
		for (int j = 0; j < words[0].size(); j++) {
			if (begin[j] == words[i][j]) cnt++;
			if (target[j] == words[i][j]) tcnt++;
		}
		
		// �´� �ܾ 2���� �湮�ߴٰ� ǥ���ϰ� ans++ 
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

	bool flag = false;  // Ÿ�� �ִ��� ������

	// ó���� target�� �ִ������� �˻�
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