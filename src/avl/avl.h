#ifndef AVL_H
#define AVL_H

struct avlNode {
	int data;
	int size;
	int height;
	struct avlNode *parent;
	struct avlNode *left;
	struct avlNode *right;
};

/* clears & frees the list */
void avlClear (struct avlNode **rootPtr);

/* counts number of nodes within a range of numbers (inclusive) */
int avlCountRange (struct avlNode *root, int min, int max);

/* counts number of nodes greater than or equal to 'min' */
int avlCountGE (struct avlNode *root, int min);

/* counts number of nodes less than or equal to 'max' */
int avlCountLE (struct avlNode *root, int max);

/* deletes a node from the tree */
void avlDelete (struct avlNode **rootPtr, int key);

	/* swaps two nodes from the tree */
	void avlSwap (struct avlNode **headPtr, struct avlNode *x, struct avlNode *y);

	/* updates the height of a node */
	void avlUpdateHeight (struct avlNode *node);

	/* updates size after deleting mode */
	void avlFixStats (struct avlNode *node);

	/* rebalances the avl tree */
	void avlDeleteFix (struct avlNode **rootPtr, struct avlNode *node);

	/* right rotates node */
	void avlLeftRotate (struct avlNode **headPtr, struct avlNode *node);

	/* right rotates node */
	void avlRightRotate (struct avlNode **headPtr, struct avlNode *node);

/* returns the height of tree */
int avlHeight (struct avlNode *root);

/* inserts a node into the tree */
void avlInsert (struct avlNode **rootPtr, int data);

	/* locates the parent node of the node to be inserted */
	struct avlNode *avlLocateParent(struct avlNode *root, int data);

	/* rebalances the avl tree */
	void avlInsertFix (struct avlNode **rootPtr, struct avlNode *node);

/* returns min of a tree */
struct avlNode *avlMin (struct avlNode *root);

/* returns min node greater than or equal to 'key' */
struct avlNode *avlMinGE (struct avlNode *root, int key);

/* returns max of a tree */
struct avlNode *avlMax (struct avlNode *root);

/* returns max node less than or equal to 'key' */
struct avlNode *avlMaxLE (struct avlNode *root, int key);

/* returns the successor of a node */
struct avlNode *avlPredecessor (struct avlNode *node);

/* prettyprints tree with an in order traversal */
void avlPrettyPrint (struct avlNode *root, int depth);

	void printSpaces(struct avlNode *node, int depth);

/* prints out tree with an in order traversal */
void avlPrint (struct avlNode *root);

/* returns the size of the tree */
int avlSize (struct avlNode *root);

/* searches & returns a node w/ data, NULL if it doesn't exist */
struct avlNode *avlSearch (struct avlNode *root, int key);

/* returns the successor of a node */
struct avlNode *avlSuccessor (struct avlNode *node);

#endif
