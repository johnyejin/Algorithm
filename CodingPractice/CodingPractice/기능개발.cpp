#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	vector<int> end;  // �� ����� ���ϸ��� �Ϸ�ƴ��� 
	int cnt = 0;

	// cnt: �� ����� ���ϸ��� �Ϸ�ƴ��� -> end vector�� push
	for (int i = 0; i < speeds.size(); i++) {
		cnt = 0;
		while (progresses[i] < 100) {
			progresses[i] += speeds[i];
			cnt++;
		}
		end.push_back(cnt);
		// cout<<progresses[i]<< " " << cnt<< " "<<end.size() <<endl;
	}


	while (!end.empty()) {
		cnt = 1; // �� �������� ��� ����� �����Ǵ���
		int front = end.front();
		// cout<<end.front()<<endl;
		end.erase(end.begin());

		// �� �ڿ����� �� ���ؼ� ������ ���� �������� vector���� �����
		for (int i = 0; i < end.size(); ) {
			if (end.front() <= front) {
				cnt++;
				end.erase(end.begin() + i);
			}
			else {
				i++;
			}
		}
		answer.push_back(cnt);
	}

	return answer;
}