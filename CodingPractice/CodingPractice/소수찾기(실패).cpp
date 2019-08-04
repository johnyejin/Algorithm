// 시간초과 뜬 코드
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool checkPrime(int num) {
	if (num == 1)
		return false;
	if (num == 2)
		return true;

	for (int i = 2; i < num / 2 + 1; i++) {
		if (num % i == 0) return false;
	}
	return true;
}

int solution(string numbers) {
	int answer = 0;
	string tmp = numbers;
	sort(tmp.begin(), tmp.end(), greater<int>());

	vector<bool> temp(stoi(tmp) + 1);  // 소수인지아닌지

	// temp에 소수면 true / 아니면 false 값 넣기
	temp[0] = false;
	for (long long i = 1; i < temp.size(); i++) {
		temp[i] = checkPrime(i);
	}

	string s = numbers;
	sort(s.begin(), s.end());
	set<int> primes;
	int l = s.size();

	do {
		for (int i = 1; i <= l; i++) {
			string sub = s.substr(0, i);
			if (temp[std::stoi(sub)]) {
				primes.insert(std::stoi(sub));
			}
		}
	} while (next_permutation(s.begin(), s.end()));


	answer = primes.size();
	return answer;
}