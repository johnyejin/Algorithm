#include <iostream>
#include <vector>
using namespace std;

int n, k; // n: �ڿ����� ����, k: ��
int sum = 0;
vector<int> arr;
int answer = 0; // n���� ���� k�� �Ǵ� ����Ǽ�

void go(int idx) {
	for (int i = idx; i < n; i++) {
		sum += arr[i];
		if (sum == k) {
			sum = 0;
			answer++;
			break;
		}
		
		if (sum > k) {
			sum -= arr[i];
			go(i);
		}
	}
}

int main()
{
	int t; // �׽�Ʈ ���̽�
	cin >> t;

	for (int test = 0; test < t; test++) {
		
		cin >> n >> k;
		

		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			arr.push_back(num);
		}

		go(0);

		cout << "#" << test << " " << answer << endl;
	}

	system("pause");
}