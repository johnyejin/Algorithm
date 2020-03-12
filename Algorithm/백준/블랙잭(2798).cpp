#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m; // n: ī�尳��, m: ��ǥ ����
	cin >> n >> m;
	vector<int> card(n);

	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}

	int sum = 0;
	int max = 0;

	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				sum = card[i] + card[j] + card[k];
				if (sum > m) continue;
				if (max < sum) max = sum;
				//cout << max <<" " << sum << endl;
			}
		}
	}

	cout << max << endl;

	system("pause");
}