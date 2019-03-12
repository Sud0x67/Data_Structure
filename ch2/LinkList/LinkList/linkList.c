#include<stdio.h>
#include"PreDefined.h"
#include "linkList.h"
//
//��ʼ�����Ҫ�ı�һ��ָ���ֵ�봫��һ��ָ���ָ�룬С����Ӧ�ö���ò
Status initList(linkList *L)
{
	*L = (linkList)malloc(sizeof(LNode));
	(*L)->data = 0;
	(*L)->next = NULL; 
	return OK;
}

Status listEmpty(linkList L)
{
	return L->data == 0;
}
int listLength(linkList L)
{
	return L->data;
}
//�㷨2-10 Ҳд��������
Status creatList(linkList L, int n)
{
	if (!L) {
		initList(L);
	}
	for (int i = 1; i <= n; i++)
	{
		Element e;
		printf("�������%d��Ԫ�ص�ֵ��", i);
		scanf("%d", &e);
		struct LNode* p = (struct LNode*)malloc(sizeof(LNode));
		p->data = e;
		p->next = L->next;
		L->next = p;
		L->data++;
	}
	return OK;
}
Status destroyList(linkList L)
{
	struct LNode *q;
	struct LNode *p = L->next;
	while (p != NULL) {
		q = p;
		p = p->next;
		free(q);
	}
	L->next = NULL;
	L->data = 0;
}
Status getElement(linkList L, int i, Element *e)
{
	linkList p = L;
	if (i<1 && i>listLength(L)) return ERROR;
	for (int j = 1; j <= i; j++)
	{
		p = p->next;
	}
	*e = p->data;
	return OK;
}
int locateElement(linkList L, Element e, Status(*compare)(Element, Element))
{
	int i = 1;
	linkList p = L->next;
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
Status getPriorElement(linkList L, Element e, Element* pre_e)
{
	int i = 1;
	linkList p = L->next;
	for (i = 1; i <= L->data; i++)
	{
		if (p->next!=NULL&&p->next->data == e)
		{
			*pre_e=p->data;
			return OK;
		}
		else
		{
			p = p->next;
		}

	}
	return INFEASIBLE;
}
Status nextElement(linkList L, Element e, Element* next_e)
{
	int i = 1;
	linkList p = L->next;
	for (i = 1; i <= L->data; i++)
	{
		if (p != NULL&&p->data == e)
		{
			if (p->next != NULL)
			{
				*next_e= p->next->data;
				return OK;
			}
		}
		else
		{
			p = p->next;
		}
	}
	return INFEASIBLE;
}
Status listInsert(linkList L, int i, Element e)//����һ��Ԫ��
{
	if (i<1 || i>L->data + 1)return ERROR;
	int j = 1; 
	linkList p = L;
	for (j = 1; j <i; j++)
	{
		p = p->next;
	}
	linkList q = (linkList)malloc(sizeof(LNode));
	q->data = e;
	q->next = p->next;
	p->next = q;
	L->data++;
	return OK;
}
//ɾ��һ��Ԫ�أ�����ɾ����Ԫ�ظ�ֵ��e
Status listDelete(linkList L, int i, Element *e)
{
	if (i<1 ||i>L->data)return ERROR;
	int j = 1;
	linkList p = L;
	for (j = 1; j <i; j++)
	{
		p = p->next;
	}
	linkList q = p->next;
	*e = q->data;
	p->next = p->next->next;
	free(q);
	L->data--;
	return OK;
}
//�������ݱ�
Status listTraverse(linkList L, void(*visit)(Element*))
{
	linkList p = L->next;
	while (p!=NULL)
	{
		visit(&(p->data));
		p = p->next;
	}
	return OK;
}
