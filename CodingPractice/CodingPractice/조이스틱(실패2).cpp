// �� ������ �׽�Ʈ ����
#include <string>
#include <vector>
#include <cmath>

using namespace std;

// BAAAB -> B�����̰� �������� / ABBAA �� ��� -> ABB���� �����̰� ��
int solution(string name) {
	int answer1 = 0;  // Ŀ���� ���������� �̵��� ��� ��
	int answer2;  // Ŀ���� �������� �̵��� ��� ��

	answer1 += min(name[0] - 'A', 'Z' - name[0] + 1);
	answer2 = answer1;

	// Ŀ���� ���������� �̵��� ���
	for (int i = 1; i < name.size(); i++) {

		bool flag = true;  // A�� ��� true
		for (int j = i; j < name.size(); j++) {
			if (name[j] != 'A') {
				flag = false;
				break;
			}
		}

		if (flag) break;  // �ǳ��� 'A'�� ��� ������ �ʿ䰡 �����ϱ� 
		answer1++;
		answer1 += min(name[i] - 'A', 'Z' - name[i] + 1);
	}

	// Ŀ���� �������� �̵��� ���
	for (int i = name.size() - 1; i >= 1; i--) {

		bool flag = true;  // A�� ��� true
		for (int j = i; j >= 1; j--) {
			if (name[j] != 'A') {
				flag = false;
				break;
			}
		}

		if (flag) break;  // �ǳ��� 'A'�� ��� ������ �ʿ䰡 �����ϱ� 
		answer2++;
		answer2 += min(name[i] - 'A', 'Z' - name[i] + 1);
	}


	return min(answer1, answer2);
}