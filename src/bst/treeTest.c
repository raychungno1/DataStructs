#include "bst.h"
#include "treeTest.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void pInfo(struct bstNode *root) {
	printf("----------\n");
	bstPrettyPrint(root, 0);
	printf("In order traversal: ");
	bstPrint(root);
	printf("\nSize: %i\n", bstSize(root));
	printf("Height: %i\n", bstHeight(root));
}

void leftSkew(struct bstNode **head) {
	int i;
	bstClear(head);
	for (i = 9; i >= 0; i--) bstInsert(head, i);
}

void rightSkew(struct bstNode **head) {
	int i;
	bstClear(head);
	for (i = 0; i < 10; i++) bstInsert(head, i);
}

void rootOnly(struct bstNode **head) {
	bstClear(head);
	bstInsert(head, 25);
}

void random(struct bstNode **head) {
	int i;
	srand(time(0));
	bstClear(head);
	for (i = 0; i < 25; i++) bstInsert(head, rand()%100);
}

