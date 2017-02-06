#include<stdio.h>
#include<malloc.h>
#include<string.h>
#pragma warning(disable:4996)

int main() {
	int num;
	char **arr;
	scanf("%d", &num);
	arr = (char**)malloc(sizeof(char*)*num);
	for (int i = 0; i < num; i++) {
		arr[i] = (char*)malloc(sizeof(char) * 51);
		scanf("%s", arr[i]);
		
	}

	int j, k;
	char copy[51] = "";

	for (int i = 0; i < strlen(arr[0]); i++) {
		copy[i] = arr[0][i];
		copy[i + 1] = '\0';
	}
	for (j = 1; j < num; j++) {
		for (k = 0; k < strlen(arr[0]);k++) {
			if (arr[j][k] == copy[k]){
				copy[k] = arr[j][k];				
			}
			else {
				copy[k]= '?';
			}
		}
	}
	for (int i = 0; i < strlen(arr[0]); i++) {
		if(i<k) printf("%c",copy[i]);
		
	}

}