#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	int n;  // ������ ũ��
	cin >> n;

	//vector<vector<int>> arr;

	// ������ �迭 ���� �Ҵ�
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

	int a = 0, b = 0;  // chicken, house ���� �� �ϳ��� ������Ű����
	// �迭 �Է¹ޱ�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {  // ġŲ��
				chicken[a++] = 
			}
			else if (arr[i][j] == 1) {  // ��

			}
		}
	}

	// �迭�� �ִ� �� ����Ʈ
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}

	system("pause");
	return 0;
}