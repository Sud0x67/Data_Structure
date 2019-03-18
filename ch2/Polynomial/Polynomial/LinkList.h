#pragma once
#ifndef LINKLIST_H
#define LINKLIST_H
//之前链表中类型均为Element，现与书中保持一致
#include"ElemType.h"
typedef struct LNode {//结点类型
	ElemType data;
	struct LNode *next;
}*Link, *Position;
typedef struct {
	Link head, tail;
	int len;
}LinkList;
Status makeNode(Link * p, ElemType e);
void freeNode(Link * p);
Status initList(LinkList * L);
Status destroyList(LinkList *L);
Status clearList(LinkList *L);
Status inFirst(LinkList * L, Link h, Link s);
Status delFirst(LinkList * L, Link h, Link * q);
Status append(LinkList * L, Link s);
Status remove(LinkList * L, Link * q);
Status insBefore(LinkList * L, Link * p, Link * s);

Status insAfter(LinkList * L, Link * p, Link * s);

Status LocatePos(LinkList L, int i, Link * p);

Status listTraverse(LinkList L, void(*visit)(ElemType *));
Status locateElement(LinkList L, ElemType e, Position * q, Status(*compare)(ElemType, ElemType));
Status orderInsert(LinkList * L, ElemType e, Status(*compare)(ElemType, ElemType));
Status setCurrentElement(Link p, ElemType e);
ElemType getCurrentElement(Link p);
Status listEmpty(LinkList L);
int listLength(LinkList L);
Position getHead(LinkList L);

Position getLast(LinkList L);

Position priorPos(LinkList L, Link p);

Position nextPos(LinkList L, Link p);
#endif // LINKLIST_H


