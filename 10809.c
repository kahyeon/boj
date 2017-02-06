#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int main() {
	char input[101];
	scanf("%s", input);
	int i, j;
	int count;

	//for(int i = )
	for (i = 97; i <= 122; i++) {
		
		for (j = 0; j < strlen(input); j++) {
			count = 0;
			if ((int)input[j] == i) {
				count = j;
				break;
			}
		}
		if (j==strlen(input)&&count == 0) count = -1;
		printf("%d ",count);
	}
	
	
}