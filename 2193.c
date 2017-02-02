#include <stdio.h>
#include <malloc.h>
#pragma warning(disable:4996)

int main() {
	int arr[2];
	int num, temp,i;
	scanf("%d", &num);
	//arr = (int*)malloc(sizeof(int)*(num-1));
	arr[0] = 1;
	arr[1] = 0;
	for (i = 3; i <= num; i++) {
		temp = arr[1];
		arr[1] = arr[0];
		arr[0] = temp + arr[0];

	}
	
	printf("%d", arr[1]+arr[0]);

	return 0;
	
}