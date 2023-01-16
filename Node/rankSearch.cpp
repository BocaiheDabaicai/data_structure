#include<stdio.h>
#define N 10
int main() {
	int arr[N];
	int mid,left=0,right=N-1,target;
	printf("Please import ten datas to the matrix.\n");
	for(int i=0;i<N;i++)
		scanf_s("%d", &arr[i]);
	for (int i = 0; i < N ; i++)
		printf("%d ", arr[i]);
	printf("\nPlease tell me what is your target of interge data.\n");
	scanf_s("%d", &target);
	while (left<=right) {
		mid = (left + right) / 2;
		if (arr[mid] == target) {
			printf("The number rank is  %d  .\n", mid+1);
			break;
		}
		if (arr[mid] > target) right--;
		else if (arr[mid] < target) left++;
	}
	if(left > right)
		printf("Sorry,Finding was failed .\n");
	return 1;
}