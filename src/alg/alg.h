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

struct algQNode {
	int vertex;
	int parent;
};

struct algQueue {
	struct algQNode *queue;
	int front;
	int back;
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

/* prints an adjacency list */
void algPrint (struct algGraph *graph);

/* initialize queue */
struct algQueue *algQueueInit (int size);

/* clear queue */
struct algQueue *algQueueClear (struct algQueue *queue);

/* enquque helper function */
void algEnqueue (struct algQueue *queue, int vertex, int parent);

/* dequque helper function */
struct algQNode *algDequeue (struct algQueue *queue);

#endif
