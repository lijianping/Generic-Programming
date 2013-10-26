#ifndef __DOUBLE_LINKED_LIST_H_
#define __DOUBLE_LINKED_LIST_H_

typedef struct DbList {
	int elem_size;
	int *elem;
} DbList;

/* 
 * @brief Initialize a double linked list
 * @param dblist [in] The head of th double linked list
 * @param elem_size [in] The size of the double linked list's element
 * */
void DbListNew(DbList *dblist, int elem_size);

/* 
 * @brief Free the double linked list memory
 * @param dblist [in] The head of th double linked list
 * */
void DbListFree(DbList *dblist);

/* 
 * @brief Add element to the double linked list
 * @param dblist [in] The head of th double linked list
 * @param elem_addr [in] The address of the element which will be added
 * */
void DbListAdd(DbList *dblist, void *elem_addr);

/* 
 * @biref Get the length of the double linked list
 * @param dblist [in] The head of th double linked list
 * */
int DbListLength(DbList *dblist);

/* 
 * @biref Judge the double linked list whether empty
 * @param dblist [in] The head of th double linked list
 * */
int DbListEmpty(DbList *dblist);

/* 
 * @brief Insert a new element at specified position
 * @param dblist [in] The head of th double linked list
 * @param pos [in] The position which the element will be inserted
 * @param elem_addr [in] The address of the element will be inserted
 * @note If the pos less than zero, the element will be intserted at
 *       the first of the double linked list. Also, if the pos bigger
 *       than the length of the list, the element will be inserted at
 *       the end of the list.
 * */
void DbListInsert(DbList *dblist, int pos, void *elem_addr);

/* 
 * @brief Delete the specified position element
 * @param dblist [in] The head of th double linked list
 * @param pos [in] The position will be deleted
 * */
void DbListDelete(DbList *dblist, int pos);

#endif
