#include<stdio.h>
#include"PreDefined.h"
#include"Stack.h"
void conversion()
{
	Stack S;
	int n;
	int m;
	initStack(&S);
	printf("辣鸡请输入一个数字：\n");
	scanf("%d", &n);
	while (n)
	{
		push(&S, n % 8);
		n = n / 8;
	}
	while (pop(&S, &m)) {
		printf("%d", m);
	}
}
void main()
{
	conversion();
	system("pause");
}
