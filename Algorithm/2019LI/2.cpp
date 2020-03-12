/*
 * 10일때 처리안함
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
		// 대문자
		if (isupper(str[i])) {
			resultAlpha.push_back(str[i]);
			cntAlpha++;
		}
		// 소문자
		else if (islower(str[i])) {
			resultAlpha.push_back(str[i]);
		}
		// 숫자
		else if (isdigit(str[i])) {
			// 숫자가 10인 경우
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
//	int tmp = 0;   // 원소 개수가 10인 경우 1씩 증가
//
//	// 입력받은 문자열을 문자와 숫자로 분리
//	for (int i = 0; i < str.length(); i++) {
//		// 대문자
//		if (isupper(str[i])) {
//			resultAlpha += str[i];
//			cntAlpha++;
//		}
//		// 소문자
//		else if (islower(str[i])) {
//			resultAlpha += str[i];
//		}
//		// 숫자
//		else if (isdigit(str[i])) {
//			resultNum += str[i];
//			cntNum++;
//			cout << i << " " << resultNum << endl;
//			// 숫자가 10인 경우
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
//	// 예외
//	if (cntAlpha != cntNum) {
//		cout << "error" << endl;
//		system("pause");
//		return 0;
//	}
//
//	// 원소기호와 숫자 합치기
//	for (int i = 0; i < cntAlpha; i++) {
//		result += resultAlpha[i];
//		// 10인 경우
//		if (resultNum[i] == '1' && resultNum[i + 1] == '0') {
//			result = result + resultNum[i] + resultNum[i + 1];
//			tmp++;
//		}
//		// 1인 경우
//		else if (resultNum[i] == '1') continue;
//		result += resultNum[i + tmp];
//	}
//	cout << result << endl;
//
//	system("pause");
//	return 0;
//}