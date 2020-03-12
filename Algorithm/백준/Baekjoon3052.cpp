#include<iostream>
#include<string>
using namespace std;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int arr[42] = { 0 };
	int cnt = 0;
	int temp;

	for (int i = 0; i < 10; i++) {
		cin >> temp;
		arr[temp % 42] = 1;
	}

	for (int i = 0; i < 42; i++)
		cnt += arr[i];

	cout << cnt << "\n";

	system("pause");
}


//#include<iostream>
//#include<string>
//using namespace std;
//int main() {
//	cin.tie(NULL);
//	ios_base::sync_with_stdio(false);
//
//	int arr[10];
//	int rest[10];  // 나머지
//	int cnt = 1;   // 서로 다른 값
//	bool flag = false;
//
//	for (int i = 0; i < 10; i++) 
//		cin >> arr[i];
//
//	for (int i = 0; i < 10; i++)
//		rest[i] = arr[i] % 42;
//
//	for (int i = 1; i < 10; i++) {
//		for (int j = i - 1; j >= 0; j--) {
//			if (rest[i] == rest[j]) {
//				flag = true;
//				break;
//			}
//		}
//		if (flag == true)
//			continue;
//		else
//			cnt++;
//	}
//
//	cout << cnt << "\n";
//
//	system("pause");
//}