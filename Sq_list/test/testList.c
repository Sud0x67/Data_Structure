#include <stdio.h>
#include "PreDefined.h"
#include "List.h"
//visit函数
void print_e(Elementtype *c)
{
	printf("\t%d", *c);
}
//compare函数
Status compare(Elementtype c, Elementtype c2)//compare函数
{
	return c == c2;
}
void main()
{

	SqList L;
	Elementtype e, e0;
	Status i;
	int j, k;
	//测试初始化函数
	i = initList(&L);
	printf("线性表L.element=%u L.length=%d L.listsize=%d\n", L.element, L.length, L.listsize);
	//测试insert函数
	for (j = 1; j <= 5; j++)
		i = listInsert(&L, j, 1);
	printf("对L插入5个元素\n");
	printf("L.element=%u L.length=%d L.listsize=%d\n", L.element, L.length, L.listsize);
	//测试travers函数
	listTraverse(&L,print_e);
	printf("\n");
	//测试clear和destroy函数
	printf("listEmpty\?:=%d\n", listEmpty(L));
	clearList(&L);
	printf("L.element=%u L.length=%d L.listsize=%d\n", L.element, L.length, L.listsize);
	printf("listEmpty\?:=%d\n", listEmpty(L));
	destroyList(&L);
	printf("L.element=%u L.length=%d L.listsize=%d\n", L.element, L.length, L.listsize);
	printf("listEmpty\?:=%d\n", listEmpty(L));
	//测试insert函数
	//initList(&L);
	for (j = 1; j <= 100; j++)
	{
		listInsert(&L, j, j);
		printf("插入第%d个元素\n",j);
		printf("L.element=%u L.length=%d L.listsize=%d\n", L.element, L.length, L.listsize);
		listTraverse(&L, print_e);
		printf("\n");
	}
	getchar();
	for (j = 1; j <= 100; j++)
	{
		printf("\t%d", L.element[j-1]);

	}
	getchar();
	for (j = 1; j <= 10; j++)
	{
		listInsert(&L, j, j);
		printf("插入第%d个元素\n", j);
		printf("L.element=%u L.length=%d L.listsize=%d\n", L.element, L.length, L.listsize);
		listTraverse(&L, print_e);
		printf("\n");
	}
	getchar();
	for (j = 1; j <= 200; j++)
	{
		listInsert(&L, j, j);
		printf("插入第%d个元素\n", j);
		printf("L.element=%u L.length=%d L.listsize=%d\n", L.element, L.length, L.listsize);
		listTraverse(&L, print_e);
		printf("\n");
	}
	getchar();
	//测试getElement函数
	printf("测试getElement函数\n");
	for (int i = 1; i <= L.length; i++)
	{
		getElement(L, i, &e);
		printf("\t%d", e);
	}
	getchar();
	//测试getElement函数
	printf("测试getPriorElement函数\n");
	getPriorElement(L, e, &e0);
	printf("\t%d", e0);
	for (int i = 1; i <= L.length; i++)
	{
		if (getPriorElement(L, i, &e)==1)
		{
			printf("\t%d", e);
		}
		else
		{
			printf("\tINFEASIBLE");
		}
		
	}
	//nextElement()函数
	printf("测试nextElement函数\n");
	for (int i = 1; i <= L.length; i++)
	{
		if (nextElement(L, i, &e) == 1)
		{
			printf("\t%d", e);
		}
		else
		{
			printf("\tINFEASIBLE");
		}
	}
	//listDelete函数
	printf("测试listDelete函数\n");
	for (int i = 1; i <= L.length; i++)//删除后数据在表中的顺序改变，故函数没有全部删完，只能从一边删删的完
	{
		if (listDelete(&L, i, &e) == 1)
		{
			printf("\t%d\n", e);
			printf("L.element=%u L.length=%d L.listsize=%d\n", L.element, L.length, L.listsize);
		}
		else
		{
			printf("\tINFEASIBLE");
		}
	}
	//locate函数
	printf("测试locate函数\n");
	for (int i = 1; i <= L.length; i++)//删除后数据在表中的顺序改变，故函数没有全部删完，只能从一边删删的完
	{
		int s = locateElement(L, i, compare);
		if (s!= INFEASIBLE)
		{
			printf("%d位于线性表中第%d位\t",i,s);
		}
		else
		{
			printf("\tINFEASIBLE\t");
		}
	}
	listTraverse(&L, print_e);
	system("pause");

	
}