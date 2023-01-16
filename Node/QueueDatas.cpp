#include<stdio.h>
int main() {
	int array[4][5];
	printf("Please insert four grades of class for three students.\n");
	for (int i = 0; i < 3; i++) {
		scanf_s("%d %d %d %d", &array[i][0], &array[i][1], &array[i][2], &array[i][3]);
		array[i][4] = array[i][0] + array[i][1] + array[i][2] + array[i][3];
	}
	printf("\n");
	for (int i = 0; i < 3; i++)
		printf("%d %d %d %d %d\n", array[i][0], array[i][1], array[i][2], array[i][3], array[i][4]);
	for (int i = 0; i < 5; i++) {
		array[3][i] = (array[0][i] + array[1][i] + array[2][i])/3;
	}
	for (int i = 0; i < 4; i++)
		printf("%d %d %d %d %d\n", array[i][0], array[i][1], array[i][2], array[i][3], array[i][4]);
	return 1;
}