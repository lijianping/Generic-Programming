#include "../src/loop_single_list/loop_single_list.h"
#include <stdio.h>

void Display(LSgList *lsglist);

int main() {
	LSgList lsgList;
	int a = 6;
	int i, arr[] = {
		1, 2, 3, 4, 5, 6
	};
	LSgListNew(&lsgList, sizeof(int));
 	for (i = 0; i < sizeof(arr) / sizeof(int); ++i) {
		LSgListAdd(&lsgList, &arr[i]);
	}
	Display(&lsgList);
	if (LSgListEmpty(&lsgList)) {
		printf("The loop single list is empty\n");
	} else {
		printf("The length of the loop single list is %d\n", LSgListLength(&lsgList));
	}
	LSgListInsert(&lsgList, 6, &arr[2]);
	Display(&lsgList);
	LSgListDelete(&lsgList, 4);
    Display(&lsgList);
	i = LSgListFindElem(&lsgList, &a);
	if (i != -1) {
		printf("Find %d at position %d\n", a, i);
	} else {
		printf("Can not find\n");
	}
	LSgListFree(&lsgList);
}

void Display(LSgList *lsglist) {
	int i, data, len = 0;
	if (lsglist) {
		len = LSgListLength(lsglist);
		for (i = 0; i < len; ++i) {
			LSgListGetElem(lsglist, i, &data);
			printf("%d ", data);
		}
		printf("\n");
	}
}
