#ifndef BST_H
#define BST_H

struct bstNode {
	int data;
	int size;
	struct bstNode *parent;
	struct bstNode *left;
	struct bstNode *right;
};

/* clears & frees the list */
void bstClear (struct bstNode **rootPtr);

/* counts number of nodes within a range of numbers (inclusive) */
int bstCountRange (struct bstNode *root, int min, int max);

/* counts number of nodes greater than or equal to 'min' */
int bstCountGE (struct bstNode *root, int min);

/* counts number of nodes less than or equal to 'max' */
int bstCountLE (struct bstNode *root, int max);

/* deletes a node from the tree */
void bstDelete (struct bstNode **rootPtr, int key);

	/* swaps two nodes from the tree */
	void bstSwap (struct bstNode **headPtr, struct bstNode *x, struct bstNode *y);

	/* updates size after deleting mode */
	void bstFixSize (struct bstNode *node);

/* returns the height of tree */
int bstHeight (struct bstNode *root);

/* inserts a node into the tree */
void bstInsert (struct bstNode **rootPtr, int data);

	/* locates the parent node of the node to be inserted */
	struct bstNode *bstLocateParent(struct bstNode *root, int data);

/* returns min of a tree */
struct bstNode *bstMin (struct bstNode *root);

/* returns min node greater than or equal to 'key' */
struct bstNode *bstMinGE (struct bstNode *root, int key);

/* returns max of a tree */
struct bstNode *bstMax (struct bstNode *root);

/* returns max node less than or equal to 'key' */
struct bstNode *bstMaxLE (struct bstNode *root, int key);

/* returns the successor of a node */
struct bstNode *bstPredecessor (struct bstNode *node);

/* prettyprints tree with an in order traversal */
void bstPrettyPrint (struct bstNode *root, int depth);

	void printSpaces(struct bstNode *node, int depth);

/* prints out tree with an in order traversal */
void bstPrint (struct bstNode *root);

/* returns the size of the tree */
int bstSize (struct bstNode *root);

/* searches & returns a node w/ data, NULL if it doesn't exist */
struct bstNode *bstSearch (struct bstNode *root, int key);

/* returns the successor of a node */
struct bstNode *bstSuccessor (struct bstNode *node);

#endif
