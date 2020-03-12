#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// (6,10)이면 6+10 = 610 / 10+6 = 106 으로 비교
bool cmp(string a, string b) {
	return a + b > b + a ? true : false;
}

string solution(vector<int> numbers) {
	string answer = "";
	vector<string> str;

	for (int i = 0; i < numbers.size(); i++) {
		str.push_back(to_string(numbers[i]));
	}
	sort(str.begin(), str.end(), cmp);

	for (string s : str) {
		answer += s;
	}

	// 
	if (answer[0] == '0') return "0";

	return answer;
}