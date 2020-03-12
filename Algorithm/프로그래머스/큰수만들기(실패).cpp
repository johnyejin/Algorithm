// 마지막 테스트 시간초과떠서 실패
#include <string>
#include <vector>

using namespace std;

// 뒤에 숫자가 앞에 숫자보다 크면 앞에꺼 지우기
string solution(string number, int k) {
	int cnt = 0;  // 제거한 숫자 개수

	if (number[0] == '0') return "0";

	// i가 계속 0으로 초기화되어야함
	while (cnt != k) {
		int i = 0;  // 인덱스 맨처음으로 초기화

		// i를 계속 증가시키면서 비교하기위해
		for (; !number.empty(); i++) {
			if (i == number.size() - 1) break;
			if (number[i] < number[i + 1]) {
				number.erase(number.begin() + i);
				cnt++;
				break;
			}
		}
	}

	return number;
}