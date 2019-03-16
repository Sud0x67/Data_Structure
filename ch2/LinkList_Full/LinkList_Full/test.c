#include <stdio.h>
#include <stdlib.h>
#include "PreDefined.h"
#include "LinkList.h"
void print_e(ElemType *c)
{
	printf("\t%d", *c);
}
Status compare(ElemType c, ElemType e)
{
	return c == e;
}
void main()
{
	Link p;
	LinkList L;
	initList(&L);
	printf("\nL的head是%d，tail是%d，L的长度是%d,是否为空%d\n", L.head, L.tail, listLength(L), listEmpty(L));
	makeNode(&p, 4);
	inFirst(&L, L.head, p);
	printf("\nL的head是%d，tail是%d，L的长度是%d,是否为空%d\n", L.head, L.tail, listLength(L), listEmpty(L));
	for (int i = 100; i >0; i--)
	{
		Link q;
		makeNode(&q, i);
		inFirst(&L, L.head, q);
	}
	listTraverse(L, print_e);
	printf("\nL的head是%d，tail是%d，L的长度是%d,是否为空%d\n", L.head, L.tail, listLength(L), listEmpty(L));
	//测试locate
	LocatePos(L, 64, &p);
	print_e(&p->data);
	//
	Link y;
	makeNode(&y, 1000);
	insBefore(&L, &p, &y);
	printf("\nL的head是%d，tail是%d，L的长度是%d,是否为空%d\n", L.head, L.tail, listLength(L), listEmpty(L));
	makeNode(&y, 1010);
	insBefore(&L, &p, &y);
	printf("\nL的head是%d，tail是%d，L的长度是%d,是否为空%d\n", L.head, L.tail, listLength(L), listEmpty(L));
	makeNode(&y, 1110);
	insAfter(&L, &p, &y);
	printf("\nL的head是%d，tail是%d，L的长度是%d,是否为空%d\n", L.head, L.tail, listLength(L), listEmpty(L));
	makeNode(&y, 1111);
	
	insAfter(&L, &p, &y);
	printf("\nL的head是%d，tail是%d，L的长度是%d,是否为空%d\n", L.head, L.tail, listLength(L), listEmpty(L));
	listTraverse(L, print_e);
	printf("测试append函数");
	makeNode(&y, 900);
	Link temp=y;
	for (int i = 1; i < 20; i++) {
		Link k;
		makeNode(&k, 900 + i);
		temp->next = k;
		temp = k;
	}
	append(&L, y);
	printf("\nL的head是%d，tail是%d，L的长度是%d,是否为空%d\n", L.head, L.tail, listLength(L), listEmpty(L));
	listTraverse(L, print_e);
	//测试LocateElement
	for (int i = 1; i < 100; i++)
	{
		Link q = locateElement(L, i, compare);
		print_e(&q->data);
	}
	getchar();
	Link q = priorPos(L, p);
	setCurrentElement(q, 999);
	print_e(&q->data);
	q = nextPos(L, q);
	ElemType e0 = getCurrentElement(q);
	print_e(&e0);
	print_e(&q->data);
	getchar();
	q = getHead(L);
	print_e(&q->data);
	q = getLast(L);
	print_e(&q->data);
	//测试remove；
	for (int i = 1; i < 200; i++)
	{
		Link q;
		remove(&L, &q);
		print_e(&(q->data));
	}
	printf("\nL的head是%d，tail是%d，L的长度是%d,是否为空%d\n", L.head, L.tail, listLength(L), listEmpty(L));
	clearList(&L);
	printf("\nL的head是%d，tail是%d，L的长度是%d,是否为空%d\n", L.head, L.tail, listLength(L), listEmpty(L));
	destroyList(&L);
	printf("\nL的head是%d，tail是%d，L的长度是%d,是否为空%d\n", L.head, L.tail, listLength(L), listEmpty(L));
	system("pause");
}