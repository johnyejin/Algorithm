/*
 *‘()’ 인 괄호열의 값은 2이다.
 *‘[]’ 인 괄호열의 값은 3이다.
 *‘(X)’ 의 괄호값은 2×값(X) 으로 계산된다.
 *‘[X]’ 의 괄호값은 3×값(X) 으로 계산된다.
 * 올바른 괄호열 X와 Y가 결합된 XY의 괄호값은 값(XY)= 값(X)+값(Y) 로 계산된다. 
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
	int sum = 0;  // 괄호 연산 결과
	int mul = 1;  // 같은 괄호가 중복되는경우 곱한 결과
	int a = 0, b = 0;  // a: '('의 개수 / b: '['의 개수

	// stack에 여는 괄호를 push
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
	// 예외처리
	if (vpn.size() != 0 || a != 0 || b != 0) {
		sum = 0;
	}
	
	std::cout << sum << std::endl;

	system("pause");
	return 0;
}