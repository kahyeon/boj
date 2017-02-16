#include<stdio.h>
#pragma warning(disable:4996)
#define MAX(a,b) a>b?a:b

int main() {
	int num;
	int arr[1001] = { 0, };
	int dp[1001] = { 0, };

	scanf("%d", &num);
	for (int i = 1; i < num+1; i++) {
		scanf("%d", &arr[i]);
	}

	dp[0] = 0;
	dp[1] = arr[1];
	for (int i = 2; i <= num; i++) {
		dp[i] = dp[i - 1] + arr[1];
		for (int j = 2; j <= i; j++) {
			dp[i] = MAX(dp[i - j] + arr[j], dp[i]);
		}
	}
	printf("%d", dp[num]);
}