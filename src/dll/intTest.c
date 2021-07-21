#include "dll.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

	int i, j;
	int arr[20] = {46, 22, 73, 36, 29, 52, 50, 84, 87, 76, 6, 68, 100, 56, 52, 78, 90, 6, 78, 26};

	/* generate linked list */
	struct dllNode *head = NULL;

	/* test dllAddFirst */	
	printf("\n----- dllAddFirst Test: -----\nTest - Adding 10 Elements:\n\t");
	for (i = 0; i < 10; i++) dllAddFirst(&head, i);
	dllPrint(&head);
	dllClear(&head);

	/* test dllAddFirst */	
	printf("\n----- dllAddLast Test: -----\nTest - Adding 10 Elements:\n\t");
	for (i = 0; i < 10; i++) dllAddLast(&head, i);
	dllPrint(&head);

	/* test dllClear */
	printf("\n----- dllClear: -----\n");
	dllClear(&head);
	printf("Test - Clearing list of length 10... success\n");
	dllClear(&head);
	printf("Test - Clearing empty list... success\n");

	/* test dllContains */
	printf("\n----- dllContains Test:-----\nTest - Empty list {}:\n");
	dllContains(&head, i) ? printf("\tList contains %i.\n", i) : printf("\tList doesn't contain %i.\n",i);

	printf("\nTest - List of length 10 {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}:\n");
	for (i = 0; i < 10; i++) dllAddLast(&head, i);
	for (i = 0; i < 11; i++) {
		dllContains(&head, i) ? printf("\tList contains %i.\n", i) : printf("\tList doesn't contain %i.\n",i);
	}

	/* test dllPrint */
	printf("\n----- dllPrint Test: -----\n");
	printf("Test - List of length 10:\n\t");
	dllPrint(&head);
	dllClear(&head);

	printf("Test - List of length 1:\n\t");
	dllAddFirst(&head, 25);
	dllPrint(&head);
	dllClear(&head);

	printf("Test - Empty list:\n\t");
	dllPrint(&head);

	/* test dllRemove */
	printf("\n----- dllRemove Test: -----\n");
	printf("Test - List of length 5 {0, 1, 2, 3, 4}:\n");
	for (i = 0; i < 5; i++) dllAddLast(&head, i);
	printf("\tRemoving first element(0)...\t\t");
	dllRemove(&head, 0);
	dllPrint(&head);
	
	printf("\tRemoving middle element(2)...\t\t");
	dllRemove(&head, 2);
	dllPrint(&head);

	printf("\tRemoving last element(4)...\t\t");
	dllRemove(&head, 4);
	dllPrint(&head);

	printf("\tRemoving element(1)...\t\t\t");
	dllRemove(&head, 1);
	dllPrint(&head);

	printf("\tRemoving non-existent element(6)...\t");
	dllRemove(&head, 6);
	dllPrint(&head);

	printf("\tRemoving element(3) to empty list...\t");
	dllRemove(&head, 3);
	dllPrint(&head);

	printf("Test - Empty list {}:\n\tRemoving non-existent element...\t");
	dllRemove(&head, 0);
	dllPrint(&head);

	/* test dllRemoveFirst */
	printf("\n----- dllRemoveFirst Test: -----\n");
	printf("Test - List of length 5 {0, 1, 2, 3, 4}:\n");
	for (i = 0; i < 5; i++) dllAddLast(&head, i);
	for (i = 0; i < 5; i++) {
		dllRemoveFirst(&head);
		printf("\t");
		dllPrint(&head);
	}
	dllClear(&head);

	printf("Test - Empty list {}:\n");
	dllRemoveFirst(&head);
	printf("\t");
	dllPrint(&head);

	/* test dllRemoveLasst */
	printf("\n----- dllRemoveLast Test: -----\n");
	printf("Test - List of length 5 {0, 1, 2, 3, 4}:\n");
	for (i = 0; i < 5; i++) dllAddLast(&head, i);
	for (i = 0; i < 5; i++) {
		dllRemoveLast(&head);
		printf("\t");
		dllPrint(&head);
	}
	dllClear(&head);

	printf("Test - Empty list {}:\n");
	dllRemoveLast(&head);
	printf("\t");
	dllPrint(&head);

	/* test dllSize */
	printf("\n----- dllSize Test: -----\n");
	printf("Test - Empty list {}:\n");
	printf("\tSize: %i\n", dllSize(&head));

	printf("Test - List of length 1 {25}:\n");
	dllAddFirst(&head, 25);
	printf("\tSize: %i\n", dllSize(&head));
	dllClear(&head);

	printf("Test - List of length 10 {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}:\n");
	for (i = 0; i < 10; i++) dllAddLast(&head, i);
	printf("\tSize: %i\n", dllSize(&head));

	/* test dllFlip */
	printf("\n----- dllFlip Test: -----\n");
	printf("Test - List of length 10 {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}:\n");
	dllFlip(&head);
	printf("\t");
	dllPrint(&head);
	dllClear(&head);

	printf("Test - List of length 1 {25}:\n");
	dllAddFirst(&head, 25);
	printf("\t");
	dllClear(&head);

	printf("Test - Empty list {}:\n");
	dllFlip(&head);
	printf("\t");
	dllPrint(&head);

	/* test dllSortQS */
	printf("\n----- dllSortQS Test: -----\n");
	printf("Test - Empty list {}:\n");
	dllSortQS(&head);
	printf("\t");
	dllPrint(&head);

	printf("Test - List of length 1 {25}:\n");
	dllAddFirst(&head, 25);
	dllSortQS(&head);
	printf("\t");
	dllPrint(&head);
	dllClear(&head);

	printf("Test - Already sorted list of length 10 {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}:\n");
	for (i = 0; i < 10; i++) dllAddLast(&head, i);
	dllSortQS(&head);
	printf("\t");
	dllPrint(&head);

	printf("Test - Reverse-sorted list of length 10 {9, 8, 7, 6, 5, 4, 3, 2, 1, 0}:\n");
	dllClear(&head);
	for (i = 0; i < 10; i++) dllAddFirst(&head, i);
	dllSortQS(&head);
	printf("\t");
	dllPrint(&head);

	printf("Test - Random list of length 20: ");
	dllClear(&head);
	for (i = 0; i < 20; i++) dllAddLast(&head, arr[i]);
	dllPrint(&head);
	dllSortQS(&head);
	printf("\t");
	dllPrint(&head);

	/* test dllSortMS */
	printf("\n----- dllSortMS Test: -----\n");
	printf("Test - Empty list {}:\n");
	dllClear(&head);
	dllSortMS(&head);
	printf("\t");
	dllPrint(&head);

	printf("Test - List of length 1 {25}:\n");
	dllAddFirst(&head, 25);
	dllSortMS(&head);
	printf("\t");
	dllPrint(&head);
	dllClear(&head);

	printf("Test - Already sorted list of length 10 {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}:\n");
	for (i = 0; i < 10; i++) dllAddLast(&head, i);
	dllSortMS(&head);
	printf("\t");
	dllPrint(&head);

	printf("Test - Reverse-sorted list of length 10 {9, 8, 7, 6, 5, 4, 3, 2, 1, 0}:\n");
	dllClear(&head);
	for (i = 0; i < 10; i++) dllAddFirst(&head, i);
	dllSortMS(&head);
	printf("\t");
	dllPrint(&head);

	printf("Test - Random list of length 20: ");
	dllClear(&head);
	for (i = 0; i < 20; i++) dllAddLast(&head, arr[i]);
	dllPrint(&head);
	dllSortMS(&head);
	printf("\t");
	dllPrint(&head);
	printf("\tRandom Test of sllFlip: ");
	dllFlip(&head);
	dllPrint(&head);

	/* test dllIndexOf */
	printf("\n----- dllSortIndexOf Test: -----\n");
	printf("Test - Empty list {}:\n");
	dllClear(&head);
	printf("\tIndex of 1 is: %i\n", dllIndexOf(&head, 1));

	printf("Test - List of length 1 {25}:\n");
	dllAddFirst(&head, 25);
	printf("\tIndex of 25 is: %i\n", dllIndexOf(&head, 25));
	printf("\tIndex of 1 is: %i\n", dllIndexOf(&head, 1));
	dllClear(&head);

	printf("Test - List of length 10 {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}:\n");
	for (i = 0; i < 10; i++) dllAddLast(&head, i);
	printf("\tIndex of 0 is: %i\n", dllIndexOf(&head, 0));
	printf("\tIndex of 5 is: %i\n", dllIndexOf(&head, 5));
	printf("\tIndex of 9 is: %i\n", dllIndexOf(&head, 9));
	printf("\tIndex of 10 is: %i\n", dllIndexOf(&head, 10));

	/* test dllPeekFirst & dllPeekLast */
	printf("\n----- dllPeekFirst & dllPeekLast Test: -----\n");
	printf("Test - Empty list {}:\n");
	dllClear(&head);
	printf("\tFirst element: %i\n\tLast element: %i\n", dllPeekFirst(&head), dllPeekLast(&head));

	printf("Test - List of length 1 {25}:\n");
	dllAddFirst(&head, 25);
	printf("\tFirst element: %i\n\tLast element: %i\n", dllPeekFirst(&head), dllPeekLast(&head));
	dllClear(&head);
	
	printf("Test - List of length 10 {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}:\n");
	for (i = 0; i < 10; i++) dllAddLast(&head, i);
	printf("\tFirst element: %i\n\tLast element: %i\n", dllPeekFirst(&head), dllPeekLast(&head));

	printf("\n");
	dllClear(&head);

	return 0;
}


