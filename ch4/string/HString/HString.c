#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "PreDefined.h"

typedef struct {
	char *ch;
	int len;
}HString;
Status Init(HString *H) {
	H->ch = NULL;
	H->len = 0;
	return OK;
}
Status StrAssign(HString *H, char* str)
{
	int i = 0;
	char*q, *p = str;
	while (*p != '\0') {
		p++;
		i++;
	}
	H->len = i;
	if (H->ch) free(H->ch);
	if (i = 0) { H->len = 0; H->ch = NULL; return 0; }
	if (!(H->ch = (char*)malloc(sizeof(char)*H->len)))return OVERFLOW;
	p = str; q = H->ch;
	while (*p != '\0') {
		*q = *p;
		q++; p++;
	}
}
int StrLength(HString H)
{
	return H.len;
}
Status ClearStr(HString *H) {
	H->len = 0;
	free(H->ch);
	H->ch = NULL;
	return OK;
}
int StrCompare(HString H1, HString H2) {
	char *p, *q;
	p = H1.ch; q = H2.ch;
	while (p < H1.ch + H1.len&&q < H2.ch + H2.len)
	{
		if (*p == *q) {
			p++;
			q++;
		}
		else if (*p < *q) {
			return -1;
		}
		else {
			return 1;
		}
	}
	if (p == H1.ch + H1.len && q == H2.ch + H2.len) {
		return 0;
	}
	else if (p == H1.ch + H1.len) {
		return -1;
	}
	else {
		return 1;
	}
}
Status Concat(HString *H1, HString H2)
{
	char *p, *q;
	char *ptr = (char *)realloc(H1->ch, sizeof(char)*(H1->len + H2.len));
	if (!ptr)return OVERFLOW;
	H1->ch = ptr;
	p = H1->ch + H1->len;
	q = H2.ch;
	while (q < H2.ch + H2.len)
	{
		*p = *q;
		p++; q++;
	}
	H1->len = H1->len + H2.len;
	return OK;
}
HString SubString(HString *Sub, HString S, int pos, int len) {
	if (Sub->ch) {
		free(Sub->ch);
		Sub->ch = NULL;
		Sub->len = 0;
	}
	if (pos < 1 || len<0 || pos + len - 1>S.len) return *Sub;
	if (!(Sub->ch = (char*)malloc(sizeof(char)*len)))exit(OVERFLOW);
	Sub->len = len;
	char *p, *q;
	p = Sub->ch; q = S.ch + pos - 1;
	while (p < Sub->ch + len)
	{
		*p = *q;
		p++; q++;
	}
	return *Sub;
}
void main() {
	HString H1, H2, Sub;
	Init(&H1); Init(&H2);
	Init(&Sub);
	StrAssign(&H1, "afoafggaogogo");
	printf("H1->ch:%zd,H1->len:%d\n", H1.ch, H1.len);
	StrAssign(&H2, "fagsgfgaogogo");
	printf("H2->ch:%zd,H2->len:%d\n", H2.ch, H2.len);
	printf("%d\n", StrCompare(H1, H2));
	printf("%d\n", StrCompare(H1, H1));
	Concat(&H1, H2);
	Sub=SubString(&Sub, H1, 3, 4);
	char *p = H1.ch;
	while (p < H1.ch + H1.len)
	{
		printf("%c", *p++);
	}
	printf("\n");
	p = Sub.ch;
	while (p < Sub.ch + Sub.len)
	{
		printf("%c", *p++);
	}
	printf("\n");
	system("pause");
}