#include <stdio.h>
#include <string.h>
#include<stdlib.h>

#pragma warning(disable:4996)



//97, 122
int main() {
	char S[101] = "";
	gets(S);

	int count[26] = { 0, };
	for (int i = 0; i < strlen(S); i++) {
		if(S[i]>='A' && S[i]<='Z') count[(int)S[i] - 65]++;
		else count[(int)S[i] - 97]++;
	}

	int index = 0;
	int max = 0;
	int flag = 0;
	for (int i = 0; i <= 26; i++) {
		if (count[i] > max) {
			max = count[i];
			index = i;
			flag = 0;
		}
		else if (count[i] == max) {
			flag = 1;
		}
	}

	if (flag ==1 ) printf("?");
	else {
			printf("%c", index+65);
	}
}