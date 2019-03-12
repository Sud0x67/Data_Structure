#pragma once
#ifndef LINKLIST_H
//֮ǰ���������;�ΪElement���������б���һ��
typedef int ElemType;
typedef struct LNode {//�������
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


