#include<stdio.h>
#include"PreDefined.h"
#define MAXSIZE 1000
typedef int Element;
//�����ʾ�����Ա��ֳƾ�̬���Ա�
//��ʵ���˾�̬���Ա��ADT��Ϊ�˱�֤����Ŀɶ��Դӱ��ο�ʼ�����������������б���һ��
typedef struct {
	Element data;
	int cur;
}component, ArrayList[MAXSIZE];

//��ʼ����̬���Ա���Ҫ�����Ա�Ŀսڵ�����һ�����ÿռ䱸��
Status initList(ArrayList L) {
	for (int i = 0; i < MAXSIZE-1;i++)
		L[i].cur = i + 1;
	L[MAXSIZE - 1].cur = 0;
	return OK;
}
//�ֶ�ʵ��Malloc��free����
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


Status listEmpty(ArrayList L)//�ж�List�Ƿ�Ϊ��
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
	return MAXSIZE -1- j;//L[0]�����ڴ������
}
//int locateElement(ArrayList L, Element e,int r) //����e�����Ա��е�λ��
//�ص�i=L[i].cur ����p=p->next

Status listTraverse(ArrayList L,int S, void(*visit)(Element*))//�������ݱ�
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
//��A-B��B-A
//L����������ڵĿռ䣬S�������Ա��ͷ���
void difference(ArrayList L, int * S)
{
	initList(L);
	*S = mallocNode(L);//L[S].data��ȻΪ�ա�
	int R = *S;//R�ı������β�����
	int m, n;
	printf("������A��B���ϵ�����:");
	scanf("%d %d",&m,&n);
	for (int i = 1; i <= m; i++)
	{
		int newnode = mallocNode(L);
		printf("������A���ϵ�%d��Ԫ��\n",i);
		scanf("%d", &L[newnode].data);//
		L[R].cur = newnode;
		R = newnode;
	}
	L[R].cur = 0;
	printf("��ӡһ�£�");
	listTraverse(L, *S, print_e);
	//���뼯��B
	for (int j = 1; j <= n; j++)
	{
		int e;
		printf("������B���ϵ�%d��Ԫ��\n", j);
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
			printf("��ӡһ�£�");
			listTraverse(L, *S, print_e);
		}
		else
		{
			L[p].cur = L[h].cur;
			freeNode(L, h);
			printf("��ӡһ�£�");
			listTraverse(L, *S, print_e);
		}
	}

}
//ֱ����������԰ɣ����ý����ļ���
void main()
{ 
	ArrayList L;
	int S;
	difference(L, &S);
	printf("����listTraverse\n");
	listTraverse(L, S, print_e);
	system("pause");
	return;
}
