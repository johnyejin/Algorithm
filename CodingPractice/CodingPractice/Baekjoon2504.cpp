/*
 *��()�� �� ��ȣ���� ���� 2�̴�.
 *��[]�� �� ��ȣ���� ���� 3�̴�.
 *��(X)�� �� ��ȣ���� 2����(X) ���� ���ȴ�.
 *��[X]�� �� ��ȣ���� 3����(X) ���� ���ȴ�.
 * �ùٸ� ��ȣ�� X�� Y�� ���յ� XY�� ��ȣ���� ��(XY)= ��(X)+��(Y) �� ���ȴ�. 
 */
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	string str;
	cin >> str;
	stack<char> vpn;
	int sum = 0;  // ��ȣ ���� ���
	int mul = 1;  // ���� ��ȣ�� �ߺ��Ǵ°�� ���� ���
	int a = 0, b = 0;  // a: '('�� ���� / b: '['�� ����

	// stack�� ���� ��ȣ�� push
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			a++;
			vpn.push(str[i]);
			mul *= 2;
			if (i+1<str.length() && str[i + 1] == ')') {
				sum += mul;
			}
		}
		else if (str[i] == '[') {
			b++;
			vpn.push(str[i]);
			mul *= 3;
			if (i + 1 < str.length() && str[i + 1] == ']') {
				sum += mul;
			}
		}
		else if (str[i] == ')') {
			a--;
			vpn.pop();
			mul /= 2;
		}
		else if (str[i] == ']') {
			b--;
			vpn.pop();
			mul /= 3;
		}
	}
	// ����ó��
	if (vpn.size() != 0 || a != 0 || b != 0) {
		sum = 0;
	}
	
	std::cout << sum << std::endl;

	system("pause");
	return 0;
}