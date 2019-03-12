#include <stdio.h>
#include"PreDefined.h"
#include "linkList.h"
//mergeList 2-12函数和测试函数写在了一起
Status compare(Element c, Element c2)//compare函数
{
	return c == c2;
}
void print_e(Element *c)
{
	printf("\t%d", *c);
}
void mergeList(linkList La, linkList Lb, linkList Lc)
{
	linkList p1, p2, p3;
	p1 = La->next;
	p2 = Lb->next;
	p3 = Lc;
	while (p1!= NULL&&p2 != NULL)
	{
		if (p1->data <= p2->data)
		{
			p3->next = p1;
			p1 = p1->next;
			p3 = p3->next;
		}
		else
		{
			p3->next = p2;
			p2 = p2->next;
			p3 = p3->next;
		}

	}
	if(p1 != NULL)
	{
		p3->next = p1;
	}
	if(p2 != NULL)
	{
		p3->next = p2;
	}

}
int main()
{
	linkList La,Lb,Lc;
	Element e;
	//测试init
	initList(&La);
	initList(&Lb);
	initList(&Lc);
	creatList(La, 5);
	listTraverse(La, print_e);
	printf("链表A的地址为L：%d；长度为L->data：%d；是否为空：%d\n", La, listLength(La), listEmpty(La));
	creatList(Lb, 5);
	listTraverse(Lb, print_e);
	printf("链表A的地址为L：%d；长度为L->data：%d；是否为空：%d\n", Lb, listLength(Lb), listEmpty(Lb));
	mergeList(La, Lb, Lc);
	listTraverse(Lc, print_e);
	printf("链表A的地址为L：%d；长度为L->data：%d；是否为空：%d\n", Lc, listLength(Lc), listEmpty(Lc));
	system("pause");
}