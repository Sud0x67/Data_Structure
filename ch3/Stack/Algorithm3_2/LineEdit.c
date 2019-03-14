#include <stdio.h>
#include "PreDefined.h"
#include "Stack.h"
void print_e(ElemType *c)
{
	printf("%c", *c);
}
void editLine()
{
	char ch,e;
	Stack S;
	initStack(&S);
	while ((ch = getchar() )!= EOF) {
		while (ch != '\n'&&ch != EOF)//单引号和双引号不能混用，编译器会将双引号看做字符串
		{
			switch (ch)
			{
			case '#':
				pop(&S, &e);
				break;
			case '@':
				clearStack(&S);
				break;
			default:
				push(&S, ch);
			} 
			ch = getchar();
		}
		stackTraverse(S, print_e);//读完以后要执行的操作
		putchar('\n');//读完以后要执行的操作
		clearStack(&S);
	}
	destroyStack(&S);
}
void main()
{
	editLine();
	system("pause");
}