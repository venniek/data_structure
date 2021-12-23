#include "../mst.h"

void	test_MST(ArrayGraph *pGraph)
{
	int input = 0, err_flag = 0;

	while (1)
	{
		ArrayGraph *mst_graph;
		err_flag = 1;
		printf("BEFORE==========================================\n");
		displayArrayGraph(pGraph);
		printf("================================================\n");
		printf("\n  1 (Dijkstra)   2 (floyd)   3 (kruskal)\n  4(prim)   5 (exit)\n\nType your command number : ");
		scanf(" %d", &input);
		printf("\nMST Status : ===================================\n");
		if (input == 5)
		{
			printf("\n______________Terminate the Test Program_________________\n");
			break;
		}
		switch (input)
		{
			case 1 :
				printf("Dijkstra---\n");
				if (!(mst_graph = Dijkstra(pGraph)))
					err_flag = 0;
				break;
			case 2 :
				printf("floyd---\n");
				if (!(mst_graph = floyd(pGraph)))
					err_flag = 0;
				break;
			case 3 :
				printf("kruskal---\n");
				if (!(mst_graph = kruskal(pGraph)))
					err_flag = 0;
				break;
			case 4 :
				printf("prim---\n");
				if (!(mst_graph = prim(pGraph)))
					err_flag = 0;
				break;
			default :  //exit
				printf("[error] undefined command number.\n");
				break;
		}
		if (err_flag == 0)
		{
			printf("[error] Terminate the Test Program\n");
			break;
		}
		printf("AFTER===============================\n");
		displayArrayGraph(mst_graph);
		deleteArrayGraph(mst_graph);
		printf("\n====================================\n");
		printf("===========ANOTHER COMMAND==========\n");
		printf("====================================\n\n");
	}
	deleteArrayGraph(pGraph);
}

int  main()
{
	printf("This is the shortest path algorithm using undirected graph\n");

	ArrayGraph *pGraph = createArrayGraph(6);
	addVertexAG(pGraph, 0);
	addVertexAG(pGraph, 1);
	addVertexAG(pGraph, 2);
	addVertexAG(pGraph, 3);
	addVertexAG(pGraph, 4);
	addVertexAG(pGraph, 5);

	addEdgewithWeightAG(pGraph, 0, 1, 4);
	addEdgewithWeightAG(pGraph, 0, 2, 3);
	addEdgewithWeightAG(pGraph, 1, 2, 2);
	addEdgewithWeightAG(pGraph, 2, 3, 1);
	addEdgewithWeightAG(pGraph, 4, 3, 1);
	addEdgewithWeightAG(pGraph, 4, 5, 6);
	addEdgewithWeightAG(pGraph, 3, 5, 5);

	test_MST(pGraph);
	pGraph = 0;
	system("leaks mst");

	return (0);
}