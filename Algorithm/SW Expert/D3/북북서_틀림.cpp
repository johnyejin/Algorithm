#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int gcd(int a, int b) {
	if (a % b == 0)
		return b;
	return gcd(b, a % b);
}

int main(int argc, char** argv)
{
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; ++test_case)
	{
		string str;
		cin >> str;
		int cnt = 1;
		double answer = 0;
		int idx = 0;

		// 맨 오른쪽꺼 먼저 빼주기
		if (str[str.size() - 1] == 'h') {
			idx = str.size() - 6;
		}
		else {
			idx = str.size() - 5;
			answer += 90;
		}

		while (idx > 0) {
			if (str[idx] == 'h') {
				answer -= 90 / pow(2, cnt);
				idx -= 5;
			}
			else {
				answer += 90 / pow(2, cnt);
				idx -= 4;
			}
			cnt += 1;
		}

		// 기약분수로 변경
		int numerator = (int)(answer * pow(10, cnt - 1));
		int denominator = pow(10, cnt - 1);

		if (answer == 0) {
			denominator = 1;
		} else {
			int div = gcd(numerator, denominator);
			numerator /= div;
			denominator /= div;
		}
		// 출력
		if (denominator == 1)
			cout << "#" << test_case << " " << numerator << endl;
		else
			cout << "#" << test_case << " " << numerator << "/" << denominator << endl;
	}
	system("pause");
	return 0;
}