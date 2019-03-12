#include <stdio.h>
#include "PreDefined.h"
#include "List.h"
//visit����
void print_e(Elementtype *c)
{
	printf("\t%d", *c);
}
//compare����
Status compare(Elementtype c, Elementtype c2)//compare����
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
//����unionList����
void main()
{

	SqList LA,LB;
	int j, k;
	//���Գ�ʼ��LA
	initList(&LA);
	printf("���Ա�AL.element=%u L.length=%d L.listsize=%d\n", LA.element, LA.length, LA.listsize);
	//��LA����1,2,3,4��5
	for (j = 1; j <= 5; j++)
		listInsert(&LA, j, j);
	printf("��L����5��Ԫ��\n");
	printf("L.element=%u L.length=%d L.listsize=%d\n", LA.element, LA.length, LA.listsize);
	listTraverse(&LA,print_e);
	printf("\n");
	//��ʼ��LB
	initList(&LB);
	printf("���Ա�BL.element=%u L.length=%d L.listsize=%d\n", LB.element, LB.length, LB.listsize);
	//��LB����6,7,8,9,10
	for (j = 1; j <= 5; j++)
		listInsert(&LB, j, j+5);
	printf("��LB����5��Ԫ��\n");
	printf("L.element=%u L.length=%d L.listsize=%d\n", LB.element, LB.length, LB.listsize);
	listTraverse(&LB, print_e);
	printf("\n");
	unionList(&LA, LB);
	printf("�ϲ���\n");
	printf("L.element=%u L.length=%d L.listsize=%d\n", LA.element, LA.length, LA.listsize);
	listTraverse(&LA, print_e);
	printf("\n");
	system("pause");
}