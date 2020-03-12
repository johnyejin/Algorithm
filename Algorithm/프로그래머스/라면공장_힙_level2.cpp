#include <string>
#include <vector>
#include <queue>

using namespace std;

// 밀가루 수량, 공급 일자, 수량, 원래 공장으로부터 공급받을수있는 시점
int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	int answer = 0;
	priority_queue<int, vector<int>, less<int>> temp;  // 최소한으로 공급받으려면 한번에 공급받는 양이 많아야 하니까 우선순위 큐 사용

	int j = 0;  // supplies index
	for (int i = 0; i < k; i++) {
		// 공급일자가 되면 temp에 공급량 넣기
		if (dates[j] == i) {
			temp.push(supplies[j]);
			j++;
		}
		// 재고가 없으면 temp에 있는 젤 많은 공급량부터 빼서 넣기
		if (stock == 0) {
			stock += temp.top();
			temp.pop();
			answer++;
		}
		stock--;
	}

	return answer;
}