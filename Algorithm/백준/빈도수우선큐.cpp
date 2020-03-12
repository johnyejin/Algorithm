#include <iostream>
#include <map>
#include <string>
using namespace std;
int main() {
	int n;
	cin >> n;
	map<int, int> m;
	map<int, int> cnt;

	// �Է�
	for (int i = 0; i < n; i++) {
		string tmp;
		int num;
		if (tmp.compare("enqueue")) {
			cin >> num;
			cnt[num] = i;
			m[i] = num;
		}
		else {
			// �󵵼��� ���� ������ ã��(������ ������� en�� �� ����)
			int max = 0;
			int idx; // �󵵼� ���� ū�� idx
			for (auto it = cnt.end(); it != cnt.begin(); it--) {
				if (cnt.count(it->first) >= max) {
					max = cnt.count(it->first); //
					idx = it->second;
				}
			}

			// front ��ȯ�ϰ� map���� �����
			if (i == n - 1)
				cout << m.find(idx)->second;
			else
				cout << m.find(idx)->second << " ";
			m.erase(idx);

			// cnt map������ �����
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