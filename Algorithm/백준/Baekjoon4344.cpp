#include<iostream>
#include<string>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int std;  // 각 케이스별 학생수
	int sum = 0;  // 각 케이스별 점수의 합
	int cnt = 0;  // 각 케이스별 평균을 넘는 학생수
	
	for (int i = 0; i < n; i++) {
		sum = 0;
		cnt = 0;
		// 처음에 학생수 입력받고 학생수만큼 배열만들어 점수 입력받기
		cin >> std;
		int *arr = new int[std];

		for (int j = 0; j < std; j++) {
			cin >> arr[j];
			sum += arr[j];
		}
		
		for (int j = 0; j < std; j++) {
			if (arr[j] > (sum / (double)std)) {
				cnt++;
			}
		}
		// 백준에선 이렇게 해야 맞음;;
		printf("%.3f%%\n", (double)cnt / (double)std * 100);
		/*cout << fixed;
		cout.precision(3);
		cout << (double)cnt / (double)std * 100 << "\n";*/
	}
		
	system("pause");
}