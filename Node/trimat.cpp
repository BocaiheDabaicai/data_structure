#include<iostream>
#define N 15
typedef struct trimat {
	int val;
	int i, j;
}trimat;
int cratetrimat(trimat a[], int ab[3][4], int m, int n);
int ToString(trimat a[]);
int Tprintf(trimat a[]);
int main() {
	//int trimat[N][3];
	trimat a[N];
	int ab[3][4] = { {1,0,3,4},{2,0,0,7},{1,4,0,3} };
	cratetrimat(a, ab, 3, 4);
	//ToString(a);
	Tprintf(a);
}
int cratetrimat(trimat a[], int ab[3][4], int m, int n)
{
	int k=1;
	for(int i=0;i<m;++i)
		for(int j=0;j<n;++j)
			if (ab[i][j] != 0) {
				a[k].val = ab[i][j];
				a[k].i = i;
				a[k].j = j;
				//printf("%d,%d,%d\n", a[k].val, a[k].i, a[k].j);
				++k;
			}
	a[0].val = k - 1;
	a[0].i = m;
	a[0].j = n;
	//printf("%d,%d,%d\n", a[0].val, a[0].i, a[0].j);
	return 0;
}
int ToString(trimat a[])
{
	for (int i1 = 1; i1 < a[0].val; i1++)
		printf("%d,%d,%d\n", a[i1].val, a[i1].i, a[i1].j);
	return 0;
}
int Tprintf(trimat a[])
{
	int k = 1;
	for (int i = 0; i < a[0].i; ++i) {
		for (int j = 0; j < a[0].j; ++j) {
			if (i == a[k].i && j == a[k].j) {	//把对应行、列标的打印出来，其余位置补0
				printf("%d ", a[k].val);
				++k;
			}
			else
				printf("0 ");
		}
		printf("\n");
	}
	return 0;
}
