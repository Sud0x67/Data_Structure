#pragma once
#ifndef STACK_H
#define STACK_H
#include "maze.h"
#define INIT_SIZE 100
#define INCREAMENT 10
typedef struct {
	ElemType *top;
	ElemType *base;
	int stacksize;
}Stack;
Status initStack(Stack *S);

Status destroyStack(Stack * S);

Status clearStack(Stack * S);

Status stackEmpty(Stack S);

int stackLength(Stack S);

Status getTop(Stack S, ElemType * e);

Status push(Stack * S, ElemType e);

Status pop(Stack(*S), ElemType * e);
Status stackTraverse(Stack S, Status(*visit)(ElemType *));
#endif // !STACK_H

