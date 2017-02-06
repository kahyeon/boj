#include <stdio.h>
#pragma warning(disable:4996)

int max(int a, int b) {
	return (a > b) ? a : b;
}

int main() {
	int dp[501][501] = { 0, };
	int num;
	int arr[501][501] = { 0, };

	scanf("%d", &num);

	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= i; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	dp[1][1] = arr[1][1];
	for (int i = 2; i <= num; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1) {
				dp[i][j] = dp[i - 1][j] + arr[i][j];
			}
			else if (j == i) {
				dp[i][j] = dp[i - 1][j - 1] + arr[i][j];
			}
			else {
				dp[i][j] = arr[i][j] + max(dp[i - 1][j], dp[i - 1][j - 1]);
			}
		}
	}
	int maxNum = dp[num][1];
	for (int i = 2; i <= num; i++) {
		if (dp[num][i] > maxNum) {
			maxNum = dp[num][i];
		}
	}
	printf("%d", maxNum);

	return 0;
}