#include "../src/stack/my_stack.h"
#include <stdio.h>

int main() {
	int arr[] = {
		1, 2, 3, 4, 5, 6, 7
	};
	int i = 0, *top = 0;
	Stack stack;
	StackInit(&stack, sizeof(int));

	while (i < sizeof(arr) / sizeof(int)) {
		StackPush(&stack, &arr[i]);
		++i;
	}

	top = StackTop(&stack);
	printf("The top of the stack element is %d\n", *top);
	top = StackPop(&stack);
	printf("Pop element  %d\n", *top);
	top = StackTop(&stack);
	printf("The top of the stack element is %d\n", *top);

	printf("The stack size is %d\n", StackSize(&stack));

	StackClear(&stack);
	if (StackEmpty(&stack)) {
		printf("Stack is empty.\n");
	} else {
		printf("Stack is not empty.\n");
	}
	StackDestory(&stack);
	return 0;
}
