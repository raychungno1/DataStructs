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

	int arr[3] = {0, 1, 2}, i;
	int temp;
	struct sllNode *head = NULL;
	
	sllRemoveFirst(&head, &temp, sizeof(int));
	sllRemoveLast(&head, &temp, sizeof(int));
	for (i = 0; i < 3; i++) {
		sllAddLast(&head, &arr[i], sizeof(int));
	}
	i = sllSize(&head);
	printf("Size: %i\n", i);
	sllPrint(&head, pInt);

	i = 0;
	sllContains(&head, &i, compInt) ? printf("List contains %i.\n", i) : printf("List doesn't contain %i.\n",i);
	
	i = 1;
	sllContains(&head, &i, compInt) ? printf("List contains %i.\n", i) : printf("List doesn't contain %i.\n",i);
	
	i = 2;
	sllContains(&head, &i, compInt) ? printf("List contains %i.\n", i) : printf("List doesn't contain %i.\n",i);
	
	i = 3;
	sllContains(&head, &i, compInt) ? printf("List contains %i.\n", i) : printf("List doesn't contain %i.\n",i);

	sllRemoveFirst(&head, &temp, sizeof(int));
	printf("Removed: %i\n", temp);
	sllPrint(&head, pInt);

	sllRemoveLast(&head, &temp, sizeof(int));
	printf("Removed: %i\n", temp);
	sllPrint(&head, pInt);

	sllRemoveLast(&head, &temp, sizeof(int));
	printf("Removed: %i\n", temp);
	sllPrint(&head, pInt);

	for (i = 0; i < 3; i++) {
		sllAddLast(&head, &arr[i], sizeof(int));
	}
	i = sllSize(&head);
	printf("Size: %i\n", i);
	sllPrint(&head, pInt);

	i = 1;
	sllRemove(&head, &i, compInt);
	printf("Removed: %i\n", i);
	sllPrint(&head, pInt);

	i = 3;
	sllRemove(&head, &i, compInt);
	printf("Removed: %i\n", i);
	sllPrint(&head, pInt);

	i = 2;
	sllRemove(&head, &i, compInt);
	printf("Removed: %i\n", i);
	sllPrint(&head, pInt);

	i = 0;
	sllRemove(&head, &i, compInt);
	printf("Removed: %i\n", i);
	sllPrint(&head, pInt);

	sllClear(&head);

	return 0;
}


