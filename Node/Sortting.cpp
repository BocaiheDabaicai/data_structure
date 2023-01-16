#include<stdio.h>
int main() {
	int array[6],temp;
	printf("Please insert six numbers of integer.\n");
	for(int i=0;i<6;i++)
		scanf_s("%d", &array[i]);
	for (int i = 0; i < 6; i++)
		printf("%d ", array[i]);
	printf("\n");
	for (int i = 0; i < 6; i++) {
		for (int j = i + 1; j < 6; j++) {
			if (array[i] > array[j]) {
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
	printf("The final result is: \n");
	for (int i = 0; i < 6; i++)
		printf("%d ", array[i]);
	return 1;
}