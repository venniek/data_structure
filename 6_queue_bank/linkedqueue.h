#ifndef _LINKED_Queue_
#define _LINKED_Queue_

#include <stdio.h>
#include <stdlib.h>

#define f(x) #x

typedef enum SimStatusType 
{ 
	arrival, 
	start,
	end
} SimStatus;

typedef struct SimCustomerType
{
	SimStatus status;
	int arrivalTime;	// 도착 시각.
	int serviceTime;	// 서비스 시간.
	int startTime;		// 시작 시각.
	int endTime;		// 종료 시각: 시작 시각 + 서비스 시간.
} SimCustomer;

typedef struct QueueNodeType
{
	SimCustomer data;
	struct QueueNodeType* pRLink;
} QueueNode;

typedef struct LinkedQueueType
{
	int currentElementCount;	// ???? ?????? ????
	QueueNode* pFrontNode;		// Front ????? ??????
	QueueNode* pRearNode;		// Rear ????? ??????
} LinkedQueue;

LinkedQueue* createLinkedQueue();
int insertRearLD(LinkedQueue* pQueue, QueueNode element);
QueueNode* deleteFrontLD(LinkedQueue* pQueue);
void deleteLinkedQueue(LinkedQueue* pQueue);
int isLinkedQueueEmpty(LinkedQueue* pQueue);
void displayLinkedQueue(LinkedQueue *pQueue);

#endif

#ifndef _COMMON_QUEUE_DEF_
#define _COMMON_QUEUE_DEF_

#define TRUE		1
#define FALSE		0

#endif