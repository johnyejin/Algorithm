// 15 / 100점
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
vector<vector<string>> arr(101, vector<string>(101, ""));

// 시계
void clockwise(int row, int col, int x, int y, int n) {
	string pre, cur; // pre:이전 배열의 값 , cur:현재 배열의 값

	while (row < x - 1 && col < y - 1) {
		pre = arr[row + 1][col]; // 시작 단어

		// 위쪽 테두리
		for (int i = col; i < y; i++) {
			cur = arr[row][i];
			arr[row][i] = pre;
			pre = cur;
		}
		row++;

		// 오른쪽 테두리
		for (int i = row; i < x; i++) {
			cur = arr[i][y - 1];
			arr[i][y - 1] = pre;
			pre = cur;
		}
		y--;

		// 아래쪽 테두리
		for (int i = y - 1; i >= col; i--) {
			cur = arr[x - 1][i];
			arr[x - 1][i] = pre;
			pre = cur;
		}
		x--;

		// 왼쪽 테두리
		for (int i = x - 1; i > row; i--) {
			cur = arr[i][col];
			arr[i][col] = pre;
			pre = cur;
		}
		col++;
	}
}

// 반시계
void counterclockwise(int row, int col, int x, int y, int n) {
	string pre, cur; // pre:이전 배열의 값 , cur:현재 배열의 값

	while (row < x - 1 && col < y - 1) {
		pre = arr[row][col + 1];

		// 왼쪽 테두리
		for (int i = row; i < n; i++) {
			cur = arr[i][col];
			arr[i][col] = pre;
			pre = cur;
		}
		col++;

		// 아래쪽 테두리
		for (int i = col; i < n; i++) {
			cur = arr[x - 1][i];
			arr[y - 1][i] = pre;
			pre = cur;
		}
		x--;

		// 오른쪽 테두리
		for (int i = x - 1; i >= row; i--) {
			cur = arr[i][y - 1];
			arr[i][y - 1] = pre;
			pre = cur;
		}
		y--;

		// 위쪽 테두리
		for (int i = y - 1; i >= col; i--) {
			cur = arr[row][i];
			arr[row][i] = pre;
			pre = cur;
		}
		row++;

	}
}

int main() {
	int n, w; // n:행렬크기, w:회전수
	cin >> n >> w;

	bool flag; // 0=반시계, 1=시계
	// vector<vector<string>> answer(n, vector<string>(n,""));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			string tmp;
			cin >> tmp;
			arr[i][j] = tmp;
			// cout<<arr[i][j]<<" ";
		}
		// cout<<endl;
	}

	if (w < 0)
		flag = 0;
	else if (w > 0)
		flag = 1;
	else {  // 회전수가 0이면 걍 출력하고 끝냄
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << arr[i][j] << " ";
			}
			cout << "\n";
		}
		return 0;
	}


	w = abs(w) % (int)pow(2, n);
	// cout<<w<<endl;


	int row = 0, col = 0; // 시작하는 배열 idx [행][열]
	// string pre, cur; // pre:이전 배열의 값 , cur:현재 배열의 값
	int x = n, y = n; // 끝나는 배열 idx [행][열]

	// 테두리 개수만큼 돌리기
	for (int a = 1; a <= n / 2; a++) {
		// 회전 수만큼 돌리기
		for (int b = 0; b < w; b++) {
			if (flag == 0) {
				counterclockwise(row, col, x, y, n);
				if (a == n / 2 && a % 2 == 1) break; // 홀수인 경우
				clockwise(row, col, x, y, n);
			}
			else {
				clockwise(row, col, x, y, n);
				if (a == n / 2 && a % 2 == 1) break; // 홀수인 경우
				counterclockwise(row, col, x, y, n);
			}
		}
	}



	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j == n - 1)
				cout << arr[i][j];
			else
				cout << arr[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}