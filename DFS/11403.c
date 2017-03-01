#include <stdio.h>
#pragma warning(disable:4996)

int graph[100][100];
int result[100][100];
int visit[100] = { 0, };
int n;

void DFS(int start);
void init();

int main() {
	//int input;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &graph[i][j]);
			
		}
	}

	for (int i = 0; i < n; i++) {
		init();
		DFS(i);
		for (int j = 0; j < n; j++) {
			result[i][j] = visit[j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}

	return 0;
}

void init() {
	for (int i = 0; i<n; i++)
		visit[i] = 0;
}

void DFS(int start) {
	
	for (int i = 0; i < n; i++) {
		if (graph[start][i] == 1 && visit[i] == 0) {
			visit[i] = 1;
			DFS(i);
		}
	}

}