#include<iostream>
#include<string>
using namespace std;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	string *s = new string[n];
	int cnt = 0;   // O의개수
	int sum = 0;  // 점수

	for (int i = 0; i < n; i++)
		cin >> s[i];

	for (int i = 0; i < n; i++) {
		sum = 0;
		cnt = 0;
		for (int j = 0; j < s[i].size(); j++) {
			if (s[i].at(j) == 'X') {
				cnt = 0;
				continue;
			}
			else {
				cnt++;
				sum += cnt;
			}

		}
		cout << sum << "\n";
	}
	

	system("pause");
}