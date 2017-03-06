#include<stdio.h>
#pragma warning(disable: 4996)

int pos[4][2] = { { -1, 0 },{ 0, -1 },{ 1, 0 },{ 0, 1 } };
char arr[26][26];
int result[100];
int num;
int count=2;

void dfs(int preX, int preY) {
	arr[preX][preY] = count + '0';
	result[count] += 1;
	for (int i = 0; i < 4; i++) {
		int x = preX + pos[i][0];
		int y = preY + pos[i][1];
		if (x >= 0 && y >= 0 && x < num && y < num) {
			if (arr[x][y] == '1') {
				dfs(x, y);
			}
		}
	}
}

int main() {
	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		scanf("%s", arr[i]);
	}

	for (int i = 0; i < num; i++)	{
		for (int j = 0; j < num; j++) {
			if (arr[i][j] == '1' ) {
				dfs(i, j);
				count++;
			}
		}
	}
	

	printf("%d\n", count - 2);

	for (int i = 2; i < count; i++) {
		for (int j = i + 1; j < count; j++) {
			if (result[i] > result[j]) {
				int tmp = result[j];
				result[j] = result[i];
				result[i] = tmp;
			}
		}
	}

	for (int i = 2; i < count; i++) {
		printf("%d\n", result[i]);
	}
	return 0;
	

}