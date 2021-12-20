#include "linkedgraph.h"

static void free_all(LinkedGraph *linkedgraph)
{
	for (int j = 0; j < linkedgraph->maxVertexCount; j++)
	{
		if (linkedgraph->ppAdjEdge[j])
		{
			free(linkedgraph->ppAdjEdge[j]);
			linkedgraph->ppAdjEdge[j] = 0;
		}
	}
	if (linkedgraph->ppAdjEdge)
	{
		free(linkedgraph->ppAdjEdge);
		linkedgraph->ppAdjEdge = 0;
	}
	if (linkedgraph->pVertex)
	{
		free(linkedgraph->pVertex);
		linkedgraph->pVertex = 0;
	}
	if (linkedgraph)
	{
		free(linkedgraph);
		linkedgraph = 0;
	}
}

LinkedGraph* createLinkedGraph(int maxVertexCount)
{
	LinkedGraph *pGraph;

	pGraph = (LinkedGraph *)calloc(1, sizeof(LinkedGraph));
	if (!pGraph)
	{
		printf("[error] Null Parameter : pGraph\n");
		return (FALSE);
	}
	pGraph->maxVertexCount = maxVertexCount;
	pGraph->graphType = 1;
	pGraph->ppAdjEdge = (LinkedList **)calloc(pGraph->maxVertexCount, sizeof(LinkedList *));
	if (!pGraph->ppAdjEdge)
	{
		printf("[error] malloc failure : ppAdjEdge\n");
		free_all(pGraph);
		return (NULL);
	}
	pGraph->pVertex = (int *)calloc(maxVertexCount,sizeof(int));
	if (!pGraph->pVertex)
	{
		printf("[error] malloc failure : pVertex\n");
		free_all(pGraph);
		return (NULL);
	}
	return (pGraph);
}

LinkedGraph* createLinkedDirectedGraph(int maxVertexCount)
{
	LinkedGraph *pGraph;

	pGraph = (LinkedGraph *)calloc(1, sizeof(LinkedGraph));
	if (!pGraph)
	{
		printf("[error] Null Parameter : pGraph\n");
		return (FALSE);
	}
	pGraph->maxVertexCount = maxVertexCount;
	pGraph->graphType = 2;
	pGraph->ppAdjEdge = (LinkedList **)calloc(pGraph->maxVertexCount, sizeof(LinkedList *));
	if (!pGraph->ppAdjEdge)
	{
		printf("[error] malloc failure : ppAdjEdge\n");
		free_all(pGraph);
		return (NULL);
	}
	pGraph->pVertex = (int *)calloc(maxVertexCount,sizeof(int));
	if (!pGraph->pVertex)
	{
		printf("[error] malloc failure : pVertex\n");
		free_all(pGraph);
		return (NULL);
	}
	return (pGraph);
}

int isEmptyLG(LinkedGraph* pGraph)
{
	if (!pGraph)
	{
		printf("[error] Null Parameter : pGraph\n");
		return (FALSE);
	}
	if (pGraph->currentVertexCount == 0)
		return (TRUE);
	return (FALSE);
}

int addVertexLG(LinkedGraph* pGraph, int vertexID)
{
	if (!pGraph)
	{
		printf("[error] Null Parameter : pGraph\n");
		return (FALSE);
	}
	if (vertexID < 0 || vertexID > pGraph-> maxVertexCount - 1)
	{
		printf("[error] Invalid value : VertexID\n");
		return (FALSE);
	}
	if (pGraph->pVertex[vertexID] == NOT_USED)
	{
		pGraph->pVertex[vertexID] = USED;
		pGraph->currentVertexCount++;
		pGraph->ppAdjEdge[vertexID] = createLinkedList();
	}
	else
		printf("That vertex already exists.\n");
	return (TRUE);
}

int addEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
{
	LinkedList *ptr;
	ListNode new_edge;
	int index;
	
	if (!pGraph)
	{
		printf("[error] Null Parameter : pGraph\n");
		return (FALSE);
	}
	if (!checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID))
		return (FALSE);
	ptr = pGraph->ppAdjEdge[fromVertexID];
	new_edge.to = toVertexID;
	new_edge.weight = 1;
	new_edge.pLink = NULL;
	index = findGraphNodePosition(ptr, toVertexID);
	if (index < 0)
		return (FALSE);
	if (index == 0) // 해당 노드가 없다.
	{
		addLLElement(ptr, ptr->currentElementCount, new_edge);
		if (pGraph->graphType == GRAPH_UNDIRECTED)
		{
			ptr = pGraph->ppAdjEdge[toVertexID];
			new_edge.to = fromVertexID;
			addLLElement(ptr, ptr->currentElementCount, new_edge);
		}
	}
	else
		printf("That edge already exists.\n");
	return (TRUE);
}

int addEdgewithWeightLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID, int weight)
{
	LinkedList *ptr;
	ListNode new_edge;
	int index;
	
	if (!pGraph)
	{
		printf("[error] Null Parameter : pGraph\n");
		return (FALSE);
	}
	if (!checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID))
		return (FALSE);
	ptr = pGraph->ppAdjEdge[fromVertexID];
	new_edge.to = toVertexID;
	new_edge.weight = weight;
	new_edge.pLink = NULL;
	index = findGraphNodePosition(ptr, toVertexID);
	if (index < 0)
		return (FALSE);
	if (index == 0) // 해당 노드가 없다.
	{
		addLLElement(ptr, ptr->currentElementCount, new_edge);
		if (pGraph->graphType == GRAPH_UNDIRECTED)
		{
			ptr = pGraph->ppAdjEdge[toVertexID];
			new_edge.to = fromVertexID;
			addLLElement(ptr, ptr->currentElementCount, new_edge);
		}
	}
	else
		printf("That edge already exists.\n");
	return (TRUE);
}

