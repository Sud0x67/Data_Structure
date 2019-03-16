#include <stdio.h>
#include<stdlib.h>
#include"PreDefined.h"
#include"ListQueue.h"

void print_e(QElemType* c)
{
	printf("\t%d", *c);
}
//����һ�����������ӳ��Ӻ�����
void main() {
	LinkQueue Q;
	initQueue(&Q);
	printf("Q�Ļ������head��%#p��rear��%p��Len��%d���Ƿ�Ϊ�գ�%d", Q.head, Q.rear, queueLength(Q), queueEmpty(Q));
	for (int i = 100; i < 200; i++)
	{
		QElemType e;
		enQueue(&Q, i);
		getHead(Q, &e);
		print_e(&e);
	}
	queueTraverse(Q, print_e);
	printf("Q�Ļ������head��%#p��rear��%p��Len��%d���Ƿ�Ϊ�գ�%d", Q.head, Q.rear, queueLength(Q), queueEmpty(Q));
	for (int i = 100; i < 200; i++)
	{
		QElemType e;
		deQueue(&Q, &e);
		getHead(Q, &e);
		print_e(&e);
	}
	printf("Q�Ļ������head��%#p��rear��%p��Len��%d���Ƿ�Ϊ�գ�%d", Q.head, Q.rear, queueLength(Q), queueEmpty(Q));
	clearQueue(&Q);
	printf("Q�Ļ������head��%#p��rear��%p��Len��%d���Ƿ�Ϊ�գ�%d", Q.head, Q.rear, queueLength(Q), queueEmpty(Q));
	destroyQueue(&Q);
	printf("\n**************************\n");
	printf("\t%d\t%p\t%d", NULL, NULL, !NULL);
	printf("\n**************************\n");
	printf("Q�Ļ������head��%#p��rear��%p��Len��%d���Ƿ�Ϊ�գ�%d", Q.head, Q.rear, queueLength(Q), queueEmpty(Q));
	system("pause");

}