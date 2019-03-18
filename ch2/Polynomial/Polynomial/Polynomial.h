#pragma once
#ifndef _POLYNOMIAL_H
#define _POLYNOMIAL_H
#define destroyPolyn destroyList
#define polynLength listLength
typedef LinkList Polynomial;
void print_e(ElemType * c);

Status compare(ElemType e1, ElemType e2);

void creatPolynomial(Polynomial * L, int m);

void printPolyn(Polynomial L);
void addPolyn(Polynomial * La, Polynomial * Lb);
#endif // !_POLYNOMIAL_H


