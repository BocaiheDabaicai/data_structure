#include<iostream>
#define N 10
typedef struct sqlist {	//顺序表的定义
	int data[N];
	int lenght;
}sqlist;
typedef struct Node {	//单链表的定义
	int data;
	struct Node* next;
}Node;
typedef struct DNode {	//双链表的定义
	int data;
	struct DNode* piror;
	struct DNode* next;
}DNode;
int ToString(sqlist E);
int initList(sqlist &E);
int initList(sqlist& E, int a[], int n);
int getElem(sqlist E, int p, int& e);
int findElem(sqlist E, int x);
int sqlistInsert(sqlist& E, int x, int i);
int compare(sqlist E, int i);
int deleteElem(sqlist& E, int& x, int p);
int reverse(int x[], int left, int right, int k);
int movetoEnd(int x[], int n, int k);
int movetoP(int x[], int n, int p);
int SortingAandB(sqlist& E, int n, int m);
int main() {
	sqlist a;
	int x[] = { 2,3,5,1,4,6,8 },y;
	initList(a, x, 7);
	SortingAandB(a, 3, 4);
	//movetoEnd(a.data, a.lenght, 5);
	//movetoP(a.data, a.lenght, 3);
	ToString(a);
	//getElem(a, 1, y);
	//printf("The result is: %d", y);
	/*a.data[0] = 2;
	a.data[1] = 3;
	a.data[2] = 5;
	a.data[3] = 6;
	a.data[4] = 7;
	a.data[5] = 9;	
	a.lenght = 6;
	printf("There exist a number: %d\nand its length is %d\n\n\n", a.data[0],a.lenght);
	int i = findElem(a, 8);
	//printf("The result is: %d\n", i);
	sqlistInsert(a, 8, i);
	printf("There exist a number: %d\nand its length is %d\n\n\n", a.data[5], a.lenght);
	//ToString(a);
	i = compare(a, 6);
	//printf("The result is: %d\n", i);
	deleteElem(a, i, 4);
	//ToString(a);
	//printf("The result is: %d\n", i);*/
	return 0;
}
int ToString(sqlist E) {
	for (int i = 0; i < E.lenght; ++i)
		printf("The Data is: %d\n", E.data[i]);
	printf("\n");
	return 1;
}
int initList(sqlist &E) {		//顺序表初始化
	E.lenght = 0;
	return 1;
}
int initList(sqlist& E, int a[], int n) {
	for (int i = 0; i < n; ++i)
		E.data[i] = a[i];
	E.lenght = n;
	return 1;
}
int getElem(sqlist E, int p, int& e) {		//获取第p个位置的值，并将值赋给e
	if (p<0 || p>E.lenght-1)
		return 0;
	e = E.data[p];
	return 1;
}
int findElem(sqlist E, int x) {		//寻找比x大的顺序表位置
	int i;
	for (i = 0; i < E.lenght; ++i)
		if (x < E.data[i])
			return i;
	return i;
}
int sqlistInsert(sqlist& E, int x, int i) {		//将x的值插入对应的位置
	for (int j = E.lenght - 1; j >= i; --j)
		E.data[j + 1] = E.data[j];
	E.data[i] = x;
	(++E.lenght);
	return 1;
}
int compare(sqlist E, int i) {		//查找相同的值，并返回下标
	int j;
	for (j = 0; j < E.lenght; ++j)
		if (i == E.data[j])
			return j;
	return 0;
}
int deleteElem(sqlist& E, int& x, int p) {		//根据下标，删除相应的结点，用x保留删除结点的值
	x = E.data[p];
	for (int j = p; j < E.lenght; ++j)
		E.data[j] = E.data[j + 1];
	(--E.lenght);
	return 1;
}
int reverse(int x[], int left, int right, int k) {
	int temp;
	for (int i = left, j = right; i < j && i < left + k; ++i, --j) {
		temp = x[i];
		x[i] = x[j];
		x[j] = temp;
	}
		return 1;
}
int movetoEnd(int x[], int n, int k) {		//k范围内的一串数据，保持原序移动至尾部，其余数据乱序无关紧要
	reverse(x, 0, k - 1, k);
	reverse(x, 0, n - 1, k);
	return 1;
}
int movetoP(int x[], int n, int p) {		//两串数据保持原序交换位置(0 - p-1 与 p - p-n 的两串数据交换位置，n为数据长度，p为数据交换点（上n、k同）)
	reverse(x, 0, p - 1, p);
	reverse(x, p, n - 1, n-p);
	reverse(x, 0, n - 1, n);
	return 1;
}
int SortingAandB(sqlist& E, int n, int m) {		//使前n个单调递增的元素与前m个单调递增的元素合并为整体递增（0-n-m+n)
	int temp,i,j;
	for (i = n; i < n + m; ++i) {
		temp = E.data[i];
		for (j = i - 1; j >= 0 && temp < E.data[j]; --j)	//前n个数组不断扩充，即j变量应该随i的变化而变化
			E.data[j + 1] = E.data[j];
		E.data[j + 1] = temp;
	}
	return 1;
}//2,3,5,1,4,6,8

