#include "../mst.h"

ArrayGraph	*fill_newArrayGraph_floyd(ArrayGraph *pGraph, int maxCount)
{
	ArrayGraph *ret_graph = createArrayGraph(maxCount);

	for (int i = 0; i < maxCount; i++)
		addVertexAG(ret_graph, i);
	for (int i = 0; i < maxCount; i++)
	{
		for (int j = 0; j < maxCount; j++)
		{
			if (i == j)
				ret_graph->ppAdjEdge[i][j] = 0;
			else if (pGraph->ppAdjEdge[i][j] == 0)
				ret_graph->ppAdjEdge[i][j] = INF;
			else
				ret_graph->ppAdjEdge[i][j] = pGraph->ppAdjEdge[i][j];
		}
	}
	return (ret_graph);
}

ArrayGraph  *floyd(ArrayGraph *pGraph)
{
	if (!error_nullparameter(pGraph, "pGraph"))
		return (NULL);
	int maxCount = pGraph->maxVertexCount;
	ArrayGraph *ret_graph = fill_newArrayGraph_floyd(pGraph, maxCount);
	if (!error_mallocfailure(ret_graph, "ret_graph"))
		return (NULL);
	int **edge = ret_graph->ppAdjEdge;
	
	for (int i = 0; i < maxCount; i++)
		for (int j = 0; j < maxCount; j++)
			for (int k = 0; k < maxCount; k++)
				if (i != j)
					edge[i][j] = ft_min(edge[i][j], (long long)edge[i][k] + edge[k][j]);
	return (ret_graph);
}