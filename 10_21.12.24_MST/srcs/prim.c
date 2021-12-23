#include "../mst.h"

void put_firstHeapNode(ArrayGraph *pGraph, int *visited, ArrayHeap *heap)
{
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		if (pGraph->ppAdjEdge[0][i] != 0)
			insertHeapAH(heap, make_element(i, 0, pGraph->ppAdjEdge[0][i]));
	}
	visited[0] = 1;
}

ArrayGraph *prim(ArrayGraph *pGraph)
{
	int maxCount = pGraph->maxVertexCount;
	if (!error_nullparameter(pGraph, "pGraph"))
		return (NULL);
	int *visited = (int *)calloc(maxCount, sizeof(int));
	if (!error_mallocfailure(visited, "visited"))
		return (NULL);
	ArrayGraph *ret_graph = createArrayGraph(maxCount);
	if (!error_mallocfailure(ret_graph, "ret_graph"))
		return (NULL);
	ArrayHeap *heap = createArrayHeap(maxCount);
	if (!error_mallocfailure(heap, "heap"))
		return (NULL);

	for (int i = 0; i < maxCount; i++)
		addVertexAG(ret_graph, i);
	put_firstHeapNode(pGraph, visited, heap);
	while (!isArrayHeapEmpty(heap))
	{
		ArrayHeapNode *pop = deleteHeapAH(heap);
		if (visited[pop->x] == 0)
		{
			addEdgewithWeightAG(ret_graph, pop->x, pop->y, pop->weight);
			visited[pop->x] = 1;
			for (int i = 0; i < maxCount; i++)
				if (pGraph->ppAdjEdge[pop->x][i] != 0)
					insertHeapAH(heap, make_element(i, pop->x, pGraph->ppAdjEdge[pop->x][i]));
		}
		free(pop);
		pop = 0;
	}

	free(visited);
	visited = 0;
	deleteArrayHeap(heap);
	heap = 0;

	return (ret_graph);
}
