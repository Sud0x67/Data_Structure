#include<stdio.h>
#include"PreDefined.h"
#include"LinkList.h"
void main()
{
	Link p;
	makeNode(&p, 4);
	printf("L的地址是%d,值是%d", p, p->data);
	freeNode(p);
	printf("L的地址是%d,值是%d", p, p->data);
	system("pause");
}