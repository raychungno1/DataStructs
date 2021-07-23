#include "bst.h"
#include "treeTest.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void pInfo(struct bstNode *root) {
	struct bstNode *min, *max, *temp;
	printf("----------\n");
	/* bstPrettyPrint */
	bstPrettyPrint(root, 0);
	printf("In order traversal: ");
	/* bstPrint */
	bstPrint(root);
	/* bstSize */
	printf("\nSize: %i\n", bstSize(root));
	/* bstHeight */
	printf("Height: %i\n", bstHeight(root));
	/* bstMin */
	min = bstMin(root);
	printf("Min: %i\n", min->data);
	/* bstSuccessor */
	printf("  Sucessor(s): ");
	while (min = bstSuccessor(min)) printf("%i ", min->data);
	printf("\n");
	/* bstMax */
	max = bstMax(root);
	printf("Max: %i\n", max->data);
	/* bstPredecessor */
	printf("  Predecessor(s): ");
	while (max = bstPredecessor(max)) printf("%i ", max->data);
	printf("\n");
	/* bstMinGE */
	printf("Min Node >= 25: ");
	(min = bstMinGE(root, 25)) ? printf("%i\n", min->data) : printf("NULL\n");
	/* bstMaxLE */
	printf("Max Node <= 75: ");
	(max = bstMaxLE(root, 75)) ? printf("%i\n", max->data) : printf("NULL\n");
	/* bstCountRange */
	printf("# Nodes between 25 & 75: %i\n", bstCountRange(root, 25, 75));
	/* bstCountGE */
	printf("# Nodes >= 25: %i\n", bstCountGE(root, 25));
	/* bstCountLE */
	printf("# Nodes <= 75: %i\n", bstCountLE(root, 75));
}

void leftSkew(struct bstNode **head) {
	int i;
	bstClear(head);
	for (i = 90; i >= 0; i-=10) bstInsert(head, i);
}

void rightSkew(struct bstNode **head) {
	int i;
	bstClear(head);
	for (i = 0; i < 100; i+=10) bstInsert(head, i);
}

void rootOnly(struct bstNode **head) {
	bstClear(head);
	bstInsert(head, 100);
}

void random(struct bstNode **head) {
	int i;
	srand(time(0));
	bstClear(head);
	for (i = 0; i < 25; i++) bstInsert(head, rand()%100);
}

void test1(struct bstNode **head) {
	int i, arr[20] = {46, 22, 73, 36, 29, 52, 50, 84, 87, 76, 6, 68, 100, 56, 52, 78, 90, 6, 78, 26};
	bstClear(head);
	for (i = 0; i < 20; i++) bstInsert(head, arr[i]);
}

