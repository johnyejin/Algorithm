// 15 / 100��
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
vector<vector<string>> arr(101, vector<string>(101, ""));

// �ð�
void clockwise(int row, int col, int x, int y, int n) {
	string pre, cur; // pre:���� �迭�� �� , cur:���� �迭�� ��

	while (row < x - 1 && col < y - 1) {
		pre = arr[row + 1][col]; // ���� �ܾ�

		// ���� �׵θ�
		for (int i = col; i < y; i++) {
			cur = arr[row][i];
			arr[row][i] = pre;
			pre = cur;
		}
		row++;

		// ������ �׵θ�
		for (int i = row; i < x; i++) {
			cur = arr[i][y - 1];
			arr[i][y - 1] = pre;
			pre = cur;
		}
		y--;

		// �Ʒ��� �׵θ�
		for (int i = y - 1; i >= col; i--) {
			cur = arr[x - 1][i];
			arr[x - 1][i] = pre;
			pre = cur;
		}
		x--;

		// ���� �׵θ�
		for (int i = x - 1; i > row; i--) {
			cur = arr[i][col];
			arr[i][col] = pre;
			pre = cur;
		}
		col++;
	}
}

// �ݽð�
void counterclockwise(int row, int col, int x, int y, int n) {
	string pre, cur; // pre:���� �迭�� �� , cur:���� �迭�� ��

	while (row < x - 1 && col < y - 1) {
		pre = arr[row][col + 1];

		// ���� �׵θ�
		for (int i = row; i < n; i++) {
			cur = arr[i][col];
			arr[i][col] = pre;
			pre = cur;
		}
		col++;

		// �Ʒ��� �׵θ�
		for (int i = col; i < n; i++) {
			cur = arr[x - 1][i];
			arr[y - 1][i] = pre;
			pre = cur;
		}
		x--;

		// ������ �׵θ�
		for (int i = x - 1; i >= row; i--) {
			cur = arr[i][y - 1];
			arr[i][y - 1] = pre;
			pre = cur;
		}
		y--;

		// ���� �׵θ�
		for (int i = y - 1; i >= col; i--) {
			cur = arr[row][i];
			arr[row][i] = pre;
			pre = cur;
		}
		row++;

	}
}

int main() {
	int n, w; // n:���ũ��, w:ȸ����
	cin >> n >> w;

	bool flag; // 0=�ݽð�, 1=�ð�
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
	else {  // ȸ������ 0�̸� �� ����ϰ� ����
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


	int row = 0, col = 0; // �����ϴ� �迭 idx [��][��]
	// string pre, cur; // pre:���� �迭�� �� , cur:���� �迭�� ��
	int x = n, y = n; // ������ �迭 idx [��][��]

	// �׵θ� ������ŭ ������
	for (int a = 1; a <= n / 2; a++) {
		// ȸ�� ����ŭ ������
		for (int b = 0; b < w; b++) {
			if (flag == 0) {
				counterclockwise(row, col, x, y, n);
				if (a == n / 2 && a % 2 == 1) break; // Ȧ���� ���
				clockwise(row, col, x, y, n);
			}
			else {
				clockwise(row, col, x, y, n);
				if (a == n / 2 && a % 2 == 1) break; // Ȧ���� ���
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