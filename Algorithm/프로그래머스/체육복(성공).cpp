#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	vector<int> student(n, 1);  // 초기값을 1로 설정

	for (int i : lost) {
		student[i - 1]--;
	}
	for (int i : reserve) {
		student[i - 1]++;
	}

	// (뒷사람보다) 앞사람먼저 고려
	for (int i = 0; i < student.size(); i++) {
		// 앞사람 옷이 없는경우
		if (i != 0 && student[i - 1] == 0) {
			if (student[i] == 2) {
				student[i - 1]++;
				student[i]--;
				continue;
			}
		}
		// 뒷사람 옷이 없는 경우
		if (i != student.size() - 1 && student[i + 1] == 0) {
			if (student[i] == 2) {
				student[i + 1]++;
				student[i]--;
			}
		}
	}

	for (int i = 0; i < student.size(); i++) {
		if (student[i] > 0) answer++;
	}

	return answer;
}