#include<iostream>
using namespace std;
int main() {

	// ����� �ӵ� �ø���
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;  // �׽�Ʈ ���̽� ����
	cin >> t;
	int a, b;

	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		cout << a + b << "\n";
	}
	system("pause");
}