#include<stdio.h>
#include"PreDefined.h"
#include "DuLinkList.h"
//具有头结点的双向循环列表
//双链表的结构体：
//typedef struct DuLNode{
//Element data;
//struct DuLNode *prior, *next;//必须为嵌套的的结构指针使用类型全名！！！我也不知道为啥
//}DuLNode, *DuLinkList;
//初始化如果要改变一个指针的值请传入一个指针的指针，小孩子应该懂礼貌
Status initList(DuLinkList *PtrL)
{
	*PtrL = (DuLinkList)malloc(sizeof(DuLNode));
	(*PtrL)->data = 0;//头结点的数据存储链表长度
	(*PtrL)->prior =(*PtrL);
	(*PtrL)->next = (*PtrL);
	return OK;
}

Status listEmpty(DuLinkList L)
{
	return L->next == L;//data=0，或头结点指向自身都是空表
}
int listLength(DuLinkList L)
{
	//return L->data;重新写计算长度的算法
	DuLinkList p = L->next;
	int i = 0;
	while (p!= L)
	{
		p = p->next;
		i++;
	}
	return i;
}
//算法2-10 也写在了这里
Status creatList(DuLinkList L, int n)
{
	if (!L) {
		initList(L);
	}
	for (int i = 1; i <= n; i++)
	{
		Element e;
		printf("请输入第%d个元素的值：", i);
		scanf("%d", &e);
		DuLNode* p = (struct DuLNode*)malloc(sizeof(DuLNode));
		p->data = e;
		//尾部插入
		p->prior = L->prior;
		p->next = L;
		p->next->prior = p;
		p->prior->next = p;
		L->data++;
	}
	return OK;
}
Status destroyList(DuLinkList L)
{
	DuLNode *q;
	DuLNode *p = L->next;
	while (p != L) {
		q = p;
		p = p->next;
		free(q);
	}
	//L->next = NULL;
	//L->data = 0;
	//最后free头结点
	free(L);
	return OK;
}
Status getElement(DuLinkList L, int i, Element *e)
{
	DuLinkList p = L;
	if (i<1 && i>listLength(L)) return ERROR;
	for (int j = 1; j <= i; j++)
	{
		p = p->next;
	}
	*e = p->data;
	return OK;
}
int locateElement(DuLinkList L, Element e, Status(*compare)(Element, Element))
{
	int i = 1;
	DuLinkList p = L->next;
	while ((*compare)(e, p->data) != TRUE&&i<=L->data)
	{
		p=p->next;
		i++;
	}
	if (i <= L->data) {
		return i;
	}
	else
	{
		return INFEASIBLE;
	}
}
Status getPriorElement(DuLinkList L, Element e, Element* pre_e)
{
	DuLinkList p = L->next;
	while (p != L)
	{
		if (p->data == e)break;
		p = p->next;
	}
	if (p == L)
	{
		return INFEASIBLE;
	}
	else if(p==L->next)
	{
		//跳过L；
		*pre_e = p->prior->prior->data;
		return OK;
	}
	else
	{
		*pre_e = p->prior->data;
		return OK;
	}
}
Status nextElement(DuLinkList L, Element e, Element* next_e)
{
	DuLinkList p = L->next;
	while (p != L)
	{
		if (p->data == e)break;
		p = p->next;
	}
	if (p == L)
	{
		return INFEASIBLE;
	}
	else if (p == L->prior)
	{
		//跳过头结点
		*next_e = p->next->next->data;
		return OK;
	}
	else
	{
		*next_e = p->next->data;
		return OK;
	}
}
Status listInsert(DuLinkList L, int i, Element e)//插入一个元素
{
	if (i<1 || i>L->data + 1)return ERROR;
	int j = 1; 
	DuLinkList p = L;
	//单向链表找的前一个结点，现在没必要了
	for (j = 1; j <=i; j++)
	{
		p = p->next;
	}
	DuLinkList q = (DuLinkList)malloc(sizeof(DuLNode));
	q->data = e;
	q->prior = p->prior;
	q->next = p;
	q->prior->next = q;
	q->next->prior = q;
	L->data++;
	return OK;
}
//删除一个元素，并把删除的元素赋值给e
Status listDelete(DuLinkList L, int i, Element *e)
{
	if (i<1 ||i>L->data)return ERROR;
	int j = 1;
	DuLinkList p = L;
	//单向链表找的前一个结点，现在没必要了
	for (j = 1; j <= i; j++)
	{
		p = p->next;
	};
	*e = p->data;
	p->next->prior = p->prior;
	p->prior->next = p->next;
	free(p);
	L->data--;
	return OK;
}
//遍历数据表
Status listTraverse(DuLinkList L, void(*visit)(Element*))
{
	DuLinkList p = L->next;
	while (p!=L)
	{
		visit(&(p->data));
		p = p->next;
	}
	return OK;
}