int checkVertexValid(LinkedGraph* pGraph, int vertexID)
{
	if (vertexID < 0 || vertexID > pGraph->maxVertexCount - 1)
	{
		printf("[error] Invalid value : vertexID\n");
		return (FALSE);
	}
	if (pGraph->pVertex[vertexID] == NOT_USED)
	{
		printf("[error] Invalid value : vertexID NOT_USED\n");
		return (FALSE);
	}
	return (TRUE);
}

int removeVertexLG(LinkedGraph* pGraph, int vertexID)
{
	LinkedList *ptr;

	if (!pGraph)
	{
		printf("[error] Null Parameter : pGraph\n");
		return (FALSE);
	}
	if (!checkVertexValid(pGraph, vertexID))
		return (FALSE);
	ptr = pGraph->ppAdjEdge[vertexID];
	deleteLinkedList(ptr);
	pGraph->pVertex[vertexID] = NOT_USED;
	return (TRUE);
}

int removeEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
{
	LinkedList *ptr;
	int index = 0;

	if (!pGraph)
	{
		printf("[error] Null Parameter : pGraph\n");
		return (FALSE);
	}
	if (!checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID))
		return (FALSE);
	ptr = pGraph->ppAdjEdge[fromVertexID];
	index = findGraphNodePosition(ptr, toVertexID);
	if (index < 0)
		return (FALSE);
	if (index > 0)
	{
		deleteGraphNode(ptr, toVertexID);
		if (pGraph->graphType == GRAPH_UNDIRECTED)
			deleteGraphNode(pGraph->ppAdjEdge[toVertexID], fromVertexID);
	}
	else
		printf("[error] Cannot remove edge that doesn't exist.\n");
	return (TRUE);
}

void deleteLinkedGraph(LinkedGraph* pGraph)
{
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		removeVertexLG(pGraph, i);
	}
	free(pGraph->ppAdjEdge);
	pGraph->ppAdjEdge = 0;
	free(pGraph->pVertex);
	pGraph->pVertex = 0;
	free(pGraph);
	pGraph = 0;
}

void deleteGraphNode(LinkedList* pList, int delVertexID)
{
	int index = 0;

	if (!pList)
	{
		printf("[error] Null Parameter : plist\n");
		return;
	}
	if ((index = findGraphNodePosition(pList, delVertexID)) > 0)
		removeLLElement(pList, index - 1);
}

// 주어진 LinkedList에서 vertexID를 데이터로 가진 노드가 있는 지 찾는다.
int findGraphNodePosition(LinkedList* pList, int vertexID)
{
	ListNode *now;

	if (!pList)
	{
		printf("[error] Null Parameter : plist\n");
		return (ERROR); // FALSE(=0) 을 반환해버리면 0번째 인덱스를 찾았는 지랑 구분이 안됨. 따라서 -1 반환.
	}
	now = pList->headerNode.pLink;
	for (int i = 0; i < pList->currentElementCount; i++)
	{
		if (now->to == vertexID)
			return (i + 1); // 참고 : remove시나 다른 쪽에서 i - 1 로 인덱스 넘길 것이므로 ㄱㅊ.
		now = now->pLink;
	}
	return (FALSE);
}

/*
* GET
*/
int getEdgeCountLG(LinkedGraph* pGraph)
{
	if (!pGraph)
	{
		printf("[error] Null Parameter : pGraph\n");
		return (FALSE);
	}
	return (pGraph->currentEdgeCount);
}

int getVertexCountLG(LinkedGraph* pGraph)
{
	if (!pGraph)
	{
		printf("[error] Null Parameter : pGraph\n");
		return (FALSE);
	}
	return (pGraph->currentVertexCount);
}

int getMaxVertexCountLG(LinkedGraph* pGraph)
{
	if (!pGraph)
	{
		printf("[error] Null Parameter : pGraph\n");
		return (FALSE);
	}
	return (pGraph->maxVertexCount);
}

int getGraphTypeLG(LinkedGraph* pGraph)
{
	if (!pGraph)
	{
		printf("[error] Null Parameter : pGraph\n");
		return (FALSE);
	}
	return (pGraph->graphType);
}

void displayLinkedGraph(LinkedGraph* pGraph)
{
	if (!pGraph)
	{
		printf("[error] Null Parameter : pGraph\n");
		return ;
	}
	if (isEmptyLG(pGraph))
	{
		printf("This is an Empty graph.\n");
		return ;
	}
	printf("-----------Adjacent Nodes----------\n");
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		if (pGraph->pVertex[i] == NOT_USED)
			continue;
		printf("from node %d:\n", i);
		print_list(&pGraph->ppAdjEdge[i]->headerNode);
		printf("\n");
	}
	printf("-----------------------------------\n");
}

void print_list(ListNode *curr)
{
	curr = curr->pLink; // 헤더노드의 다음 노드(이 노드에 연결된 노드들)부터 출력
	while(curr)
	{
		printf("           to: %d, weight: %d\n", curr->to, curr->weight);
		curr = curr->pLink;
	}
}