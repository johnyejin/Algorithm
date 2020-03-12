#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int answer = 1;

	while (answer <= n) {
		string str = to_string(answer);
		int sum = 0; 

		for (int i = 0; i < str.size(); i++) {
			int tmp = str[i] - '0';
			sum += tmp;
		}
		sum += answer;
		
		if (sum == n) break;

		answer++;
	}

	if (answer >= n)
		cout << 0 << endl;
	else
		cout << answer << endl;

	system("pause");
}