#pragma once
#ifndef LINKLIST_H
//之前链表中类型均为Element，现与书中保持一致
typedef int ElemType;
typedef struct LNode {//结点类型
	ElemType data;
	struct LNode *next;
}*Link, *Position;
typedef struct {
	Link head, tail;
	int len;
}LinkList;
Status makeNode(Link * p, ElemType e);
void freeNode(Link p);
#endif // LINKLIST_H


