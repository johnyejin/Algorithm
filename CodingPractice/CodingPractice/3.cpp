#include<iostream>
#include<istream>
#include<string>
using namespace std;

int main() {
	// table1 입력받기
	int n1;  // 행의 수 입력
	cin >> n1;
	string *arr1 = new string[n1];
	
	for (int i = 0; i < n1; i++) {
		getline(cin, arr1[i]);
	}
	cout << endl;

	// table2 입력받기
	int n2;
	cin >> n2;
	string *arr2 = new string[n2];

	for (int i = 0; i < n2; i++) {
		getline(cin, arr2[i]);
	}
	cout << endl;

	// table1의 id를 기준으로 table1 id랑 일치하는 정보 검색해 조인
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n2; j++) {

		}
	}

	system("pause");
	return 0;
}