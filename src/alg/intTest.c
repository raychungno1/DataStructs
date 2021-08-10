#include "alg.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

	int i, j;
	int arr[20] = {46, 22, 73, 36, 29, 52, 50, 84, 87, 76, 6, 68, 100, 56, 52, 78, 90, 6, 78, 26};

	/* generate graph */
	struct algGraph *graph = algInit(5);

	algAddEdge(graph, 0, 1, 1);
	algAddEdge(graph, 0, 2, 1);
	algAddEdge(graph, 1, 2, 1);
	algAddEdge(graph, 1, 3, 1);
	algAddEdge(graph, 1, 4, 1);
	algAddEdge(graph, 2, 4, 1);

	algPrint(graph);

	printf("\n");
	algBFS(graph, 0);

	printf("\n");
	algClear(graph);

	return 0;
}


