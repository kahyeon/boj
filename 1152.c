#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)

int getInput(int *cnt) {
	char str[1000000] = "";
	getchar();
	//scanf("%s", str);
	gets(str);
	int len = strlen(str);
	int i = 0;
	int flag = 1;

	for (i = 0; i<len; i++) {//1. ���ڰ� ������ ���� ������ ���, ���� �ʴ´�.
		if ((int)str[i] == 32) {
			flag = 1;
		}
		else{
			if(flag!=0){
				(*cnt)++;
				flag = 0;
			}
		}
		
	}

	return *cnt;
}

int main() {
	int cnt = 0;
	printf("%d", getInput(&cnt));
	return 0;
}