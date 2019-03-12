#pragma once
#ifndef LINKLIST_H
#define LINKLIST_H
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
typedef struct LNode{
	Element data;
	struct LNode *next;//必须为嵌套的的结构指针使用类型全名！！！我也不知道为啥
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


