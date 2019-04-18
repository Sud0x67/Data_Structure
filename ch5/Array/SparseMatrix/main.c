#include <stdio.h>
#include <stdlib.h>
#include "PreDefined.h"
#include "SparseMatrix.h"
void main()
{
	SparseMatrix M, T;
	CreatMatrix(&M);
	PrintRealMatrix(M);
	TransposeMatrix(M, &T);
	PrintRealMatrix(T);
	PrintMatrix(T);
	printf(":\n");
	fastTransposeMatirx(M, &T);
	PrintMatrix(T);
	system("pause");
}