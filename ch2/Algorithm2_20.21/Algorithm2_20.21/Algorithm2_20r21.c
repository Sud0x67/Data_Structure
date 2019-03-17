#include <stdio.h>
#include <stdlib.h>
#include "PreDefined.h"
#include "LinkList.h"
#include "Algorithm2_20r21.h"
Status listInsertL(LinkList *L, int i, ElemType e)
{
	Link p,s;
	if (!LocatePos(*L, i - 1, &p)) return ERROR;
	if (!makeNode(&s, e))return ERROR;
	inFirst(&L, p, s);
	return OK;
}
//��֪����La��LbΪ�ǵݼ�����
Status mergeList(LinkList *La, LinkList *Lb, LinkList*Lc, int(*compare)(ElemType, ElemType))
{
	if (!initList(Lc))return ERROR;
	Link Ha, Hb, Pa, Pb;
	Ha = getHead(*La);
	Hb = getHead(*Lb);
	Pa = nextPos(*La, Ha);
	Pb = nextPos(*Lb, Hb);
	while (Pa&&Pb)
	{
		if (compare(Pa->data, Pb->data))
		{
			Link p = Pa;
			Pa= nextPos(*La, Pa);
			Link tail = getLast(*Lc);
			insAfter(Lc, &tail, &p);
		}
		else
		{
			Link p = Pb;
			Pb = nextPos(*Lb, Pb);
			Link tail = getLast(*Lc);
			insAfter(Lc, &tail, &p);
		}
	}
	if (Pa) {
		append(Lc, Pa);
	}
	else {
		append(Lc, Pb);
	}

	return OK;
}
//�������е�mergeListʵ�ֵĸ��ã�ʵ�����е�mergeList����㷨�д����Լ�ʵ�ֵĺð���
Status mergeList2(LinkList *La, LinkList *Lb, LinkList*Lc, int(*compare)(ElemType, ElemType))
{
	if (!initList(Lc))return ERROR;
	Link Ha, Hb, Pa, Pb;
	Ha = getHead(*La);
	Hb = getHead(*Lb);
	Pa = nextPos(*La, Ha);
	Pb = nextPos(*Lb, Hb);
	while (Pa&&Pb)
	{
		if (compare(Pa->data, Pb->data))
		{
			Link q;
			delFirst(La, Ha, &q);
			q->next = NULL;
			append(Lc, q);
			Pa = nextPos(*La, Ha);
		}
		else
		{
			Link q;
			delFirst(Lb, Hb, &q);
			q->next = NULL;
			append(Lc, q);
			Pb = nextPos(*Lb, Hb);
		}
	}
	if (Pa) {
		append(Lc, Pa);
	}
	else {
		append(Lc, Pb);
	}
	freeNode(&Ha); freeNode(&Hb);
	return OK;
}