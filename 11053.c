#include <stdio.h>
#include <malloc.h>
#pragma warning(disable:4996)

int main() {
	int* arr;
	int *dp;
	int num;
	scanf("%d", &num);
	arr = (int*)malloc(sizeof(int)*num);
	dp = (int*)calloc(num,sizeof(int)*num);
	for (int i = 0; i < num; i++) {
		scanf("%d", &arr[i]);
	}
	int max = 0;
	for (int i = 0; i < num; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && dp[j + 1]>dp[i]) {
				dp[i] = dp[j] + 1;
			}
		}
	}

	int max = dp[0];
	for (int i = 1; i < num; i++) {
		if (max < dp[i]) max = dp[i];
	}
	
	printf("%d", max);

	free(arr);
	free(dp);
}