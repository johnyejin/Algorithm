#include<iostream>
using namespace std;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; // 과목 수
	double *arr = new double[n];
	double max, sum = 0;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	max = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] > max)
			max = arr[i];
	}

	for (int i = 0; i < n; i++) {
		arr[i] = arr[i] / max * 100;
		sum += arr[i];
	}
	cout << sum / n << "\n";

	system("pause");
}

// 이게 맞은거;
//#include<iostream>
//using namespace std;
//int main() {
//	cin.tie(NULL);
//	ios_base::sync_with_stdio(false);
//
//	int n; // 과목 수
//	cin >> n;
//	double *arr = new double[n];
//	int max;
//	double sum = 0;
//
//	for (int i = 0; i < n; i++)
//		cin >> arr[i];
//
//	max = arr[0];
//	for (int i = 1; i < n; i++) {
//		if (arr[i] > max)
//			max = arr[i];
//	}
//
//	for (int i = 0; i < n; i++) {
//		arr[i] = (double)arr[i] / (double)max * 100;
//		sum += arr[i];
//	}
//	cout.precision(2);
//	cout << fixed << (double)sum / (double)n;
//}