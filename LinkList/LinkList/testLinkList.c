#include <stdio.h>
#include"PreDefined.h"
#include "linkList.h"
//����linkList�еĺ���
Status compare(Element c, Element c2)//compare����
{
	return c == c2;
}


int main()
{
	linkList L;
	Element e;
	//����init
	initList(&L);
	printf("����L�ĵ�ַΪL��%d������ΪL->data��%d���Ƿ�Ϊ�գ�%d\n",L,L->data,listEmpty(L));
	//����create
	creatList(L, 5);
	//����listLength
	printf("����L�ĵ�ַΪL��%d������ΪL->data��%d���Ƿ�Ϊ�գ�%d\n", L, listLength(L), listEmpty(L));
	//����getElement����
	for (int i = 1; i <= 5; i++)
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
	for (int i = 1; i <= 5; i++)
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
	for (int i = 1; i <= 6; i++)
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
	for (int i = 1; i <= 6; i++)
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
	printf("����insert");
	
	system("pause");
}