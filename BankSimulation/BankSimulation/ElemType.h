#pragma once
#ifndef _ELEMTYPE_H
#define _ELEMTYPE_H
typedef struct
{
	int OccurTime;//�¼�������ʱ��
	int NType;//�¼�����������0�����1��2,3,4�ֱ�����ĸ�����
}Event,ElemType;
typedef struct {
	int ArriaveTime;
	int Duration;
}QElemType;

#endif // !_ELEMTYPE_H

