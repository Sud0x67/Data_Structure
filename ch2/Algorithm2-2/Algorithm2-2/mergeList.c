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

//前提：LA和LB均为非递减排列，将LA和LB中的值插入LC中使其仍未非递减排列
void mergeList(SqList LA, SqList LB, SqList *LC)
{
	int i, j,k;
	Elementtype e1, e2;
	for (i = 1, j = 1, k=1; i <= LA.length&&j <= LB.length; )
	{
		getElement(LA, i, &e1);
		getElement(LB, j, &e2);
		if (e1 < e2)
		{
			listInsert(LC, k, e1);
			k++, i++;
		}
		else
		{
			listInsert(LC, k, e2);
			k++, j++;
		}
	}
	while (i <= LA.length)
	{
		getElement(LA, i, &e1);
		listInsert(LC, k, e1);
		k++, i++;
	}
	while (j <= LB.length)
	{
		getElement(LB, j, &e2);
		listInsert(LC, k, e2);
		k++, j++;
	}
}
//测试mergeList函数
void main()
{

	SqList LA,LB,LC;
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
	//给LB插入2,3,4，5,6
	for (j = 1; j <= 5; j++)
		listInsert(&LB, j, j+1);
	printf("对LB插入5个元素\n");
	printf("L.element=%u L.length=%d L.listsize=%d\n", LB.element, LB.length, LB.listsize);
	listTraverse(&LB, print_e);
	printf("\n");
	initList(&LC);
	mergeList(LA, LB, &LC);
	printf("合并后\n");
	printf("L.element=%u L.length=%d L.listsize=%d\n", LC.element, LC.length, LC.listsize);
	listTraverse(&LC, print_e);
	printf("\n");
	system("pause");
}