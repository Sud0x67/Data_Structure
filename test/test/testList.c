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
void main()
{

	SqList L;
	Elementtype e, e0;
	Status i;
	int j, k;
	//���Գ�ʼ������
	i = initList(&L);
	printf("���Ա�L.element=%u L.length=%d L.listsize=%d\n", L.element, L.length, L.listsize);
	//����insert����
	for (j = 1; j <= 5; j++)
		i = listInsert(&L, j, 1);
	printf("��L����5��Ԫ��\n");
	printf("L.element=%u L.length=%d L.listsize=%d\n", L.element, L.length, L.listsize);
	//����travers����
	listTraverse(&L,print_e);
	printf("\n");
	//����clear��destroy����
	printf("listEmpty\?:=%d\n", listEmpty(L));
	clearList(&L);
	printf("L.element=%u L.length=%d L.listsize=%d\n", L.element, L.length, L.listsize);
	printf("listEmpty\?:=%d\n", listEmpty(L));
	destroyList(&L);
	printf("L.element=%u L.length=%d L.listsize=%d\n", L.element, L.length, L.listsize);
	printf("listEmpty\?:=%d\n", listEmpty(L));
	//����insert����
	//initList(&L);
	for (j = 1; j <= 100; j++)
	{
		listInsert(&L, j, j);
		printf("�����%d��Ԫ��\n",j);
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
		printf("�����%d��Ԫ��\n", j);
		printf("L.element=%u L.length=%d L.listsize=%d\n", L.element, L.length, L.listsize);
		listTraverse(&L, print_e);
		printf("\n");
	}
	getchar();
	for (j = 1; j <= 200; j++)
	{
		listInsert(&L, j, j);
		printf("�����%d��Ԫ��\n", j);
		printf("L.element=%u L.length=%d L.listsize=%d\n", L.element, L.length, L.listsize);
		listTraverse(&L, print_e);
		printf("\n");
	}
	getchar();
	//����getElement����
	printf("����getElement����\n");
	for (int i = 1; i <= L.length; i++)
	{
		getElement(L, i, &e);
		printf("\t%d", e);
	}
	getchar();
	//����getElement����
	printf("����getPriorElement����\n");
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
	//nextElement()����
	printf("����nextElement����\n");
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
	//listDelete����
	printf("����listDelete����\n");
	for (int i = 1; i <= L.length; i++)//ɾ���������ڱ��е�˳��ı䣬�ʺ���û��ȫ��ɾ�ֻ꣬�ܴ�һ��ɾɾ����
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
	//locate����
	printf("����locate����\n");
	for (int i = 1; i <= L.length; i++)//ɾ���������ڱ��е�˳��ı䣬�ʺ���û��ȫ��ɾ�ֻ꣬�ܴ�һ��ɾɾ����
	{
		int s = locateElement(L, i, compare);
		if (s!= INFEASIBLE)
		{
			printf("%dλ�����Ա��е�%dλ\t",i,s);
		}
		else
		{
			printf("\tINFEASIBLE\t");
		}
	}
	listTraverse(&L, print_e);
	system("pause");

	
}