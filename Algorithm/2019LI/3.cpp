#include<iostream>
#include<istream>
#include<string>
using namespace std;

int main() {
	// table1 �Է¹ޱ�
	int n1;  // ���� �� �Է�
	cin >> n1;
	string *arr1 = new string[n1];
	
	for (int i = 0; i < n1; i++) {
		getline(cin, arr1[i]);
	}
	cout << endl;

	// table2 �Է¹ޱ�
	int n2;
	cin >> n2;
	string *arr2 = new string[n2];

	for (int i = 0; i < n2; i++) {
		getline(cin, arr2[i]);
	}
	cout << endl;

	// table1�� id�� �������� table1 id�� ��ġ�ϴ� ���� �˻��� ����
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n2; j++) {

		}
	}

	system("pause");
	return 0;
}