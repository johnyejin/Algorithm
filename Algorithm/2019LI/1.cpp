#include <iostream>
#include <math.h>
using namespace std;

int main(void) {
	int n;  // 사각형의 넓이
	cin >> n;
	int *arr = new int[sqrt(n)];  // n의 약수 
	int h;  // 직사각형 가로, 세로
	int min;   // |w-h| 최소값

	for (int i = 1; i*i <= n; i++) {
		if (n % i == 0) {
			arr[i - 1] = i;
			cout << arr[i - 1] << " ";
		}
	}
	cout << endl;

	h = n / arr[0];
	min = abs(arr[0] - h);

	for (int i = 0; i <= sizeof(arr) / sizeof(arr[0]); i++) {
		if (n == 1) {
			break;
		}

		h = n / arr[i];

		if (abs(arr[i] - h) < min) {
			min = abs(arr[i] - h);
		}
	}

	cout << min << endl;
	system("pause");
	return 0;
}