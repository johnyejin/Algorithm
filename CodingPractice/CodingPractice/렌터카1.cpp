#include <string>
#include <vector>
#include <algorithm>

using namespace std;
// n: 아반떼 대수, plates: 차량번호, odo: 적산 주행거리, k: 고객 수, drives: 각 고객의 주행거리
string solution(int n, vector<string> plates, vector<int> odo, int k, vector<int> drives) {
	string answer = "";
	vector<pair<int, int>> p;

	for (int i = 0; i < plates.size(); i++) {
		p.push_back(make_pair(odo[i], i));
	}

	for (int i = 0; i < k; i++) {
		sort(p.begin(), p.end());
		p[0].first += drives[i];
	}

	sort(p.begin(), p.end());

	answer = plates[p[0].second];
	return answer;
}