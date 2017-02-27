#include <stdio.h>
#include<malloc.h>
#pragma warning(disable:4996)

int *tree;
int *exist;
int num;

void start(int startIndex) {
	
	for (int i = 0; i < num; i++) {
		if (tree[i] == startIndex) {
			exist[i] = 1;
			start(i);
		}
	}
}

int main() {
	int i;
	scanf("%d", &num);

	
	tree = (int*)malloc(sizeof(int)*num);
	exist = (int*)calloc(1,sizeof(int)*num);

	for (i = 0; i < num; i++) {
		scanf("%d", &tree[i]);
		if (tree[i] != -1) exist[tree[i]] = 1;
		//else exist[i] = 1;

	}
	int del;
	scanf("%d", &del);
	exist[del] = 1;
	if(exist[del] == 1) start(del);

	int count = 0;

	for (i = 0; i < num; i++) {
		if (exist[i] ==0) count++;
	}
	printf("%d", count);
	free(tree);
    free(exist);
	return 0;
}