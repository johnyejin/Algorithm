// cin -> scanf�� �ٲ��ְ� arr�迭�� vector -> ����ü �迭�� �ٲٴϱ� ����
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

struct user {
	int age;
	char name[101];
};

bool cmp(user a, user b) {
	return a.age < b.age;
}

int main() {
	int n; // ȸ����
	scanf("%d", &n);
	// ���̼�, ���Լ����� ����
	user arr[100000];

	for (int i = 0; i < n; i++) {
		scanf("%d %s", &arr[i].age, &arr[i].name);
	}
	// ������ �ִ� ��� �����ϱ� ���� ���� ����
	stable_sort(&arr[0], &arr[n], cmp);

	for (int i = 0; i < n; i++) {
		printf("%d %s\n", arr[i].age, arr[i].name);
	}
}
