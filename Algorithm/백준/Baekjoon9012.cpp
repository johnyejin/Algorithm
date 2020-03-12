#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	int n; // 데이터 크기
	cin >> n;
	string str;  // 입력받은 괄호 문자열
	stack<char> vpn;  // 스택에 넣을 괄호들
	bool chk = true;  // vpn이면 yes, 아니면 no

	for (int i = 0; i < n; i++) {
		cin >> str;

		for (int i = 0; i < str.length(); i++) {
			// (인 경우 스택에 푸시
			// )인 경우 스택에서 팝
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
		// stack에 괄호가 남아있으면 false
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