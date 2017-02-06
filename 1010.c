#include <stdio.h>
#pragma warning(disable:4996)

int main(){
	int num,n,m;
	scanf("%d", &num);

	
	for (int i = 0; i < num; i++) {
		int dp[31][31] = { 0, };
		scanf("%d %d", &n, &m);
		for (int j = 0; j < m; i++) {
			dp[1][j] = j;
		}
		for (int j = 2; j <= n; j++) {
			for (int k = j; k <= m; k++) {
				for (int l = k; l >= j; l--) {
					dp[j][k] += dp[j - 1][l - 1];
				}
			}
		}
		printf("%d\n", dp[n][m]);
		
	}

	return 0;
}