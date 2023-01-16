#include<iostream>
#define N 10
typedef struct NQueue {
	int data;
	struct NQueue* next;
}NQueue;
typedef struct CNQueue {
	NQueue* front;
	NQueue* rear;
}CNQueue;
int initCNQueue(CNQueue*& a);
int initCNQueue(CNQueue*& a, int x[], int n);
int isEmpty(CNQueue* a);
int enCNQueue(CNQueue*& a, int x);
int deCNQueue(CNQueue*& a, int& x);
int ToString(CNQueue* a);
int main() {
	CNQueue* a;
	int x[] = { 1,3,4,5,8,9 }, n = 6,m;
	initCNQueue(a, x, n);
	//deCNQueue(a, m);
	ToString(a);
	return 0;
}
int initCNQueue(CNQueue*& a) {
	a = (CNQueue*)malloc(sizeof(CNQueue));
	a->front = a->rear = NULL;
	return 1;
}
int initCNQueue(CNQueue*& a, int x[], int n) {
	initCNQueue(a);
	int i;
	for (i = 0; i < n; ++i)
		enCNQueue(a, x[i]);
	return 1;
}
int isEmpty(CNQueue* a) {
	if (a->front == NULL || a->rear == NULL)
		return 1;
	else
		return 0;
}
int enCNQueue(CNQueue*& a, int x) {
	NQueue* p = (NQueue*)malloc(sizeof(NQueue));
	p->data = x;
	p->next = NULL;
	if (a->rear == NULL)
		a->front = a->rear = p;
	else {
		a->rear->next = p;
		a->rear = p;
	}
	return 1;
}
int deCNQueue(CNQueue*& a, int& x) {
	NQueue* p;
	if (a->rear == NULL)
		return 0;
	else
		p = a->front;
	if (a->front == a->rear)
		a->front = a->rear = NULL;
	else
		a->front = a->front->next;
	x = p->data;
	free(p);
	return 1;
}
int ToString(CNQueue* a) {
	NQueue* q;
	q = a->front;
	while (q != NULL) {
		printf("%d ", q->data);
		q = q->next;
	}
	return 1;
}
