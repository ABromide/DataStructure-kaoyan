/*线性表 */
#include <bits/stdc++.h>
#define MaxSize 100
typedef  int ElemType;
//1.顺序表
typedef struct {
	ElemType data[MaxSize];
	//ElemType *data;
	int Length;
}Sqlist;

bool initSqList(Sqlist& L)
{
	//L.data = (ElemType*)malloc(sizeof(ElemType)*MaxSize);
	//if(L.data==NULL) return false;
	for (size_t i = 0; i < MaxSize; i++)
	{
		L.data[i] = 0;
	}
	L.Length = 0;
	return true;
}

bool DestorySqList(Sqlist& L)
{
	L.Length = 0;
	//若为malloc需要free，否则不需要
	return true;
}

bool InsertSqList(Sqlist& L, int i, ElemType e) {//i为位序
	if (i <= 0 || i > L.Length + 1)
	{
		return false;
	}
	if (L.Length >= MaxSize) return false;
	for (size_t j = L.Length; j >= i; j--)
	{
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;
	L.Length++;
	return true;
}
bool DeleteSqList(Sqlist& L, int i, ElemType& e) {
	if (i<1 || i>L.Length)
	{
		return false;
	}
	e = L.data[i - 1];
	for (size_t j = i; j < L.Length; j++)
	{
		L.data[j - 1] = L.data[j];
	}
	L.Length--;
	return true;
}

int FindValSqList(Sqlist L, ElemType e) {
	for (size_t i = 0; i < L.Length; i++)
	{
		if (e == L.data[i]) return i + 1;
	}
	return false;
}

int FindLocSqList(Sqlist L, int i) {
	if (i<1 || i>L.Length)
		return false;
	else
	{
		return L.data[i - 1];
	}
}