// 실패
#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(string p) {
	string answer = "";
	stack<char> str;


	if (p.size() == 0)
		return answer;

	int cnt = 0;  // 올바른 괄호 문자열 개수
	bool flag = false; // 올바르지 않은 문자열이 있으면 true
	while (cnt < p.size()) {
		string u, v;
		stack<char> wrong; // 올바르지 않은 문자열

		for (int i = cnt; i < p.size(); i++) {
			u += p[i];


			if (p[i] == '(') {
				str.push(p[i]);
			}
			else {
				if (str.empty()) {
					flag = true; // 올바르지 않은 문자열이 있으니까
					if (p[i] == ')') {
						wrong.push(p[i]);
					}
					else {
						if (!wrong.empty()) {
							wrong.pop();
						}
						else { // u: "))((", v: "()"
							v = p.substr(i);
							break;
						}
					}

					// v = p.substr(i+1);  // 올바르지 않은 문자열
					// if(u.size() != p.size())
					//     v = 
				}
				else {
					str.pop();
				}
			}
		}
		if (flag) {
			answer += u.front();
			for (int i = 1; i < u.size() - 1; i++) {
				if (u[i] == ')')
					answer += '(';
				else
					answer += ')';
			}
			answer += u.back();
		}
		else answer += u;

		cnt += u.size();
	}


	return answer;
}