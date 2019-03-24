#include<stdio.h>
#include <stdlib.h>
#include "PreDefined.h"
#include "ListQueue.h"
/*typedef int QElemType;
typedef struct QNode {
	QElemType data;
	struct QNode * next;
}QNode,*QueuePtr;
typedef struct Queue {
	QueuePtr head, rear;
	int len;
}LinkQueue;*/
//构造一个空队列
Status initQueue(LinkQueue *Q)
{
	Q->head = (QueuePtr)malloc(sizeof(QNode));
	if (!Q)return OVERFLOW;
	Q->head->next = NULL;
	Q->rear = Q->head;
	Q->len = 0;
	return OK;
}
Status destroyQueue(LinkQueue *Q) {
	QueuePtr p = Q->head;
	QueuePtr q;
	while (!p)
	{
		q = p;
		p = p->next;
		free(q);
	}
	Q->rear = NULL;
	Q->head = NULL;
	Q->len = 0;
	return OK;
}
Status clearQueue(LinkQueue *Q) {
	QueuePtr p = Q->head->next;
	QueuePtr q;
	while (p)
	{
		q = p;
		p = p->next;
		free(q);
	}
	Q->rear = Q->head;
	Q->len = 0;
	return OK;
}
int queueLength(LinkQueue Q)
{
	return Q.len;
}
Status queueEmpty(LinkQueue Q)
{
	return Q.len == 0;
}
Status getHead(LinkQueue Q, QElemType*e)
{
	if (Q.head->next) {
		*e = Q.head->next->data;
		return OK;
	}
	return INFEASIBLE;
}
Status enQueue(LinkQueue *Q, QElemType e) {
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	p->data = e;
	p->next = Q->rear->next;
	Q->rear->next = p;
	Q->rear = p;
	Q->len++;
	return OK;
}
Status deQueue(LinkQueue *Q, QElemType *e)
{
	QueuePtr p = Q->head->next;
	if (p) {
		*e = p->data;
		Q->head->next = p->next;
		free(p);
		Q->len--;
		return OK;
	}
	else
		return INFEASIBLE;
}
Status queueTraverse(LinkQueue Q, void(*visit)(QElemType*))
{
	QueuePtr p = Q.head->next;
	while (p != NULL)
	{
		visit(&(p->data));
		p = p->next;
	}
	return OK;
}