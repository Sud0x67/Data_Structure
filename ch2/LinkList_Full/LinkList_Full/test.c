#include<stdio.h>
#include"PreDefined.h"
#include"LinkList.h"
void main()
{
	Link p;
	makeNode(&p, 4);
	printf("L�ĵ�ַ��%d,ֵ��%d", p, p->data);
	freeNode(p);
	printf("L�ĵ�ַ��%d,ֵ��%d", p, p->data);
	system("pause");
}