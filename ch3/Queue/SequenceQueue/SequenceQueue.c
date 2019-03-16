#include<stdio.h>
#include<stdlib.h>
#include"PreDefined.h"
#include "SequenceQueue.h"

Status initQueue(SequenceQueue *S) {
	//malloc函数一定要写好，脑子一混bug改半天
	S->base = (QElemType*)malloc(sizeof(QElemType)*MAXSIZE);
	if (!S->base)return OVERFLOW;
	S->front = 0;
	S->rear = 0;
	return OK;
}
Status destroyQueue(SequenceQueue *S) {
	free((S->base));
	S->front = 0;
	S->rear = 0;
	S->base = NULL;
	return OK;
}
Status clearQueue(SequenceQueue *S) {
	S->front = 0;
	S->rear = 0;
	return OK;
}
int queueLength(SequenceQueue S) {
	return (S.rear + MAXSIZE - S.front) % MAXSIZE;
}
Status queueEmpty(SequenceQueue S)
{
	return S.front == S.rear;
}
Status enQueue(SequenceQueue *S,QElemType e) {
	if ((S->rear + 1) % MAXSIZE == S->front)return ERROR;
	*(S->base+S->rear)= e;
	S->rear = (S->rear + 1) % MAXSIZE;
	return OK;
}
Status deQueue(SequenceQueue *S, QElemType *e) {
	if (S->front == S->rear) return ERROR;
	*e = S->base[S->front];
	S->front = (S->front + 1) % MAXSIZE;
	return OK;
}
Status getHead(SequenceQueue S, QElemType *e)
{
	if (S.front == S.rear) return ERROR;
	*e = S.base[S.front];
	return OK;
}
Status queueTraverse(SequenceQueue S, void(*visit)(QElemType*))
{
	int p = S.front;
	while (p == S.rear)
	{
		visit(&(S.base[p]));
		p++;
	}
	return OK;
}