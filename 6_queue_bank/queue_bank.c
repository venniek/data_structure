#include "linkedqueue.h"
#include "simutil.h"

// 고객 도착 -> 고객 대기 -> 서비스 노드 -> free
// -> : 디큐, 반환값을 다음 큐에 인큐

// 고객 도착 큐에 고객 추가.
void insertCustomer(int arrivalTime, int serviceTime, LinkedQueue *pArrivalQueue)
{
	QueueNode new_cus;

	if (!pArrivalQueue)
		return ;
	new_cus.data.status = arrival;
	new_cus.data.arrivalTime = arrivalTime;
	new_cus.data.serviceTime = serviceTime;
	new_cus.data.startTime = 0;
	new_cus.data.endTime = 0;
	insertRearLD(pArrivalQueue, new_cus);
}

// 고객 도착 처리.
//currentTime : system상 현재 시각
void processArrival(int currentTime, LinkedQueue *pArrivalQueue, LinkedQueue *pWaitQueue)
{
	if (!pWaitQueue)
		return ;
	if (!pArrivalQueue)
		return ;
	if (currentTime == pArrivalQueue->pFrontNode->data.arrivalTime)
	{
		QueueNode *wait_cus = deleteFrontLD(pArrivalQueue);
		insertRearLD(pWaitQueue, *wait_cus);
		free(wait_cus);
	}
}

// 서비스 시작 처리.
QueueNode* processServiceNodeStart(int currentTime, LinkedQueue *pWaitQueue)
{
	QueueNode *pServiceNode;
	if (!pWaitQueue)
		return (NULL);
	pServiceNode = deleteFrontLD(pWaitQueue);
	if (!pServiceNode)
		return (NULL);
	pServiceNode->data.startTime = currentTime;
	pServiceNode->data.status = start;
	return (pServiceNode);
}

// 서비스 종료 처리.
QueueNode* processServiceNodeEnd(int currentTime, QueueNode *pServiceNode,
					int *pServiceUserCount, int *pTotalWaitTime)
{
	if (!pServiceNode)
		return (NULL);
	pServiceNode->data.status = end;
	pServiceNode->data.endTime = currentTime;
	*pTotalWaitTime += pServiceNode->data.startTime - pServiceNode->data.arrivalTime;
	(*pServiceUserCount)++;

	return (pServiceNode);
}

// 고객의 상태를 출력.
void printSimCustomer(int currentTime, SimCustomer customer)
{
	char * status;
    status = f(customer.status);
	printf("time: %d customer status: %s\n", currentTime, status);
}

// 대기 열의 상태를 출력.
void printWaitQueueStatus(int currentTime, LinkedQueue *pWaitQueue)
{
	if (!pWaitQueue)
		return ;
	printf("now time: %d\n", currentTime);
	displayLinkedQueue(pWaitQueue);
}

// 최종 시뮬레이션 결과(통계치) 출력.
void printReport(LinkedQueue *pWaitQueue, LinkedQueue *pArrivalQueue, int serviceUserCount,	int totalWaitTime)
{
	if (!pWaitQueue)
		return ;
	int flag = 0;
	
	if (!isLinkedQueueEmpty(pArrivalQueue))
	{
		printf(">>> Please come tommorrow LIST!\n");
		displayLinkedQueue(pArrivalQueue);
		printf("\n");
		flag++;
	}
	if (!isLinkedQueueEmpty(pWaitQueue))
	{
		printf(">>> There are remaining customers LIST :(\n");	
		displayLinkedQueue(pWaitQueue);
		printf("\n");
		flag++;
	}
	if (!flag)
		printf("Every customer has been satisfied! :)\n");	
	printf("\n");
	printf("----->>>>>\n");
	printf("The number of customers we provided : %d\n", serviceUserCount);
	printf("The total waiting time for customers : %d\n", totalWaitTime);
	printf("AVERAGE WAIT TIME : %.1f\n", (float)totalWaitTime / serviceUserCount);
}

int main()
{
	LinkedQueue *pWaitQueue = createLinkedQueue();
	LinkedQueue *pArrivalQueue = createLinkedQueue();
	QueueNode *serviceNode = 0;

	int isOnService = FALSE;

	int systemTime = 0;
	int closingTime = 4;
	int totalWaitTime = 0;
	int serviceUserCount = 0;

	//insertCustomer(int arrivalTime, int serviceTime, LinkedQueue *pArrivalQueue)
	insertCustomer(0, 3, pArrivalQueue);
	insertCustomer(2, 2, pArrivalQueue);
	insertCustomer(4, 1, pArrivalQueue);
	insertCustomer(6, 1, pArrivalQueue);
	insertCustomer(8, 3, pArrivalQueue);
	//고객 리스트가 도착 큐에 있다가, 시스템타임과 고객 도착시간이 일치하면 대기 큐로 넘어간다. 고객이 은행이 도착했다는 의미
	// serviceNode가 점유되어잇으면
	// 현재 serviceNode를 끝낼 시간이니?
	// 끝낼거면 점유해제 안 끝나면 계속 점유

	// 점유안돼잇니?
	// 안돼잇으면 start
	//돼잇으면 넘기고
	while (systemTime <= closingTime)
	{
		if (pArrivalQueue->currentElementCount > 0)
			processArrival(systemTime, pArrivalQueue, pWaitQueue);

		if (isOnService == TRUE)
		{
			if (systemTime - serviceNode->data.startTime == serviceNode->data.serviceTime)
			{
				free(processServiceNodeEnd(systemTime, serviceNode, &serviceUserCount, &totalWaitTime));
				serviceNode = 0;
				isOnService = FALSE;
			}
		}
		if (isOnService == FALSE)
		{
			serviceNode = processServiceNodeStart(systemTime, pWaitQueue);
			if (serviceNode != 0)
				isOnService = TRUE;
		}
		systemTime++;
	}

	if (isOnService == TRUE)
	{
		systemTime = serviceNode->data.serviceTime + serviceNode->data.startTime;
		free(processServiceNodeEnd(systemTime, serviceNode, &serviceUserCount, &totalWaitTime));
		serviceNode = 0;
		isOnService = FALSE;
		printf("Overtime : %d\n", systemTime - closingTime);
	}
	printf("**************** REPORT *****************\n");
	printf("\n");
	printReport(pWaitQueue, pArrivalQueue, serviceUserCount, totalWaitTime);

	deleteLinkedQueue(pArrivalQueue);
	deleteLinkedQueue(pWaitQueue);


	return 0;
}