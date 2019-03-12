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

//ǰ�᣺LA��LB��Ϊ�ǵݼ����У���LA��LB�е�ֵ����LC��ʹ����δ�ǵݼ�����
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
//����mergeList����
void main()
{

	SqList LA,LB,LC;
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
	//��LB����2,3,4��5,6
	for (j = 1; j <= 5; j++)
		listInsert(&LB, j, j+1);
	printf("��LB����5��Ԫ��\n");
	printf("L.element=%u L.length=%d L.listsize=%d\n", LB.element, LB.length, LB.listsize);
	listTraverse(&LB, print_e);
	printf("\n");
	initList(&LC);
	mergeList(LA, LB, &LC);
	printf("�ϲ���\n");
	printf("L.element=%u L.length=%d L.listsize=%d\n", LC.element, LC.length, LC.listsize);
	listTraverse(&LC, print_e);
	printf("\n");
	system("pause");
}