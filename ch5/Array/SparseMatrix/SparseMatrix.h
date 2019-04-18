
#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H
#define MAXSIZE 12500
typedef int ElemType;
typedef struct {
	int i, j;
	ElemType data;
}Triple;
typedef struct {
	Triple data[MAXSIZE + 1];//0�����洢��������Ϊ����
	int mu, nu, tu;//���������������������Ԫ����
}SparseMatrix;
Status CreatMatrix(SparseMatrix * M);
Status CreatMatrix(SparseMatrix *M);

//DestroyMatrix û�ж�̬�����ڴ棬destroy����ʲô��
Status DestroyMatrix(SparseMatrix *M);

//��ӡ����
Status PrintMatrix(SparseMatrix M);

Status PrintRealMatrix(SparseMatrix M);

void CopyMatrix(SparseMatrix M, SparseMatrix *T);

void AddMatrix(SparseMatrix M, SparseMatrix N, SparseMatrix *Q);

void SubMatrix(SparseMatrix M, SparseMatrix N, SparseMatrix* Q);

void MultMatrix(SparseMatrix M, SparseMatrix N, SparseMatrix *Q);

void TransposeMatrix(SparseMatrix M,  SparseMatrix *T);

//���������Ԫ��λ��
void fastTransposeMatirx(SparseMatrix M, SparseMatrix * T);
#endif // !SPARSEMATRIX_H


