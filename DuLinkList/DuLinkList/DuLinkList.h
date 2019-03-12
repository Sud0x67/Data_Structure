#pragma once
#ifndef DULINKLIST_H
#define DULINKLIST_H
#include"PreDefined.h"
//�������Ա����ʽ��ʾ��ʽ
//��ʽ���Ա����ͷ��㣬ͷ���洢��ʽ����
typedef int Element;
/*
��ʵ֤��typedef���������Ǵ����
typedef struct{
Element data;
LNode *next;//����ΪǶ�׵ĵĽṹָ��ʹ������ȫ��
}LNode, *linkList;

*/
typedef struct DuLNode{
	Element data;
	struct DuLNode *prior,*next;//����ΪǶ�׵ĵĽṹָ��ʹ������ȫ����������Ҳ��֪��Ϊɶ
}DuLNode,*DuLinkList;
 
Status initList(DuLinkList *L);

Status listEmpty(DuLinkList L);

int listLength(DuLinkList L);

Status creatList(DuLinkList L, int n);

Status destroyList(DuLinkList L);
Status getElement(DuLinkList L, int i, Element * e);
int locateElement(DuLinkList L, Element e, Status(*compare)(Element, Element));
Status getPriorElement(DuLinkList L, Element e, Element * pre_e);
Status nextElement(DuLinkList L, Element e, Element * pre_e);
Status listInsert(DuLinkList L, int i, Element e);
Status listDelete(DuLinkList L, int i, Element * e);
Status listTraverse(DuLinkList L, void(*visit)(Element *));
#endif // !LINKLIST_H


