#include<iostream>
#define N 10
typedef struct ShareQueue {
	int indata[N];
	int dedata[N];
	int top[2];
}ShareQueue;
int initShareQueue(ShareQueue& a);
int pushShareQueue(ShareQueue& a, int x);
int popShareQueue(ShareQueue& a,int &x);
int isEmpty(ShareQueue a);
int main() {
	return 1;
}
int initShareQueue(ShareQueue& a)
{
	a.top[0] = a.top[1] = -1;
	return 1;
}
int pushShareQueue(ShareQueue& a, int x)
{
	int y;
	if (a.top[0] == N - 1) {
		if (a.top[1] != -1)
			return 0;
		else if (a.top[1] == -1) {
			while (a.top[0] != -1) {
				y = a.indata[a.top[0]--];
				a.dedata[++a.top[1]] = y;
			}
			a.indata[++a.top[0]] = x;
			return 1;
		}
		else {
			a.indata[++a.top[0]] = x;
			return 1;
		}
	}
}
int popShareQueue(ShareQueue& a, int& x)
{
	int y;
	if (a.top[1] != -1) {
		x = a.dedata[a.top[1]--];
		return 1;
	}
	else {
		if (a.top[0] == -1)
			return 0;
		else {
			while (a.top[0] != -1) {
				y = a.indata[a.top[0]--];
				a.dedata[++a.top[1]] = y;
			}
			x = a.dedata[a.top[1]--];
			return 1;
		}
	}
}
int isEmpty(ShareQueue a)
{
	if (a.top[0] == -1 && a.top[1] == -1)
		return 1;
	else
		return 0;
}
