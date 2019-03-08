
#include <stdio.h>
#include "PreDefined.h"
#include "List.h"



Status initList(SqList *L) {
	L->element = (Elementtype*)malloc(LIST_INIT_SIZE * sizeof(Elementtype));
	if (!L->element)exit(OVERFLOW);
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
	return OK;
}
Status destroyList(SqList *L)//销毁List,释放elment所占的内存空间
{
	free(L->element);
	L->length = 0;
	L->listsize = 0;
	L->element = NULL;
	return OK;
}
Status clearList(SqList * L)//清空数据表
{
	L->length = 0;
	return OK;
}
Status listEmpty(SqList L)//判断List是否为空
{
	if (L.length == 0)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
int listLength(SqList L)
{
	return L.length;
}
Status getElement(SqList L, int i, Elementtype *e)//将i处的元素赋值给e；
{
	if (i > 0 && i <= L.length) {
		*e = L.element[i - 1];
		return OK;
	}
	return ERROR;
}
int locateElement(SqList L, Elementtype e, Status(*compare)(Elementtype, Elementtype)) //返回e在线性表中的位置
{
	for (int i = 0; i < L.length; i++) {
		if ((*compare)(L.element[i], e)) {
			return i + 1;
		}
	}
	return INFEASIBLE;
}
//比较函数
//Status compare(Elementtype; a, Elementtype; b) {
//	return a == b;

Status getPriorElement(SqList L, Elementtype e, Elementtype* pre_e)
{//返回线性表前一个数值
	int i;
	for (i = 0; i < L.length; i++)
	{
		if (L.element[i] == e)break;
	}
	if (i > 0&&i<L.length) {//2以后的数据项才会有前一个
	*pre_e = L.element[i - 1];
	return OK;
	}
	else {
	return INFEASIBLE;
	}
}
Status nextElement(SqList L, Elementtype e, Elementtype* next_e)
{//获取下一个元素
	int i;
	for (i = 0; i < L.length; i++)
	{
		if (L.element[i] == e)break;
	}
	if (i >= 0 && i<L.length-1) {//2以后的数据项才会有前一个
		*next_e = L.element[i+1];
		return OK;
	}
	else {
		return INFEASIBLE;
	}
}

Status listInsert(SqList *L, int i, Elementtype e)//插入一个元素
{
	if (i<1 && i > L->length + 1) return ERROR;
	if (L->length >= L->listsize)
	{
		printf("分配新的空间\n");
		Elementtype* newbase = (Elementtype*)realloc(L->element, (L->listsize + LISTINSCREMENT)*sizeof(Elementtype)); 
		if (!newbase)exit(OVERFLOW);
		L->element = newbase;
		L->listsize = L->listsize + LISTINSCREMENT;//listsize变化
		printf("分配新的空间\n");
	}
	for (int j = L->length; j >=i; j--)//边界条件，j=i时再
	{
		L->element  [j] = L->element[j-1];
	}
	L->element[i - 1] = e;
	L->length++;
	return OK;
}
Status listDelete(SqList *L, int i, Elementtype* e)//删除一个元素，并把删除的元素赋值给e
{
	if (i<1 && i > L->length) return ERROR;
	*e = L->element[i - 1];
	for (int j = i - 1; j < L->length - 1; j++)
	{
		L->element[j] = L->element[j + 1];
	}
	L->length--;
	return OK;
}
Status listTraverse(SqList *L, void(*visit)(Elementtype*))//遍历数据表
{
	for (int i = 0; i < L->length; i++) {
		(*visit)(L->element + i);
	}
	return OK;
}

/*
typedef double Elementtype;//定义类型以保证list可以重用
#define LIST_INIT_SIZE 100 //初始长度
#define LISTINSCREMENT 10 //动态分配线性表时的增量
typedef struct {
Elementtype *element;//指向首地址的指针
int length; //线性表长度，指示线性表内元素的个数
int listsize;//线性表所占的空间大小
}SqList;
*/


void main00()
{
	SqList L;
	Elementtype e, e0;
	Status i;
	int j, k;
	i = initList(&L);
	printf("线性表L.element=%u L.length=%d L.listsize=%d\n", L.element, L.length, L.listsize);
	for (j = 1; j <= 5; j++)
		i = listInsert(&L, j, 1);
	printf("对L插入5个元素1.element=");
	system("pause");
	for (j = 1; j <= 5; j++)
		printf("%d ", *(L.element + j - 1));
	printf("\n");
	printf("L.element=%u L.length=%d L.listsize=%d\n", L.element, L.length, L.listsize);
	/*
	i = listEmpty(L);
	printf("L线性表i=%d(1:空 0:非空)\n", i);
	i = clearList(&L);
	printf("清空L后：L.element=%u L.length=%d L.listsize=%d\n", L.element, L.length, L.listsize);
	i = listEmpty(L);
	printf("L线性表清空后i=%d(1:空 0:非空)\n\n", i);
	for (j = 1; j <= 10; j++)
		listInsert(&L, j, j);
	printf("插入10个元素L.element=");
	for (j = 1; j <= 10; j++)
		printf("%d ", *(L.element + j - 1));
	printf("\n");
	printf("L.element=%u L.length=%d L.listsize=%d\n", L.element, L.length, L.listsize);
	listInsert(&L, 1, 0);
	printf("插入单个元素后L.element=");
	for (j = 1; j <= listLength(L); j++) //ListLength(L)ΪԪ�ظ���
		printf("%d ", *(L.element + j - 1));
	printf("\n");
	printf("L.element=%u(指针位置) L.length=%d(长度) L.listsize=%d(空间大小)\n", L.element, L.length, L.listsize);
	getElement(L, 5, &e);
	printf("第5个\n", e);
	for (j = 3; j <= 4; j++)
	{
		k = locateElement(L, j, compare);
		if (k) {
			printf("j在L中的位置%dj：%d\n", k, j);
		}
		else {
			printf("没有找到这个元素：%d", j);
		}
	}
	for (j = 1; j <= 2; j++)
	{
		getElement(L, j, &e0); 
		i = getPriorElement(L, e0, &e); 
		if (i == INFEASIBLE)
			printf("%d前边的元素不可得\n", e0);
		else
			printf("元素%d前一位为：%d\n", e0, e);
	}
	for (j = listLength(L) - 1; j <= listLength(L); j++) //测试nextElement函数 
	{
		getElement(L, j, &e0);
		i = nextElement(L, e0, &e);
		if (i == INFEASIBLE)
			printf("%d后边的元素不可得\n", e0);
		else
			printf("元素%d后一位为：%d\n", e0, e);
	}
	k = listLength(L); //测试删除操作
	for (j = k + 1; j >= k; j--)
	{
		i = listDelete(&L, j, &e);
		if (i == ERROR)
			printf("删除不成功\n", j);
		else
			printf("删除了%d\n", e);
	}
	printf("L：double前：\n");
	listTraverse(&L, visit);
	printf("L：double后：\n");
	listTraverse(&L, dbl); 
	listTraverse(&L, visit);
	destroyList(&L);
	printf("销毁L：L.element=%u L.length=%d L.listsize=%d\n", L.element, L.length, L.listsize);
	*/
}
