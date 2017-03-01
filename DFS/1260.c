#include <stdio.h>
#define MAX 1001
#pragma warning(disable:4996)

int queue[MAX];
int graph[MAX][MAX];
int visit[MAX] = { 0, };//방문:1
int n, m, v;
int front, rear;

void DFS(int cur);
void BFS();
void enqueue(int data);
int dequeue();

void DFS(int cur) {//cur: 현재 노드
	visit[cur] = 1;
	printf("%d ", cur);
	for (int i = 1; i <= n; i++) {
		if (graph[cur][i] == 1 && visit[i] == 0) {
			DFS(i);
		}
	}
}



void BFS() {
	enqueue(v);
	visit[v] = 1;
	while ((v=dequeue()) != -1) {
		printf("%d ", v);
		for (int i = 1; i <= n; i++) {
			if (graph[v][i] == 1 && visit[i] == 0) {
				enqueue(i);
				visit[i] = 1;
			

			}
		}
		
	}
}

int dequeue() {
	if (front >= rear) {//비어있다
		return -1;
	}
	else {
		return queue[front++];
	}

}

void enqueue(int data) {
	if (rear >= MAX) {
		return;
	}
	queue[rear++] = data;
}
int main() {
	int a, b;

	scanf("%d %d %d", &n, &m, &v);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		graph[a][b] = graph[b][a] = 1;
	}

	DFS(v);
	printf("\n");
	for (int i = 1; i <= n; i++) {
		visit[i] = 0;
	}
	BFS();
}