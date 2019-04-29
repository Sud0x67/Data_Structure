#include <stdio.h>
#include <stdlib.h>
#include "PreDefined.h"
#include<string.h>
#include "PreDefined.h"
#define MAXSTRLEN 255
//一个串最长为255个字符0处存储长度。
//
typedef unsigned char SString[MAXSTRLEN + 1];//unsigned char 转换为整数时范围不同,字符范围没有不同。
//扩展线性表表示法
typedef int AtomType;
typedef enum { ATOM, LIST }ElemTag;
typedef struct GLNode {
	ElemTag tag;
	union {
		AtomType atom;
		struct GLNode * hp;
	}elem;
	struct GLNode *next;
}GLNode, *GList;
//函数声明;
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
void Traverse_GL(GList L, void(*visit)(AtomType A));
Status InitGList(GList *L)
{
	if (*L)DestroyGList(L);
	*L = NULL;
	return OK;
}
void DestroyGList(GList *L)
{
	GList p,q;
	if (*L)
	{
		if ((*L)->tag == ATOM)
		{
			free(*L);
			*L = NULL;
		}
		else
		{
			p = (*L)->elem.hp;
			DestroyGList(&p);
			q = (*L)->next;
			DestroyGList(&q);
			free(*L);
			*L = NULL;
			//利用循环
			//*L指向列表 L=NULL时列表结束；
			p = *L;
			while (p)
			{
				q = p;
				p = p->next;
				DestroyGList(q);
			}
			*L = NULL;
		}
	}
}
Status CopyList(GList *T, GList L)
{
	if (!L)
	{
		*T = NULL;
		return OK;
	}
	else if (L->tag == ATOM)
	{
		*T = (GList)malloc(sizeof(GLNode));
		if (!*T)exit(0);
		(*T)->tag=L->tag;
		(*T)->elem.atom= L->elem.atom;
		(*T)->next = NULL;
	}
	else
	{
		*T = (GList)malloc(sizeof(GLNode));
		if (!*T)exit(0);
		(*T)->tag = L->tag;
		CopyList(&(*T)->elem.hp, L->elem.hp);
		CopyGList(&(*T)->next, L->next);
	}
	return OK;
}
int GListLength(GList L)
{
	int len = 0;
	if(L&&L->tag==ATOM)
	{
		len = 1;
	}
	else if (L&&L->tag == LIST)
	{
		GList p = L;
		while (p)
		{
			len++;
			p = p->next;
		}
	}
	return len;
}
int GListDepth(GList L)
{
	int max, dep;
	GList pp;
	if (L == NULL)return 1;
	if (L->tag == ATOM)return 0;
	for (max = 0, pp = L; pp; pp = pp->next)
	{
		dep = GListDepth(pp);
		if (dep > max)max = dep;
	}
	return max + 1;
}
Status InsertFirst_GL(GList*L, GList e)
{
	//1.GList 作为一个线性表插入
	if (e)
	{
		GList pre, pp;
		pre = e; pp = e->next;
		while (pp)
		{
			pp = pp->next;
			pre = pp;
		}
		pp->next = *L;
		*L = pp;
	}
	//2.e作为一个元素插入；
	//即，L的hp为GList
	if (e)
	{
		GLNode a;
		a.elem.hp = e;
		a.next = *L;
		*L = &a;
	}
}
Status DeleteFirst_GL(GList *L, GList *e)
{
	if (*L)
	{
		*e = (*L)->tag == ATOM ? (*L) : (*L)->elem.hp;
		*L = (*L)->next;
		(*e)->next = NULL;
	}
	else
	{
		*e == NULL;
	}
	return OK;
}
void Traverse_GL(GList L, void(*visit)(AtomType))
{
	if (L)
	{
		if (L->tag == ATOM) {
			visit(L->elem.atom);
			Traverse_GL(L->next, visit);
		}
		else {
			Traverse_GL(L->elem.hp, visit);
			Traverse_GL(L->next, visit);
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
//Index函数有问题已经更改，要避免犯类似错误。//写的太复杂了
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
	int flag;//表示插入的量会不会被截断；
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
		//删除T；
		for (j = i; j <= S[0] - T[0]; j++) {
			S[j] = S[j + T[0]];
		}
		S[0] = S[0] - T[0];
		//从第i位插入C；
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
Status sever(SString *str, SString *hstr)
{
	//将非空串分割为两部分hstr为,之前的str为逗号之后的
	int n, i = 1, k = 0;
	/* z字符串的样子为， a,b,(c,d)或 (),b,c,d等*/
	int n, i = 1, k = 0; /* k记尚未配对的左括号个数 */
	SString ch, c1, c2, c3;
	InitString(&ch); /* 初始化HString类型的变量 */
	InitString(&c1);
	InitString(&c2);
	InitString(&c3);
	StrAssign(&c1, ",");
	StrAssign(&c2, "(");
	StrAssign(&c3, ")");
	n = StrLength(*str);
	//查找一个()或字母后的位置
	do {
		SubString(&ch, *str, i, 1);
		if (StrCompare(ch, c2)==0)
			k++;
		if (StrCompare(ch, c1) == 0)
			k--;
		i++;
	} while (i <= n&&k != 0||StrCompare(ch,c1)!=0);
	if (i > n)
	{
		
		StrCopy(*hstr, *str);
		ClearStr(*str);
	}
	else {
		StrCopy(&ch, *str);
		SubString(*hstr, *str, 1, i-2);
		SubString(*str, *str, i , n - i+1);
	}
}
Status CreatGList(GList *L,SString S)
{
	SString emp, sub, hsub;
	GList p;
	InitStr(emp);
	InitStr(sub);
	InitStr(hsub);
	StrAssign(emp, "()");
	if (compare(S, emp) == 0)
	{
		(*L)->tag = LIST;
		(*L)->elem.hp = NULL;
		(*L)->next = NULL;
	}
	else if (StrLength(S) == 1)
	{
		(*L)->tag = ATOM;
		(*L)->elem.atom=S[1];
		(*L)->next = NULL;
	}
	else {
		(*L)->tag = LIST;
		SubString(sub, S, 2, StrLength(S) - 1);
		sever(&sub, &hsub);
		CreatList((*L)->next, hsub);
		p = (*L)->next;
		while (!StrEmpty(sub))
		{
			sever(&sub, &hsub);
			CreatList(&p, hsub);
			p = p->next;
		}
	}
	return OK;
}