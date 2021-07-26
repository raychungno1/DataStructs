#include "avl.h"
#include "treeTest.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void pInfo(struct avlNode *root) {
	struct avlNode *min, *max, *temp;
	printf("----------\n");
	/* avlPrettyPrint */
	avlPrettyPrint(root, 0);
	printf("In order traversal: ");
	/* avlPrint */
	avlPrint(root);
	/* avlSize */
	printf("\nSize: %i\n", avlSize(root));
	/* avlHeight */
	printf("Height: %i\n", avlHeight(root));
	/* avlMin */
	min = avlMin(root);
	printf("Min: %i\n", min->data);
	/* avlSuccessor */
	printf("  Sucessor(s): ");
	while (min = avlSuccessor(min)) printf("%i ", min->data);
	printf("\n");
	/* avlMax */
	max = avlMax(root);
	printf("Max: %i\n", max->data);
	/* avlPredecessor */
	printf("  Predecessor(s): ");
	while (max = avlPredecessor(max)) printf("%i ", max->data);
	printf("\n");
	/* avlMinGE */
	printf("Min Node >= 25: ");
	(min = avlMinGE(root, 25)) ? printf("%i\n", min->data) : printf("NULL\n");
	/* avlMaxLE */
	printf("Max Node <= 75: ");
	(max = avlMaxLE(root, 75)) ? printf("%i\n", max->data) : printf("NULL\n");
	/* avlCountRange */
	printf("# Nodes between 25 & 75: %i\n", avlCountRange(root, 25, 75));
	/* avlCountGE */
	printf("# Nodes >= 25: %i\n", avlCountGE(root, 25));
	/* avlCountLE */
	printf("# Nodes <= 75: %i\n", avlCountLE(root, 75));
}

void leftSkew(struct avlNode **head) {
	int i;
	avlClear(head);
	for (i = 90; i >= 0; i-=10) avlInsert(head, i);
}

void rightSkew(struct avlNode **head) {
	int i;
	avlClear(head);
	for (i = 0; i < 100; i+=10) avlInsert(head, i);
}

void rootOnly(struct avlNode **head) {
	avlClear(head);
	avlInsert(head, 100);
}

void random(struct avlNode **head) {
	int i;
	srand(time(0));
	avlClear(head);
	for (i = 0; i < 25; i++) avlInsert(head, rand()%100);
}

void test1(struct avlNode **head) {
	int i, arr[20] = {46, 22, 73, 36, 29, 52, 50, 84, 87, 76, 6, 68, 100, 56, 52, 78, 90, 6, 78, 26};
	avlClear(head);
	for (i = 0; i < 20; i++) avlInsert(head, arr[i]);
}

