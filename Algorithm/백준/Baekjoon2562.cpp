#include<iostream>
using namespace std;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int arr[9] = { 0 };
	int max = arr[0];
	int n;  // 최대값 순서

	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		if (arr[i] > max) {
			max = arr[i];
			n = i + 1;
		}
	}
	cout << max << "\n";
	cout << n << "\n";
	

	system("pause");
}