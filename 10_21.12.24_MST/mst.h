#ifndef MST_H
#define MST_H

#include "arraygraph/arraygraph.h"
#include "arrayheap/arrayheap.h"
#include "stdbool.h"

# define INF 2147483647

/*utils****************/
int ft_min(int a, long long b);
int error_nullparameter(void *parameter, char *str);
int error_mallocfailure(void *parameter, char *str);
ArrayHeapNode make_element(int x, int y, int weight);

/*Dijkstra*************/
ArrayGraph *fill_newArrayGraph_Dijkstra(int maxCount);
void find_Dijkstra(int i, ArrayGraph *ret_graph, ArrayGraph *pGraph);
ArrayGraph  *Dijkstra(ArrayGraph *pGraph);

/*floyd***************/
ArrayGraph *fill_newArrayGraph_floyd(ArrayGraph *pGraph, int maxCount);
ArrayGraph *floyd(ArrayGraph *pGraph);

/*kruskal*************/
int find(int dot, int *parent);
void merge(int start, int end, int *parent);
void move_Graph2Heap(ArrayGraph *pGraph, ArrayHeap *heap);
ArrayGraph *kruskal(ArrayGraph *pGraph);

/*prim****************/
void		put_firstHeapNode(ArrayGraph *pGraph, int *visited, ArrayHeap *heap);
ArrayGraph *prim(ArrayGraph *pGraph);

#endif

#ifndef _COMMON_HEAP_DEF_
#define _COMMON_HEAP_DEF_

#define TRUE		1
#define FALSE		0

#endif