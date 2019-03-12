#include <stdio.h>
#include "PreDefined.h"
#include "Stack.h"
/*
#define INIT_SIZE 100
#define INCREAMENT 10
typedef int ElemType;
typedef struct {
ElemType *top;
ElemType *base;
int stacksize;
}Stack;
*/

Status initStack(Stack *S)
{
	(*S).base = (ElemType*)malloc(sizeof(ElemType)*INIT_SIZE);
	if (!(*S).base)return OVERFLOW;
	(*S).top = (*S).base;
	(*S).stacksize = INIT_SIZE;
	return OK;
}
Status destroyStack(Stack *S)
{
	free((*S).base);
	(*S).base = (*S).top = NULL;
	return OK;
}
Status clearStack(Stack *S)
{
	(*S).top = (*S).base;
	return OK;
}
Status stackEmpty(Stack S)
{
	return S.top == S.base;
}
int stackLength(Stack S)
{
	return S.top - S.base - 1;
}
Status getTop(Stack S,ElemType *e)
{
	if (S.base == S.top)return ERROR;
	*e= *(S.top-1);
	return OK; 
}
Status push(Stack *S, ElemType e)
{
	if (((*S).top - (*S).base >= (*S).stacksize))
	{
		ElemType * newbase = (ElemType*)realloc((*S).base, sizeof(ElemType)*((*S).stacksize + INCREAMENT));
		if (!newbase)return OVERFLOW;
		(*S).base = newbase;
		(*S).stacksize += INCREAMENT;
	}
	*(*S).top = e;
	(*S).top++;
	return OK;
}
Status pop(Stack(*S), ElemType *e)
{
	if ((*S).top == (*S).base)return ERROR;
	*e = *(--(*S).top);
	return OK;
}
Status stackTraverse(Stack S,Status (*visit)(ElemType*))
{
	ElemType* p = S.base;
	while (p != S.top)
	{
		visit(p);
		p++;
	}
	return OK;
}
