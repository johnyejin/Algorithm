#include<iostream>
using namespace std;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int arr[8];
	for (int i = 0; i < 8; i++) {
		cin >> arr[i];
	}

	int cnt = 0;  // 
	if (arr[0] == 1) cnt++;
	else if (arr[0] == 8) cnt--;

	for (int i = 1; i < 8; i++) {
		if (arr[i] == arr[i - 1] + 1) cnt++;
		else if (arr[i] == arr[i - 1] - 1) cnt--;
	}

	if (cnt == 8) cout << "ascending\n";
	else if (cnt == -8) cout << "descending\n";
	else cout << "mixed\n";

	system("pause");
}