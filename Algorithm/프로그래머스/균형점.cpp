#include <iostream>
#include <vector>
using namespace std;


int main()
{
	int t; // �׽�Ʈ ���̽�
	cin >> t;

	for (int test = 0; test < t; test++) {
		int n; // �ڼ�ü�� ����
		cin >> n;
		vector<vector<int>> arr;
		arr.assign(n, vector<int>(2));
		for (int j = 0; j < 2; j++) {
			for (int i = 0; i < n; i++) {
				cin >> arr[i][j];
			}
		}
		

		//cout << "#" << test << " " << answer << endl;
	}

	system("pause");
}