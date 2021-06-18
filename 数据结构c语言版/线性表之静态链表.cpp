#include <bits/stdc++.h>

#define MAXSIZE 1000
#define ERROR 0
#define OK 1

typedef int ElemType;
typedef int Status;

typedef struct SLinkNode {
	ElemType data;
	int cur;            // cur是游标，做指针用，用来链接下一个结点（区别于数组下标）
} SLinkList[MAXSIZE];   // 链表空间类型

void InitSpace(SLinkList space) {
	int i;

	for (i = 0; i < MAXSIZE - 1; ++i) {
		space[i].cur = i + 1;
	}
	space[MAXSIZE - 1].cur = 0;
}
int Malloc(SLinkList space) {//类似于单链表的delete，删除头节点后的那个空闲的节点
	int i = space[0].cur;

	if (i != 0) {
		// 将申请到的空间从备用空间中删去
		space[0].cur = space[i].cur;
	}
	// 返回新申请结点下标
	return i;
}
void Free(SLinkList space, int k) {//插入空闲的space的头节点后，相当于Insert操作
	space[k].cur = space[0].cur;
	space[0].cur = k;
}
/*以下所有函数的形参中：
* space：指示备用空间
* S    ：指示静态链表头结点索引*/
Status InitList(SLinkList space, int* S) {
	int index;
	// 初始化备用空间
	InitSpace(space);
	// 申请头结点空间
	index = Malloc(space);
	if (index == 0) {
		return ERROR;
	}
	space[index].cur = 0;//表示L->next==NULL
	*S = index;
	return OK;
}
Status DestroyList(SLinkList space, int* S) {
	int cur;
	// 确保静态链表存在
	if (S == NULL || *S == 0) {
		return ERROR;
	}
	while (*S != 0) {
		// 暂存下一个结点的索引: q=p->next
		cur = space[*S].cur;
		// 回收当前结点所占空间:free(p)
		Free(space, *S);
		// 前进到下一个结点的索引处p=q;
		*S = cur;
	}
	return OK;
}
Status ClearList(SLinkList space, int S) {
	int P;//用P代替*S，不删除头节点
	int cur;
	// 确保静态链表存在
	if (S == 0) {
		return ERROR;
	}
	// 获取静态链表首个结点的索引
	P = space[S].cur;
	while (P != 0) {
		// 暂存下一个结点的索引
		cur = space[P].cur;
		// 回收当前结点所占空间
		Free(space, P);
		// 前进到下一个结点的索引处
		P = cur;
	}
	space[S].cur = 0;
	return OK;
}

Status ListEmpty(SLinkList space, int S) {
	// 只存在头结点的静态链表被视为空表
	if (S != 0 && space[S].cur == 0) {
		return true;
	}
	else {
		return false;
	}
}

int ListLength(SLinkList space, int S) {
	int count;
	// 静态链表不存在，或静态链表为空时，返回0
	if (S == 0 || space[S].cur == 0) {
		return 0;
	}
	// 获取静态链表首个元素的索引
	S = space[S].cur;
	count = 0;
	while (S != 0) {
		count++;
		S = space[S].cur;
	}

	return count;
}

Status GetElem(SLinkList space, int S, int i, ElemType* e) {
	int count;
	// 确保静态链表存在且不为空
	if (S == 0 || space[S].cur == 0) {
		return ERROR;
	}
	// 获取静态链表首个元素的索引
	S = space[S].cur;//不会修改真正的头指针S
	count = 0;
	while (S != 0 && count < i - 1) {
		count++;
		S = space[S].cur;
	}
	if (S == 0 || count > i - 1) {
		return ERROR;
	}
	*e = space[S].data;//e=p->data
	return OK;
}

int LocateElem(SLinkList space, int S, ElemType e, Status(Compare)(ElemType, ElemType)) {
	int i;
	int p;
	// 确保静态链表存在且不为空
	if (S == 0 || space[S].cur == 0) {
		return 0;
	}
	i = 1;              // i的初值为第1个元素的位序
	p = space[S].cur;   // p的初值为第1个元素的索引
	while (p != 0 && !Compare(space[p].data, e)) {
		i++;
		p = space[p].cur;
	}
	if (p != 0) {
		return i;
	}
	else {
		return 0;
	}
}