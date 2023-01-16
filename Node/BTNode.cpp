#include<iostream>
#define N 10
typedef struct BTNode {
	int data;
	struct BTNode* lchild, * rchild;
}BTNode;
typedef struct CBTNode {
	char data;
	struct CBTNode* lchild, * rchild;
}CBTNode;
typedef struct TBTNode {
	int data, ltag, rtag;
	struct TBTNode* lchild, * rchild;
}TBTNode;
void initBTNode(BTNode* a, char c);
int preorder(BTNode* a);
int inorder(BTNode* a);
int postorder(BTNode* a);
int comp(CBTNode* a);
int op(int a, int b, char c);
int getDepth(BTNode* a);
int search(BTNode* a, BTNode*& b, int key);
int trave(BTNode* a, int key);
int level(BTNode* a);
int preorderStack(BTNode* a);
int inroderStack(BTNode* a);
int preThread(TBTNode* a, TBTNode*& pre);
int main() {
	/*BTNode* a;
	a = (BTNode*)malloc(sizeof(BTNode));
	a->data = 1;
	a->lchild = NULL;
	a->rchild = NULL;
	initBTNode(a, 3);
	initBTNode(a, 0);
	initBTNode(a->lchild, 1);
	preorder(a); */
	//-----------------------------------------------
	/*CBTNode* a, * a1, * a2, * a3,* a4;
	a = (CBTNode*)malloc(sizeof(CBTNode));
	a1 = (CBTNode*)malloc(sizeof(CBTNode));
	a2 = (CBTNode*)malloc(sizeof(CBTNode));
	a3 = (CBTNode*)malloc(sizeof(CBTNode));
	a4 = (CBTNode*)malloc(sizeof(CBTNode));
	a->data = '*';
	a->lchild = a1;
	a->rchild = a4;
	a1->data = '+';
	a1->lchild = a2;
	a1->rchild = a3;
	a2->data = '1';
	a2->lchild = NULL;
	a2->rchild = NULL;
	a3->data = '2';
	a3->lchild = NULL;
	a3->rchild = NULL;
	a4->data = '6';
	a4->lchild = NULL;
	a4->rchild = NULL;
	int i;
	i = comp(a);
	printf("Congratulation! My friend , herein lie a data %d\n", i);*/
	//----------------------------------------------------------------------------
	BTNode* a;
	a = (BTNode*)malloc(sizeof(BTNode));
	initBTNode(a, 'l');
	initBTNode(a, 'r');
	initBTNode(a->lchild, 'l');
	initBTNode(a->lchild, 'r');
	initBTNode(a->lchild->lchild, 'l');
	initBTNode(a->lchild->rchild, 'l');
	int i;
	i = getDepth(a);
	printf("data of depth is %d", i);
	return 1;
}
void initBTNode(BTNode* a, char c)
{
	BTNode* p;
	if (c=='l') {
		p = (BTNode*)malloc(sizeof(BTNode));
		p->data = 1;
		p->lchild = NULL;
		p->rchild = NULL;
		a->lchild = p;
	}
	if(c=='r'){
		p = (BTNode*)malloc(sizeof(BTNode));
		p->data = 1;
		p->lchild = NULL;
		p->rchild = NULL;
		a->rchild = p;
	}
}
int preorder(BTNode* a)
{
	if (a != NULL) {
		printf("%d\n", a->data);
		preorder(a->lchild);
		preorder(a->rchild);
	}
	return 0;
}
int inorder(BTNode* a)
{
	if (a != NULL) {
		inorder(a->lchild);
		printf("%d\n", a->data);
		inorder(a->rchild);
	}
	return 0;
}
int postorder(BTNode* a)
{
	if (a != NULL) {
		postorder(a->lchild);
		postorder(a->rchild);
		printf("%d\n", a->data);
	}
	return 0;
}
int comp(CBTNode* a)
{
	int A, B;
	if (a != NULL) {
		if (a->lchild != NULL && a->rchild != NULL) {
			A = comp(a->lchild);
			B = comp(a->rchild);
			return op(A, B, a->data);
		}
		return a->data - '0';
	}
	else
		return 0;
}
int op(int a, int b, char c)
{
	if (c == '+')
		return a + b;
	if (c == '-')
		return a - b;
	if (c == '*')
		return a* b;
	if (c == '/'&&b!=0)
		return a / b;
	return -1;
}
int getDepth(BTNode* a)
{
	int A, B;
	if (a == NULL)
		return 0;
	else {
		A = getDepth(a->lchild);
		B = getDepth(a->rchild);
		return (A > B ? A : B) + 1;
	}
	
}
int search(BTNode* a, BTNode*& b, int key)
{
	if (a != NULL) {
		if (a->data == key)
			b = a;
		else {
			search(a->lchild, b, key);
			if (b = NULL)
				search(a->rchild, b, key);
		}
	}
	return 0;
}
int n = 0;
int trave(BTNode* a, int key)
{
	if (a != NULL) {
		n++;
		if (n == key) {
			printf("Search is finished!And finding relevant data is successful. ");
			return;
		}
		trave(a->lchild, key);
		trave(a->rchild, key);
	}
	return -1;
}
int level(BTNode* a)
{
	int front, rear;
	BTNode* arr[N];
	front = rear = 0;
	BTNode* b;
	if (a != NULL) {
		rear = (rear + 1) % N;
		arr[rear] = a;
		while (rear != front) {
			front = (front + 1) % N;
			b = arr[front];
			printf("%d\n", b->data);	//对结点进行访问
			if (b->lchild != NULL) {
				rear = (rear + 1) % N;
				arr[rear] = b->lchild;
			}
			if (b->rchild != NULL) {
				rear = (rear + 1) % N;
				arr[rear] = b->rchild;
			}
		}
	}
	return 1;
}
int preorderStack(BTNode* a)
{
	if (a != NULL) {
		BTNode* arr[N];
		BTNode* p;
		int top = -1;
		arr[++top] = a;
		while (top != -1) {
			p = arr[top--];
			printf("%d\n", p->data);
			if (p->rchild != NULL) 
				arr[++top] = p->rchild;
			if (p->lchild != NULL)
				arr[++top] = p->lchild;
		}
	}
	return 1;
}
int inroderStack(BTNode* a)
{
	if (a != NULL) {
		BTNode* arr[N];
		int top = -1;
		BTNode* p;
		p = a;
		while (top != -1||p!=NULL) {
			while (p->lchild != NULL) {
				arr[++top] = p->lchild;
				p = p->lchild;
			}
			if (top != -1) {
				p = arr[top--];
				printf("%d\n", p->data);
				p = p->rchild;
			}
		}
	}
	return 0;
}
int preThread(TBTNode* a, TBTNode*& pre)
{
	if (a != NULL) {
		if (a->lchild == NULL) {
			a->lchild = pre;
			a->ltag = 1;
		}
		if (pre != NULL && pre->rchild == NULL) {
			a->rchild = pre;
			a->rtag = 1;
		}
		pre = a;
		if (a->ltag == 0)
			preThread(a->lchild, pre);
		if (a->ltag == 0)
			preThread(a->rchild, pre);

	}
	return 0;
}
