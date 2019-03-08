#include <stdio.h>
#include"PreDefined.h"
#include "linkList.h"
//测试linkList中的函数
Status compare(Element c, Element c2)//compare函数
{
	return c == c2;
}


int main()
{
	linkList L;
	Element e;
	//测试init
	initList(&L);
	printf("链表L的地址为L：%d；长度为L->data：%d；是否为空：%d\n",L,L->data,listEmpty(L));
	//测试create
	creatList(L, 5);
	//测试listLength
	printf("链表L的地址为L：%d；长度为L->data：%d；是否为空：%d\n", L, listLength(L), listEmpty(L));
	//测试getElement函数
	for (int i = 1; i <= 5; i++)
	{
		if (getElement(L, i, &e) != ERROR)
		{
			printf("第%d位元素是：%d", i,e);
		}
		else {
			printf("INFESIBLE");
		}
	}
	printf("链表L的地址为L：%d；长度为L->data：%d；是否为空：%d\n", L, listLength(L), listEmpty(L));

	//测试locateElement函数
	for (int i = 1; i <= 5; i++)
	{
		e=locateElement(L, i, compare);
		if ( e!= INFEASIBLE)
		{
			printf("元素%d位于%d\n", i, e);
		}
		else {
			printf("INFESIBLE");
		}
	}
	printf("链表L的地址为L：%d；长度为L->data：%d；是否为空：%d\n", L, listLength(L), listEmpty(L));
	//测时prior和next函数
	for (int i = 1; i <= 6; i++)
	{
		int s=getPriorElement(L, i, &e);
		if (s != INFEASIBLE)
		{
			printf("%d的前一位是%d\n", i, e);
		}
		else {
			printf("INFESIBLE\n");
		}
	}
	printf("链表L的地址为L：%d；长度为L->data：%d；是否为空：%d\n", L, listLength(L), listEmpty(L));
	//测时prior和next函数
	for (int i = 1; i <= 6; i++)
	{
		int s=nextElement(L, i, &e);
		if (s!= INFEASIBLE)
		{
			printf("%d的后一位是%d\n", i, e);
		}
		else {
			printf("INFESIBLE\n");
		}
	}
	printf("链表L的地址为L：%d；长度为L->data：%d；是否为空：%d\n", L, listLength(L), listEmpty(L));
	//测试insert
	printf("测试insert");
	
	system("pause");
}