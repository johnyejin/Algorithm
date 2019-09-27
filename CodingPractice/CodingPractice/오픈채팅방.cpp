// 6.3�� ����
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	vector<pair<string, string>> current; // [id, name]
	vector<pair<string, pair<string, string>>> ans; // [id, name, string]

	for (int i = 0; i < record.size(); i++) {
		// ���ڿ� �ڸ���
		stringstream ss(record[i]);
		string go, id, name;
		ss >> go;
		ss >> id;
		ss >> name;

		if (go[0] == 'E') {
			current.push_back(make_pair(id, name));
			ans.push_back(make_pair(id, make_pair(name, "���� ���Խ��ϴ�.")));
			// ������ �ٽ� ���Դµ� �̸� �ٲ���
			for (int k = 0; k < ans.size(); k++) {
				if (id.compare(ans[k].first) == 0) {
					if (name.compare(ans[k].second.first) != 0) {
						ans[k].second.first = name;
						current[k].second = name;
					}
				}
			}
		}
		else if (go[0] == 'L') {
			// ���� ģ�� �̸� �ٿ��ֱ�
			for (int k = 0; k < current.size(); k++) {
				if (id.compare(current[k].first) == 0) {
					name = current[k].second;
					break;
				}
			}
			ans.push_back(make_pair(id, make_pair(name, "���� �������ϴ�.")));

		}
		else {
			for (int k = 0; k < ans.size(); k++) {
				if (id.compare(ans[k].first) == 0) {
					ans[k].second.first = name;
				}
			}
		}
	}

	for (int i = 0; i < ans.size(); i++) {
		string s = ans[i].second.first;
		s.append(ans[i].second.second);
		answer.push_back(s);
	}

	return answer;
}