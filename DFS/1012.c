#include <stdio.h>
#pragma warning(disable:4996)
#include<malloc.h>

int arr[51][51];
void DFS(int x, int y);
int m, n, k;

int main() {
	int num;
	scanf("%d", &num);
	
	int count; 

	for (int i = 0; i < num; i++) {
		count = 0;
		scanf("%d %d %d", &m, &n, &k);
		int a, b;

		for (int j = 0; j < k; j++) {
			scanf("%d %d", &a, &b);
			arr[a][b] = 1;
		}

		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {
				if (arr[j][k] == 1) {
					count++;
					DFS(j, k);
				}
			}
		}

		printf("%d\n", count);
	}
	return 0;
}

void DFS(int x, int y) {
	arr[x][y] = 0;
	if (x < m - 1 && arr[x + 1][y] == 1) {
		DFS(x + 1, y);
	}
	if (x > 0 && arr[x - 1][y] == 1) {
		DFS(x - 1, y);
	}
	if (y < n - 1 && arr[x][y + 1] == 1) {
		DFS(x, y + 1);
	}
	if (y > 0 && arr[x][y - 1] == 1) {
		DFS(x, y - 1);
	}
}