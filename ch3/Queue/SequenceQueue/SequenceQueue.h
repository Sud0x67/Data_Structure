#pragma once
#ifndef SEQUENCEQUEUE_H
#define SEQUENCEQUEUE_H
//ѭ���������rearָ��ǰԪ�ص���һλ��fontָ��ͷ��Ԫ�أ�
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


