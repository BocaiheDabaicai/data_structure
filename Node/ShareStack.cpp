#include<iostream>
#define N 10
typedef struct ShareStack {
	int data[N];
	int top[2];
}ShareStack;
int initShareStack(ShareStack& a);
int pushShareStack(ShareStack& a, int No, int x);
int popShareStack(ShareStack& a, int No, int& x);
int ToString(ShareStack a);
int main() {
	ShareStack a;
	initShareStack(a);
	pushShareStack(a, 0, 2);
	pushShareStack(a, 0, 3);
	pushShareStack(a, 1, 5);
	pushShareStack(a, 1, 7);
	ToString(a);
	return 1;
}
int initShareStack(ShareStack& a)
{
	a.top[0] = -1;
	a.top[1] = N;
	return 1;
}
int pushShareStack(ShareStack& a, int No, int x)
{
	if (a.top[0] + 1 < a.top[1]) {
		if (No == 0)
			a.data[++a.top[0]] = x;
		if (No == 1)
			a.data[--a.top[1]] = x;
		else
			return 0;
	}
	return -1;
}
int popShareStack(ShareStack& a, int No, int& x)
{
	if (a.top[0] != -1 && No == 0) {
		x = a.data[a.top[0]--];
		return 1;
	}
	if (a.top[1] != N && No == 1) {
		x = a.data[a.top[1]++];
		return 1;
	}
	return -1;
}
int ToString(ShareStack a)
{
	int i;
	for (i = 0; i < N; ++i)
		printf("%d ", a.data[i]);
	printf("\n");
	return 1;
}
