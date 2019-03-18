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
	printf("\nLa的head是%d，tail是%d，La的长度是%d,是否为空%d\n", La.head, La.tail, polynLength(La), listEmpty(La));
	printPolyn(La);
	creatPolynomial(&Lb, 6);
	printf("\nLb的head是%d，tail是%d，Lb的长度是%d,是否为空%d\n", Lb.head, Lb.tail, polynLength(Lb), listEmpty(Lb));
	printPolyn(Lb);
	addPolyn(&La, &Lb);
	printPolyn(La);
	destroyList(&La);
	printf("\nL的head是%d，tail是%d，L的长度是%d,是否为空%d\n", La.head, La.tail, polynLength(La), listEmpty(La));
	system("pause");
}