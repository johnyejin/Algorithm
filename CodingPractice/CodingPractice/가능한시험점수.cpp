#include <iostream>
#include <vector>
using namespace std;


int main()
{
	int t; // �׽�Ʈ ���̽�
	cin >> t;

	for (int test = 0; test < t; test++) {
		int n; // ������ ����
		cin >> n;
		vector<int> arr(n); // �� ������ ����

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