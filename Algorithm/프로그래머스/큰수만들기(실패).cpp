// ������ �׽�Ʈ �ð��ʰ����� ����
#include <string>
#include <vector>

using namespace std;

// �ڿ� ���ڰ� �տ� ���ں��� ũ�� �տ��� �����
string solution(string number, int k) {
	int cnt = 0;  // ������ ���� ����

	if (number[0] == '0') return "0";

	// i�� ��� 0���� �ʱ�ȭ�Ǿ����
	while (cnt != k) {
		int i = 0;  // �ε��� ��ó������ �ʱ�ȭ

		// i�� ��� ������Ű�鼭 ���ϱ�����
		for (; !number.empty(); i++) {
			if (i == number.size() - 1) break;
			if (number[i] < number[i + 1]) {
				number.erase(number.begin() + i);
				cnt++;
				break;
			}
		}
	}

	return number;
}