#include<stdio.h>
#include <malloc.h>
#include"PreDefined.h"
#include "LinkList.h"
#include "Polynomial.h"
//这两个函数完全一样



void print_e(ElemType *c)
{
	printf("%+.1fX^%d", (*c).coef, (*c).expn);
}
Status compare(ElemType e1, ElemType e2)
{
	if (e1.expn < e2.expn)return -1;
	else if (e1.expn == e2.expn)return 0;
	else return 1;
}
void creatPolynomial(Polynomial *L, int m)
{
	if (!initList(L))return ERROR;
	Link p;
	ElemType e;
	double coef;
	int expn;
	for (int i = 1; i <= m; i++)
	{
		printf("请输入第%d项：格式：coef,expn:\n", i);
		scanf("%lf,%d", &coef, &expn);
		printf("%lf,%d\n", coef, expn);
		e.coef = coef; e.expn = expn;
		orderInsert(L, e, compare);
	}
}
void printPolyn(Polynomial L)
{
	listTraverse(L, print_e);
	printf("\n");

}
//相加并销毁多项式Pb
void addPolyn(Polynomial *La, Polynomial *Lb)
{
	Link Ph = getHead(*Lb);
	Link q;
	delFirst(Lb, Ph, &q);
	while (q)
	{
		orderInsert(La, q->data, compare);
		delFirst(Lb, Ph, &q);
	}
	destroyPolyn(Lb);
}
void substractPolyn(Polynomial *La, Polynomial *Lb)
{
	Link Ph = getHead(*Lb);
	Link q;
	delFirst(Lb, Ph, &q);
	
	while (q)
	{
		q->data.coef *= -1;
		orderInsert(La, q->data, compare);
		delFirst(Lb, Ph, &q);
	}
	destroyPolyn(Lb);
}
void multiplyPloyn(Polynomial *La, Polynomial *Lb)
{
	Polynomial Lc;
	initList(&Lc);
	Position qa, qb;
	term a, b, c;
	qa = getHead(*La);
	qa = qa->next;
	while (qa)
	{
		a = getCurrentElement(qa);
		qb = getHead(*Lb);
		qb = qb->next;
		while (qb)
		{
			b = getCurrentElement(qb);
			c.coef = a.coef*b.coef;
			c.expn = a.expn + b.expn;
			orderInsert(&Lc, c, compare);
			qb = qb->next;
		}
		qa = qa->next;
	}
	destroyPolyn(Lb); /* 销毁Pb */
	clearList(La);
	addPolyn(La, &Lc);
}
