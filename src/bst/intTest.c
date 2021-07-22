#include "bst.h"
#include "treeTest.h"
#include <stdio.h>

int main() {

	struct bstNode *root = NULL;

	leftSkew(&root);
	pInfo(root);

	rightSkew(&root);
	pInfo(root);

	rootOnly(&root);
	pInfo(root);

	random(&root);
	pInfo(root);
/*
	bstInsert(&root, 20);
	bstInsert(&root, 5);
	bstInsert(&root, 3);
	bstInsert(&root, 2);
	bstInsert(&root, 4);
	bstInsert(&root, 5);
	bstInsert(&root, 15);
	bstInsert(&root, 10);
	bstInsert(&root, 18);
	bstInsert(&root, 30);
	bstInsert(&root, 35);
	bstInsert(&root, 25);
	bstInsert(&root, 24);
	bstInsert(&root, 26);

	pInfo(root);

	bstPrint(root);
	printf("\n");
	bstPrettyPrint(root, 0);
	printf("Size: %i\n", bstSize(root));

	bstDelete(&root, 5);
	bstPrint(root);
	printf("Size: %i\n", bstSize(root));

	bstDelete(&root, 2);
	bstPrint(root);
	printf("Size: %i\n", bstSize(root));

	bstInsert(&root, 7);
	bstPrint(root);
	printf("Size: %i\n", bstSize(root));

	bstInsert(&root, 6);
	bstPrint(root);
	printf("Size: %i\n", bstSize(root));

	bstDelete(&root, 7);
	bstPrint(root);
	printf("Size: %i\n", bstSize(root));

	printf("Height: %i\n", bstHeight(root));
*/
	bstClear(&root);

	printf("\n");
	return 0;
}
