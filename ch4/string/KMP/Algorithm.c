#include <stdio.h>
#include <stdlib.h>
#include "../string/PreDefined.h"
#include<string.h>
#define MAXSTRLEN 255
//一个串最长为255个字符0处存储长度。
//  b  
typedef unsigned char SString[MAXSTRLEN + 1];//unsigned char 转换为整数时范围不同,字符范围没有不同。
int next[MAXSTRLEN + 1];//next定义为全局变量与SString长度保持一致；
//BF 算法
void get_next(int next[], int n, SString T);
int Index(SString S, SString T, int pos)
{
	if (pos<1 || pos>S[0])return ERROR;
	int i = pos, j = 1;
	while (i <= S[0] && j <= T[0]) {
		if (S[i] == T[j])
		{
			i++; j++;
		}
		else {
			i = i - j + 1;
			j = 1;
			i++;
		}
	}
	if (j > T[0])return i - j + 1;
	else return -1;

}
int Index_KMP(SString S, SString T, int pos)
{
	if (pos<1 || pos>S[0])return ERROR;
	int i = pos, j = 1;
	//先建立next数组；
	int next[MAXSTRLEN + 1];//c语言数组不支持不定长数组；
	next[0] = S[0];
	get_next(next, T[0], T);
	
	
	while (i <= S[0] && j <= T[0]) {
		if (S[i] == T[j])
		{
			i++; j++;
		}
		else {
			if (next[j] == 0)
			{
				i++; j = 1;
			}
			else j = next[j];
		}
	}
	if (j > T[0])return i - T[0];
	else return -1;
}
//get next 方法
void get_next(int next[],int n,SString T)
{
	//i=1时k=0
	//i=2时k=1 k =max(重复的片段)+1//没有重复片段 k=1；k=next[k] k==0 则没有T[k],k==1
	//i=3,4,5,6时 if（S[i-1])=T[k]
	int k = 0, i = 2;
	next[1] =0;
	while (i <= n)
	{
		if (k == 0 || T[i - 1] == T[k])
		{
			++k;
			next[i] = k;
			++i;  
			
		}
		else {
			k = next[k]; 
		}
	}
}
void get_next2(int next[], int n, SString T)
{
	int j = 0, i = 1;
	next[1] = 0;
	while (i <n)
	{
		if ( j == 0 || T[i] == T[j])
		{
			++j;
			i++;
			next[i] = j;
		}
		else {
			j = next[j];
		}
	}
}
//以下是无关的一些算法RF和KMP算法都在上边
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
	int flag=1, i = Index(S, T, 1);
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
void main() {
	SString S1, S2, T;
	InitStr(T);
	InitStr(S1);
	InitStr(S2);
	StrAssign(S1, "12344babaabbffofoa");
	StrAssign(S2, "ab");
	printf("%d\t", Index(S1, S2, 1));
	printf("%d\t", Index_KMP(S1, S2, 1));
	for (int i = 1; i <= S1[0]; i++)
	{
		printf("%c", S1[i]);
	}
	printf("\n");
	printf("%d\t", Index(S1, S2, 1));
	printf("\n");
	int next[MAXSTRLEN + 1];//c语言数组不支持不定长数组；
	next[0] = S1[0];
	get_next(next, S1[0], S1);
	for (int i = 1; i < next[0]; i++)
	{
		printf("%d\t", next[i]);
	}
	printf("\n");
	get_next2(next, S1[0], S1);
	for (int i = 1; i < next[0]; i++)
	{
		printf("%d\t", next[i]);
	}
	system("pause");
}