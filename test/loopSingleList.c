#include "../src/loop_single_list/loop_single_list.h"
#include <stdio.h>

int main() {
	LSgList lsgList;
	int i, arr[] = {
		1, 2, 3, 4, 5, 6
	};
	LSgListNew(&lsgList, sizeof(int));
 	for (i = 0; i < sizeof(arr) / sizeof(int); ++i) {
		LSgListAdd(&lsgList, &arr[i]);
	}
	if (LSgListEmpty(&lsgList)) {
		printf("The loop single list is empty\n");
	} else {
		printf("The length of the loop single list is %d\n", LSgListLength(&lsgList));
	}
	LSgListFree(&lsgList);
}
