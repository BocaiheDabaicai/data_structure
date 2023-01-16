#include<iostream>
#define M 3
#define N 3
//矩阵转置、相加、相乘
typedef struct matrix {
	int matr[M][N];
}matrix;
int initmatrix(matrix& a, int ab[M][N]);
int trsmat(matrix& a, matrix& b, int m, int n);
int addmat(matrix a, matrix b, matrix& c);
int mutmat(matrix a, matrix b, matrix& c);
int Mprintf(matrix a);
int main() {
	matrix a,b,c;
	int b1[M][N] = { {2,3,4},{5,7,9},{1,6,8} };
	int b2[M][N] = { {1,8,9},{2,5,7},{6,4,3} };
	initmatrix(a, b1);
	initmatrix(b, b2);
	Mprintf(a);
	Mprintf(b);
	printf("-------------------\n");
	//trsmat(a, b, M, N);
	//addmat(a, b, a);
	mutmat(a, b, c);
	//Mprintf(a);
	//Mprintf(b);
	Mprintf(c);
	return 1;
}
int initmatrix(matrix& a, int ab[M][N])
{
	for (int i = 0; i < M; ++i)
		for (int j = 0; j < N; ++j)
			a.matr[i][j] = ab[i][j];
	return 0;
}
int trsmat(matrix& a, matrix& b, int m, int n)
{
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			b.matr[i][j] = a.matr[j][i];
	return 0;
}
int addmat(matrix a, matrix b, matrix& c)
{
	for (int i = 0; i < M; ++i)
		for (int j = 0; j < N; ++j)
			c.matr[i][j] = a.matr[i][j] + b.matr[i][j];
	return 0;
}
int mutmat(matrix a, matrix b, matrix& c)
{
	for (int i = 0; i < M; ++i) 
		for (int k = 0; k < N; ++k) {	//上面两层循环表明矩阵的行列，而下面的循环变量表示两个矩阵的中间变量
			c.matr[i][k] = 0;
			for (int j = 0; j < N; ++j)
				c.matr[i][k] += a.matr[i][j] * b.matr[j][k]; //C ixk,A i*j,B j*k
		}

	return 0;
}
int Mprintf(matrix a)
{
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j)
			printf("%d ", a.matr[i][j]);
		printf("\n");
	}
	return 0;
}
