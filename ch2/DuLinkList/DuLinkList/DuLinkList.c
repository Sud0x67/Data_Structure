#include<stdio.h>
#include"PreDefined.h"
#include "DuLinkList.h"
//����ͷ����˫��ѭ���б�
//˫����Ľṹ�壺
//typedef struct DuLNode{
//Element data;
//struct DuLNode *prior, *next;//����ΪǶ�׵ĵĽṹָ��ʹ������ȫ����������Ҳ��֪��Ϊɶ
//}DuLNode, *DuLinkList;
//��ʼ�����Ҫ�ı�һ��ָ���ֵ�봫��һ��ָ���ָ�룬С����Ӧ�ö���ò
Status initList(DuLinkList *PtrL)
{
	*PtrL = (DuLinkList)malloc(sizeof(DuLNode));
	(*PtrL)->data = 0;//ͷ�������ݴ洢������
	(*PtrL)->prior =(*PtrL);
	(*PtrL)->next = (*PtrL);
	return OK;
}

Status listEmpty(DuLinkList L)
{
	return L->next == L;//data=0����ͷ���ָ�������ǿձ�
}
int listLength(DuLinkList L)
{
	//return L->data;����д���㳤�ȵ��㷨
	DuLinkList p = L->next;
	int i = 0;
	while (p!= L)
	{
		p = p->next;
		i++;
	}
	return i;
}
//�㷨2-10 Ҳд��������
Status creatList(DuLinkList L, int n)
{
	if (!L) {
		initList(L);
	}
	for (int i = 1; i <= n; i++)
	{
		Element e;
		printf("�������%d��Ԫ�ص�ֵ��", i);
		scanf("%d", &e);
		DuLNode* p = (struct DuLNode*)malloc(sizeof(DuLNode));
		p->data = e;
		//β������
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
	//���freeͷ���
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
		//����L��
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
		//����ͷ���
		*next_e = p->next->next->data;
		return OK;
	}
	else
	{
		*next_e = p->next->data;
		return OK;
	}
}
Status listInsert(DuLinkList L, int i, Element e)//����һ��Ԫ��
{
	if (i<1 || i>L->data + 1)return ERROR;
	int j = 1; 
	DuLinkList p = L;
	//���������ҵ�ǰһ����㣬����û��Ҫ��
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
//ɾ��һ��Ԫ�أ�����ɾ����Ԫ�ظ�ֵ��e
Status listDelete(DuLinkList L, int i, Element *e)
{
	if (i<1 ||i>L->data)return ERROR;
	int j = 1;
	DuLinkList p = L;
	//���������ҵ�ǰһ����㣬����û��Ҫ��
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
//�������ݱ�
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
