// 테스트 5번만 실패
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
	int answer = 1001;
	int slice = 1; // 자를 단위

	while (slice <= s.size() / 2) {
		string ans = "";
		int cnt = 0;
		string tmp1, tmp2;

		for (int i = 0; i < s.size(); i += slice) {
			cnt++;

			// slice만큼 자르기
			tmp1 = s.substr(i, slice);
			if (i + slice >= s.size())
				tmp2 = "0";
			else
				tmp2 = s.substr(i + slice, slice);

			if (tmp1.compare(tmp2) != 0) {
				if (cnt == 1)
					ans += tmp1;
				else
					ans += to_string(cnt) + tmp1;
				cnt = 0;
			}
		}
		// cout<<ans<<endl;
		if (ans.size() < answer)
			answer = ans.size();

		slice++;
	}



	return answer;
}