// kruskal 알고리즘
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int arr[101];  // 부모 정점 저장

// 최상위 부모를 찾는 함수
int find(int node) {
	// 부모가 자기자신이면 현재 노드가 최상위 부모
	if (node == arr[node]) return node;
	// 아니면 최상위 부모를 찾음
	else return arr[node] = find(arr[node]);
}

// 간선의 가중치를 기준으로 오름차순 정렬
bool cmp(const vector<int> &a, const vector<int> &b) {
	return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
	int answer = 0;

	sort(costs.begin(), costs.end(), cmp);

	// 맨 처음 부모는 자기자신
	for (int i = 0; i < n; i++)
		arr[i] = i;

	// 모든 간선 검사
	for (int i = 0; i < costs.size(); i++) {
		int start = find(costs[i][0]);
		int end = find(costs[i][1]);
		int cost = costs[i][2];

		// start와 end가 아직 연결되지 않았으면
		if (start != end) {
			// start의 부모를 end로 설정
			arr[start] = end;
			// 간선의 가중치를 결과에 더해줌
			answer += cost;
		}
	}

	return answer;
}