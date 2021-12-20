#include "linkedgraph.h"

void traversal_DFS_recur(LinkedGraph *pGraph, int from)
{
	printf("%d ", from);
	pGraph->pVertex[from] = VISITED;
	ListNode *now = pGraph->ppAdjEdge[from]->headerNode.pLink;
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		if (now == NULL)
			break;
		if (pGraph->pVertex[now->to] == USED) // 내가 앞으로 들어갈 방향이 i
		{
			traversal_DFS_recur(pGraph, now->to);
		}
		now = now->pLink;
	}
}

void traversal_DFS(LinkedGraph *pGraph)
{
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		if (pGraph->pVertex[i] == USED)
		{
			traversal_DFS_recur(pGraph, i); // 간선으로 연결된 노드들 싹 돌고 나옴.
			printf("\n");
		}
	}
}

void traversal_BFS(LinkedGraph *pGraph)
{
	ArrayQueue *queue = createArrayQueue(pGraph->maxVertexCount);
	ArrayQueueNode tmp;

	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		if (pGraph->pVertex[i] == USED) // 내가 앞으로 들어갈 방향이 i
		{
			tmp.data = i;
			enqueueAQ(queue, tmp);
			pGraph->pVertex[i] = VISITED;
			while (!isArrayQueueEmpty(queue))
			{
				ArrayQueueNode *now;
				now = dequeueAQ(queue);
				printf("%d ", now->data);
				ListNode *next = pGraph->ppAdjEdge[now->data]->headerNode.pLink;
				for (int j = 0; j < pGraph->ppAdjEdge[next->to]->currentElementCount; j++)
				{
					if (next == NULL)
						break;
					if (pGraph->pVertex[next->to] == USED)
					{
						tmp.data = next->to;
						enqueueAQ(queue, tmp);
						pGraph->pVertex[tmp.data] = VISITED;
					}
					next = next->pLink;
				}
				free(now);
			}
			printf("\n");
		}
	}
	deleteArrayQueue(queue);
}