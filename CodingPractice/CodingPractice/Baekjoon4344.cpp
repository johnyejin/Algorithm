#include<iostream>
#include<string>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int std;  // �� ���̽��� �л���
	int sum = 0;  // �� ���̽��� ������ ��
	int cnt = 0;  // �� ���̽��� ����� �Ѵ� �л���
	
	for (int i = 0; i < n; i++) {
		sum = 0;
		cnt = 0;
		// ó���� �л��� �Է¹ް� �л�����ŭ �迭����� ���� �Է¹ޱ�
		cin >> std;
		int *arr = new int[std];

		for (int j = 0; j < std; j++) {
			cin >> arr[j];
			sum += arr[j];
		}
		
		for (int j = 0; j < std; j++) {
			if (arr[j] > (sum / (double)std)) {
				cnt++;
			}
		}
		// ���ؿ��� �̷��� �ؾ� ����;;
		printf("%.3f%%\n", (double)cnt / (double)std * 100);
		/*cout << fixed;
		cout.precision(3);
		cout << (double)cnt / (double)std * 100 << "\n";*/
	}
		
	system("pause");
}