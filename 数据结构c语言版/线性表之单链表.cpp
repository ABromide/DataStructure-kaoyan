/*线性表 */
#include <bits/stdc++.h>
#define MaxSize 100
typedef  int ElemType;
//单链表
typedef	struct LNode {
	ElemType data;
	LNode* next;
}LNode, * LinkList;

bool InitLinkList(LinkList L) {
	L = (LinkList)malloc(sizeof(LNode));
	if (L == NULL) return false;
	L->next = NULL;
	return true;
}
//保留头节点，即不对头节点的指向进行修改，故一级指针足够了
bool ClearLinkList(LinkList L) {
	if (L == NULL)
		return false;
	LinkList p, q;
	p = q = L->next;
	while (p != NULL)
	{
		p = q->next;
		free(q);
		q = p;
	}
	L->next = NULL;
	return true;
}
//当头节点也要删除的时候要传入LinkList *L，要对指针进行修改，则需要传入二级指针，修改一级指针
bool DestroyLinkList(LinkList* L) {
	if (*L == NULL || L == NULL)
		return false;
	LinkList p = (*L);
	while (p != NULL)
	{
		p = (*L)->next;
		free(*L);
		(*L) = p;
	}
	(*L) = NULL;
	return true;
}
bool ListEmpty(LinkList L) {
	if (L != NULL && L->next == NULL)
		return true;
	else
		return false;
}
int GetElemLocLinkList(LinkList L, int Loc, ElemType* e) {//loc为位序
	if (L == NULL || L->next == NULL)
		return false;
	if (Loc <= 0) return false;
	int i = 1;
	LinkList p = L->next;
	while (p != NULL && i < Loc)
	{
		p = p->next;
		i++;
	}
	if (p == NULL)
		return false;
	else
		return *e = p->data;
}
LNode* GetElemValLinkList(LinkList L, ElemType e) {//由值找节点
	if (L == NULL || L->next == NULL)
		return NULL;
	LinkList p = L->next;
	while (p != NULL && p->data != e)
	{
		p = p->next;
	}
	return p;
}
LNode* GetNodeLinkList(LinkList L, int Loc) {//loc为位序
	if (L == NULL || L->next == NULL)
		return NULL;
	int i = 0;
	LinkList p = L;
	while (p != NULL && i < Loc)
	{
		p = p->next;
		i++;
	}
	return p;
}
bool InsertLinkList(LinkList L, int Loc, ElemType e) {
	LinkList p = GetNodeLinkList(L, Loc - 1);
	if (!p) return false;

	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (!s) return false;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}
bool DeleteLinkList(LinkList L, int Loc, ElemType e) {
	LinkList p = GetNodeLinkList(L, Loc - 1);
	if (p == NULL || p->next == NULL) return false;
	LinkList q = p->next;
	p->next = q->next;
	free(q);
	return true;
}