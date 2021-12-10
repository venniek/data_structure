#include "linkedqueue.h"
#include "simutil.h"

LinkedQueue* createLinkedQueue()
{
	LinkedQueue* myQueue;

	myQueue = (LinkedQueue *)malloc(sizeof(LinkedQueue));
	if (!myQueue)
		return (FALSE);
	myQueue->currentElementCount = 0;
	myQueue->pFrontNode = 0;
	myQueue->pRearNode = 0;
	
	return (myQueue);
}

QueueNode *deleteFrontLD(LinkedQueue *pQueue)
{
	QueueNode *ret_node;

	if (!pQueue)
		return (NULL);
	if (isLinkedQueueEmpty(pQueue))
		return (NULL);
	ret_node = pQueue->pFrontNode;

	if (pQueue->currentElementCount == 1)
	{
		pQueue->pFrontNode = 0;
		pQueue->pRearNode = 0;
	}
	else
	{
		pQueue->pFrontNode = pQueue->pFrontNode->pRLink;
		ret_node->pRLink = NULL;
	}
	pQueue->currentElementCount--;
	return (ret_node);
}

void deleteLinkedQueue(LinkedQueue* pQueue)
{
	QueueNode *temp;
	
	if (!pQueue)
		return ;
	while (pQueue->currentElementCount)
	{
		temp = deleteFrontLD(pQueue);
		free(temp);
	}
	free(pQueue);
}

void displayLinkedQueue(LinkedQueue *pQueue)
{
	if (!pQueue)
		return;
	QueueNode *curr;
	int idx = 0;

	curr = pQueue->pFrontNode;
	printf("Queue size : %d\n", pQueue->currentElementCount);
	while (idx < pQueue->currentElementCount)
	{
		printf("{index: %d, arrivalTime: %d}\n", idx, curr->data.arrivalTime);
		curr = curr->pRLink;
		idx++;
	}
}

int insertRearLD(LinkedQueue* pQueue, QueueNode element)
{
	QueueNode *new_node;

	if (!pQueue)
		return (FALSE);
	new_node = (QueueNode *)malloc(sizeof(QueueNode));
	if (!new_node)
		return (FALSE);
	new_node->data = element.data;
	if (pQueue->pRearNode)
	{
		pQueue->pRearNode->pRLink = new_node;
		pQueue->pRearNode = new_node;
		new_node->pRLink = NULL;
	}
	else
	{
		pQueue->pFrontNode = new_node;
		pQueue->pRearNode = new_node;
		new_node->pRLink = NULL;
	}
	
	pQueue->currentElementCount++;

	return (TRUE);
}

int isLinkedQueueEmpty(LinkedQueue* pQueue)
{
	if (!pQueue)
		return (FALSE);
	return (pQueue->currentElementCount == 0 ? TRUE : FALSE);
}