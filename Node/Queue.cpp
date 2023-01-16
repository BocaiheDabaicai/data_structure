#include<iostream>
#define N 10
typedef struct LQueue {
	int data[N];
	int front;
	int rear;
}LQueue;
typedef struct NQueue {
	int data;
	struct NQueue* next;
}NQueue;
typedef struct CNQueue {
	NQueue* front;
	NQueue* rear;
}CNQueue;
int initLQueue(LQueue& a);
int initLQueue(LQueue& a, int x[], int n);
int isEmpty(LQueue a);
int enLQueue(LQueue& a, int x);
int deLQueue(LQueue& a, int& x);
int ToString(LQueue a);
int main() {
	LQueue a;
	int x[] = { 1,4,7,5,6,2 }, n = 6,m;
	initLQueue(a, x, n);
	ToString(a);
	return 0;
}
int initLQueue(LQueue& a) {
	a.front = a.rear = 0;
	return 1;
}
int initLQueue(LQueue& a, int x[], int n) {
	int i;
	a.front = a.rear = 0;
	for (i = 0; i < n; ++i)
		enLQueue(a, x[i]);
	return 1;
}
int isEmpty(LQueue a) {
	if (a.front == a.rear)
		return 1;
	else
		return 0;
}
int enLQueue(LQueue& a, int x) {
	if ((a.rear + 1) % N == a.front)
		return -1;
	a.rear = (a.rear + 1) % N;
	a.data[a.rear] = x;
	return 1;
}
int deLQueue(LQueue& a, int& x) {
	if (a.front == a.rear)
		return -1;
	a.front = (a.front + 1) % N;
	x = a.data[a.front];
	return 1;
}
int ToString(LQueue a) {
	int i;
	for (i = 0; i < N; ++i)
		printf("%d ", a.data[i]);
	printf("\n");
	return 1;
}
