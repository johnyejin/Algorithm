#include<iostream>
#include<cmath>
using namespace std;

int main() {
	int n;  // 빌딩의 개수
	cin >> n;
	int *arr = new int[n];
	int *temp = new int[n];  // 각 빌딩에서 연결할 수 있는 밧줄의 길이
	int max;  // 밧줄길이 최대값

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	// 오른쪽으로 가면서 훑기
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (arr[i] <= arr[j]) {
				temp[i] = abs(i - j);
				break;
			}
		}
	}

	// 왼쪽으로 가면서 훑기
	for (int i = n - 1; i >= 0; i--) {
		for (int j = i - 1; j >= 0; j--) {
			if (arr[i] <= arr[j]) {
				if (temp[i] < abs(i - j)) {
					temp[i] = abs(i - j);
					break;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) cout << temp[i] << " ";
	cout << endl;

	max = temp[0];
	for (int i = 0; i < n; i++) {
		if (temp[i] > max) {
			max = temp[i];
		}
	}
	cout << "max: " << max << endl;

	system("pause");
	return 0;
}