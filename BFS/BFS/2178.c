#include <stdio.h>
#pragma warning(disable: 4996)
int map[500][500];
int visit[500][500];


typedef struct pos {
	int x;
	int y;
}Queue;

Queue queue[250000];

int front, rear, top;
int N, M;

void enqueue(int x, int y){
	Queue q;
	q.x = x;
	q.y = y;
	queue[rear++] = q;
}
Queue dequeue(){
	Queue q = queue[front++];
	return q;
}

int isEmpty(){
	if (front == rear)
		return 1;
	else
		return 0;
}
int posX[4] = { 0,1,0,-1 };
int posY[4] = { 1,0,-1,0 };

int count = 0;

void bfs()
{
	int nextX, nextY, x, y;

	while (!isEmpty()) {

		Queue q = dequeue();
		x = q.x;
		y = q.y;


		for (int i = 0; i < 4; i++)	{
			nextX = x + posX[i];
			nextY = y + posY[i];
			if (nextX >= 0 && nextX < M && nextY >= 0 && nextY < N){
				if (map[nextX][nextY] == 1 && visit[nextX][nextY] == 0){
					visit[nextX][nextY] = visit[x][y] + 1;
					enqueue(nextX, nextY);
				}
			}
		}
	}
}
int main(){
	scanf("%d %d", &M, &N);	//4,6
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	enqueue(0, 0);
	visit[0][0] = 1;
	bfs();
	printf("%d", visit[M - 1][N - 1]);

	return 0;
}
