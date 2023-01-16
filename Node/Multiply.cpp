#include<stdio.h>
int main() {
	int n,sum=1;
	printf("setting the oringinal multi-data\n");
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++) {
		sum *= i;
	}
	printf("The final result is %d", sum);
	return 1;
}