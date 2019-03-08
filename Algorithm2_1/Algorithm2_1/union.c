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
Status unionList(SqList *a, SqList b)
{
	for (int i = 1; i <= b.length; i++)
	{
		if (locateElement(*a, b.element[i-1], compare) == INFEASIBLE)
		{
			listInsert(a, a->length + 1, b.element[i - 1]);
		}
	}
}
//测试unionList函数
void main()
{

	SqList LA,LB;
	int j, k;
	//测试初始化LA
	initList(&LA);
	printf("线性表AL.element=%u L.length=%d L.listsize=%d\n", LA.element, LA.length, LA.listsize);
	//给LA插入1,2,3,4，5
	for (j = 1; j <= 5; j++)
		listInsert(&LA, j, j);
	printf("对L插入5个元素\n");
	printf("L.element=%u L.length=%d L.listsize=%d\n", LA.element, LA.length, LA.listsize);
	listTraverse(&LA,print_e);
	printf("\n");
	//初始化LB
	initList(&LB);
	printf("线性表BL.element=%u L.length=%d L.listsize=%d\n", LB.element, LB.length, LB.listsize);
	//给LB插入6,7,8,9,10
	for (j = 1; j <= 5; j++)
		listInsert(&LB, j, j+5);
	printf("对LB插入5个元素\n");
	printf("L.element=%u L.length=%d L.listsize=%d\n", LB.element, LB.length, LB.listsize);
	listTraverse(&LB, print_e);
	printf("\n");
	unionList(&LA, LB);
	printf("合并后\n");
	printf("L.element=%u L.length=%d L.listsize=%d\n", LA.element, LA.length, LA.listsize);
	listTraverse(&LA, print_e);
	printf("\n");
	system("pause");
}