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
	int *visited; /* "visited" array & temporary storage variables */
	struct algNode *temp; /* node to traverse through linked lists */
	struct algQNode *value; /* node to store vertex & its parent */
	struct algGraph *BFS; /* output BFS tree */

	if (queue) { /* if memory allocation succeeds, allocate second array */
		visited = calloc(graph->V, sizeof(int));
		if (!visited) {
			printf("Error allocating memory for 'visited' array.\n");
			queue = algQueueClear(queue);
			return NULL; /* error if allocation fails */
		}
	} else {
		printf("Error allocating memory for queue.\n");
		return NULL; /* error if allocation fails */
	} /* after this line, both arrays have been successfully allocated */

	BFS = algInit(graph->V); /* initialize graph */
	if (!BFS) { /* free & return NULL if allocation fails */
		printf("Error allocating memory for BFS tree.");
		queue = algQueueClear(queue);
		free (visited), visited = NULL;
		return NULL;
	}

	printf("BFS traversal: ");
	visited[start] = 1; /* mark 'start' as visited & enqueue start vertex */
	algEnqueue(queue, start, -1);

	while (queue->back != -1) { /* loop until queue is empty */

		value = algDequeue(queue); /* dequeue element & add to BFS tree */
		if (value->parent != -1) algAddEdge(BFS, value->parent, value->vertex, 0);
		printf("%i ", value->vertex);

		temp = *(graph->adjList + value->vertex); /* select linked list for node */
		while (temp) { /* for each node adjacemt to 'vertex' */
			if (!visited[temp->dest]) { /* if node is not visited, enqueue it & mark it as visited */
				visited[temp->dest] = 1;
				algEnqueue(queue, temp->dest, value->vertex);
			}
			temp = temp->next;
		}
		free(value); /* reset value for next iteration */
	}

	printf("\n");
	/* free allocated memory */
	algQueueClear(queue);
	free(visited), visited = NULL;
	return BFS; /* output */
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

/* conducts a depth fist search on a graph starting from vertex 'start' */
struct algGraph *algDFS (struct algGraph *graph, int start) {

	struct algGraph *DFS; /* output graph */
	int *visited = calloc(graph->V, sizeof(int)); /* array to store visited verticies */
	if (!visited) {
		printf("Error allocating memory for 'visited' array.\n");
		return NULL; /* if memory allocation fails */
	}

	DFS = algInit(graph->V);
	if (!DFS) {
		printf("Error allocating memory for DFS tree.\n");
		free(visited), visited = NULL;
		return NULL;
	}

	printf("DFS traversal: ");
	algDFSRec(graph, start, visited, DFS); /* main DFS function */
	printf("\n");
	free(visited), visited = NULL; /* free 'visited' array */
	return DFS; /* output */
}

/* recursive part of DFS */
void algDFSRec (struct algGraph *graph, int start, int *visited, struct algGraph *DFS) {

	int i;
	struct algNode *temp = *(graph->adjList + start); /* node to traverse through linked lists */

	/* set node to visited */
	visited[start] = 1;
	printf("%i ", start);

	/* recursive call for every adjacent vertex */
	while (temp) { /*if an adjacent node hasn't been visited */
		if (!visited[temp->dest]) {
			algAddEdge(DFS, start, temp->dest, 0); /* add edge to BFS graph */
			algDFSRec(graph, temp->dest, visited, DFS);
		}
		temp = temp->next;
	}
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
		q->queue = malloc(size * sizeof(struct algQNode));
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

/* clear queue */
struct algQueue *algQueueClear (struct algQueue *queue) {

	/* clear array, queue structure, & return null */
	free(queue->queue), queue->queue = NULL;
	free(queue), queue = NULL;
	return NULL;
}

/* enquque helper function */
void algEnqueue (struct algQueue *queue, int value, int parent) {

	/* if size = 0 */
	if (queue->front == -1) queue->front = 0;

	queue->back++; /* increment back of queue & add value */
	(queue->queue + queue->back)->vertex = value;
	(queue->queue + queue->back)->parent = parent;
}

/* dequque helper function */
struct algQNode *algDequeue (struct algQueue *queue) {

	struct algQNode *node = malloc(sizeof(struct algQNode)); /* temporary storage for dequeued value */

	/* if node allocation fails or the queue is empty */
	if (!node || queue->back == -1) return NULL;
	
	node->vertex = (queue->queue + queue->front)->vertex;
	node->parent = (queue->queue + queue->front)->parent;
	queue->front++; /* store queue[front] and increment front */

	/* reset front & back variables if queue is empty */
	if (queue->front > queue->back) queue->front = queue->back = -1;
	
	return node; /* output */
}

