#include <stdio.h>
#include <malloc.h>
#pragma warning(disable:4996)

int arr[10000001] = { 0, };

void count(int n){
	//int temp;

	//arr[1] = 0
	for (int i = 2; i <= n;i++){
		//n-1
		arr[i] = arr[i - 1] + 1;
		if (n % 2 == 0) {//arr[4] , 4->2->1, 4->3->2->1, 4->3->1, 
						 //arr[2] = 1
						 //temp = arr[i / 2] + 1;
			if (arr[i / 2] + 1 < arr[i]) arr[i] = arr[i / 2] + 1;

		}
		if (i % 3 == 0) {//arr[3]의 경우, 2->1  ->1  두 가지 있는데, 1이 더 짧음.
			//temp = arr[i / 3] + 1;
			if (arr[i / 3] + 1 < arr[i]) arr[i] = arr[i / 3] + 1;//arr[3] = arr[1]+1
		}
		
	}

}

int main() {
	int num;
	scanf("%d", &num);
	//arr = (int*)calloc(num + 1,sizeof(int));
	
	count(num);
	printf("%d", arr[num]);
	//free(arr);

	return 0;
}