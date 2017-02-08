#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
//97, 122
int main() {
	char S[101] = "";
	gets(S);

	int count[26] = { 0, };
	for (int i = 0; i < strlen(S); i++) {
		count[(int)S[i]-97]++;
	}

	for (int i = 97; i <= 122; i++) {
		printf("%d ", count[i-97]);
	}
}