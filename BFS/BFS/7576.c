#include <stdio.h>
#pragma warning(disable: 4996)
int map[1001][1001];
int visit[1001][1001];


int posX[4] = { 0,1,0,-1 };
int posY[4] = { 1,0,-1,0 };

int M, N;
int count = 0;

typedef struct pos {
	int x;
	int y;
	//int time;
}Queue;

Queue queue[1000000];

int front, rear, top;
int N, M,count;
int flag = 100000;
void enqueue(int x, int y)
{
	Queue q;
	q.x = x;
	q.y = y;
	
	queue[rear++] = q;
}
Queue dequeue()
{
	Queue q = queue[front++];
	return q;
}


int isEmpty()
{
	if (front == rear)
		return 1;
	else
		return 0;
}

int bfs() {
	int y, x;
	int nextX;
	int nextY;
	while (isEmpty())
	{
		Queue temp = dequeue();
		x = temp.x;
		y = temp.y;

		for (int i = 0; i < 4; i++)	{
			nextX = x + posX[i];
			nextY = y + posY[i];
			if (nextX >= 0 && nextX < M && nextY >= 0 && nextY < N)	{
				if (map[nextX][nextY] == 0)
				{
					map[nextX][nextY] = map[x][y] + 1;
					enqueue(nextX, nextY);
					count--;
				}
			}
		}
	}
	if (count == 0)
		return map[x][y] - flag - 1;
	return -1;
}
int main() {
	scanf("%d %d", &M, &N);	
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &map[i][j]);
			if (map[i][j] == 0) count++;
			else if (map[i][j] == 1) {
				map[i][j] += flag;
				enqueue(i, j);
			}
		}
	}

	printf("%d", bfs());
		
}