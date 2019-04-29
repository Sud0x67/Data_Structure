#include <stdio.h>
#include <stdlib.h>
#include "PreDefined.h"
//ͷβ��ʾ��
#include<string.h>
#include "PreDefined.h"
#define MAXSTRLEN 255
//һ�����Ϊ255���ַ�0���洢���ȡ�
//
typedef unsigned char SString[MAXSTRLEN + 1];//unsigned char ת��Ϊ����ʱ��Χ��ͬ,�ַ���Χû�в�ͬ��
											 //��չ���Ա��ʾ��
typedef int AtomType;
typedef int AtomType;
typedef enum {ATOM,LIST }ElemTag;
typedef struct GLNode{
	ElemTag tag;
	union {
		AtomType atom;
		struct {
			struct GLNode * hp, *tp;
		}ptr;
	}elem;
}GLNode, *GList;
//��������;
Status InitGList(GList * L);
Status CreatGList(GList *L);
void DestroyGList(GList *L);
Status CopyGList(GList *T, GList L);
Status GListLength(GList L);
Status GListDepth(GList L);
Status GListEmpty(GList L);
GList GetHead(GList L);
GList GetTail(GList L);
Status InsertFirst_GL(GList *L, GList e);
Status DeleteFirst_GL(GList *L, GList *e);
void Traverse_GL(GList L,void (*visit)(AtomType A));
Status InitGList(GList *L)
{
	*L = NULL;
	return OK;
}
//��(a,(b,(d��e��f))��ʽ������ȥ���ŵķ�ʽ���������
Status CreatGList(GList *L) {
	return OK;
}
void DestroyGList(GList *L)
{
	GList q1, q2;
	if (*L)
	{
		if ((*L)->tag == ATOM)
		{
			free(*L);
			*L = NULL;
		}
		else
		{
			q1 = (*L)->elem.ptr.hp;
			q2 = (*L)->elem.ptr.hp;
			free(*L);
			*L = NULL;
			DestroyGList(&q1);
			DestroyGList(&q2);
		}
	}
}
Status CopyGList(GList *T, GList L)
{
	if (*T)DestroyGList(T);
	if (!L)*T = NULL;
	else
	{
		*T = (GList)malloc(sizeof(GLNode)); /* ������ */
		if (!*T)
			exit(OVERFLOW);
		if (L->tag == ATOM)
		{
			(*T)->tag = L->tag;
			(*T)->elem = L->elem;
		}
		else
		{
			(*T)->tag = L->tag;
			CopyGList(&(*T)->elem.ptr.hp, L->elem.ptr.hp);
			CopyGList(&(*T)->elem.ptr.tp, L->elem.ptr.tp);
		}
	}
}
int GListDepth(GList L)
{
	int max, dep;
	GList pp;
	if (!L)return 1;//�ձ����Ϊ1
	if (L->tag == ATOM)return 0;//ԭ��Ϊ0��
	for (max = 0, pp = L; pp; pp = pp->elem.ptr.tp)
	{
		dep = GListDepth(pp->elem.ptr.hp);
		if (dep > max)max = dep;
	}
	return max + 1;
}
GList GetHead(GList L)
{
	GList h;
	if (!L || L->tag == ATOM)return NULL;
	CopyGList(&h, L->elem.ptr.hp);
	return h;
}
GList GetTail(GList L)
{
	GList l;
	if (!L || L->tag == ATOM)return NULL;
	CopyGList(&l, L->elem.ptr.tp);
	return l;
}
Status InsertFirst_GL(GList *L, GList e)
{
	//�ձ����Ϊԭ�ӣ�
	//��e��Ϊhead��L��Ϊtail�ͺ�
	GList temp;
	temp = (GList)malloc(sizeof(GLNode));
	if (!temp)exit(0);
	temp->tag = LIST;
	temp->elem.ptr.hp = e;
	temp->elem.ptr.tp = *L;
	*L = NULL;
	return OK;
}
Status DeleteFirst_GL(GList *L, GList *e)
{
	if (!*L || (*L)->tag == ATOM)
	{
		*e = NULL;
		return FALSE;
	}
	*e = (*L)->elem.ptr.hp;
	GList p = *L;
	*L = (*L)->elem.ptr.tp;
	free(p);
	return OK;
}
void Traverse_GL(GList L, void(*visit)(AtomType A))
{
	if(L)
	{
		if (L->tag == ATOM)visit(L->elem.atom);
		else {
			Traverse_GL(L->elem.ptr.hp, visit);
			Traverse_GL(L->elem.ptr.tp, visit);
		}
	}
}

