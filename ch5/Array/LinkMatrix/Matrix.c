#include <stdio.h>
#include <stdlib.h>
#include "PreDefined.h"
//十字链表在三元组的基础加入了指针两个指针分别为down 和right；
//
typedef int ElemType;
typedef struct OLNode{
	int i, j;
	ElemType e;
	struct OLNode * down, *right;
}OLNode, *OLink;
typedef struct {
	OLink * rhead, *chead;
	int mu, nu, tu;
}CrossList;
Status InitMatrix(CrossList *M)
{
	M->mu = 0;
	M->nu = 0;
	M->tu = 0;
	M->rhead = NULL;
	M->chead = NULL;
}
Status DestroyMatrix(CrossList *M)
{
	//按行destroy
	OLNode *p, *q;
	for (int i = 0; i < M->mu; i++)
	{
		p=M->rhead[i];
		if (p) {
			q = p;
			free(p);
			p = q->right;
		}
	}
	M->mu = 0;
	M->nu = 0;
	M->tu = 0;
	M->rhead = NULL;
	M->chead = NULL;
}
Status CreatMatrix(CrossList *M)
{
	printf("\n请输入矩阵的行数：");
	scanf("%d", &M->mu);
	printf("\n请输入矩阵的列数：");
	scanf("%d", &M->nu);
	printf("\n请输入矩阵的元素数：");
	scanf("%d", &M->tu);
	M->rhead = (OLink *)malloc(sizeof(OLink)*M->mu);
	if (!M->rhead)exit(OVERFLOW);
	M->chead = (OLink *)malloc(sizeof(OLink)*M->nu);
	if (!M->chead)exit(OVERFLOW);
	for (int i = 0; i < M->mu; i++)M->rhead[i] = NULL;
	for (int i = 0; i < M->nu; i++)M->chead[i] = NULL;
	for (int i = 1; i <= M->tu; i++)
	{
		int x, y, e;
		OLink p;
		printf("\n请输入一个三元组：");
		scanf("%d %d %d", &x, &y, &e);
		OLink k = (OLink)malloc(sizeof(OLNode));
		k->e = e; k->i = x; k->j = y; k->right = NULL; k->down = NULL;
		//将i，j个元素放入对应的链中；
		if (M->rhead[x - 1] == NULL || M->rhead[x - 1]->j > k->j)
		{
			k->right = M->rhead[x - 1];
			M->rhead[x - 1] = k;
		}
		else
		{
			for (p = M->rhead[x - 1];p->right != NULL&& p->right->j< k->j; p = p->right);
			k->right = p->right;
			p ->right=k;
		}
		if (M->chead[y - 1] == NULL || M->rhead[y - 1]->i> k->i)
		{
			k->down = M->rhead[y - 1];
			M->rhead[y - 1] = k;
		}
		else
		{
			for (p = M->chead[y - 1]; p->down != NULL&& p->down->i < k->i; p = p->down);
			k->down = p->down;
			p->down = k;
		}
	}
}
Status AddMatrix(CrossList *A, CrossList B)
{
	if (A->mu != B.mu || A->nu != B.nu)return ERROR;
	//把B加给A有四种情况
	//
	OLink p, q, temp;
	//按行相加
	for (int i = 0; i < A->mu; i++)
	{
		p = A->rhead[i]; q = B.rhead[i];
		while (p != NULL && q != NULL)
		{
			//都是i+1行，比较j的大小
			if (p->j < q->j)
			{
				//1.p在q前面，p往后推；
				p = p->right;
			}
			else if (p->j == q->j)
			{
				//两种情况p->e+q->e!=0
				if (p->e + q->e != 0) {
					p->e += q->e;
					p = p->right;
					q = q->right;
				}else {
					//p->e+q->e==0删除结点；
					//纵向和横向扫描删除结点;
					temp = A->chead[p->j - 1];
					while (temp)
					{
						if (temp->down == p)
						{
							temp->down = p->down;
							break;
						}
						temp = temp->down;
					}
					temp = A->rhead[i];
					while (temp)
					{
						if (temp->right == p)
						{
							temp->right = p->right;
							break;
						}
						temp = temp->right;
					}
					p = p->right;
					q = q->right;
				}
			}
			else {
				//p->j > q->j
				//q插在p前面
				//TODO：没考虑temp==NULL的情况；
				OLink newnode = (OLink)malloc(sizeof(OLNode));
				newnode->i = q->i;
				newnode->j = q->j;
				newnode->e = q->e;
				temp = A->rhead[i];
				while (temp)
				{
					if (temp->right == p)
					{
						temp->right = newnode;
						newnode->right = p;
						break;
					}
					temp = temp->right;
				}
				temp = A->chead[q->j - 1];
				while (temp)
				{
					if (temp->i<q->i&&(temp->down->i>q->i||temp->down==NULL))
					{
						newnode->down=temp->down;
						temp->down = newnode;
						break;
					}
					temp = temp->right;
				}
			}
		}
	}
}