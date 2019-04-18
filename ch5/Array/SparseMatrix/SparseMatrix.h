
#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H
#define MAXSIZE 12500
typedef int ElemType;
typedef struct {
	int i, j;
	ElemType data;
}Triple;
typedef struct {
	Triple data[MAXSIZE + 1];//0处不存储；以行序为主序
	int mu, nu, tu;//矩阵的行数、列数、非零元个数
}SparseMatrix;
Status CreatMatrix(SparseMatrix * M);
Status CreatMatrix(SparseMatrix *M);

//DestroyMatrix 没有动态分配内存，destroy不做什么事
Status DestroyMatrix(SparseMatrix *M);

//打印矩阵
Status PrintMatrix(SparseMatrix M);

Status PrintRealMatrix(SparseMatrix M);

void CopyMatrix(SparseMatrix M, SparseMatrix *T);

void AddMatrix(SparseMatrix M, SparseMatrix N, SparseMatrix *Q);

void SubMatrix(SparseMatrix M, SparseMatrix N, SparseMatrix* Q);

void MultMatrix(SparseMatrix M, SparseMatrix N, SparseMatrix *Q);

void TransposeMatrix(SparseMatrix M,  SparseMatrix *T);

//先求出非零元的位置
void fastTransposeMatirx(SparseMatrix M, SparseMatrix * T);
#endif // !SPARSEMATRIX_H


