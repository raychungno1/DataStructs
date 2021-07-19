#include "sll.h"
#include <stdio.h>
#include <stdlib.h>

void pInt(void *i) {
	printf("%i", *(int *)i);
}

int compInt(void *x, void *y) {
	if (*(int *)x > *(int *)y) return 1;
	if (*(int *)x < *(int *)y) return -1;
	return 0;
}

int main() {

	int i, j;
	int arr[20] = {6, 22, 73, 36, 29, 52, 50, 84, 87, 76, 46, 68, 100, 56, 52, 78, 90, 6, 78, 26};

	/* generate linked list */
	struct sllNode *head = NULL;

	/* test sllAddFirst */	
	printf("\n----- sllAddFirst Test: -----\nTest - Adding 10 Elements:\n\t");
	for (i = 0; i < 10; i++) sllAddFirst(&head, i);
	sllPrint(&head);
	sllClear(&head);

	/* test sllAddFirst */	
	printf("\n----- sllAddLast Test: -----\nTest - Adding 10 Elements:\n\t");
	for (i = 0; i < 10; i++) sllAddLast(&head, i);
	sllPrint(&head);

	/* test sllClear */
	printf("\n----- sllClear: -----\n");
	sllClear(&head);
	printf("Test - Clearing list of length 10... success\n");
	sllClear(&head);
	printf("Test - Clearing empty list... success\n");

	/* test sllContains */
	printf("\n----- sllContains Test:-----\nTest - Empty list {}:\n");
	sllContains(&head, i) ? printf("\tList contains %i.\n", i) : printf("\tList doesn't contain %i.\n",i);

	printf("\nTest - List of length 10 {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}:\n");
	for (i = 0; i < 10; i++) sllAddLast(&head, i);
	for (i = 0; i < 11; i++) {
		sllContains(&head, i) ? printf("\tList contains %i.\n", i) : printf("\tList doesn't contain %i.\n",i);
	}

	/* test sllPrint */
	printf("\n----- sllPrint Test: -----\n");
	printf("Test - List of length 10:\n\t");
	sllPrint(&head);
	sllClear(&head);

	printf("Test - Empty list:\n\t");
	sllPrint(&head);

	/* test sllRemove */
	printf("\n----- sllRemove Test: -----\n");
	printf("Test - List of length 5 {0, 1, 2, 3, 4}:\n");
	for (i = 0; i < 5; i++) sllAddLast(&head, i);
	printf("\tRemoving first element(0)...");
	sllRemove(&head, 0);
	sllPrint(&head);
	
	printf("\tRemoving middle element(2)...");
	sllRemove(&head, 2);
	sllPrint(&head);

	printf("\tRemoving last element(4)...");
	sllRemove(&head, 4);
	sllPrint(&head);

	printf("\tRemoving non-existent element(6)...");
	sllRemove(&head, 6);
	sllPrint(&head);

	sllClear(&head);
	printf("Test - Empty list {}:\n\tRemoving non-existent element...");
	sllRemove(&head, 0);
	sllPrint(&head);

	/* test sllRemoveFirst */
	printf("\n----- sllRemoveFirst Test: -----\n");
	printf("Test - List of length 5 {0, 1, 2, 3, 4}:\n");
	for (i = 0; i < 5; i++) sllAddLast(&head, i);
	for (i = 0; i < 5; i++) {
		sllRemoveFirst(&head);
		printf("\t");
		sllPrint(&head);
	}
	sllClear(&head);

	printf("Test - Empty list {}:\n");
	sllRemoveFirst(&head);
	printf("\t");
	sllPrint(&head);

	/* test sllRemoveLasst */
	printf("\n----- sllRemoveLast Test: -----\n");
	printf("Test - List of length 5 {0, 1, 2, 3, 4}:\n");
	for (i = 0; i < 5; i++) sllAddLast(&head, i);
	for (i = 0; i < 5; i++) {
		sllRemoveLast(&head);
		printf("\t");
		sllPrint(&head);
	}
	sllClear(&head);

	printf("Test - Empty list {}:\n");
	sllRemoveLast(&head);
	printf("\t");
	sllPrint(&head);

	/* test sllSize */
	printf("\n----- sllSize Test: -----\n");
	printf("Test - Empty list {}:\n");
	printf("\tSize: %i\n", sllSize(&head));

	printf("Test - List of length 10 {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}:\n");
	for (i = 0; i < 10; i++) sllAddLast(&head, i);
	printf("\tSize: %i\n", sllSize(&head));

	/* test sllFlip */
	printf("\n----- sllFlip Test: -----\n");
	printf("Test - List of length 10 {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}:\n");
	sllFlip(&head);
	printf("\t");
	sllPrint(&head);
	sllClear(&head);

	printf("Test - Empty list {}:\n");
	sllFlip(&head);
	printf("\t");
	sllPrint(&head);

	/* test sllSort */
	printf("\n----- sllSort Test: -----\n");
	printf("Test - Empty list {}:\n");
	sllSort(&head);
	printf("\t");
	sllPrint(&head);

	printf("Test - Already sorted list of length 10 {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}:\n");
	for (i = 0; i < 10; i++) sllAddLast(&head, i);
	sllSort(&head);
	printf("\t");
	sllPrint(&head);

	printf("Test - Reverse-sorted list of length 10 {9, 8, 7, 6, 5, 4, 3, 2, 1, 0}:\n");
	for (i = 0; i < 10; i++) sllAddFirst(&head, i);
	sllSort(&head);
	printf("\t");
	sllPrint(&head);

	printf("Test - Random list of length 20: ");
	sllClear(&head);
	for (i = 0; i < 20; i++) sllAddLast(&head, arr[i]);
	sllPrint(&head);
	sllSort(&head);
	printf("\t");
	sllPrint(&head);

	printf("\n");
	sllClear(&head);

	return 0;
}


