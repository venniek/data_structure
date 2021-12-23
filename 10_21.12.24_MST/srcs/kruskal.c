#include "../mst.h"

bool chk;

int find(int dot, int *parent) // find : 가장 부모를 찾는다.
{
	if (dot == parent[dot])
		return dot;
	return parent[dot] = find(parent[dot], parent);
}

void merge(int a, int b, int *parent) // union : 같은 그룹인지
{
	chk = false;
	a = find(a, parent);
	b = find(b, parent);
	
	if (a == b)
		return ;
	parent[a] = b; // 무조건 어느 하나는 다른 하나의 부모가 된다.
	chk = true;
}

void	move_Graph2Heap(ArrayGraph *pGraph, ArrayHeap *heap)
{
	if (!error_nullparameter(pGraph, "pGraph") || !error_nullparameter(heap, "heap"))
		return ;
	for (int i = 0; i < pGraph->maxVertexCount; i++)
		for (int j = 0; j < pGraph->maxVertexCount; j++)
			if (pGraph->ppAdjEdge[i][j] != 0)
				insertHeapAH(heap, make_element(i, j, pGraph->ppAdjEdge[i][j]));
}

ArrayGraph *kruskal(ArrayGraph *pGraph)
{
	if (!error_nullparameter(pGraph, "pGraph"))
		return (NULL);
	int maxCount = pGraph->maxVertexCount;
	ArrayGraph *ret_graph = createArrayGraph(maxCount);
	if (!error_mallocfailure(ret_graph, "ret_graph"))
		return (NULL);
	ArrayHeap *heap = createArrayHeap(pGraph->currentEdgeCount);
	if (!error_mallocfailure(heap, "heap"))
		return (NULL);
	int *parent = (int *)malloc(sizeof(int) * (maxCount));
	if (!error_mallocfailure(parent, "parent"))
		return (NULL);

	for (int i = 0; i < maxCount; i++)
		addVertexAG(ret_graph, i); // 새 그래프에 기존 그래프만큼 노드를 만들어줌. 
	move_Graph2Heap(pGraph, heap);
	for (int i = 0; i < maxCount; i++)
		parent[i] = i; // parent 배열을 채워줌 : 초기값 - 자신이 자기자신의 parent
	while (!isArrayHeapEmpty(heap))
	{
		ArrayHeapNode *pop = deleteHeapAH(heap);
		merge(pop->x, pop->y, parent);
		if (chk) // cycle이 생기지 않는다면
			addEdgewithWeightAG(ret_graph, pop->x, pop->y, pop->weight);
		free(pop);
		pop = 0;
	}

	free(parent);
	parent = 0;
	deleteArrayHeap(heap);
	heap = 0;
	return (ret_graph);
}
/* 
* 원래의 그래프를 min_heap에 담아 정렬한다 -> 힙에서 노드-간선 정보를 하나씩 빼면서, 그게 사이클을 형성하지 않는다면 새 그래프에 하나씩 넣어준다.  
* cycle 없이 탐색할 때 간선의 개수를 n - 1로 맞출 것이기 때문에, 노드^2만큼 인접행렬을 할당하는 arraygraph는 비효율적 
* 따라서 linkedgraph가 더 효율적이지만, 우리는 네 경우를 모두 실행하기 때문에 편의를 위해 arraygraph를 택했다.
*/