#include <stdio.h>
#include <stdlib.h>
#include "PreDefined.h"
#include "LinkList.h"
#include "Polynomial.h"
void main()
{
	Link p;
	Polynomial  La,Lb;
	creatPolynomial(&La, 3);
	printf("\nLa��head��%d��tail��%d��La�ĳ�����%d,�Ƿ�Ϊ��%d\n", La.head, La.tail, polynLength(La), listEmpty(La));
	printPolyn(La);
	creatPolynomial(&Lb, 6);
	printf("\nLb��head��%d��tail��%d��Lb�ĳ�����%d,�Ƿ�Ϊ��%d\n", Lb.head, Lb.tail, polynLength(Lb), listEmpty(Lb));
	printPolyn(Lb);
	addPolyn(&La, &Lb);
	printPolyn(La);
	destroyList(&La);
	printf("\nL��head��%d��tail��%d��L�ĳ�����%d,�Ƿ�Ϊ��%d\n", La.head, La.tail, polynLength(La), listEmpty(La));
	system("pause");
}