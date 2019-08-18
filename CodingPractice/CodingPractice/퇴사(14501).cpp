#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; // ��
	cin >> n;
	int *t = new int[n]; // ��� �Ⱓ
	int *p = new int[n]; // �ݾ�
	vector<int> answer(n, 0);  // 0���� �ʱ�ȭ

	for (int i = 0; i < n; i++) {
		cin >> t[i] >> p[i];

		int Max = answer[0]; 
		t[0]--;
		for (int j = 1; j <= i; j++) {
			if (t[j] == 0) {
				answer[j] += max(answer[j-1], p[j]);
			}
			else {
				t[j]--;

			}
		}
		
	}
	cout << answer[4] << endl;
	
	system("pause");
}