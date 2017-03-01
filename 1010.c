#include<stdio.h>
int main() {
	int num;
	int n,m;
	int i, j, k; 
	scanf("%d", &num);
//n=2, m=4 dp[2][4] = (dp[1][3] + dp[1][2] + dp[1][1])


	while (num-- > 0) {
		int dp[30][30] = { 0, };
		scanf("%d %d", &n, &m);
		for (i = 0; i <= m; i++) {
			dp[1][i] = i;
		}
		for (i = 2; i <= n; i++){
			for (j = i; j <= m; j++){
				for (k = j; k >= i; k--){
					dp[i][j] += dp[i - 1][k - 1];
				}
			}
		}
		printf("%d\n", dp[n][m]);
	}
    return 0;
}