//SString
Status InitStr(SString S)
{
	S[0] = 0;
	return TRUE;
}
Status StrAssign(SString T, char *str)
{
	if (strlen(str)> MAXSTRLEN)return ERROR;
	T[0] = strlen(str);
	for (int i = 1; i <= strlen(str); i++)
	{
		T[i] = str[i - 1];
	}
	return TRUE;
}
Status StrCopy(SString T, SString S)
{
	for (int i = 0; i <= S[0]; i++)
	{
		T[i] = S[i];
	}
	return TRUE;
}
StrEmpty(SString S)
{
	if (S[0] == 0)return TRUE;
	else return FALSE;
}
int StrCompare(SString S, SString T)
{
	int i = 1;
	while (i <= S[0] && i <= T[0])
	{
		if (S[i] == T[i]) i++;
		else if (S[i] < T[i])return 0;
		else return -1;
	}
	if (S[0] == T[0])return 0;
	else if (S[0] > T[0])return 1;
	else return -1;
}
int StrLength(SString S)
{
	return S[0];
}
Status ClearStr(SString S)
{
	S[0] = 0;
	return TRUE;
}
Status Concat(SString T, SString S1, SString S2)
{
	int flag;
	if ((S1[0] + S2[0]) > MAXSTRLEN)
	{
		flag = FALSE;
		T[0] = MAXSTRLEN;
		for (int i = 1; i <= S1[0]; i++)
		{
			T[i] = S1[i];
		}
		for (int i = S1[0] + 1; i <= MAXSTRLEN; i++)
		{
			T[i] = S2[i - S1[0]];
		}
	}
	else {
		flag = TRUE;
		T[0] = S1[0] + S2[0];
		for (int i = 1; i <= S1[0]; i++)
		{
			T[i] = S1[i];
		}
		for (int i = S1[0] + 1; i <= T[0]; i++)
		{
			T[i] = S2[i - S1[0]];
		}
	}
	return flag;
}
Status SubString(SString sub, SString S, int pos, int length)
{
	if (pos<1 || pos>S[0] || length<0 || pos + length - 1>S[0])return ERROR;
	sub[0] = length;
	for (int i = 1; i <= length; i++)
	{
		sub[i] = S[pos + i - 1];
	}
	return TRUE;
}
//Index�����������Ѿ����ģ�Ҫ���ⷸ���ƴ���//д��̫������
int Index(SString S, SString T, int pos)
{
	if (pos < 0 || pos>S[0])return ERROR;
	for (int i = pos; i <= S[0]; i++)
	{
		int j = 1;
		while (j <= T[0] && i <= S[0])
		{
			if (S[i] == T[j])
			{
				i++; j++;
			}
			else break;
		}
		if (j == T[0] + 1)return i - j + 1;
		if (i == S[0] + 1)return -1;
		i = i - j + 1;
	}
	return -1;
}
Status Insert(SString S, int pos, SString T) {
	int flag;//��ʾ��������᲻�ᱻ�ضϣ�
	if (pos<1 || pos>S[0] + 1)return ERROR;
	if (S[0] + T[0] > MAXSTRLEN)
	{
		flag = FALSE;
		int interval = MAXSTRLEN - S[0];
		for (int j = MAXSTRLEN; j >= pos; j--)
		{
			S[j] = S[j - interval];
		}
		for (int i = 1; i <= interval; i++)
		{
			S[pos - 1 + i] = T[i];
		}
		S[0] = MAXSTRLEN;
	}
	else
	{
		flag = TRUE;
		int interval = T[0];
		for (int j = S[0] + interval; j >= pos; j--)
		{
			S[j] = S[j - interval];
		}
		for (int i = 1; i <= interval; i++)
		{
			S[pos - 1 + i] = T[i];
		}
		S[0] = T[0] + S[0];
	}
	return flag;
}

