#include<iostream>
typedef struct DNode {
	int data;
	struct DNode* piror;
	struct DNode* next;
}DNode;
int Tostring(DNode* a);
int createDNodeR(DNode*& a, int b[], int n);
int insertDNode(DNode*& a, int t, int n);	//在t位置之前插入一个数值为n的结点
int deleteDNode(DNode*& a, int t);
DNode* findDNode(DNode* a, int b);		//比较值，返回对应位置的指针
int main() {
	DNode* a,* a1;
	int b[] = { 2,3,4,6,7 },n=5;
	createDNodeR(a, b, n);
	//insertDNode(a, 4, 5);
	//deleteDNode(a, 3);
	Tostring(a);
	//--------------------
	/*a1 = (DNode*)malloc(sizeof(DNode));
	a1->next = NULL;
	a1 = findDNode(a, 6);
	printf("The search result is %d\n", a1->data);*/
	return 1;
}
int Tostring(DNode* a) {
	DNode* p = a->next;
	while (p != NULL) {
		printf("This is %d\n", p->data);
		p = p->next;
	}
	return 1;
}
int createDNodeR(DNode*& a, int b[], int n) {
	DNode* p, * q;
	a = (DNode*)malloc(sizeof(DNode));
	a->next = NULL;
	a->piror = NULL;
	p = a;
	for (int i = 0; i < n; ++i) {
		q = (DNode*)malloc(sizeof(DNode));
		q->data = b[i];
		p->next = q;
		q->piror = p;
		p = p->next;
	}
	p->next = NULL;
	return 1;
}
int insertDNode(DNode*& a, int t, int n)
{
	DNode* p, * q;
	p = a;
	for (int i = 1; i < t; ++i)
		p = p->next;
	//printf("%d\n", p->data);
	q = (DNode*)malloc(sizeof(DNode));
	q->data = n;
	q->piror = p;
	q->next = p->next;
	p->next = q;
	q->next->piror = q;
	return 1;
}
int deleteDNode(DNode*& a, int t) {
	DNode* p, * q;
	p = a;
	for (int i = 1; i < t; ++i)
		p = p->next;
	q = p->next;
	p->next = p->next->next;
	q->next->piror = p;
	free(q);
	return 1;
}
DNode* findDNode(DNode* a, int b) {
	DNode* p = a->next;
	while (p != NULL) {
		if (p->data == b)
			break;
		p = p->next;
	}
	return p;
}