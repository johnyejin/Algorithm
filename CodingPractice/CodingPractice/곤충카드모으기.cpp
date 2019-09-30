#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
// 뒤에꺼를 기준으로 내림차순 정렬
bool cmp(const pair<string, int> &a, const pair<string, int> &b)
{
	return a.second > b.second;
}

int main() {
	int n;
	cin >> n;
	vector<string> input;
	vector<pair<string, int>> arr;

	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		input.push_back(tmp);
	}
	sort(input.begin(), input.end());

	// arr에 값 집어넣기
	for (int i = 1; i < n; ) {
		arr.push_back({ input[i - 1], 1 });

		if (input[i - 1] == input[i]) {
			arr[i - 1].second++;
			i++;
		}

		if (i == n - 1) {
			if (input[i - 1] == input[i]) {
				arr[i - 1].second++;
			}
			else
				arr.push_back({ input[i], 1 });
			break;
		}

		i++;
	}
	sort(arr.begin(), arr.end(), cmp);

	char answer = 'N';
	bool flag;
	// answer값 바꿔주기
	for (int i = 0; i < arr.size() - 1; i++) {
		if (arr[i].second == arr[i + 1].second) {
			if (i + 1 == arr.size() - 1) {
				answer = 'Y';
				flag = false;
			}
		}
		else {
			if (i == arr.size() - 2) {
				answer = 'Y';
				flag = true;
			}
			else
				break;
		}
	}

	cout << answer << endl;
	if (flag)
		cout << n + 1 << endl;
	else
		cout << n << endl;
	cout << arr.size() << endl;
	// for(int i=0; i<arr.size(); i++)
	// 	cout<<arr[i].first<<" "<<arr[i].second<<endl;

	return 0;
}