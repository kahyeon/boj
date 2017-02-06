
#include <stdio.h>
#include <malloc.h>
#pragma warning(disable:4996)

int main() {
	int N, M,i,j,x,y,num;
	int **arr;
	int result = 0;
	scanf("%d %d",&N, &M);

	arr = (int**)malloc(sizeof(int*)*N);
	for (int count = 0; count < N; count++) {
		arr[count] = (int*)malloc(sizeof(int)*M);
		for (int u = 0; u < M; u++) {
			scanf("%d", &arr[count][u]);
		}
	}

	scanf("%d", &num);
	for (int count = 0; count < num; count++) {
		scanf("%d %d %d %d", &i, &j, &x, &y);
		for (int w = i - 1; w < x; w++) {
			for (int e = j - 1; e < y; e++) {
				result += arr[w][e];

			}
		}
		
		printf("%d", result);
		result = 0;
	}

	for (int count = 0; count < N; count++) {
		free(arr[count]);
	}
	free(arr);

}


