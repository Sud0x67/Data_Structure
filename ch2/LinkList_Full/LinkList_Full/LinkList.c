#include<stdio.h>
#include <malloc.h>
#include"PreDefined.h"
#include "LinkList.h"
//û�����Ӳ��ԣ�̫��Ѫ������Ժ���°�
//��������������
/*
typedef struct LNode {//�������
ElemType data;
struct LNode *next;
}*Link, *Position;
typedef struct {
Link head, tail;
int len;
}LinkList;
*/
Status makeNode(Link *p,ElemType e)
{
	(*p) = (Link)malloc(sizeof(struct LNode));
	if (!*p)return OVERFLOW;
	(*p)->data = e;
	(*p)->next = NULL;
	return OK;
}
//ָ��ָ��������ͷź�ָ��ǵ���ΪNULL
void freeNode(Link *p)
{
	free(*p);
	*p = NULL;
} 
Status initList(LinkList *L)
{
	Link p;
	Status i;
	if (i= makeNode(&p, 0))
	{
		L->head = p;
		L->tail = p;
		L->len = 0;
		return OK;
	}
	return i;
}
Status destroyList(LinkList *L)
{
	Link q,p=(*L).head;
	while (p!=NULL)
	{
		q = p;
		p = p->next;
		free(q);
	}
	(*L).len = 0;
	(*L).head = NULL;
	(*L).tail = NULL;
	return OK;
}
Status clearList(LinkList *L)
{
	Link q, p = (*L).head->next;
	while (p != NULL)
	{
		q = p;
		p = p->next;
		free(q);
	}
	(*L).head->next = NULL;
	(*L).tail = (*L).head;
	(*L).len = 0;
	return OK;
}
//hָ�����Ա��ͷ��㣬��s������ͷ���֮�󣬵�һ�����֮ǰ��
Status inFirst(LinkList *L, Link h, Link s)
{
	s->next= h->next;
	h ->next = s;
	if (h == (*L).tail) /* hָ��β��� */
		(*L).tail = h->next; /* �޸�βָ�� */
	(*L).len++;
	return OK;
}
//hָ�����Ա��ͷ��㣬��ɾ�������е�һ����㣻
Status delFirst(LinkList *L,Link h, Link *q)
{
	////////
	if (!h->next)return ERROR;
	*q = h->next;
	h->next = h->next->next;
	(*L).len--;
	return OK;
}
//��s��ָ��һ����㣨û��ͷ��㣩����������L֮��//�޸���һ����������
Status append(LinkList *L, Link s)
{
	(*L).tail->next= s;
	Link p = s;
	(*L).len++;
	while (p->next!=NULL)
	{
		p = p->next;
		(*L).len++;
	}
	(*L).tail = p;
	return OK;
}
///test2
//ɾ��β�ڵ���q���أ��ı�βָ��
//remove nnnnnnnnnnnnnnn
Status remove(LinkList *L, Link *q)
{
	if (L->tail==L->head) return ERROR;
	(*q) = (*L).tail;
	(*L).len--;
	Link p= (*L).head;
	for (int i = 1; i <= (*L).len; i++)
	{
		p = p->next;
	}
	p->next = NULL;
	(*L).tail = p;
	return OK;
}
//��֪pָ��L�е�һ����㣬��S����p���֮ǰ,���ı�p��ָ��ָ��s
Status insBefore(LinkList *L, Link *p, Link *s)
{
	Link q = L->head;
	while (q!=NULL&&q->next != (*p))
	{
		q = q->next;
	}
	if (!q)return ERROR;
	q ->next = *s;
	(*s)->next = (*p);
	(*p) = *s;
	L->len++;
	return OK;
}
//��֪pָ��L�е�һ����㣬��S����p���֮��,���ı�p��ָ��ָ��s
Status insAfter(LinkList *L, Link *p, Link *s)
{
	if (L->tail == *p)L->tail = *s;
	(*s)->next = (*p)->next;
	(*p)->next = *s;
	(*p) = *s;
	L->len++;
	return OK;
}
//�޸�p����ֵ
Status setCurrentElement(Link p, ElemType e)
{
	p->data = e;
	return OK;
}
//����p����ֵ
ElemType getCurrentElement(Link p)
{
	return p->data;
}
Status listEmpty(LinkList L)
{
	if (L.len == 0)return TRUE;
	return FALSE;
}
int listLength(LinkList L)
{
	return L.len;
}
Position getHead(LinkList L)
{
	return L.head;
}
Position getLast(LinkList L)
{
	return L.tail;
}
Position priorPos(LinkList L, Link p)
{
	Link q = L.head;
	while (q!=NULL&&q->next != p)
	{
		q = q->next;
	}
	if (q == NULL)return NULL;
	return q;
 }
Position nextPos(LinkList L, Link p)
{
	if (!p)return NULL;
	return p->next;
}
Status LocatePos(LinkList L, int i, Link *p)
{
	if (i <1 || i>L.len)return ERROR;
	Link ptr=L.head;
	int q;
	for (q = 1; q <=i; q++)
	{
		ptr = ptr->next;
	}
	(*p) = ptr;
	return OK;
}
Position locateElement(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType))
{
	Link p = L.head->next;
	while (p!=NULL&&(*compare)(e, p->data) != TRUE)
	{
		p = p->next;
	}
	if (p!=NULL) {
		return p;
	}
	else
	{
		return NULL;
	}
}
Status listTraverse(LinkList L, void(*visit)(ElemType*))
{
	Link p = L.head->next;
	while (p != NULL)
	{
		visit(&(p->data));
		p = p->next;
	}
	return OK;
}
