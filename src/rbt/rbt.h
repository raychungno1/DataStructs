#ifndef RBT_H
#define RBT_H

struct rbtNode {
	int data;
	int size;
	int isRed;
	struct rbtNode *parent;
	struct rbtNode *left;
	struct rbtNode *right;
};

/* clears & frees the list */
void rbtClear (struct rbtNode **rootPtr);

/* counts number of nodes within a range of numbers (inclusive) */
int rbtCountRange (struct rbtNode *root, int min, int max);

/* counts number of nodes greater than or equal to 'min' */
int rbtCountGE (struct rbtNode *root, int min);

/* counts number of nodes less than or equal to 'max' */
int rbtCountLE (struct rbtNode *root, int max);

/* deletes a node from the tree */
void rbtDelete (struct rbtNode **rootPtr, int key);

	/* swaps two nodes from the tree */
	void rbtSwap (struct rbtNode **headPtr, struct rbtNode *x, struct rbtNode *y);

	/* updates size after deleting mode */
	void rbtFixSize (struct rbtNode *node);

	/* fixes coloring of tree */
	void rbtDeleteFix (struct rbtNode **rootPtr, struct rbtNode *node);

	/* preforms left rotation at node 'node' */
	void rbtLeftRotate (struct rbtNode **rootPtr, struct rbtNode *node);

	/* preforms right rotation at node 'node' */
	void rbtRightRotate(struct rbtNode **rootPtr, struct rbtNode *node);

/* returns the height of tree */
int rbtHeight (struct rbtNode *root);

/* inserts a node into the tree */
void rbtInsert (struct rbtNode **rootPtr, int data);

	/* locates the parent node of the node to be inserted */
	struct rbtNode *rbtLocateParent(struct rbtNode *root, int data);

	/* fixes coloring of tree */
	void rbtInsertFix (struct rbtNode **rootPtr, struct rbtNode *node);

	/* fixes coloring if parent & uncle of node are red */
	void rbtInsertFixA (struct rbtNode **node);

	/* fixes coloring if parent is red & uncle is black & node & parent are both left/right children */
	void rbtInsertFixB (struct rbtNode **rootPtr, struct rbtNode **node);

	/* fixes coloring if parent is red & uncle is black & one of the node/parent is left and the other is a right child */
	void rbtInsertFixC (struct rbtNode **rootPtr, struct rbtNode *node);

/* returns min of a tree */
struct rbtNode *rbtMin (struct rbtNode *root);

/* returns min node greater than or equal to 'key' */
struct rbtNode *rbtMinGE (struct rbtNode *root, int key);

/* returns max of a tree */
struct rbtNode *rbtMax (struct rbtNode *root);

/* returns max node less than or equal to 'key' */
struct rbtNode *rbtMaxLE (struct rbtNode *root, int key);

/* returns the successor of a node */
struct rbtNode *rbtPredecessor (struct rbtNode *node);

/* prettyprints tree with an in order traversal */
void rbtPrettyPrint (struct rbtNode *root, int depth);

	void printSpaces(struct rbtNode *node, int depth);

/* prints out tree with an in order traversal */
void rbtPrint (struct rbtNode *root);

/* returns the size of the tree */
int rbtSize (struct rbtNode *root);

/* searches & returns a node w/ data, NULL if it doesn't exist */
struct rbtNode *rbtSearch (struct rbtNode *root, int key);

/* returns the successor of a node */
struct rbtNode *rbtSuccessor (struct rbtNode *node);

#endif
