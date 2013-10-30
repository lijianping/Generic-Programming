#include "my_stack.h"
#include <malloc.h>
#include <string.h>
#include <assert.h>

void StackExtend(Stack *stack) {
	stack->alloc_size *= 2;
	stack->elem = realloc(stack->elem, stack->alloc_size * stack->elem_size);
	assert(stack->elem != 0);
}
void StackInit(Stack *stack, int elem_size) {
	assert(stack != 0);
	stack->elem_size = elem_size;
	stack->alloc_size = 4;
	stack->logic_size = 0;
	stack->elem = malloc(stack->alloc_size * elem_size);
	assert(stack->elem != 0);
}

void StackDestory(Stack *stack) {
	assert(stack != 0);
	free(stack->elem);
}

void StackClear(Stack *stack) {
	assert(stack != 0);
	stack->logic_size = 0;
}

int StackEmpty(Stack *stack) {
	assert(stack != 0);
	return stack->logic_size == 0 ? 1 : 0;
}

void StackPush(Stack *stack, void *elem) {
	void *tmp = 0;
	assert(stack != 0);
	if (stack->alloc_size == stack->alloc_size) {
		StackExtend(stack);
	}
	tmp = (char *)stack->elem + stack->logic_size * stack->elem_size;
	memcpy(tmp, elem, stack->elem_size);
	stack->logic_size++;
}

void* StackPop(Stack *stack) {
	void *tmp = 0;
	assert(stack != 0);
	if (stack->logic_size == 0) return NULL;
	stack->logic_size--;
	tmp = (char *)stack->elem + stack->logic_size * stack->elem_size;
	return tmp;
}

void* StackTop(Stack *stack) {
	void *tmp = 0;
	assert(stack != 0);
	if (stack->logic_size == 0) return NULL;
	tmp = (char *)stack->elem + (stack->logic_size - 1) * stack->elem_size;
	return tmp;
}

int StackSize(Stack *stack) {
	assert(stack != 0);
	return stack->logic_size;
}
