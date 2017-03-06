#include<stdio.h>
#pragma warning(disable: 4996)
#define MAX(a,b) (a>b)? a:b
int pos[4][2] = { { -1, 0 },{ 0, -1 },{ 1, 0 },{ 0, 1 } };
char arr[21][21];
int r, c;
int count=0;
int visit[26];

void dfs(int preX, int preY, int next)
{
	count = MAX(next, count);

	for (int i = 0; i < 4; i++)
	{
		int x = preX + pos[i][0];
		int y = preY + pos[i][1];
		
		if (x >= 0 && y >= 0 && x < r&& y < c) {
			if (visit[arr[x][y] - 65] == 0) {
				visit[arr[x][y] - 65] = 1;
				dfs(x, y, next + 1);
				visit[arr[x][y] - 65] = 0;
			}
				
		}
	}
}


int main() {
	
	scanf("%d %d", &r, &c);
	getchar();
	for (int i = 0; i < r; i++) {
		scanf("%s", &arr[i]);
	}

	visit[arr[0][0] - 65] = 1;
	dfs(0, 0, 1);
	printf("%d", count);

	return 0;

}