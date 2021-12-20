#include "arraygraph.h"

int     test_ArrayGraph(int op)
{
    ArrayGraph  *pGraph;
	int input = 0;
    int maxcount = 0;
	printf("maxcount: ");
	scanf(" %d", &maxcount);
	if (op == 1 || op == 3)
		pGraph = createArrayGraph(maxcount);
	else
		pGraph = createArrayDirectedGraph(maxcount);
    while (1)
    {
        int err_flag = 1;
        printf("\nEdge Status : ======================================================================\n");
        displayArrayGraph(pGraph);
        printf("====================================================================================\n");
        printf("\n    1 (add Vertex)   2 (add Edge)   3 (remove Vertex)\n    4 (remove Edge)   5 (Traversal)   6 (exit)\n\nType your command number : ");
        scanf(" %d", &input);
        if (input == 6)
        {
            printf("\n__________________________Terminate the Test Program___________________________\n");
            break;
        }
        switch (input)
        {
            case 1 :  //add vertex
            {
                int d;
                printf("Type any number to add Vertex: \n");
                scanf(" %d", &d);
				err_flag = addVertexAG(pGraph, d);
                break;
            }
            case 2 :  //add edge
            {
                int from; int to; int weight;
                printf("Type two number to add edge between them: \n");
				printf("from, to: ");
                scanf(" %d %d", &from, &to);
				if (op == 1 || op == 2)
					err_flag = addEdgeAG(pGraph, from, to);
				else
				{
					printf("This is Directed graph, so type weight: ");
					scanf(" %d", &weight);
					err_flag = addEdgewithWeightAG(pGraph, from, to, weight);
				}
                break;
            }
            case 3 :  // remove vertex
            {
                int c;
				printf("Vertex ID to remove: ");
				scanf(" %d", &c);
				err_flag = removeVertexAG(pGraph, c);
                break;
            }
            case 4 :  //remove edge
            {
				int from; int to;
                printf("Two number to remove edge between them: \n");
				printf("from, to: ");
                scanf(" %d %d", &from, &to);
				err_flag = removeEdgeAG(pGraph, from, to);
                break;
            }
			case 5 :  //traversal
            {
				// int option;
                // printf("Choose Traversal option    1 (DFS traversal)   2 (BFS traversal) : \n");
                // scanf(" %d", &option);
                // // if (option == 1)
				// // 	err_flag = dfs_traversal(pGraph);
				// // else
				// // 	err_flag = bfs_traversal(pGraph);
				break;
            }
			default :  //exit
            {
				printf("[error] undefined command number.\n");
                break ;
            }
        }
        if (err_flag == 0)
        {
            printf("[error] Terminate the Test Program\n");
            break;
        }
    }
    printf("\n");
    deleteArrayGraph(pGraph);
    return (0);
}

int     main()
{
    int option = 0;
    printf("Choose your Graph\n    1 Undirected Unweighted    2 Directed Unweighted\n");
	printf("    3 Undirected Weighted      4 Directed Weighted\n");
    scanf(" %d", &option);
    if (!(option >= 1 && option <= 4))
    {
        printf("[error] undefined command number.\n");
        printf("[error] Terminate the Test Program\n");
        return (0);
    }
    test_ArrayGraph(option);
    system("leaks a.out");
    return (0);
}