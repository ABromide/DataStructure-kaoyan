#include <bits/stdc++.h>

#define MAXSIZE 1000
#define ERROR 0
#define OK 1

typedef int ElemType;
typedef int Status;

typedef	struct LNode {
	ElemType data;
	LNode* next;
}LNode, * LinkList;
//1(非递归)
Status DeleteXLinkList(LinkList* L, ElemType e) {
	if (L == NULL || *L == NULL) return false;
	while ((*L)->data == e)
	{
		L = &((*L)->next);
	}
	LinkList q = (*L);
	LinkList p;
	while (q->next != NULL)
	{
		if (q->next->data == e)
		{
			p = q->next;
			q->next = p->next;
			free(p);
		}
	}
	return true;
}