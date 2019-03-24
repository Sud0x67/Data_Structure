#include<stdio.h>
#include<stdlib.h>
#include "PreDefined.h"
#include "LinkList.h"
#include "ListQueue.h"
#include<time.h>
#define CLOSE 800

typedef LinkList EventList;
EventList evList;
Event event;
LinkQueue q[5];//q(1,2,3,4）表示4个队列q0不使用；书中这样写的没办法；
QElemType customer;
int TotalTime, CustomerNum;
//compare函数；
Status compare(ElemType e1, ElemType e2)
{
	if (e1.OccurTime < e2.OccurTime)return -1;
	if (e1.OccurTime > e2.OccurTime)return 1;
	if (e1.OccurTime == e2.OccurTime)return 0;
}
void openforDay()
{
	TotalTime = 0;
	CustomerNum = 0;
	initList(&evList);
	event .NType=0;
	event.OccurTime = 0;
	orderInsert(&evList, event, compare);
	for (int i = 1; i < 5; i++)
	{
		initQueue(&q[i]);
	}
}
void customerArrived(Event event) {
	CustomerNum++;
	srand((unsigned int)time(NULL));
	int durtime = rand() % 100;//当前客户办理业务所需时间
	int intertime = rand() % 200;//下一个客户到来的时间；
	customer.Duration = durtime;
	customer.ArriaveTime = event.OccurTime;
	int i = 0;
	for (int j = 1; j <= 4; j++)
	{
		if (i >= queueLength(q[j]))i = j;
	}
	enQueue(&q[i], customer);
	event.OccurTime = event.OccurTime +intertime;
	event.NType = 0;
	if (event.OccurTime < CLOSE)
	{
		orderInsert(&evList, event, compare);
	}
}
void customerDeparture(Event event)
{
	int i = event.NType;
	deQueue(&q[i],&customer);
	TotalTime += event.OccurTime - customer.ArriaveTime;
	if (!queueEmpty(q[i])) {
		event.OccurTime += customer.Duration;
		event.NType = i;
		orderInsert(&evList, event, compare);
	}
}
void bank() {
	openforDay();
	Link q;
	while (!listEmpty(evList))
	{
		delFirst(&evList, evList.head, &q);
		ElemType event;
		event.NType = q->data.NType;
		event.OccurTime = q->data.OccurTime;
		if (!event.NType)
		{
			customerArrived(event);
		}
		else {
			customerDeparture(event);
		}
	}
	printf("The Average Time is %f/n", (float)TotalTime / CustomerNum);
}
void main() {
	bank();
	system("pause");
}