#pragma once
#ifndef LISTQUEUE_H
#define LISTQUEUE_H
//队列的链式表示;队列以带头结点的链表表示；Q->rear指向队尾；
typedef int QElemType;
typedef struct QNode {
	QElemType data;
	struct QNode * next;
}QNode, *QueuePtr;
typedef struct Queue {
	QueuePtr head, rear;
	int len;
}LinkQueue;
Status initQueue(LinkQueue * Q);

Status destroyQueue(LinkQueue * Q);

Status clearQueue(LinkQueue * Q);

int queueLength(LinkQueue Q);

Status queueEmpty(LinkQueue Q);

Status getHead(LinkQueue Q, QElemType * e);

Status enQueue(LinkQueue * Q, QElemType e);

Status deQueue(LinkQueue * Q, QElemType * e);

Status queueTraverse(LinkQueue Q, void(*visit)(QElemType *));

#endif // !LISTQUEUE_H


