#include<stdio.h>
#include"PreDefined.h"
#include "LinkList.h"
//没有增加测试，太狗血了这个以后更新吧
//定义完整的链表
/*
typedef struct LNode {//结点类型
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
	if (!*p)return(OVERFLOW);
	(*p)->data = e;
	return OK;
}
//指针指向的内容释放后，指针记得置为NULL
void freeNode(Link *p)
{
	free(*p);
	*p = NULL;
} 
Status initList(LinkList *L)
{
	Link p;
	Status i;
	if (i= makeNode(p, 0))
	{
		//p->next=NULL
		L->head = p;
		L->tail = p;
		L->len = 0;
		return OK;
	}
	return i;
}
Status destroyList(LinkList L)
{
	Link q,p=L.head;
	while (p!=L.tail)
	{
		q = p;
		p = p->next;
		free(q);
	}
	free(p);
	L.len = 0;
	L.head = NULL;
	L.tail = NULL;
	return OK;
}
Status clearList(LinkList L)
{
	Link q, p = L.head->next;
	while (p != L.tail)
	{
		q = p;
		p = p->next;
		free(q);
	}
	free(p);
	L.tail = L.head;
	L.len = 0;
	return OK;
}
Status inFirst(LinkList L, Link h, Link s)
{
	s->next= h->next;
	h ->next = s;
	if (h == L.tail) /* h指向尾结点 */
		L.tail = h->next; /* 修改尾指针 */
	L.len++;
	return OK;
}
Status delFirst(LinkList L,Link h, Link *q)
{
	////////
	*q = h->next;
	h->next = h->next->next;
	return OK;
}
Status append(LinkList L, Link s)
{
	L.tail->next= s;
	L.len++;
	Link p = s;
	while (p->next!=NULL)
	{
		p = p->next;
		L.len++;
	}
	L.tail = p;
	return OK;
}
Status Remove(LinkList L, Link *q)
{
	*q = L.tail;
	L.len--;
	for (int i = 1; i <= L.len; i++)
	{
		L.tail = L.head->next;
	}
}
Status insBefore(LinkList L, Link *p, Link s)
{
	Link q = L.head;
	while (q->next != (*p))
	{
		q = q->next;
	}
	q ->next = s;
	s->next = (*p);
	(*p) = s;
	L.len++;
	return OK;
}
Status insAfter(LinkList L, Link *p, Link s)
{
	s->next = (*p)->next;
	(*p)->next = s;
	(*p) = s;
	return OK;
}
Status setCurrentElement(Link p, ElemType e)
{
	p->data = e;
	return OK;
}
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
	while (q->next != p)
	{
		q = q->next;
	}
	if (q == L.head)return NULL;
	return q;
 }
Position nextPos(LinkList L, Link p)
{
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
		return INFEASIBLE;
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
