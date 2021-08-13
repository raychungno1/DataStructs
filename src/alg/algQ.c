#include "alg.h"
#include <stdio.h>
#include <stdlib.h>

/* initialize queue */
struct algQueue *algQueueInit (int size) {
	
	/* initialize structue */
	struct algQueue *q = malloc(sizeof(struct algQueue));
	
	if (q) { /* if allocation succeeds, allocate array */
		q->queue = malloc(size * sizeof(struct algStorage));
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
struct algStorage *algDequeue (struct algQueue *queue) {

	struct algStorage *node = malloc(sizeof(struct algStorage)); /* temporary storage for dequeued value */

	/* if node allocation fails or the queue is empty */
	if (!node || queue->back == -1) return NULL;
	
	node->vertex = (queue->queue + queue->front)->vertex;
	node->parent = (queue->queue + queue->front)->parent;
	queue->front++; /* store queue[front] and increment front */

	/* reset front & back variables if queue is empty */
	if (queue->front > queue->back) queue->front = queue->back = -1;
	
	return node; /* output */
}

