#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {
	vector<int> answer;
	vector<int> div;  // 약수

	// 약수 저장
	for (int i = 1; i <= red; i++) {
		if (red % i == 0) div.push_back(i);
	}

	for (int i = 0; i < div.size() / 2 + 1; i++) {
		if ((div[i] + div[div.size() - 1 - i] + 2) * 2 == brown) {
			answer.push_back(div[div.size() - 1 - i] + 2);
			answer.push_back(div[i] + 2);
			break;
		}
	}

	return answer;
}