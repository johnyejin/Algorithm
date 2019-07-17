#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";

	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());

	for (int i = 0; i < participant.size(); i++) {
		if (participant[i] != completion[i]) {
			return participant[i];
		}
	}

	return answer;

	/*for (int i = 0; i < participant.size(); i++) {
		for (int j = 0; i < completion.size(); j++) {
			if (participant.at(i) == completion.at(j)) {
				cout << participant.at(i) << endl;
				participant.erase(participant.begin() + (i));
				break;
			}
		}
	}*/

	 /*for(vector<string>::iterator it = participant.begin(); it != participant.end();) {
	     for(int i = 0; i<completion.size(); i++) {
			 if ((*it).data() == completion.at(i)) {

			 }
	     }
	 }

	answer = participant.front();*/

}