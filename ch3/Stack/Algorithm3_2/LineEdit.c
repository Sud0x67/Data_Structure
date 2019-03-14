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
		while (ch != '\n'&&ch != EOF)//�����ź�˫���Ų��ܻ��ã��������Ὣ˫���ſ����ַ���
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
		stackTraverse(S, print_e);//�����Ժ�Ҫִ�еĲ���
		putchar('\n');//�����Ժ�Ҫִ�еĲ���
		clearStack(&S);
	}
	destroyStack(&S);
}
void main()
{
	editLine();
	system("pause");
}