#include<stdio.h>
int main() {
	int i,n,j=0;	//j function is counting number.
	for (int n = 101; n < 200; n++) {
		for (i = 2; i < n ; i++) {
			if (n % i == 0 && n!=i) {
				//printf("This data is not true data.\n");
				break;
			}
		}
		if (i == n) {
			printf("This true data is %d\n", n);
			j++;
		}
	}
	printf("the total numbers is %d", j);
	return 1;
}