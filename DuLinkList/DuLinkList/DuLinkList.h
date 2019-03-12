#pragma once
#ifndef DULINKLIST_H
#define DULINKLIST_H
#include"PreDefined.h"
//定义线性表的链式表示方式
//链式线性表具有头结点，头结点存储链式表长度
typedef int Element;
/*
事实证明typedef这样子用是错误的
typedef struct{
Element data;
LNode *next;//必须为嵌套的的结构指针使用类型全名
}LNode, *linkList;

*/
typedef struct DuLNode{
	Element data;
	struct DuLNode *prior,*next;//必须为嵌套的的结构指针使用类型全名！！！我也不知道为啥
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


