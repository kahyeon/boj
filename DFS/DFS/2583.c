#include<stdio.h>
#pragma warning(disable: 4996)

int pos[4][2] = { { -1, 0 },{ 0, -1 },{ 1, 0 },{ 0, 1 } };
int arr[101][101];
int visit[101][101];
int space[101];
int count; 
int m, n, k;

void dfs(int preX, int preY) {
	visit[preX][preY] = 1;
	space[count]++;
	for (int i = 0; i < 4; i++) {
		int x = preX + pos[i][0];
		int y = preY + pos[i][1];

		if (x >= 0 && y >= 0 && x < m && y < n) {
			if (visit[x][y] == 0 && arr[x][y] == 0) {
				dfs(x, y);
			}
		}
	}
}


int main() {
	scanf("%d %d %d", &m, &n, &k);
	int leftX, leftY, rightX, rightY;
	for (int i = 0; i < k; i++) {
		scanf("%d %d %d %d", &leftX, &leftY, &rightX, &rightY);
		for (int j = leftY; j < rightY; j++) {
			for (int k = leftX; k < rightX; k++) {
				arr[j][k] = 1;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j] == 0 && arr[i][j] == 0) {
				dfs(i, j);
				count++;
			}
		}
	}

	printf("%d\n", count);

	for (int i = 0; i < count; i++) {
		for (int j = i+1; j < count; j++) {
			if (space[i] > space[j]) {
					int tmp = space[j];
					space[j] = space[i];
					space[i] = tmp;
			}
		}
		
	}
	for (int i = 0; i < count; i++){
		printf("%d ", space[i]);
	}
	

}