Status Replace(SString S, SString T, SString V)
{
	int flag, i = Index(S, T, 1);
	while (i > 0)
	{
		int j;
		//ɾ��T��
		for (j = i; j <= S[0] - T[0]; j++) {
			S[j] = S[j + T[0]];
		}
		S[0] = S[0] - T[0];
		//�ӵ�iλ����C��
		flag = Insert(S, i, V);
		i = Index(S, T, 1);
	}
	return flag;
}
Status StrDelete(SString S, int pos, int len) {
	if (pos<1 || pos>S[0] - len + 1 || len < 0)return ERROR;
	for (int j = pos; j <= S[0] - len; j++) {
		S[j] = S[j + len];
	}
	S[0] = S[0] - len;
	return TRUE;
}
Status DestroyString()
{
	//do nothing;
}
//typedef struct GLNode{
//ElemTag tag;
//union {
//	AtomType atom;
//	struct {
//		struct GLNode * hp, *tp;
//	}ptr;
//}elem;
//}GLNode, *GList;

Status sever(SString *str, SString *hstr)
{
	//���ǿմ��ָ�Ϊ������hstrΪ,֮ǰ��strΪ����֮���
	int n, i = 1, k = 0;
	/* z�ַ���������Ϊ�� a,b,(c,d)�� (),b,c,d��*/
	int n, i = 1, k = 0; /* k����δ��Ե������Ÿ��� */
	SString ch, c1, c2, c3;
	InitString(&ch); /* ��ʼ��HString���͵ı��� */
	InitString(&c1);
	InitString(&c2);
	InitString(&c3);
	StrAssign(&c1, ",");
	StrAssign(&c2, "(");
	StrAssign(&c3, ")");
	n = StrLength(*str);
	//����һ��()����ĸ���λ��
	do {
		SubString(&ch, *str, i, 1);
		if (StrCompare(ch, c2) == 0)
			k++;
		if (StrCompare(ch, c1) == 0)
			k--;
		i++;
	} while (i <= n&&k != 0 || StrCompare(ch, c1) != 0);
	if (i > n)
	{

		StrCopy(*hstr, *str);
		ClearStr(*str);
	}
	else {
		StrCopy(&ch, *str);
		SubString(*hstr, *str, 1, i - 2);
		SubString(*str, *str, i, n - i + 1);
	}
}
Status CreatGList(GList *L, SString S)
{
	SString emp, sub, hsub;
	SString c1, c2;
	GList p;
	InitStr(emp);
	InitStr(sub);
	InitStr(hsub);
	InitStr(c1);
	InitStr(c2);
	StrAssign(emp, "()");
	StrAssign(c1, "(");
	StrAssign(c2, ")");

	if (compare(S, emp) == 0)
	{
		(*L)->tag = LIST;
		(*L)->elem.ptr.hp = NULL;
		(*L)->elem.ptr.tp = NULL;
	}
	else if (StrLength(S) == 1)
	{
		(*L)->tag = ATOM;
		(*L)->elem.atom = S[1];
	}
	else {
		(*L)->tag = LIST;
		SubString(sub, S, 2, StrLength(S) - 1);
		sever(&sub, &hsub);
		CreatGList((*L)->elem.ptr.hp, hsub);
		//��sub������
		Insert(sub, 1, c1);
		Insert(sub, StrLength(sub) + 1, c2);
		CreatGList((*L)->elem.ptr.hp, sub);
	}
	return OK;
}