#include<stdio.h>
#define N 10
typedef struct AB {
	int i;
	float j;
	bool p;
}AB;
void insertAB(AB &x,int a, float b, bool c);
void ToString(AB a);
int main() {
	AB a;
	insertAB(a, 1, 1.1, true);
	ToString(a);
	return 1;
}
void insertAB(AB &x,int a, float b, bool c)
{
	x.i = a;
	x.j = b;
	x.p = c;
}
void ToString(AB a)
{
	printf("integer is: %d\nfloat is: %2.2f\nbool is: %d", a.i, a.j, a.p);
}
