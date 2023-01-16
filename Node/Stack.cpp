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
int initLStack(LStack& a);
int initLStack(LStack& a, int x[], int n);
int isEmpty(LStack a);
int push(LStack& a, int x);
int pop(LStack& a, int& x);
int match(char exp[], int n);
int detect(char exp[]);
int calculate(int x, int y, char op);
int ToString(LStack a);
int main() {
	/*LStack apt;
	int x[] = { 1,2,3,4,5,6,7 }, n = 7;
	initLStack(apt, x, n);
	ToString(apt);*/
	printf("test-------------------\n");
	char y[] = "64-8+5+";// 5+((6-4)+8)
	int a;
	a=detect(y);
	printf("the result is: %d", a);
	return 0;
}
int initLStack(LStack& a) {
	a.top = -1;
	return 1;
}
int initLStack(LStack& a, int x[], int n) {
	int i;
	if (n > N)
		return 0;
	for (a.top = -1, i = 0; i < n; ++i)
		push(a, x[i]);
	return 1;
}
int isEmpty(LStack a) {
	if (a.top == -1)
		return 1;
	else
		return 0;
}
int push(LStack& a, int x) {
	if (a.top == N - 1)
		return 0;
	a.data[++a.top] = x;
	return 1;
}
int pop(LStack& a, int& x) {
	if (a.top == -1)
		return 0;
	x = a.data[a.top--];
	return 1;
}
int match(char exp[], int n) {		//判断算式里的所有括号是否配对
	char Stack[N];
	int top = -1;
	int i;
	for (i = 0; i < n; ++i) {	
		if (exp[i] == '(')
			Stack[++top] = '(';
		if (exp[i] == ')') {
			if (top == -1)
				return 0;
			else
				--top;
		}
		if (top == -1) {
			//printf("success\n");
			return 1;
		}
		else
			return 0;
	}
	return 1;
}
int detect(char exp[]) {	//字符数组使用前必须对其进行初始化才能够正常使用，不推荐使用
	int Stack[N];
	int top = -1, i,a,b,c;
	char op;
	for (i = 0; exp[i] != '\0'; ++i) {		//64-8+5+
		if (exp[i] >= '0' && exp[i] <= '9')
			Stack[++top] = exp[i]-'0';
		else {
			op = exp[i];
			b = Stack[top--];
			a = Stack[top--];
			c = calculate(a, b, op);
			Stack[++top] = c;
		}
	}
	//printf("the re is: %d\n", Stack[top]);
	return Stack[top];
}
int calculate(int x, int y, char op) {
	switch (op) {
	case '+':return x + y; break;
	case '-':return x - y; break;
	case '*':return x * y; break;
	case '/':if (y == 0) {
		printf("error\n");
		return -1;
	}
			else
		return x / y;
		break;
	default:break;
	}
	return 1;
}
int ToString(LStack a) {
	int i;
	for (i = a.top; i > -1; --i)
		printf("The data is: %d\n", a.data[i]);
	return 1;
}