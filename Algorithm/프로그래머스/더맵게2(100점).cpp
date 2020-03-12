#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	priority_queue<int, vector<int>, greater<int>> temp;  // 오름차순 우선순위큐
	int a, b;

	// temp에 오름차순으로 스코빌 저장
	for (int i = 0; i < scoville.size(); i++)
		temp.push(scoville[i]);

	// temp.top이 k보다 크면 break
	while (temp.top() < K && temp.size() > 1) {  // size가 1 이하면 segment fault뜸
		answer++;
		a = temp.top();
		temp.pop();
		b = temp.top();
		temp.pop();

		temp.push(a + b * 2);

	}
	// 제한사항
	if (temp.top() < K) return -1;

	return answer;
}