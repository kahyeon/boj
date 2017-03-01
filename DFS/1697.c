#include <stdio.h>
#pragma warning(disable:4996)
#include<malloc.h>

int dequeue();
void enqueue(int data);
int front, rear;

int* dp;
int* queue;
int n, k;

int hide() {
	int x;
	enqueue(n);
	while ((x = dequeue()) != -1 || x==k) {
		if (x - 1 > 0 && dp[x - 1] == 0) {
			enqueue(x - 1);
			dp[x - 1] = dp[x]+1;
		}
		if (x + 1 <= k && dp[x + 1] == 0) {
			enqueue(x + 1);
			dp[x + 1] = dp[x] + 1;
		}
		if (x * 2 <= k && dp[x * 2] == 0) {
			enqueue(x * 2);
			dp[2 * x] = dp[x] + 1;
		}

	}
	return dp[k];
}

int main() {
	scanf("%d %d", &n, &k);

	dp = (int*)malloc(sizeof(int)*(k + 1));
	queue = (int*)malloc(sizeof(int)*(k + 1));

	for (int i = 0; i < k + 1; i++) {
		dp[i] = 0;
		queue[i] = 0;
	}
	printf("%d", hide());

	free(dp);
	free(queue);

	return 0;
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
	if (rear >= k) {
		return;
	}
	queue[rear++] = data;
}
