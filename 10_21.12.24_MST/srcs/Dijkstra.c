#include "../mst.h"

ArrayGraph  *fill_newArrayGraph_Dijkstra(int maxCount)
{
	ArrayGraph *ret_graph = createArrayGraph(maxCount);
	if (!error_mallocfailure(ret_graph, "ret_graph"))
		return (NULL);

	for (int i = 0; i < maxCount; i++)
		addVertexAG(ret_graph, i);
	for (int i = 0; i < maxCount; i++)
		for (int j = 0; j < maxCount; j++)
			ret_graph->ppAdjEdge[i][j] = i == j ? 0 : INF;
	return (ret_graph);
}

void find_Dijkstra(int i, ArrayGraph *ret_graph, ArrayGraph *pGraph)
{
	if (!(error_nullparameter(pGraph, "pGraph")))
		return ;
	if (!(error_nullparameter(ret_graph, "ret_graph")))
		return ;
	ArrayHeap *heap = createArrayHeap(pGraph->currentEdgeCount);
	if (!error_mallocfailure(heap, "heap"))
		return ;
	int **Edge = ret_graph->ppAdjEdge;

	insertHeapAH(heap, make_element(i, i, 0));
	while (!isArrayHeapEmpty(heap))
	{
		ArrayHeapNode *curr = deleteHeapAH(heap);
		if (Edge[i][curr->x] != curr->weight)
		{
			free(curr);
			curr = 0;
			continue;
		}
		for (int j = 0; j < pGraph->maxVertexCount; j++)
		{
			if (pGraph->ppAdjEdge[curr->x][j] != 0)
			{
				if (Edge[i][j] > Edge[i][curr->x] + pGraph->ppAdjEdge[curr->x][j])
				{	
					Edge[i][j] = Edge[i][curr->x] + pGraph->ppAdjEdge[curr->x][j];
					insertHeapAH(heap, make_element(j, curr->x, Edge[i][j]));
				}
			}
		}
		free(curr);
		curr = 0;
	}
    deleteArrayHeap(heap);
    heap = 0;
}

ArrayGraph *Dijkstra(ArrayGraph *pGraph)
{
	if (!(error_nullparameter(pGraph, "pGraph")))
		return (NULL);
	ArrayGraph *ret_graph = fill_newArrayGraph_Dijkstra(pGraph->maxVertexCount);
	if (!error_mallocfailure(ret_graph, "ret_graph"))
		return (NULL);

	for (int i = 0; i < pGraph->maxVertexCount; i++)
		find_Dijkstra(i, ret_graph, pGraph);
	return (ret_graph);
}