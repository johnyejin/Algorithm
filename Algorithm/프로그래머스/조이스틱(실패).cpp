// �Ųٷ� ���°� ���� ����
#include <string>
#include <vector>

using namespace std;

// BAAAB -> B�����̰� �������� / ABBAA �� ��� -> ABB���� �����̰� ��
int solution(string name) {
	int answer = 0;
	int Acnt = 1;

	for (int i = 0; i < name.size(); i++) {
		if (name[i] == 'A') {
			Acnt++;
			if (name[i + 1] != 'A') {
				if (Acnt > name.size() - (i + 1)) {
					answer += name.size() - (i + 1);
				}
				else {
					answer += Acnt;
				}
				Acnt = 1;  // �ʱ�ȭ
			}
			continue;
		}

		if (name[i] > 'N') {
			answer += 91 - name[i];
		}
		else {
			answer += name[i] - 65;
		}

		// �� ������ ���ڸ� answer�� 1 �ȴ��ϰ�
		if (i == name.size() - 1) break;
		answer++;
	}

	return answer;
}