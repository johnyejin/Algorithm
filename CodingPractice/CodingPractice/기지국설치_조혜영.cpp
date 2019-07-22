#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
	vector <int> check;
	int answer = 0;
	int cnt;

	if (stations[0] - w > 1) {
		cnt = (stations[0] - w) - 1;
		check.push_back(cnt);
	}

	for (int i = 0; i < stations.size() - 1; i++) {
		if ((stations[i + 1] - w) > (stations[i] + w)) {
			cnt = (stations[i + 1] - w) - (stations[i] + w) - 1;
			check.push_back(cnt);
		}
	}

	if (stations[stations.size() - 1] + w < n) {
		cnt = n - (stations[stations.size() - 1] + w);
		check.push_back(cnt);
	}

	int able = w * 2 + 1;

	for (int i = 0; i < check.size(); i++) {
		if (check[i] % able == 0) answer += check[i] / able;
		else answer += (check[i] / able) + 1;

	}

	return answer;
}