#pragma once
#ifndef LINKLIST_H
#define LINKLIST_H
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
typedef struct LNode{
	Element data;
	struct LNode *next;//����ΪǶ�׵ĵĽṹָ��ʹ������ȫ����������Ҳ��֪��Ϊɶ
}LNode,*linkList;
 
Status initList(linkList *L);

Status listEmpty(linkList L);

int listLength(linkList L);

Status creatList(linkList L, int n);

Status destroyList(linkList L);
Status getElement(linkList L, int i, Element * e);
int locateElement(linkList L, Element e, Status(*compare)(Element, Element));
Status getPriorElement(linkList L, Element e, Element * pre_e);
Status nextElement(linkList L, Element e, Element * pre_e);
Status listInsert(linkList L, int i, Element e);
Status listDelete(linkList L, int i, Element * e);
Status listTraverse(linkList L, void(*visit)(Element *));
#endif // !LINKLIST_H


