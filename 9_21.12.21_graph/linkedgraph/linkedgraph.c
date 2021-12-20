#include "linkedgraph.h"
#include "linkedlist.h"

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
	int index = 0;

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
	if (findGraphNodePosition(ptr, toVertexID) == 0)
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

}

int removeEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
{

}

void deleteLinkedGraph(LinkedGraph* pGraph)
{
	LinkedList **ptr = pGraph->ppAdjEdge;

	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		deleteGraphNode(ptr[i], i);
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
	
}

int findGraphNodePosition(LinkedList* pList, int vertexID)
{

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
	printf("----------Edges----------\n");
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		for (int j = 0; j < pGraph->maxVertexCount; j++)
		{
			printf("%d ", pGraph->ppAdjEdge[i][j]);
		}
		printf("\n");
	}
	printf("-------------------------\n\n");

	printf("------Adjacent Nodes-----\n");
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		if (pGraph->pVertex[i] == NOT_USED)
			continue;
		printf("from node %d to: ", i);
		for (int j = 0; j < pGraph->maxVertexCount; j++)
		{
			// if (pGraph->ppAdjEdge[i][j] == 1)
			// 	printf("%d ", j);
		}
		printf("\n");
	}
	printf("-------------------------\n");
}
