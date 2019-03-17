#include <stdio.h>
#include <stdlib.h>
#include "PreDefined.h"
#include "LinkList.h"
#include "Algorithm2_20r21.h"
void print_e(ElemType *c)
{
	printf("\t%d", *c);
}
Status compare(ElemType c, ElemType e)
{
	return c <= e;
}
void main()
{
	Link p;
	LinkList La,Lb,Lc;
	initList(&La);
	initList(&Lb);
	printf("\nLa��head��%d��tail��%d��La�ĳ�����%d,�Ƿ�Ϊ��%d\n",
		La.head, La.tail, listLength(La), listEmpty(La));
	for (int i = 100; i >0; i--)
	{
		Link q;
		makeNode(&q, i);
		inFirst(&La, La.head, q);
	}
	listTraverse(La, print_e);
	//listInsertL(&La,20,999);
	printf("\nLa��head��%d��tail��%d��La�ĳ�����%d,�Ƿ�Ϊ��%d\n",
		La.head, La.tail, listLength(La), listEmpty(La));
	//listTraverse(La, print_e);
	for (int i = 100; i >0; i-=2)
	{
		Link q;
		makeNode(&q, i);
		inFirst(&Lb, Lb.head, q);
	}
	listTraverse(Lb, print_e);
	//listInsertL(&La,20,999);
	printf("\nLb��head��%d��tail��%d��Lb�ĳ�����%d,�Ƿ�Ϊ��%d\n",
		Lb.head, Lb.tail, listLength(Lb), listEmpty(Lb));
	mergeList2(&La, &Lb, &Lc, compare);
	listTraverse(Lc, print_e);
	//listInsertL(&La,20,999);
	printf("\nLc��head��%d��tail��%d��Lc�ĳ�����%d,�Ƿ�Ϊ��%d\n",
		Lc.head, Lc.tail, listLength(Lc), listEmpty(Lc));
	printf("\nLb��head��%d��tail��%d��Lb�ĳ�����%d,�Ƿ�Ϊ��%d\n",
		Lb.head, Lb.tail, listLength(Lb), listEmpty(Lb));
	printf("\nLa��head��%d��tail��%d��La�ĳ�����%d,�Ƿ�Ϊ��%d\n",
		La.head, La.tail, listLength(La), listEmpty(La));
	system("pause");
}