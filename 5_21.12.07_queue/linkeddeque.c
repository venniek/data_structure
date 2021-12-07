#include "linkeddeque.h"

LinkedDeque* createLinkedDeque()
{
	LinkedDeque* myDeque;

	myDeque = (LinkedDeque *)malloc(sizeof(LinkedDeque));
	if (!myDeque)
		return (FALSE);
	myDeque->currentElementCount = 0;
	myDeque->pFrontNode = 0;
	myDeque->pRearNode = 0;
	
	return (myDeque);
}

DequeNode *deleteFrontLD(LinkedDeque *pDeque)
{
	DequeNode *ret_node;

	if (!pDeque)
		return (NULL);
	if (isLinkedDequeEmpty(pDeque))
		return (NULL);
	ret_node = pDeque->pFrontNode;

	if (pDeque->currentElementCount == 1)
	{
		pDeque->pFrontNode = 0;
		pDeque->pRearNode = 0;
	}
	else
	{
		pDeque->pFrontNode = pDeque->pFrontNode->pRLink;
		pDeque->pFrontNode->pLLink = NULL;
		ret_node->pRLink = NULL;
	}
	pDeque->currentElementCount--;
	return (ret_node);
}

void deleteLinkedDeque(LinkedDeque* pDeque)
{
	DequeNode *temp;
	
	if (!pDeque)
		return ;
	while (pDeque->currentElementCount)
	{
		temp = deleteFrontLD(pDeque);
		free(temp);
	}
	free(pDeque);
}

DequeNode *deleteRearLD(LinkedDeque *pDeque)
{
	DequeNode *ret_node;

	if (!pDeque)
		return (NULL);
	if (isLinkedDequeEmpty(pDeque))
		return (NULL);
	ret_node = pDeque->pRearNode;

	if (pDeque->currentElementCount == 1)
	{
		pDeque->pFrontNode = 0;
		pDeque->pRearNode = 0;
	}
	else
	{
		pDeque->pRearNode = pDeque->pRearNode->pLLink;
		pDeque->pRearNode->pRLink = NULL;
		ret_node->pLLink = NULL;
	}
	pDeque->currentElementCount--;
	return (ret_node);
}

void displayLinkedDeque(LinkedDeque *pDeque)
{
	if (!pDeque)
		return;
	DequeNode *curr;
	int idx = 0;

	curr = pDeque->pFrontNode;
	printf("Deque size : %d\n", pDeque->currentElementCount);
	while (idx < pDeque->currentElementCount)
	{
		printf("{index: %d, data: %d}\n", idx, curr->data);
		curr = curr->pRLink;
		idx++;
	}
}

int insertFrontLD(LinkedDeque* pDeque, DequeNode element)
{
	DequeNode *new_node;

	if (!pDeque)
		return (FALSE);
	new_node = (DequeNode *)malloc(sizeof(DequeNode));
	if (!new_node)
		return (FALSE);
	new_node->data = element.data;
	if (pDeque->pFrontNode)
	{
		pDeque->pFrontNode->pLLink = new_node;
		new_node->pRLink = pDeque->pFrontNode;
		pDeque->pFrontNode = new_node;
		new_node->pLLink = NULL;
	}
	else
	{
		pDeque->pFrontNode = new_node;
		pDeque->pRearNode = new_node;
		new_node->pLLink = NULL;
		new_node->pRLink = NULL;
	}

	pDeque->currentElementCount++;

	return (TRUE);
}


int insertRearLD(LinkedDeque* pDeque, DequeNode element)
{
	DequeNode *new_node;

	if (!pDeque)
		return (FALSE);
	new_node = (DequeNode *)malloc(sizeof(DequeNode));
	if (!new_node)
		return (FALSE);
	new_node->data = element.data;
	if (pDeque->pRearNode)
	{
		pDeque->pRearNode->pRLink = new_node;
		new_node->pLLink = pDeque->pRearNode;
		pDeque->pRearNode = new_node;
		new_node->pRLink = NULL;
	}
	else
	{
		pDeque->pFrontNode = new_node;
		pDeque->pRearNode = new_node;
		new_node->pLLink = NULL;
		new_node->pRLink = NULL;
	}
	
	pDeque->currentElementCount++;

	return (TRUE);
}

int isLinkedDequeEmpty(LinkedDeque* pDeque)
{
	if (!pDeque)
		return (FALSE);
	return (pDeque->currentElementCount == 0 ? TRUE : FALSE);
}

DequeNode* peekFrontLD(LinkedDeque* pDeque)
{
	if (!pDeque)
		return (NULL);
	return (pDeque->pFrontNode);
}

DequeNode* peekRearLD(LinkedDeque* pDeque)
{
	if (!pDeque)
		return (NULL);
	return (pDeque->pRearNode);
}