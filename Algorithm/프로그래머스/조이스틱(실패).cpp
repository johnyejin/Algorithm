// 거꾸로 가는걸 구현 못함
#include <string>
#include <vector>

using namespace std;

// BAAAB -> B움직이고 왼쪽으로 / ABBAA 인 경우 -> ABB까지 움직이고 끝
int solution(string name) {
	int answer = 0;
	int Acnt = 1;

	for (int i = 0; i < name.size(); i++) {
		if (name[i] == 'A') {
			Acnt++;
			if (name[i + 1] != 'A') {
				if (Acnt > name.size() - (i + 1)) {
					answer += name.size() - (i + 1);
				}
				else {
					answer += Acnt;
				}
				Acnt = 1;  // 초기화
			}
			continue;
		}

		if (name[i] > 'N') {
			answer += 91 - name[i];
		}
		else {
			answer += name[i] - 65;
		}

		// 맨 마지막 문자면 answer에 1 안더하게
		if (i == name.size() - 1) break;
		answer++;
	}

	return answer;
}