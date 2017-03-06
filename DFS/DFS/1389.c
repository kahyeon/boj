#include<stdio.h>
#pragma warning(disable: 4996)
#define MIN(a,b) a<b?a:b
int main() {
	int n, m;
	int friend[101][101];

	scanf("%d %d", &n, &m);
	int a, b;
	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			friend[i][j] = 5000;
		}
		friend[i][i] = 0;
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		friend[a][b] = friend[b][a] =1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (friend[i][k] + friend[k][j] < friend[i][j]) {
					friend[i][j] = friend[i][k] + friend[k][j];
				}
			}
		}
	}
	int max = 5000;
	int result = 0;

	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			sum += friend[i][j];
		}
		if (sum < max) {
			max = sum;
			result = i;
		}
		
	}
	printf("%d", result);
	return 0;
}