#include<iostream>
#include<string>
#include<cmath>
#include<vector>
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
		vector<char> v;

		for (int i = str.size() - 1; i >= 0; i--) {
			if (str[i] == 'n')
				v.push_back('n');
			else if (str[i] == 'w')
				v.push_back('w');
		}

		int po = pow(2, v.size() - 1);
		int ret = 0;

		// str에서 맨 오른쪽에 있던거 먼저 빼주기
		if (v[0] == 'n')
			ret = 0;
		else
			ret += 90 * po;

		for (int i = 1; i < v.size(); i++) {
			if (v[i] == 'n')
				ret -= (90 * po / pow(2, i));
			else
				ret += (90 * po / pow(2, i));
		}

		// 기약분수 만들기
		int div = gcd(ret, po);
		ret /= div;
		po /= div;

		// 출력
		if (po == 1)
			cout << "#" << test_case << " " << ret << endl;
		else
			cout << "#" << test_case << " " << ret << "/" << po << endl;
	}
	return 0;
}