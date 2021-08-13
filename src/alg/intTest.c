#include "alg.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

	int i, j;
	int arr[20] = {46, 22, 73, 36, 29, 52, 50, 84, 87, 76, 6, 68, 100, 56, 52, 78, 90, 6, 78, 26};

	/* generate graph */
	struct algGraph *graph = algInit(5), *BFS, *DFS, *MST, *SPT;

	algAddEdge(graph, 0, 1, 1);
	algAddEdge(graph, 0, 2, 1);
	algAddEdge(graph, 1, 2, 1);
	algAddEdge(graph, 1, 3, 1);
	algAddEdge(graph, 1, 4, 1);
	algAddEdge(graph, 2, 4, 1);

	printf("-----Graph 1: Simple-----\n");
	algPrint(graph);

	printf("\n");
	BFS = algBFS(graph, 0);
	algPrint(BFS);

	printf("\n");
	DFS = algDFS(graph, 0);
	algPrint(DFS);

	printf("\n");
	MST = algMST(graph);
	algPrint(MST);

	printf("\n");
	SPT = algSPT(graph, 0);
	algPrint(SPT);

	graph = algClear(graph);
	BFS = algClear(BFS);
	DFS = algClear(DFS);
	MST = algClear(MST);
	SPT = algClear(SPT);

	graph = algInit(5);

	algAddEdge(graph, 0, 1, 1);
	algAddEdge(graph, 0, 2, 1);
	algAddEdge(graph, 1, 2, 1);
	algAddEdge(graph, 1, 4, 1);
	algAddEdge(graph, 1, 3, 1);
	algAddEdge(graph, 2, 4, 1);
	algAddEdge(graph, 3, 4, 1);

	printf("\n-----Graph 2: Simple-----\n");
	algPrint(graph);

	printf("\n");
	BFS = algBFS(graph, 0);
	algPrint(BFS);

	printf("\n");
	DFS = algDFS(graph, 0);
	algPrint(DFS);

	printf("\n");
	MST = algMST(graph);
	algPrint(MST);

	printf("\n");
	SPT = algSPT(graph, 0);
	algPrint(SPT);

	graph = algClear(graph);
	BFS = algClear(BFS);
	DFS = algClear(DFS);
	MST = algClear(MST);
	SPT = algClear(SPT);

	graph = algInit(9);

	algAddEdge(graph, 0, 1, 2);
	algAddEdge(graph, 0, 5, 3);
	algAddEdge(graph, 1, 2, 7);
	algAddEdge(graph, 1, 3, 5);
	algAddEdge(graph, 2, 4, 9);
	algAddEdge(graph, 2, 8, 6);
	algAddEdge(graph, 3, 4, 5);
	algAddEdge(graph, 3, 5, 4);
	algAddEdge(graph, 3, 6, 3);
	algAddEdge(graph, 4, 7, 6);
	algAddEdge(graph, 4, 8, 8);
	algAddEdge(graph, 5, 6, 1);
	algAddEdge(graph, 6, 7, 4);
	algAddEdge(graph, 7, 8, 9);

	printf("\n-----Graph 3: Complex -----\n");
	algPrint(graph);

	printf("\n");
	BFS = algBFS(graph, 0);
	algPrint(BFS);

	printf("\n");
	DFS = algDFS(graph, 0);
	algPrint(DFS);

	printf("\n");
	MST = algMST(graph);
	algPrint(MST);

	printf("\n");
	SPT = algSPT(graph, 0);
	algPrint(SPT);

	graph = algClear(graph);
	BFS = algClear(BFS);
	DFS = algClear(DFS);
	MST = algClear(MST);
	SPT = algClear(SPT);

	printf("\n");
	return 0;
}


