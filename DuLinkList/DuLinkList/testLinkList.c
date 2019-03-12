#include <stdio.h>
#include"PreDefined.h"
#include "DuLinkList.h"
//����linkList�еĺ���
Status compare(Element c, Element c2)//compare����
{
	return c == c2;
}
void print_e(Element *c)
{
	printf("\t%d", *c);
}

int main()
{
	DuLinkList L;
	Element e;
	//����init
	initList(&L);
	printf("����L�ĵ�ַΪL��%d������ΪL->data��%d���Ƿ�Ϊ�գ�%d\n",L,L->data,listEmpty(L));
	//����create
	creatList(L, 10);
	//����listLength
	printf("����L�ĵ�ַΪL��%d������ΪL->data��%d���Ƿ�Ϊ�գ�%d\n", L, listLength(L), listEmpty(L));
	//����getElement����
	for (int i = 1; i <= 10; i++)
	{
		if (getElement(L, i, &e) != ERROR)
		{
			printf("��%dλԪ���ǣ�%d", i,e);
		}
		else {
			printf("INFESIBLE");
		}
	}
	printf("����L�ĵ�ַΪL��%d������ΪL->data��%d���Ƿ�Ϊ�գ�%d\n", L, listLength(L), listEmpty(L));

	//����locateElement����
	for (int i = 1; i <= 10; i++)
	{
		e=locateElement(L, i, compare);
		if ( e!= INFEASIBLE)
		{
			printf("Ԫ��%dλ��%d\n", i, e);
		}
		else {
			printf("INFESIBLE");
		}
	}
	printf("����L�ĵ�ַΪL��%d������ΪL->data��%d���Ƿ�Ϊ�գ�%d\n", L, listLength(L), listEmpty(L));
	//��ʱprior��next����
	for (int i = 1; i <= 10; i++)
	{
		int s=getPriorElement(L, i, &e);
		if (s != INFEASIBLE)
		{
			printf("%d��ǰһλ��%d\n", i, e);
		}
		else {
			printf("INFESIBLE\n");
		}
	}
	printf("����L�ĵ�ַΪL��%d������ΪL->data��%d���Ƿ�Ϊ�գ�%d\n", L, listLength(L), listEmpty(L));
	//��ʱprior��next����
	for (int i = 1; i <= 10; i++)
	{
		int s=nextElement(L, i, &e);
		if (s!= INFEASIBLE)
		{
			printf("%d�ĺ�һλ��%d\n", i, e);
		}
		else {
			printf("INFESIBLE\n");
		}
	}
	printf("����L�ĵ�ַΪL��%d������ΪL->data��%d���Ƿ�Ϊ�գ�%d\n", L, listLength(L), listEmpty(L));
	//����insert
	printf("����insert\n");
	getchar();
	listTraverse(L, print_e);
	printf("����L�ĵ�ַΪL��%d������ΪL->data��%d���Ƿ�Ϊ�գ�%d\n", L, listLength(L), listEmpty(L));
	for (int i = 1; i <= 100; i++)
	{
		int s = listInsert(L, i, i);
		if (s == ERROR)
		{
			printf("��%d������ʧ��\n", i);
		}
	}

	int s = listInsert(L, 0, 1);
	if (s == ERROR)
	{
		printf("��%d������ʧ��\n", 0);
	}
	getchar();
	listTraverse(L, print_e);
	printf("����L�ĵ�ַΪL��%d������ΪL->data��%d���Ƿ�Ϊ�գ�%d\n", L, listLength(L), listEmpty(L));
	//����delete
	printf("����delete\n");
	getchar();
	listTraverse(L, print_e);
	printf("����L�ĵ�ַΪL��%d������ΪL->data��%d���Ƿ�Ϊ�գ�%d\n", L, listLength(L), listEmpty(L));
	for (int i = 1; i <= 100; i++)
	{
		int s = listDelete(L, i, &e);
		if (s == ERROR)
		{
			printf("��%d��ɾ��ʧ��\n", i);
		}else
		{
			printf("%d\n", e);
		}
	}

	s = listDelete(L, 300, &e);
	if (s == ERROR)
	{
		printf("��%d��ɾ��ʧ��\n", 300);
	}
	else
	{
		printf("%d\n", e);
	}
	listTraverse(L, print_e);
	printf("����L�ĵ�ַΪL��%d������ΪL->data��%d���Ƿ�Ϊ�գ�%d\n", L, listLength(L), listEmpty(L));
	system("pause");
}