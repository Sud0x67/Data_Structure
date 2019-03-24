#pragma once
#ifndef _ELEMTYPE_H
#define _ELEMTYPE_H
typedef struct
{
	int OccurTime;//事件发生的时间
	int NType;//事件发生的类型0代表到达，1，2,3,4分别代表四个队列
}Event,ElemType;
typedef struct {
	int ArriaveTime;
	int Duration;
}QElemType;

#endif // !_ELEMTYPE_H

