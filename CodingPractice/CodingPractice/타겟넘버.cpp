#include <string>
#include <vector>

using namespace std;
int answer = 0;

void dfs(vector<int> numbers, int target, int sum, int depth) {
	if (depth >= numbers.size()) {
		if (sum == target) {  // ���ݱ��� ���Ѱ� Ÿ���̶� ������ ����
			answer++;
		}
		return;
	}

	dfs(numbers, target, sum + numbers[depth], depth + 1);  // number�� ���ϱ⸦ �ٿ� ����
	dfs(numbers, target, sum - numbers[depth], depth + 1);  // number�� ���⸦ �ٿ� ����
}

int solution(vector<int> numbers, int target) {

	dfs(numbers, target, 0, 0);  // �ֻ��� �θ���� 0

	return answer;
}