#include <string>
#include <vector>

using namespace std;
int answer = 0;

void dfs(vector<int> numbers, int target, int sum, int depth) {
	if (depth >= numbers.size()) {
		if (sum == target) {  // 지금까지 더한게 타겟이랑 같으면 리턴
			answer++;
		}
		return;
	}

	dfs(numbers, target, sum + numbers[depth], depth + 1);  // number에 더하기를 붙여 더함
	dfs(numbers, target, sum - numbers[depth], depth + 1);  // number에 빼기를 붙여 더함
}

int solution(vector<int> numbers, int target) {

	dfs(numbers, target, 0, 0);  // 최상위 부모노드는 0

	return answer;
}