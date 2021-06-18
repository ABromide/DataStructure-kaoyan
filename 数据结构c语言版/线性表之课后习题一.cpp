#include <bits/stdc++.h>

#define MAXSIZE 1000
#define ERROR 0
#define OK 1

typedef int ElemType;
typedef int Status;

typedef struct {
	ElemType data[MAXSIZE];
	//ElemType *data;
	int Length;
}Sqlist;

//1
bool Task1(Sqlist* L, ElemType* value)
{
	if (L->Length <= 0) return false;
	if (L->Length == 1) {
		return false;
	}
	ElemType temp = L->data[0];
	int Loc = 0;
	for (size_t i = 1; i < L->Length; i++)
	{
		if (temp < L->data[i])
		{
			temp = L->data[i];
			Loc = i;
		}
	}
	L->data[Loc] = L->data[L->Length - 1];
	L->Length--;
	*value = temp;
	return true;
}
//2
bool ReverseSqlist(Sqlist* L) {
	if (L == NULL || L->Length == 0)return false;
	ElemType temp;
	for (size_t i = 0; i < L->Length / 2; i++)
	{
		temp = L->data[i];
		L->data[i] = L->data[L->Length - i - 1];
		L->data[L->Length - i - 1] = temp;
	}
	return true;
}
//3
bool DeleteX(Sqlist* L, ElemType e) {
	if (L == NULL || L->Length == 0)return false;
	int RealLengh = 0;
	for (size_t Loc = 0; Loc < L->Length; Loc++)
	{
		if (L->data[Loc] != e) {
			L->data[RealLengh] = L->data[Loc];
			RealLengh++;
		}
	}
	L->Length = RealLengh;
	return true;
}
//4
bool DeleteRange1(Sqlist* L, ElemType s, ElemType t) {
	if (L == NULL || L->Length == 0) return 0;
	int start = -1;
	int end = -1;
	for (size_t i = 0; i < L->Length; i++)
	{
		if (L->data[i] == s) start = i;
		if (L->data[i] == t) {
			end = i;
			break;
		}
	}
	if (start == -1 || end == -1) return false;
	for (size_t i = end; i < L->Length; i++)
	{
		L->data[start++] = L->data[end];
	}
	L->Length = L->Length - (end - start + 1);
	return true;
}
//5
bool DeleteRange2(Sqlist* L, ElemType s, ElemType t) {
	if (L == NULL || L->Length == 0 || s >= t) return 0;
	int Count = 0;
	for (size_t i = 0; i < L->Length; i++)
	{
		if (L->data[i] >= s && L->data[i] <= t)
			Count++;
		else
			L->data[i - Count] = L->data[i];
	}
	L->Length -= Count;
	return true;
}
//6
bool DeleteToDifferent(Sqlist* L)
{
	if (L == NULL || L->Length == 0) return 0;
	int Count = 0;
	for (size_t Loc = 1; Loc < L->Length; Loc++)
	{
		if (L->data[Loc] == L->data[Loc - 1])
			Count++;
		else
			L->data[Loc - Count] = L->data[Loc];
	}
	L->Length -= Count;
	return true;
}