#include <stdio.h>
#include <stdlib.h>
#include "PreDefined.h"
#include "SparseMatrix.h"

// 创建并初始化数组
Status CreatMatrix(SparseMatrix *M)
{
	printf("\n请输入矩阵行数：");
	scanf("%d", &M->mu);
	printf("\n请输入矩阵列数：");
	scanf("%d", &M->nu);
	printf("\n请输入矩阵非零元个数：");
	scanf("%d", &M->tu);
	for (int i = 1; i <= M->tu; i++)
	{
		printf("\n请输入第%d个三元组：",i);
		scanf("%d %d %d", &M->data[i].i,&M->data[i].j,&M->data[i].data);
	}
	return TRUE;
}
//DestroyMatrix 没有动态分配内存，destroy不做什么事
Status DestroyMatrix(SparseMatrix *M)
{
	M->mu = 0; M->nu = 0; M->tu = 0;
	return TRUE;
}
//打印矩阵
Status PrintMatrix(SparseMatrix M)
{
	printf("三元组为：\n");
	printf("%d 行%d列%d个三元组\n", M.nu, M.mu, M.tu);
	for (int i = 1; i <= M.tu; i++)
	{
		printf("%d %d %d\n", M.data[i].i, M.data[i].j, M.data[i].data);
	}
	return TRUE;
}
Status PrintRealMatrix(SparseMatrix M)
{
	if (M.mu == 0 && M.nu == 0)return FALSE;
	for (int i = 1; i <= M.mu; i++)
	{
		//打印一行
		for (int j = 1; j <= M.nu; j++)
		{
			//打印aij;
			int k;
			for ( k= 1; k <= M.tu; k++)
			{
				if (M.data[k].i == i&&M.data[k].j == j)
				{
					printf("%d\t", M.data[k].data);
					break;
				}
			}
			if(k>M.tu)printf("%d\t", 0);
		}
		//行结束
		printf("\n");
	}
}
void CopyMatrix(SparseMatrix M, SparseMatrix *T)
{
	(*T) = M;
}
//操作两个矩阵相加
//操作前：两个矩阵为三元组，并且以行优先次序存储
void AddMatrix(SparseMatrix M, SparseMatrix N, SparseMatrix *Q)
{
	int indexM=1,indexN=1;
	Q->tu = 0;
	while (indexM <= M.tu&&indexN <= N.tu)
	{
		if (M.data[indexM].i <N.data[indexN].i)
		{
			Q->tu++;
			Q->data[Q->tu].i = M.data[indexM].i;
			Q->data[Q->tu].j = M.data[indexM].j;
			Q->data[Q->tu].data = M.data[indexM].data;
			indexM++;
		}else if(M.data[indexM].i > N.data[indexN].i)
		{
			Q->tu++;
			Q->data[Q->tu].i = N.data[indexN].i;
			Q->data[Q->tu].j = N.data[indexN].j;
			Q->data[Q->tu].data = N.data[indexN].data;
			indexN++;
		}
		else if (M.data[indexM].j > N.data[indexN].j)
		{
			Q->tu++;
			Q->data[Q->tu].i = N.data[indexN].i;
			Q->data[Q->tu].j = N.data[indexN].j;
			Q->data[Q->tu].data = N.data[indexN].data;
			indexN++;
		}
		else if (M.data[indexM].j < N.data[indexN].j)
		{
			Q->tu++;
			Q->data[Q->tu].i = M.data[indexM].i;
			Q->data[Q->tu].j = M.data[indexM].j;
			Q->data[Q->tu].data = M.data[indexM].data;
			indexM++;
		}
		else
		{
			if (M.data[indexM].data + N.data[indexN].data != 0)
			{
				Q->tu++;
				Q->data[Q->tu].i = M.data[indexM].i;
				Q->data[Q->tu].j = M.data[indexM].j;
				Q->data[Q->tu].data = M.data[indexM].data + N.data[indexN].data;
			}
			indexM++;
			indexN++;
		}
	}
	while (indexM <= M.tu)
	{
		Q->tu++;
		Q->data[Q->tu] = M.data[indexM];
	}
	while (indexN <= N.tu)
	{
		Q->tu++;
		Q->data[Q->tu] = N.data[indexN];
	}
}
void SubMatrix(SparseMatrix M, SparseMatrix N, SparseMatrix* Q)
{
	for (int i = 1; i < N.tu; i++)
	{
		N.data[i].data *= -1;
	}
	AddMatrix(M, N, Q);
}
//矩阵相乘Q（i，j）=sum(M（i，k）*N（k，j））
//如果为0不乘即可，对Q应该每个元素都求值为0不计算；
void MultMatrix(SparseMatrix M, SparseMatrix N, SparseMatrix *Q)
{
	int num[MAXSIZE + 1];
	int rpot[MAXSIZE + 1];
	for (int row = 1; row <= M.mu; row++)
	{
		num[row] = 0;
	}
	for (int i = 1; i <= M.tu; i++)
	{
		num[M.data[i].i]++;
	}
	rpot[1] = 1;
	for (int row = 2; row<= M.mu; row++)
	{
		rpot[row] = rpot[row - 1] + num[row- 1];
	}//! 求rpot数组
	if (M.nu != N.mu)return;
	Q->mu = M.mu;
	Q->nu = N.nu;
	Q->tu = 0;//边求积边++；
	for (int i = 1; i <= Q->mu; i++)
	{
		for (int j = 1; j < Q->nu; j++)
		{
			int lim;
			if (i == Q->mu)lim = M.tu+1;
			else lim = rpot[i + 1];
			int data = 0;
			for (int q = rpot[i]; q < lim; q++)
			{
				//默认rpot存储了行相关的信息
				//如果i，q存在且q，j存在则相乘求和；
				//第i行j个和N的j行i相乘
				for (int pos = 1; pos <= N.tu; pos++)
				{
					if(N.data[pos].i==M.data[q].j&&N.data[pos].j==j)
						data = +M.data[q].data*N.data[pos].data;
				}
			}
			//如果data！=0，向Q中加入元素；
			if (data != 0)
			{
				Q->tu++;
				Q->data[Q->tu].data = data;
				Q->data[Q->tu].i = i;
				Q->data[Q->tu].j = j;
			}
		}
	}
}
//这个解法相对更加简单
Status MultMatrix2(SparseMatrix M, SparseMatrix N, SparseMatrix *Q)
{
	if (M.nu != N.mu)return ERROR;
	Q->mu = M.mu; Q->nu = N.nu; Q->tu = 0;
	int h = Q->mu, l = Q->nu;
	ElemType * Qtemp = (ElemType*)malloc(sizeof(ElemType)*h*l);//用于存放Q的方阵
	for (int i = 0; i < h*l; i++)Qtemp[i] = 0;
	for (int i = 1; i < M.tu; i++)
	{
		for (int j = 1; j < N.tu; j++)
		{
			if (M.data[i].j == N.data[j].i)
			{
				int pos = (M.data[i].i - 1)*l + N.data[j].j - 1;
				Qtemp[pos] += M.data[i].data * N.data[j].data;
			}
		}
	}
	
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < l; j++)
		{
			if (Qtemp[i*l + j] != 0)
			{
				Q->tu++;
				Q->data[Q->tu].i = i + 1;
				Q->data[Q->tu].j = j + 1;
				Q->data[Q->tu].data = Qtemp[i*l + j];
			}
		}
	}
}
void TransposeMatrix(SparseMatrix M,  SparseMatrix *T) 
{
	//转换维度等信息；
	T->mu = M.nu;
	T->nu = M.mu;
	T->tu = M.tu;
	if (T->tu)
	{
		int col, p, q=1;
		for (col = 1; col <= M.mu; col++)
		{
			for (p = 1; p <= M.tu; p++)
			{
				if (M.data[p].j == col)
				{
					T->data[q].i = M.data[p].j;
					T->data[q].j = M.data[p].i;
					T->data[q].data = M.data[p].data;
					q++;
				}
			}
		}
	}
}
void fastTransposeMatirx(SparseMatrix M, SparseMatrix * T)
{
	int num[MAXSIZE + 1];
	int cpot[MAXSIZE + 1];
	for (int col = 1; col <= M.nu; col++)
	{
		num[col] = 0;
	}
	for (int i = 1; i <= M.tu; i++)
	{
		num[M.data[i].j]++;
	}
	cpot[1] = 1;
	for (int col = 2; col <= M.nu; col++)
	{
		cpot[col] = cpot[col - 1] + num[col-1];
	}
	//初始化后num用来存放T中第n行已经存放的个数；
	T->mu = M.nu;
	T->nu = M.mu;
	T->tu = M.tu;
	for (int col = 1; col <= T->mu; col++)
	{
		num[col] = 0;
	}
	for (int i = 1; i<=T->tu; i++)
	{
		int pos;
		pos = cpot[M.data[i].j] + num[M.data[i].j];
		T->data[pos].i = M.data[i].j;
		T->data[pos].j = M.data[i].i;
		T->data[pos].data = M.data[i].data;
		num[M.data[i].j]++;
	}
}