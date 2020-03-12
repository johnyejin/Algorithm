#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
	int answer = 0;  // ���İ� ������ �ִ�    

	// triangle[i][j]�� ���� ������ ��� ����
	for (int i = 1; i < triangle.size(); i++) {
		for (int j = 0; j < triangle[i].size(); j++) {
			// �ڱ��ڽ� ���� �밢���� �ִ� ���� 2�� ���ؼ� ū�� ���ϱ�
			triangle[i][j] += triangle[i - 1][j - 1] > triangle[i - 1][j] ? triangle[i - 1][j - 1] : triangle[i - 1][j];
		}
	}

	// �ٴڿ� �ִ� ������ ���� ū�� answer�� ����
	answer = triangle[triangle.size() - 1][0];
	for (int i = 1; i < triangle[triangle.size() - 1].size(); i++) {
		if (triangle[triangle.size() - 1][i] > answer)
			answer = triangle[triangle.size() - 1][i];
	}

	return answer;
}