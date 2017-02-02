#include <stdio.h>
#pragma warning(disable:4996)

int min(int a, int b) {
	return (a > b) ? b : a;
}

int main() {
	int r, g, b;
	int num;
	scanf("%d", &num);
	int arr[2][3] = { 0, };
	
	scanf("%d %d %d", &arr[0][0], &arr[0][1], &arr[0][2]);

	for (int i = 1; i < num; i++) {
		scanf("%d %d %d", &r, &g, &b);
		arr[1][0] = min(r + arr[0][1], r + arr[0][2]);
		arr[1][1] = min(g + arr[0][0], g + arr[0][2]);
		arr[1][2] = min(b + arr[0][0], b + arr[0][1]);

		arr[0][0] = arr[1][0];
		arr[0][1] = arr[1][1];
		arr[0][2] = arr[1][2];
	}

	printf("%d", min(min(arr[0][0], arr[0][1]), arr[0][2]));
}