/*
 * 10�϶� ó������
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	string str;
	cin >> str;
	vector<char> resultAlpha;
	vector<int> resultNum;
	vector<string> result;
	int cntAlpha = 0, cntNum = 0;

	for (int i = 0; i < str.length(); i++) {
		// �빮��
		if (isupper(str[i])) {
			resultAlpha.push_back(str[i]);
			cntAlpha++;
		}
		// �ҹ���
		else if (islower(str[i])) {
			resultAlpha.push_back(str[i]);
		}
		// ����
		else if (isdigit(str[i])) {
			// ���ڰ� 10�� ���
			if (str[i] == '1' && str[i + 1] == '0') {
				resultNum.push_back(10);
				cntNum++;
				i++;
				continue;
			}
			resultNum.push_back(str[i]);
			cntNum++;
		}
	}

	if (cntAlpha != cntNum) {

	}

	for (int i = 0; i < cntAlpha; i++) {

	}

	system("pause");
	return 0;
}

//int main() {
//	string str;
//	cin >> str;
//	string resultAlpha;
//	string resultNum;
//	string result;
//	int cntAlpha = 0, cntNum = 0;
//	int tmp = 0;   // ���� ������ 10�� ��� 1�� ����
//
//	// �Է¹��� ���ڿ��� ���ڿ� ���ڷ� �и�
//	for (int i = 0; i < str.length(); i++) {
//		// �빮��
//		if (isupper(str[i])) {
//			resultAlpha += str[i];
//			cntAlpha++;
//		}
//		// �ҹ���
//		else if (islower(str[i])) {
//			resultAlpha += str[i];
//		}
//		// ����
//		else if (isdigit(str[i])) {
//			resultNum += str[i];
//			cntNum++;
//			cout << i << " " << resultNum << endl;
//			// ���ڰ� 10�� ���
//			if (str[i] == '1' && str[i + 1] == '0') {
//				i++;
//				resultNum += '0';
//				//continue;
//			}
//			
//		}
//	}
//
//	cout << resultAlpha << endl;
//	cout << resultNum << endl;
//
//	// ����
//	if (cntAlpha != cntNum) {
//		cout << "error" << endl;
//		system("pause");
//		return 0;
//	}
//
//	// ���ұ�ȣ�� ���� ��ġ��
//	for (int i = 0; i < cntAlpha; i++) {
//		result += resultAlpha[i];
//		// 10�� ���
//		if (resultNum[i] == '1' && resultNum[i + 1] == '0') {
//			result = result + resultNum[i] + resultNum[i + 1];
//			tmp++;
//		}
//		// 1�� ���
//		else if (resultNum[i] == '1') continue;
//		result += resultNum[i + tmp];
//	}
//	cout << result << endl;
//
//	system("pause");
//	return 0;
//}