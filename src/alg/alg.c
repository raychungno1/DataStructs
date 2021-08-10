#include "alg.h"
#include "stdio.h"
#include "stdlib.h"

/* adds an edge to a graph */
void algAddEdge (struct algGraph *graph, int src, int dest, int weight) {

	/* declare two nodes */
	struct algNode *node = malloc(sizeof(struct algNode)), *node1;

	if (!node) { /* if memory allocaion fails */
		printf("Error allocating memory for node.\n");
		return;
	} else { /* otherwise, malloc second mode */
		node1 = malloc(sizeof(struct algNode));
		if (!node1) {
			printf("Error allocating memory for node.\n");
			free(node), node = NULL;
			return;
		}
	} /* after this line, both nodes have been successfully allocated */

	/* create connection from src to dest & rearrange pointers */
	node->dest = dest;
	node->weight = weight;
	node->next = *(graph->adjList + src);
	*(graph->adjList + src) = node;

	/* select adjList[dest] & create connection from dest to src & rearrange pointers */
	node1->dest = src;
	node1->weight = weight;
	node1->next = *(graph->adjList + dest);
	*(graph->adjList + dest) = node1;

	graph->E++; /* increment graph edge count */
}

/* conducts a breadth fist search on a graph starting from vertex 'start' */
struct algGraph *algBFS (struct algGraph *graph, int start) {

	/* initialize queue, start & end indexes */
	struct algQueue *queue = algQueueInit(graph->V);
	int *visited; /* "visited" array */

	if (queue) { /* if memory allocation succeeds, allocate second array */
		visited = calloc(graph->V, sizeof(int));
		if (!visited) {
			printf("Error allocating memory for 'visited' array.\n");
			return NULL; /* error if allocation fails */
		}
	} else {
		printf("Error allocating memory for queue.\n");
		return NULL; /* error if allocation fails */
	} /* after this line, both arrays have been successfully allocated */

	visited[start] = 1; /* mark 'start' as visited & enqueue start vertex */
	algEnqueue(queue, start);

	while (queue->back != -1) {

	}
	return NULL;
}

/* clears & frees the graph */
struct algGraph *algClear (struct algGraph *graph) {

	int i; /* iterate & clear all linked lists */
	struct algNode *temp;
	for (i = 0; i < graph->V; i++) {

		/* while the current node is not null */
		while (*(graph->adjList + i)) {
			temp = *(graph->adjList + i); /* store current node */
			*(graph->adjList + i) = (*(graph->adjList + i))->next; /* update pointer */

			free(temp), temp = NULL; /* clear node */
		}
	}

	/* clear adjacency list */
	free(graph->adjList); graph->adjList = NULL;

	/* clear & return null graph */
	free(graph), graph = NULL;
	return NULL;
}

/* initializes a graph with 'V' verticies */
struct algGraph *algInit (int V) {

	struct algGraph *graph = malloc(sizeof(struct algGraph));

	if (graph) { /* if memory allocation was successful */
		graph->V = V; /* assign vertex number */
		graph->E = 0; /* assign edge number */
		graph->adjList = calloc(V, sizeof(struct algNode*)); /* malloc array */
		
		if (!graph->adjList) { /* if memory allocation failed */
			printf("Error allocating array for adjacency list.\n");
			free(graph), graph = NULL;
		}
	} else {printf("Error allocating graph.\n");} /* if memory allocation failed */

	return graph; /* output */

}

/* prints an adjacency list */
void algPrint (struct algGraph *graph) {

	int i; /* index & head ptr */
	struct algNode *head;

	/* iterate & print each linked list */
	for (i = 0; i < graph->V; i++) {
		printf("v%i: (", i); /* print src vertex */
		head = *(graph->adjList + i);
		
		/* print nodes connected to the vertex */
		while (head) {
			printf("v%i", head->dest);
			if (head->next) printf(",");
			head = head->next;
		}
		printf(")\n");
	}
}

/* initialize queue */
struct algQueue *algQueueInit (int size) {
	
	/* initialize structue */
	struct algQueue *q = malloc(sizeof(struct algQueue));
	
	if (q) { /* if allocation succeeds, allocate array */
		q->queue = malloc(size * sizeof(int));
		if (q->queue) { /* initialize front & back of queue */
			q->front = -1;
			q->back = -1;
		} else {
			printf("Error allocating memory for queue.\n");
			free(q), q = NULL;
		} /* if memory allocation fails, returns NULL */
	} else printf("Error allocating memory for queue.\n");

	return q; /* output */
}

/* enquque helper function */
void algEnqueue (struct algQueue *queue, int value) {

	/* if size = 0 */
	if (queue->front == -1) queue->front = 0;

	queue->back++; /* increment back of queue & add value */
	*(queue->queue + queue->back) = value;
}

/* dequque helper function */
int algDequeue (struct algQueue *queue) {

	int dequeued; /* temporary storage for dequeued value */

	/* if queue is empty */
	if (queue->back == -1) return 0;
	
	dequeued = *(queue->queue + queue->front);
	queue->front++; /* store queue[front] and increment front */

	/* reset front & back variables if queue is empty */
	if (queue->front > queue->back) queue->front = queue->back = -1;
	
	return dequeued; /* output */
}

