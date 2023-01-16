#include<iostream>
#define N 10
typedef struct Node {
	int data;
	struct Node* next;
}Node;
int ToString(Node* a);
int merge(Node* a, Node* b, Node*& c);
int mergeF(Node* a, Node* b, Node*& c);
int creatNodeR(Node*& a, int b[], int n);
int creatNodeF(Node*& a, int b[], int n);
int findAnddelete(Node* a, int b);
int DeleteAndSort(Node* a, Node* b,int i);
int DeepCopy(Node* a,Node*& b);
int main() {
	//Node* a = (Node*)malloc(sizeof(Node));
	//Node* a1 = (Node*)malloc(sizeof(Node));
	//Node* a2 = (Node*)malloc(sizeof(Node));
	//Node* a3 = (Node*)malloc(sizeof(Node));
	//Node* a4 = (Node*)malloc(sizeof(Node));
	//Node* a5 = (Node*)malloc(sizeof(Node));
	//a->next = a1;
	//a1->data = 1;
	//a1->next = a2;
	//a2->data = 2;
	//a2->next = a3;
	//a3->data = 3;
	//a3->next = a4;
	//a4->data = 4;
	//a4->next = a5;
	//a5->data = 6;
	//a5->next = NULL;
	////------------------------------------------------------
	//Node* b = (Node*)malloc(sizeof(Node));
	//Node* b1 = (Node*)malloc(sizeof(Node));
	//Node* b2 = (Node*)malloc(sizeof(Node));
	//Node* b3 = (Node*)malloc(sizeof(Node));
	//b->next = b1;
	//b1->data = 1;
	//b1->next = b2;
	//b2->data = 5;
	//b2->next = b3;
	//b3->data = 7;
	//b3->next = NULL;
	////ToString(b);
	////---------------------------
	//Node* c = (Node*)malloc(sizeof(Node));
	//merge(a, b, c);
	//ToString(c);
	Node* d,* d1;
	int mad[] = { 2,4,5,7,9,11,15 };
	//int mad1[] = { 3,5,6,8,9,12,13 };
	creatNodeR(d, mad, 7);
	//creatNodeR(d1, mad1, 7);
	//findAnddelete(d, 15);
	ToString(d);
	//ToString(d1);
	//DeleteAndSort(d, d1);
	//ToString(d);
	return 1;
}
int ToString(Node* a) {
	Node* p;
	p = a->next;
	for (int i = 0; p != NULL; p = p->next,++i)
		printf("The number is %d,its data is %d\n", i, p->data);
	return 1;
}
int merge(Node* a, Node* b, Node*& c) {		//对链表a,b进行合并，按照递增的形式排列，新形式赋予c.(归并操作)
	Node* p = a->next;
	Node* q = b->next;
	Node* r;
	c = a;
	c->next = NULL;
	r = c;
	free(b);
	while(p!=NULL&&q!=NULL)
		if (p->data <= q->data) {
			r->next = p;
			r = r->next;
			p = p->next;
		}
		else {
			r->next = q;
			r = r->next;
			q = q->next;
		}
	if (p!= NULL)r->next = p;
	if (q!= NULL)r->next = q;
	return 1;
}
int mergeF(Node* a, Node* b, Node*& c) {		//对链表a,b进行合并，按照递减的形式排列，新形式赋予c.(归并操作2)
	Node* p = a->next;
	Node* q = b->next;
	Node* r,*d;
	c = a;
	c->next = NULL;
	free(b);
	d = c;
	while (p != NULL && q != NULL)
		if (p->data <= q->data) {
			r = p;
			p = p->next;
			r->next = c->next;
			c->next = r;
		}
		else {
			r = q;
			q = q->next;
			r->next = c->next;
			c->next = r;
		}
	while (p != NULL) {
		r = p;
		p = p->next;
		r->next = c->next;
		c->next = r;
	}
	while (q != NULL) {
		r = q;
		q = q->next;
		r->next = c->next;
		c->next = r;
	}
	c = d;
	return 1;
}
int creatNodeR(Node*& a, int b[], int n) {
	Node* p, * r;
	int i;
	a = (Node*)malloc(sizeof(Node));
	a->next = NULL;
	r = a;
	for (i = 0; i < n; ++i) {
		p = (Node*)malloc(sizeof(Node));
		p->data = b[i];
		r->next = p;
		r = r->next;
	}
	r->next = NULL;
	return 1;
}
int creatNodeF(Node*& a, int b[], int n) {
	Node* p;
	int i;
	a = (Node*)malloc(sizeof(Node));
	a->next = NULL;
	for (i = 0; i < n; ++i) {
		p = (Node*)malloc(sizeof(Node));
		p->data = b[i];
		p->next = a->next;
		a->next = p;
	}
	return 1;
}
int findAnddelete(Node* a, int b) {
	Node* p,* q;
	p = a;
	while (p->next != NULL) {
		if (b == p->next->data)
			break;
		p = p->next;
	}
	if (p->next == NULL)
		return -1;
	else {
		q = p->next;
		p->next = p->next->next;
		free(q);
		return 1;
	}
}
int DeleteAndSort(Node* a, Node* b) {	//比较A和B链表的值，相同的值在A链表中进行删除
	Node* p, * q;
	Node* pre, * r;
	p = a->next;
	q = b->next;
	pre = a;
	while (p != NULL && q != NULL) {
		if (p->data < q->data) {
			pre = p;
			p = p->next;
		}
		else if (p->data > q->data)
			q = q->next;
		else {
			pre->next = p->next;
			r = p;
			p = p->next;
			free(r);
		}
	}
	return 1;
}

int DeepCopy(Node* a, Node*& b,int i)	//unfinished!!
{
	Node* p,* q;

	return 1;
}
