#include <stdio.h>
#pragma warning(disable:4996)ㄹㅈㄱ

int fiboCount(int fibo,int* num1, int* num2);

int main() {
	int num, fibo;
	int count0 = 0;
	int count1 = 0;
	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		scanf("%d", &fibo);
		fiboCount(fibo, &count0, &count1);
		printf("%d %d\n", count0, count1);
		count0 = 0;
		count1 = 0;
	}
}

int fiboCount(int fibo, int *num1, int *num2) {
	if (fibo == 0) (*num1)++;
	else if (fibo == 1) (*num2)++;
	else return fiboCount(fibo - 1,num1,num2) + fiboCount(fibo - 2, num1, num2);
}