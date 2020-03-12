// kruskal �˰���
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int arr[101];  // �θ� ���� ����

// �ֻ��� �θ� ã�� �Լ�
int find(int node) {
	// �θ� �ڱ��ڽ��̸� ���� ��尡 �ֻ��� �θ�
	if (node == arr[node]) return node;
	// �ƴϸ� �ֻ��� �θ� ã��
	else return arr[node] = find(arr[node]);
}

// ������ ����ġ�� �������� �������� ����
bool cmp(const vector<int> &a, const vector<int> &b) {
	return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
	int answer = 0;

	sort(costs.begin(), costs.end(), cmp);

	// �� ó�� �θ�� �ڱ��ڽ�
	for (int i = 0; i < n; i++)
		arr[i] = i;

	// ��� ���� �˻�
	for (int i = 0; i < costs.size(); i++) {
		int start = find(costs[i][0]);
		int end = find(costs[i][1]);
		int cost = costs[i][2];

		// start�� end�� ���� ������� �ʾ�����
		if (start != end) {
			// start�� �θ� end�� ����
			arr[start] = end;
			// ������ ����ġ�� ����� ������
			answer += cost;
		}
	}

	return answer;
}