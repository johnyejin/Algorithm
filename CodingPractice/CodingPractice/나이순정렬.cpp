// cin -> scanf로 바꿔주고 arr배열을 vector -> 구조체 배열로 바꾸니까 성공
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
	int n; // 회원수
	scanf("%d", &n);
	// 나이순, 가입순으로 정렬
	user arr[100000];

	for (int i = 0; i < n; i++) {
		scanf("%d %s", &arr[i].age, &arr[i].name);
	}
	// 같은게 있는 경우 정렬하기 전의 순서 유지
	stable_sort(&arr[0], &arr[n], cmp);

	for (int i = 0; i < n; i++) {
		printf("%d %s\n", arr[i].age, arr[i].name);
	}
}
