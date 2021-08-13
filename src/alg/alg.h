#ifndef ALG_H
#define ALG_H

struct algNode {
	int dest;
	int weight;
	struct algNode *next;
};

struct algGraph {
	int V;
	int E;
	struct algNode **adjList;
};

struct algStorage {
	int vertex;
	int parent;
	int key;
};

struct algQueue {
	struct algStorage *queue;
	int front;
	int back;
};

struct algHeap {
	struct algStorage *arr;
	int *pos;
	int size;
	int MAX_SIZE;
};

/* adds an edge to a graph */
void algAddEdge (struct algGraph *graph, int src, int dest, int weight);

/* conducts a breadth fist search on a graph starting from vertex 'start' */
struct algGraph *algBFS (struct algGraph *graph, int start);

/* clears & frees the graph */
struct algGraph *algClear (struct algGraph *graph);

/* conducts a depth fist search on a graph starting from vertex 'start' */
struct algGraph *algDFS (struct algGraph *graph, int start);

	/* recursive part of DFS */
	void algDFSRec (struct algGraph *graph, int start, int *visited, struct algGraph *DFS);

/* initializes a graph with 'V' verticies */
struct algGraph *algInit (int V);

/* creates a minimum spanning tree on a gaph using Prim's algorithm. */
struct algGraph *algMST (struct algGraph *graph);

/* prints an adjacency list */
void algPrint (struct algGraph *graph);

/* finds the shortest path from vertex 'start' using Dijkstra's algorithm */
struct algGraph *algSPT (struct algGraph *graph, int start);

/* QUEUE FUNCTIONS */

	/* initialize queue */
	struct algQueue *algQueueInit (int size);
	
	/* clear queue */
	struct algQueue *algQueueClear (struct algQueue *queue);
	
	/* enquque helper function */
	void algEnqueue (struct algQueue *queue, int vertex, int parent);
	
	/* dequque helper function */
	struct algStorage *algDequeue (struct algQueue *queue);

/* MINHEAP FUNCTIONS */

	/* helper functions */
	int algHeapParent(int i);
	
	int algHeapLeft(int i);
	
	int algHeapRight(int i);
	
	void algHeapSwap(struct algHeap *heap, int x, int y);
	
	void algHeapMinHeapify(struct algHeap *heap, int size, int index);

	/* initialize minHeap */
	struct algHeap *algHeapInit (int size);

	/* clear minHeap */
	struct algHeap *algHeapClear (struct algHeap *heap);

	/* insert function into minHeap */
	void algHeapInsert (struct algHeap *heap, int weight, int vertex, int parent);

	/* extract fuction from minHeap */
	struct algStorage *algHeapExtractMin (struct algHeap *heap);

	/* decreaseKey function */
	void algHeapDecreaseKey (struct algHeap *heap, int vertex, int newParent, int newKey);

	void algHeapPrint (struct algHeap *heap);

#endif
