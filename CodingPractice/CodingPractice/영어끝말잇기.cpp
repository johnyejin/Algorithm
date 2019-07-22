#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
	vector<int> answer;  // Ż���ϴ� ����� ��ȣ, ���° ���ʿ� Ż��
	int flag = 0;

	for (int i = 1; i < words.size(); i++) {
		// ���۹��ڰ� Ʋ�� ���
		if (words[i - 1].back() != words[i].front()) {
			flag = 1;
		}

		// ���� �ܾ��� ���
		for (int j = 0; j < i; j++) {
			if (words[i].compare(words[j]) == 0) {
				flag = 1;
				break;
			}
		}
		if (flag) {
			answer.push_back(i % n + 1);  // ��ȣ
			answer.push_back(i / n + 1);  // ����
			return answer;
		}
	}
	// Ż���ڰ� ���� ���
	answer.push_back(0);
	answer.push_back(0);
	return answer;
}