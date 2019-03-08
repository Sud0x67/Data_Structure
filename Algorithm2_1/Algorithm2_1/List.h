#ifndef LIST_H
#define LIST_H
#include "PreDefined.h"
#define LIST_INIT_SIZE 100 //初始长度
#define LISTINSCREMENT 10 //动态分配线性表时的增量
typedef int Elementtype;
typedef struct {
	Elementtype *element;//指向首地址的指针
	int length; //线性表长度，指示线性表内元素的个数
	int listsize;//线性表所占的空间大小
} SqList;
Status initList(SqList * L);
Status destroyList(SqList * L);
Status listEmpty(SqList L);
int listLength(SqList L);
Status getElement(SqList L, int i, Elementtype *e);//将i处的元素赋值给e；
int locateElement(SqList L, Elementtype e, Status(*compare)(Elementtype, Elementtype));//返回e在线性表中的位置
Status getPriorElement(SqList L, Elementtype e, Elementtype* pre_e);
Status nextElement(SqList L, Elementtype e, Elementtype* next_e);
Status listInsert(SqList *L, int i, Elementtype e);//插入一个元素
Status listDelete(SqList *L, int i, Elementtype* e);//删除一个元素，并把删除的元素赋值给e
Status listTraverse(SqList *L, void(*visit)(Elementtype*));//遍历数据表
Status clearList(SqList * L);
#endif // !LIST_H

