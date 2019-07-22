// �׽�Ʈ�� �� ����ߴµ� �ð��ʰ��� �ڵ�
#include <iostream>
#include <vector>
using namespace std;
// n: ����Ʈ ���� / station: ������ ��ġ ����Ʈ ��ȣ / w: ���� ���ްŸ�
int solution(int n, vector<int> stations, int w)
{
	int answer = 0;  // �����ؾ��� ������ ������ �ּڰ�
	int *arr = new int[n];  // ���� ���޵Ǹ� 1

	for (int i = 0; i < n; i++) arr[i] = 0;  // arr 0���� �ʱ�ȭ

	// �� ÷�� ���� ���޵Ǵ� ����Ʈ�� +1
	for (int i = 0; i < stations.size(); i++) {
		for (int j = 0; j <= w; j++) {  // ���ްŸ���ŭ �������� +1
			if (stations[i] - j - 1 < 0) { // ���� ����
				arr[stations[i] + j - 1]++;
			}
			else if (stations[i] + j - 1 >= n) { // ������ ����
				arr[stations[i] - j - 1]++;
			}
			else {
				arr[stations[i] - j - 1]++;
				arr[stations[i] + j - 1]++;
			}
		}
	}

	// for (int i = 0; i < n; i++) cout << arr[i] << " ";
	// cout << "\n";

	int cnt = 0;  // �߰��߰� ���� ���޾ȵǴ� ����Ʈ ��
	int k = 0;    // �߰��߰� ��ġ�� �ʿ��� ������ ��
	for (int i = 0; i < n; i++) {
		if (arr[i] == 0) {
			cnt++;
			if (i == n - 1) {  // ����ó��
				if (cnt % (w * 2 + 1) == 0) k = cnt / (w * 2 + 1);
				else k = cnt / (w * 2 + 1) + 1;
				answer += k;
			}
		}
		else {
			if (cnt % (w * 2 + 1) == 0) k = cnt / (w * 2 + 1);
			else k = cnt / (w * 2 + 1) + 1;
			answer += k;
			// cout << cnt << " / " << k << " / " << answer << endl;
			cnt = 0;
			k = 0;
		}
	}

	return answer;
}