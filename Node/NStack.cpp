#include<iostream>
#define N 10
typedef struct LStack {
	int data[N];
	int top;
}LStack;
typedef struct NStack {
	int data;
	struct NStack* next;
}NStack;
int initNStack(NStack*& a);
int initNStack(NStack*& a, int x[], int n);
int isEmpty(NStack a);
int push(NStack*& a, int x);
int pop(NStack*& a,int &x);
int ToString(NStack* a);
int main(){
	NStack* a;
	int x[] = { 1,2,3,4,5,6,8 }, n = 7;
	initNStack(a, x, n);
	ToString(a);
	return 0;
}
int initNStack(NStack*& a){
	a = (NStack*)malloc(sizeof(NStack));
	a->next = NULL;
	return 1;
}
int initNStack(NStack*& a, int x[], int n) {
	int i;
	a = (NStack*)malloc(sizeof(NStack));
	a->next = NULL;
	for (i = 0; i < n; ++i)
		push(a, x[i]);
	return 1;
}
int isEmpty(NStack a) {
	if (a.next == NULL)
		return 1;
	else
		return 0;
}
int push(NStack*& a, int x){
	NStack* p;
	p = (NStack*)malloc(sizeof(NStack));
	p->data = x;
	p->next = a->next;
	a->next = p;
	return 1;
}
int pop(NStack*& a,int &x) {
	NStack* p;
	if (a->next == NULL)	//链式栈出栈要防止下溢问题
		return 0;
	p = a->next;
	a->next = p->next;
	x = p->data;
	free(p);
	return 1;
}
int ToString(NStack* a) {
	NStack* p;
	p = a->next;
	while (p != NULL) {
		printf("The data is: %d\n", p->data);
		p = p->next;
	}
	return 1;
}
