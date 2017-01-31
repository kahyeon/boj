#include <stdio.h>
#pragma warning(disable:4996)

int arr[40][2] = { {1,0},{0,1}, };
int last = 2;

void fibonacci(int fibo) {
	if(fibo!=1 && fibo!=0){
		for (int i = last; i <= fibo;i++){
			arr[i][0] = arr[i-1][0]+arr[i-2][0];
			arr[i][1] = arr[i - 1][1] + arr[i - 2][1];
		}
		last = fibo;
	}
	
}

int main() {
	int num;
	scanf("%d", &num);
	int fibo;
	for (int i = 0; i < num; i++) {
		scanf("%d", &fibo);
		fibonacci(fibo);

		printf("%d %d\n", arr[fibo][0], arr[fibo][1]);

	}
}