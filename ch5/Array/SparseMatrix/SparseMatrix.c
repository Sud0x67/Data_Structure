#include <stdio.h>
#include <stdlib.h>
#include "PreDefined.h"
#include "SparseMatrix.h"

// ��������ʼ������
Status CreatMatrix(SparseMatrix *M)
{
	printf("\n���������������");
	scanf("%d", &M->mu);
	printf("\n���������������");
	scanf("%d", &M->nu);
	printf("\n������������Ԫ������");
	scanf("%d", &M->tu);
	for (int i = 1; i <= M->tu; i++)
	{
		printf("\n�������%d����Ԫ�飺",i);
		scanf("%d %d %d", &M->data[i].i,&M->data[i].j,&M->data[i].data);
	}
	return TRUE;
}
//DestroyMatrix û�ж�̬�����ڴ棬destroy����ʲô��
Status DestroyMatrix(SparseMatrix *M)
{
	M->mu = 0; M->nu = 0; M->tu = 0;
	return TRUE;
}
//��ӡ����
Status PrintMatrix(SparseMatrix M)
{
	printf("��Ԫ��Ϊ��\n");
	printf("%d ��%d��%d����Ԫ��\n", M.nu, M.mu, M.tu);
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
		//��ӡһ��
		for (int j = 1; j <= M.nu; j++)
		{
			//��ӡaij;
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
		//�н���
		printf("\n");
	}
}
void CopyMatrix(SparseMatrix M, SparseMatrix *T)
{
	(*T) = M;
}
//���������������
//����ǰ����������Ϊ��Ԫ�飬�����������ȴ���洢
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
//�������Q��i��j��=sum(M��i��k��*N��k��j����
//���Ϊ0���˼��ɣ���QӦ��ÿ��Ԫ�ض���ֵΪ0�����㣻
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
	}//! ��rpot����
	if (M.nu != N.mu)return;
	Q->mu = M.mu;
	Q->nu = N.nu;
	Q->tu = 0;//�������++��
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
				//Ĭ��rpot�洢������ص���Ϣ
				//���i��q������q��j�����������ͣ�
				//��i��j����N��j��i���
				for (int pos = 1; pos <= N.tu; pos++)
				{
					if(N.data[pos].i==M.data[q].j&&N.data[pos].j==j)
						data = +M.data[q].data*N.data[pos].data;
				}
			}
			//���data��=0����Q�м���Ԫ�أ�
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
//����ⷨ��Ը��Ӽ�
Status MultMatrix2(SparseMatrix M, SparseMatrix N, SparseMatrix *Q)
{
	if (M.nu != N.mu)return ERROR;
	Q->mu = M.mu; Q->nu = N.nu; Q->tu = 0;
	int h = Q->mu, l = Q->nu;
	ElemType * Qtemp = (ElemType*)malloc(sizeof(ElemType)*h*l);//���ڴ��Q�ķ���
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
	//ת��ά�ȵ���Ϣ��
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
	//��ʼ����num�������T�е�n���Ѿ���ŵĸ�����
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