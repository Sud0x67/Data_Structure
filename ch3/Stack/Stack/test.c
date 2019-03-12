#include <stdio.h>
#include "PreDefined.h"
#include "Stack.h"
void print_e(ElemType *c)
{
	printf("\t%d", *c);
}
void main()
{
	Stack S;
	ElemType e;
	initStack(&S);
	printf("\nStack的内容是base：%d，top：%d，Stacksize：%d\n,stackEmpty:%d,StackLength:%d\n", S.base, S.top, S.stacksize, stackEmpty(S), stackLength(S));
	for (int i = 0;i < 200;i++)
	{
		push(&S, i);
		getTop(S, &e);
		printf("\t%d", e);
	}
	printf("\nStack的内容是base：%d，top：%d，Stacksize：%d\n,stackEmpty:%d,StackLength:%d\n", S.base, S.top, S.stacksize,stackEmpty(S),stackLength(S));
	//while(pop(&S, &e)){
	//		printf("\t%d", e);
	//	}
	printf("\nStack的内容是base：%d，top：%d，Stacksize：%d,stackEmpty:%d,StackLength:%d\n", S.base, S.top, S.stacksize, stackEmpty(S), stackLength(S));
	stackTraverse(S, print_e);
	destroyStack(&S);
	printf("\nStack的内容是base：%d，top：%d，Stacksize：%d,stackEmpty:%d,StackLength:%d\n", S.base, S.top, S.stacksize, stackEmpty(S), stackLength(S));
	//stackTraverse(S, print_e);
	system("pause");
}