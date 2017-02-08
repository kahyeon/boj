#include <stdio.h>
#pragma warning(disable:4996)

int main() {
	char arr[8][8];
	int count=0;

	for (int i = 0; i < 8; i++) {
		gets(arr[i]);		
	}


	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (arr[i][j] == 'F') {
				if ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1)) {
					count++;
				}

			}
		}
	}
	printf("%d", count);

	return 0;
}