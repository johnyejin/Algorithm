#include<iostream>
using namespace std;

int n;
int arr[100][100];
bool visit[100][100];


void dfs(int start, int next) {
	visit[start][next] = 1;
	arr[start][next] = 1;

	for (int j = 0; j < n; j++) {
		if (arr[next][j] == 1 && !visit[start][j]) {
			dfs(start, j);
		}
	}
	
}

int main() {

	cin >> n;
	

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] && !visit[i][j]) {
				dfs(i, j);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	system("pause");
}