#include<iostream>
using namespace std;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, x;
	cin >> n >> x;
	int *arr = new int[n];

	for (int i = 0; i < n; i++)
		cin >> arr[i];


	for (int i = 0; i < n; i++) {
		if (arr[i] < x)
			cout << arr[i] << " ";
	}
	cout << "\n";

	system("pause");
}