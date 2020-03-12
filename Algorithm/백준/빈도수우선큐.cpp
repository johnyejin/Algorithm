#include <iostream>
#include <map>
#include <string>
using namespace std;
int main() {
	int n;
	cin >> n;
	map<int, int> m;
	map<int, int> cnt;

	// 입력
	for (int i = 0; i < n; i++) {
		string tmp;
		int num;
		if (tmp.compare("enqueue")) {
			cin >> num;
			cnt[num] = i;
			m[i] = num;
		}
		else {
			// 빈도수가 가장 높은거 찾기(같으면 가장먼저 en된 수 저장)
			int max = 0;
			int idx; // 빈도수 가장 큰거 idx
			for (auto it = cnt.end(); it != cnt.begin(); it--) {
				if (cnt.count(it->first) >= max) {
					max = cnt.count(it->first); //
					idx = it->second;
				}
			}

			// front 반환하고 map에서 지우기
			if (i == n - 1)
				cout << m.find(idx)->second;
			else
				cout << m.find(idx)->second << " ";
			m.erase(idx);

			// cnt map에서도 지우기
			map<int, int>::iterator it = cnt.begin();
			while (it != cnt.end()) {
				if (it->second == idx) {
					cnt.erase(it++);
					break;
				}
				else
					it++;
			}

		}
	}

	return 0;
}