#include <stdio.h>
#include<stdlib.h>
#include"PreDefined.h"
#include"SequenceQueue.h"

void print_e(QElemType* c)
{
	printf("\t%d", *c);
}
//����һ�����������ӳ��Ӻ�����
void main() {
	SequenceQueue Q;
	initQueue(&Q);
	printf("Q�Ļ������head��%d��rear��%d��Len��%d���Ƿ�Ϊ�գ�%d", Q.front, Q.rear, queueLength(Q), queueEmpty(Q));
	for (QElemType i = 100; i < 300; i++)
	{
		QElemType e=0;
		enQueue(&Q, i);
		getHead(Q, &e);
		print_e(&e);
	}
	//queueTraverse(Q, print_e);
	printf("Q�Ļ������head��%d��rear��%d��Len��%d���Ƿ�Ϊ�գ�%d", Q.front, Q.rear, queueLength(Q), queueEmpty(Q));
	for (int i = 100; i < 200; i++)
	{
		QElemType e;
		deQueue(&Q, &e);
		getHead(Q, &e);
		print_e(&e);
	}
	rintf("Q�Ļ������head��%d��rear��%d��Len��%d���Ƿ�Ϊ�գ�%d", Q.front, Q.rear, queueLength(Q), queueEmpty(Q));
	clearQueue(&Q);
	rintf("Q�Ļ������head��%d��rear��%d��Len��%d���Ƿ�Ϊ�գ�%d", Q.front, Q.rear, queueLength(Q), queueEmpty(Q));
	destroyQueue(&Q);
	printf("\n**************************\n");
	printf("\t%d\t%p\t%d", NULL, NULL, !NULL);
	printf("\n**************************\n");
	rintf("Q�Ļ������head��%d��rear��%d��Len��%d���Ƿ�Ϊ�գ�%d", Q.front, Q.rear, queueLength(Q), queueEmpty(Q));
	system("pause");
}