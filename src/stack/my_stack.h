#ifndef __MY_STACK_H_
#define __MY_STACK_H_

typedef struct Stack {
	int elem_size;
	int alloc_size;
	int logic_size;
	void *elem;
} Stack;

/* 
 * @brief Extend stack space
 * @param stack [in] The stack address
 * */
void StackExtend(Stack *stack);

/* 
 * @brief Initialize the stack
 * @param stack [in] The stack address
 * @param elem_size [in] The size of the element
 * */
void StackInit(Stack *stack, int elem_size);

/* 
 * @brief Destory stack and free the stack space
 * @param stack [in] The stack address
 * */
void StackDestory(Stack *stack);

/*
 * @brief Clear the stack
 * @param stack [in] The stack address 
 * */
void StackClear(Stack *stack);

/* 
 * @brief Judge the stack is empty
 * @param stack [in] The stack address 
 * */
int StackEmpty(Stack *stack);

/* 
 * @brief Push an element into stack
 * @param stack [in] The stack address
 * @parma elem [in] The address of the element
 * */
void StackPush(Stack *stack, void *elem);

/* 
 * @brief Pop an element from stack
 * @param stack [in] The stack address
 * @return If stack is empty, the return is NULL.
 *         Otherwise, the pop element address will be returned
 * */
void* StackPop(Stack *stack);

/* 
 * @brief Get the top element of the element
 * @param stack [in] The stack address
 * @return If stack is empty, the return is NULL.
 *         Otherwise, the pop element address will be returned
 * @note This function is not equal to StackPop, through the 
 *       return address is same element
 * */
void* StackTop(Stack *stack);

/* 
 * @brief Get the size of the stack
 * @param stack [in] The stack address
 * @return The return value is the size of stack
 * */
int StackSize(Stack *stack);

#endif
