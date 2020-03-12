#include<iostream>
using namespace std;

void main() {
	int n;  // 배열의 개수
	cin >> n;
	int *arr = new int[n];
	int tmp = 0;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	// 버블 정렬
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (arr[i] > arr[j]) {
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	delete[] arr;
	system("pause");
}