#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "PreDefined.h"
#define MAXSTRLEN 255
//一个串最长为255个字符0处存储长度。
//
typedef unsigned char SString[MAXSTRLEN + 1];//unsigned char 转换为整数时范围不同,字符范围没有不同。
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
		int j=1;
		while (j <= T[0] && i <= S[0])
		{
			if (S[i] == T[j])
			{
				i++; j++;
			}
			else break;
		}
		if (j == T[0]+1)return i - j + 1;
		if (i == S[0]+1)return -1;
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
		for (int j = S[0]+interval; j >= pos; j--)
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
		S[0] =S[0]- T[0];
		//从第i位插入C；
		flag =Insert(S, i, V);
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
void main() {
	SString S1, S2, T;
	InitStr(T);
	InitStr(S1);
	InitStr(S2);
	StrAssign(S1, "what about yourfskljg;aklkgjalkgjlha;jghoaphioewoabui[ogojaiowhefawiueihgpdsjaklhfsdalhavbeiuaerhfga?");
	StrAssign(S2, "a");
	printf("%d\t", Index(S1, S2, 0));
	StrAssign(T, "99");
	Insert(S1, 33, T);
	Insert(S1, 33, T);
	Replace(S1, S2, T);
	for (int i = 1; i <= S1[0];i++)
	{
		printf("%c", S1[i]);
	}
	printf("\n");
	printf("%d\t", Index(S1, S2, 0));
	printf("\n");
	system("pause");
}