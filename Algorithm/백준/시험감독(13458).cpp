#include<iostream>
using namespace std;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long answer = 0; // �ʿ��� �������� �ּ� ��
	int n; // ������ ����
	cin >> n;
	int *a = new int[n]; // �� �����忡 �ִ� ������ ��
	int b, c; // �� �������� �����Ҽ� �ִ� ������ ��
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> b >> c;

	for (int i = 0; i < n; i++) {
		int k = a[i] - b;
		answer++;
		if (k <= 0) {
			continue;
		}
		if (k % c == 0) {
			answer += k / c;
		}
		else {
			answer += k / c + 1;
		}
	}
	cout << answer << endl;

	system("pause");
}