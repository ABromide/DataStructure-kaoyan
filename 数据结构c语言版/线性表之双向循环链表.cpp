/*线性表 */
#include <bits/stdc++.h>
#define MaxSize 100
typedef  int ElemType;
//单链表
typedef	struct DNode {
	ElemType data;
	DNode* next;
	DNode* prior;
}DNode, * DLinkList;

bool InitLinkList(DLinkList L) {
	L = (DLinkList)malloc(sizeof(DNode));
	if (L == NULL) return false;
	L->next = L;
	L->prior = L;
	return true;
}
//保留头节点，即不对头节点的指向进行修改，故一级指针足够了
bool ClearLinkList(DLinkList L) {
	if (L == NULL)
		return false;
	DLinkList p, q;
	p = q = L->next;
	while (p != NULL)
	{
		p = q->next;
		free(q);
		q = p;
	}
	L->next = L->prior = L;
	return true;
}
//当头节点也要删除的时候要传入LinkList *L，要对指针进行修改，则需要传入二级指针，修改一级指针
bool DestroyLinkList(DLinkList* L) {
	if (*L == NULL || L == NULL)
		return false;
	DLinkList p = (*L);
	while (p != NULL)
	{
		p = (*L)->next;
		free(*L);
		(*L) = p;
	}
	(*L) = NULL;
	return true;
}
bool ListEmpty(DLinkList L) {
	if (L != NULL && L->next == L && L->prior == L)
		return true;
	else
		return false;
}

DNode* GetElemValLinkList(DLinkList L, ElemType e) {//由值找节点
	if (L == NULL)//不存在
		return false;
	if (L->next == L && L->prior == L)//空表
		return false;

	DLinkList p = L->next;
	while (p != L && p->data != e)
	{
		p = p->next;
	}
	if (p == L) return NULL;
	else return p;
}
DNode* GetNodeLocLinkList(DLinkList L, int Loc) {//loc为位序
	if (L == NULL)//不存在
		return false;
	if (L->next == L && L->prior == L)//空表
		return false;

	int i = 0;
	DLinkList p = L;
	while (p->next != L && i < Loc)
	{
		p = p->next;
		i++;
	}
	if (i == Loc)	return p;
	if (i + 1 < Loc) return NULL;//loc过大，大于表长加一
	if (i + 1 == Loc) return L;//?
}
bool InsertLinkList(DLinkList L, int Loc, ElemType e) {
	if (L == NULL) {
		return false;
	}
	DLinkList p = GetNodeLocLinkList(L, Loc - 1);
	if (!p) return false;

	DNode* s = (DNode*)malloc(sizeof(DNode));
	if (!s) return false;

	s->data = e;
	//若是单向链表，还要判断是否P->next为NULL，即P是否为最后一个节点
	//if(p->next!=NULL)
	p->next->prior = s;
	s->next = p->next;
	s->prior = p;
	p->next = s;

	return true;
}
bool DeleteLinkList(DLinkList L, int Loc, ElemType e) {
	if (L == NULL || L->next == L || L->prior == L) {//保证不是空表
		return false;
	}
	DLinkList p = GetNodeLocLinkList(L, Loc - 1);
	if (p == NULL || p == L) return false;//p==L代表Loc的长度为表长加1，不符合规则

	DLinkList q = p->next;
	p->next = q->next;
	//若是单向链表，还要判断是否P->next为NULL，即P是否为最后一个节点
	//if(p->next!=NULL)
	q->next->prior = p;
	free(q);
	return true;
}