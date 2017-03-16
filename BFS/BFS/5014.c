#include <stdio.h>
#pragma warning(disable: 4996)

int queue[1000001];
int dist[1000001];
int check[1000001];

int main() {
	
	int F, S, G, U, D;
	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
	
	int front, rear;
	front = rear = 0;
	queue[rear++] = S;
	check[S] = 1;
	while (front < rear) {
		int now = queue[front++];
		
		if (now + U <= F && check[now + U] == 0) {
			check[now + U] = 1;
			queue[rear++] = now + U;
			dist[now + U] = dist[now] + 1;
		}
		
		if (now - D >= 1 && check[now - D] == 0) {
			check[now - D] = 1;
			queue[rear++] = now - D;
			dist[now - D] = dist[now] + 1;
		}
	}
	if (check[G] == 0) {
		printf("use the stairs\n");
	}
	else {
		printf("%d\n", dist[G]);
	}
	return 0;
}