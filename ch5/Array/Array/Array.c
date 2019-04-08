#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>
#include "PreDefined.h"
#define MAX_DIM 8 //数组的最大维度数为8；
typedef int ElemType;
typedef struct {
	ElemType *base;//数组的基址
	int dim;//数组的维数
	int *bounds;//数组各维度的长度
	int *constants;//数组计算位置的时候用的常量
}Array;
Status InitArray(Array *A, int dim, ...);
Status DestroyArray(Array *A);
Status Assign(Array A, ElemType e, ...);
Status Value(Array A, ElemType *e, ...);

Status InitArray(Array * A, int dim, ...)
{
	if (dim < 1 || dim > MAX_DIM)return ERROR;
	A->dim = dim;
	A->bounds = (int *)malloc(sizeof(int)*dim);
	if (!A->bounds)return OVERFLOW;
	va_list arg;
	int elemtotal=1;
	va_start(arg, dim);
	for (int i = 0; i < dim; i++)
	{
		(A->bounds)[i] = va_arg(arg, int);
		if ((A->bounds)[i] < 0)return ERROR;
		elemtotal *= (A->bounds)[i];
	}
	va_end(arg);
	A->base = (ElemType *)malloc(sizeof(ElemType)*elemtotal);
	if (!A->base)return OVERFLOW;
	A->constants= (int *)malloc(sizeof(int)*dim);
	if (!A->constants)return OVERFLOW;
	(A->constants)[dim - 1] = 1;
	for (int i = dim - 2; i >= 0; i--) {
		(A->constants)[i] = (A->constants)[i + 1] * (A->bounds)[i + 1];
	}
	return TRUE;
}

Status DestroyArray(Array * A)
{
	if (A->base) {
		free(A->base);
		A->base = NULL;
	}
	if (A->bounds) {
		free(A->bounds);
		A->bounds = NULL;
	}
	if (A->constants)
	{
		free(A->constants);
		A->constants = NULL;
	}
	return TRUE;
}

ElemType Assign(Array A, ElemType e, ...)
{
	int pos = 0;
	va_list  arg;
	va_start(arg, e);//va_start第一个参数为va_list 类型，第二个参数为不定参数直接前面的一个形参
	for (int i = 0; i < A.dim; i++)
	{
		pos += A.constants[i] * va_arg(arg,int);
	}
	va_end(arg); 
	A.base[pos] = e;
	return TRUE;
}

Status Value(Array A, ElemType *e, ...)
{
	int pos = 0;
	va_list  arg;
	va_start(arg, e);
	for (int i = 0; i < A.dim; i++)
	{
		pos += A.constants[i] * va_arg(arg, int);
	}
	va_end(arg);
	*e = A.base[pos];
	return TRUE;
}
void main() {
	Array A;
	ElemType e1, e2;
	if (InitArray(&A, 3, 6, 6, 6) < 0) {
		return;
	}
	for (int i = 0; i < 36 * 36; i++)
	{
		e1 = i;
		Assign(A, e1, 1, 2,6);
		Value(A, &e2, 1, 2,6);
		assert(e1 == e2);
	}
	DestroyArray(&A);
	system("pause");
}