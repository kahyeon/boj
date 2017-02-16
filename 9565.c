#include <stdio.h>
#include <malloc.h>
#pragma warning(disable:4996)

int MAX(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int pos[4][2] = {{1,1},{1,2},{-1,1},{-1,2}};
	int num;
	scanf("%d", &num);

	int column;
	scanf("%d", &column);

	int** sticker;
	int** dp;
	sticker = (int**)malloc(sizeof(int*)*2);
	dp = (int**)malloc(sizeof(int*)*2);
	
	for (int i = 0; i < 2; i++) {
		sticker[i] = (int*)malloc(sizeof(int)*column);
		for (int j = 0; j < column; j++) {
			scanf("%d", &sticker[i][j]);
		}
		dp[i] = (int*)malloc(sizeof(int)*column+1);

	}

	dp[0][0] = sticker[0][0];
	dp[0][1] = sticker[1][0];
	for (int j = 2; j <= column+1; j++) {
		dp[0][j] = MAX(MAX(dp[0][j - 1], dp[1][j - 1] + sticker[0][j]), dp[1][j - 2] + sticker[0][j]);
		dp[1][j] = MAX(MAX(dp[1][j - 1], dp[0][j - 1] + sticker[1][j]), dp[0][j - 2] + sticker[1][j]);
		
	}
	printf("%d %d", dp[0][column+1], dp[1][column+1]);

	return 0;
}