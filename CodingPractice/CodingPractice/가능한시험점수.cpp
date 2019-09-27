#include <iostream>
#include <vector>
using namespace std;


int main()
{
	int t; // 테스트 케이스
	cin >> t;

	for (int test = 0; test < t; test++) {
		int n; // 문제의 개수
		cin >> n;
		vector<int> arr(n); // 각 문제의 배점

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		vector<int> score;
		score.push_back(0);
		for (int cnt = 1; cnt <= n; cnt++) {
			int sum = 0;
			for (int i = 0; i < cnt; i++) {
				sum += arr[i];
				score.push_back(sum);
			}
		}

		cout << "#" << test << " " << answer << endl;
	}

	system("pause");
}