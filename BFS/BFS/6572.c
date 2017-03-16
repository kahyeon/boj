#include <stdio.h>
#pragma warning(disable: 4996)

#define SIZE 301

int main() {
	int num, l;
	int start[2], target[2];
	int map[SIZE][SIZE] = { 0, };
	int visited[SIZE][SIZE];
	int queue[SIZE][2] = { 0, };
	int front, rear;
	int dx[8] = { 2,2,-2,-2,1,-1,-1,1 };
	int dy[8] = { -1,1,1,-1,2,2,-2,-2 };

	scanf("%d", &num);
	for (int t = 0; t<num; t++) {
		scanf("%d", &l);
		scanf("%d %d", &start[0], &start[1]);
		scanf("%d %d", &target[0], &target[1]);
		
		//ÃÊ±âÈ­
		rear = front = 0;
		for (int i = 0; i<l; i++) {
			for (int j = 0; j<l; j++) {
				map[i][j] = 0;
				visited[i][j] = 0;
			}
		}

		queue[rear][0] = start[0];
		queue[rear++][1] = start[1];
		
		visited[start[0]][start[1]] = 1;
		map[start[0]][start[1]] = 0;

		while (front != rear) {
			int x = queue[front][0];
			int y = queue[front++][1];

			for (int next = 0; next<8; next++) {
				int nextX = x + dx[next];
				int nextY = y + dy[next];

				if (nextX<l && nextY<l && nextX >= 0 && nextY >= 0) {
					if (visited[nextY][nextX] == 0) {
						queue[rear][0] = nextX;
						queue[rear++][1] = nextY;
						
						visited[nextX][nextY] = 1;
						map[nextX][nextY] = map[x][y] + 1;
					}
				}
			}

		}
		
		printf("%d\n", map[target[0]][target[1]]);
	}
	
	return 0;
}