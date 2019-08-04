// 맨 마지막 테스트 실패
#include <string>
#include <vector>
#include <cmath>

using namespace std;

// BAAAB -> B움직이고 왼쪽으로 / ABBAA 인 경우 -> ABB까지 움직이고 끝
int solution(string name) {
	int answer1 = 0;  // 커서를 오른쪽으로 이동한 경우 답
	int answer2;  // 커서를 왼쪽으로 이동한 경우 답

	answer1 += min(name[0] - 'A', 'Z' - name[0] + 1);
	answer2 = answer1;

	// 커서를 오른쪽으로 이동한 경우
	for (int i = 1; i < name.size(); i++) {

		bool flag = true;  // A인 경우 true
		for (int j = i; j < name.size(); j++) {
			if (name[j] != 'A') {
				flag = false;
				break;
			}
		}

		if (flag) break;  // 맨끝이 'A'인 경우 움직일 필요가 없으니까 
		answer1++;
		answer1 += min(name[i] - 'A', 'Z' - name[i] + 1);
	}

	// 커서를 왼쪽으로 이동한 경우
	for (int i = name.size() - 1; i >= 1; i--) {

		bool flag = true;  // A인 경우 true
		for (int j = i; j >= 1; j--) {
			if (name[j] != 'A') {
				flag = false;
				break;
			}
		}

		if (flag) break;  // 맨끝이 'A'인 경우 움직일 필요가 없으니까 
		answer2++;
		answer2 += min(name[i] - 'A', 'Z' - name[i] + 1);
	}


	return min(answer1, answer2);
}