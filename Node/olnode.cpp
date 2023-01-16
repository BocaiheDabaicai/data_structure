#include<iostream>
#define N 10
typedef struct OLNode {
	int row, col;
	struct OLNode* right, * down;
	int val;
}OLNode;
typedef struct CrossList {
	OLNode* rhead, * chead;
	int m, n, k;				//行数，列数及非零节点总数。
}CrossList;
int createCrossList(int A[][N], int m, int n, int k, CrossList& M);
int main() {
	return 1;
}
int createCrossList(int A[][N], int m, int n, int k, CrossList& M)
{
	if (M.chead)
		free(M.chead);
	if (M.rhead)
		free(M.rhead);
	if (!(M.chead = (OLNode*)malloc(sizeof(OLNode) * m)))
		return -1;
	if (!(M.rhead = (OLNode*)malloc(sizeof(OLNode) * n)))
		return -1;
	for (int i = 0; i < m; ++i) {
		M.chead[i].down = NULL;
		M.chead[i].right = NULL;
	}
	for (int i = 0; i < n; ++i) {
		M.rhead[i].down = NULL;
		M.rhead[i].right = NULL;
	}
	OLNode* temp[N];
	for (int i = 0; i < n; ++i)
		temp[i]  = &M.rhead[i];
	for (int i = 0; i < m; ++i) {
		OLNode* r = &M.chead[i];
		for (int j = 0; j < n; ++j) {
			if (A[i][j] != NULL) {
				OLNode* p = (OLNode*)malloc(sizeof(OLNode));
				p->row = i;
				p->col = j;
				p->val = A[i][j];
				p->down = NULL;
				p->right = NULL;
				r->right = p;
				r = p;
				temp[j]->down = p;
				temp[j] = p;
			}
		}
	}
	return 0;
}
