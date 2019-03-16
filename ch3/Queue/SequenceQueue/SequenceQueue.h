#pragma once
#ifndef SEQUENCEQUEUE_H
#define SEQUENCEQUEUE_H
//循环数组队列rear指向当前元素的下一位；font指向头部元素；
#define MAXSIZE 100
typedef int QElemType;
typedef struct {
	QElemType *base;
	int front;
	int rear;
}SequenceQueue;
Status initQueue(SequenceQueue * S);
Status destroyQueue(SequenceQueue * S);
Status clearQueue(SequenceQueue * S);
int queueLength(SequenceQueue S);
Status queueEmpty(SequenceQueue S);
Status enQueue(SequenceQueue * S, QElemType e);
Status deQueue(SequenceQueue * S, QElemType * e);
Status getHead(SequenceQueue S, QElemType * e);
Status queueTraverse(SequenceQueue S, void(*visit)(QElemType *));
#endif // !SEQUENCEQUEUE_H


