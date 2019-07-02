#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	int n;  // 도시의 크기
	cin >> n;

	//vector<vector<int>> arr;

	// 이차원 배열 동적 할당
	int **arr = new int*[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
	}

	vector<vector<int> > chicken(2,vector<int>(;
	vector<vector<int> > house;
	for (int i = 0; i < 2; i++) {
		vector<int> temp1(2);
		chicken.push_back(temp1);
	}
	for (int i = 0; i < 2; i++) {
		vector<int> temp2(2);
		chicken.push_back(temp2);
	}

	int a = 0, b = 0;  // chicken, house 벡터 값 하나씩 증가시키려고
	// 배열 입력받기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {  // 치킨집
				chicken[a++] = 
			}
			else if (arr[i][j] == 1) {  // 집

			}
		}
	}

	// 배열에 있는 값 프린트
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}

	system("pause");
	return 0;
}