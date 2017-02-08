#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
//97, 122
int main() {
	char S[101] = "";
	gets(S);
	int index = 0;
	while (S[index] != NULL) {
		index++;
	}

	printf("%d", index);
}