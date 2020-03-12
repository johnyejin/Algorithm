#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n, vector<string> plates, vector<int> odo, int k, vector<int> drives) {
	string answer = "";
	vector<pair<int, string>> p;

	for (int i = 0; i < n; i++) {
		p.push_back({ odo[i], plates[i] });
	}

	for (int i = 0; i < k; i++) {
		sort(p.begin(), p.end());
		p[0].first += drives[i];
	}

	sort(p.begin(), p.end());

	answer = p[0].second;
	return answer;
}