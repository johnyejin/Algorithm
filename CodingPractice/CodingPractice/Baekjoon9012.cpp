#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	int n; // ������ ũ��
	cin >> n;
	string str;  // �Է¹��� ��ȣ ���ڿ�
	stack<char> vpn;  // ���ÿ� ���� ��ȣ��
	bool chk = true;  // vpn�̸� yes, �ƴϸ� no

	for (int i = 0; i < n; i++) {
		cin >> str;

		for (int i = 0; i < str.length(); i++) {
			// (�� ��� ���ÿ� Ǫ��
			// )�� ��� ���ÿ��� ��
			if (str[i] == '(') {
				vpn.push(str[i]);
			}
			else {
				if (!vpn.empty()) {
					vpn.pop();
				}
				else {
					chk = false;
				}
			}
		}
		// stack�� ��ȣ�� ���������� false
		if (!vpn.empty()) {
			chk = false;
		}

		if (chk) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}

	system("pause");
	return 0;
}