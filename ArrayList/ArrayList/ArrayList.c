#include<stdio.h>
#include"PreDefined.h"
#define MAXSIZE 1000
typedef int Element;
//数组表示的线性表又称静态线性表
//简单实现了静态线性表的ADT；为了保证代码的可读性从本次开始所有命名尽量与书中保持一致
typedef struct {
	Element data;
	int cur;
}component, ArrayList[MAXSIZE];

//初始化静态线性表需要把线性表的空节点连成一个备用空间备用
Status initList(ArrayList L) {
	for (int i = 0; i < MAXSIZE-1;i++)
		L[i].cur = i + 1;
	L[MAXSIZE - 1].cur = 0;
	return OK;
}
//手动实现Malloc和free函数
int mallocNode(ArrayList L)
{
	int i = L[0].cur;
	if (i)L[0].cur = L[i].cur;
	return i;
}
int freeNode(ArrayList L,int k)
{
	L[k].cur = L[0].cur;
	L[0].cur = k;
	return 0;
}


Status listEmpty(ArrayList L)//判断List是否为空
{
	int i=0,j=0;
	while (L[i].cur!=0)
	{
		i = L[i].cur;
		j++;
	}
	if (++j == MAXSIZE)
	{
		return TRUE;
	}
	return FALSE;
}
int listLength(ArrayList L)
{
	int i = 0, j = 0;
	while (L[i].cur != 0)
	{
		i = L[i].cur;
		j++;
	}
	return MAXSIZE -1- j;//L[0]不用于存放数据
}
//int locateElement(ArrayList L, Element e,int r) //返回e在线性表中的位置
//重点i=L[i].cur 类似p=p->next

Status listTraverse(ArrayList L,int S, void(*visit)(Element*))//遍历数据表
{
	while (L[S].cur!=0)
	{
		(*visit)(&L[S].data);
		S = L[S].cur;
	}
	(*visit)(&L[S].data);
	return OK;
}
void print_e(Element *c)
{
	printf("\t%d", *c);
}
//求A-B∪B-A
//L代表链表存在的空间，S代表线性表的头结点
void difference(ArrayList L, int * S)
{
	initList(L);
	*S = mallocNode(L);//L[S].data依然为空。
	int R = *S;//R的表链表的尾部结点
	int m, n;
	printf("请输入A、B集合的数量:");
	scanf("%d %d",&m,&n);
	for (int i = 1; i <= m; i++)
	{
		int newnode = mallocNode(L);
		printf("请输入A集合第%d个元素\n",i);
		scanf("%d", &L[newnode].data);//
		L[R].cur = newnode;
		R = newnode;
	}
	L[R].cur = 0;
	printf("打印一下：");
	listTraverse(L, *S, print_e);
	//输入集合B
	for (int j = 1; j <= n; j++)
	{
		int e;
		printf("请输入B集合第%d个元素\n", j);
		scanf("%d", &e);//
		int p = *S, h = L[*S].cur;
		while (L[h].cur != 0&&L[h].data != e)
		{
			p = h;
			h = L[h].cur;
		}
		if (L[h].cur == 0)
		{
			int newnode = mallocNode(L);
			L[newnode].data = e;
			L[newnode].cur = 0;
			L[h].cur = newnode;
			printf("打印一下：");
			listTraverse(L, *S, print_e);
		}
		else
		{
			L[p].cur = L[h].cur;
			freeNode(L, h);
			printf("打印一下：");
			listTraverse(L, *S, print_e);
		}
	}

}
//直接在下面测试吧，懒得建新文件了
void main()
{ 
	ArrayList L;
	int S;
	difference(L, &S);
	printf("测试listTraverse\n");
	listTraverse(L, S, print_e);
	system("pause");
	return;
}
