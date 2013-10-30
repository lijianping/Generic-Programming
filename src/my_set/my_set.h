#ifndef __MY_SET_H_
#define __MY_SET_H_

typedef struct SgList {
	int elem_size;
	int *elem;
}SgList;

/* 
 * @brief Initialize a single list
 * @param sglist [in] The head of the single list
 * @param elem_size [in] The single list data element size
 * */
void SgListNew(SgList *sglist, int elem_size);

/* 
 * @brief Add element into the single list
 * @param sglist [in] The head of the single list
 * @param elem_addr [in] The address of the element which will be added
 * @note This is a set. So there no duplicate elements in single lisst
 * */
void SgListAdd(SgList *sglist, void *elem_addr);

/* 
 * @brief Free the single list memory
 * @param sglist [in] The head of the single list
 * */
void SgListFree(SgList *sglist);

/* 
 * @brief Judge the single list whether is empty
 * @param sglist [in] The head of the single list
 * @return If the list is empty, the return is non-zero.
 *         Otherwise, the return will be zero
 * */
int SgListEmpty(SgList *sglist);

/* 
 * @brief Get the single list length
 * @param sglist [in] The head of the single list
 * @return The return is the length of the single list
 * */
int SgListLength(SgList *sglist);

/* 
 * @brief Insert a new element at specified position
 * @param sglist [in] The head of the single list
 * @param pos [in] The position will be inserted
 * @param elem_addr [in] The address of the element which will be inserted
 * @Note If the pos less then zero, the element will be inserted at the
 *       first of the single list. Also, if the pos bigger than the 
 *       length of single list, the element will be inserted at the 
 *       last of the single list.
 * */
void SgListInsert(SgList *sglist, int pos, void *elem_addr);

/* 
 * @brief Delete the specified position element
 * @param sglist [in] The head of the single list
 * @param pos [in] The position will be deleted
 * */
void SgListDelete(SgList *sglist, int pos);

/* 
 * @brief Get the single list element at specified position
 * @param sglist [in] The head of the single list
 * @param pos [in] The specified position
 * @param elem_addr [in,out] The element of the specified position in 
 *        single list
 * @return If failed, the return is NULL, otherwise, the address of
 *         the element will be returned
 * */
void* SgListGetElem(SgList *sglist, int pos);

/* 
 * @brief Find the specified element
 * @param sglist [in] The head of the single list
 * @param elem_addr [in] The address of the specified element which will be found
 * @return If find it, return the position of the element in the single list,
 *         Otherwise, return -1 
 * */
int SgListFindElem(SgList *sglist, void *elem_addr);

/*
 * @brief Sort the single list
 * @param sglist [in] The head of the single list
 * @param cmpfn [in] Pointer to a function that compares two elements
 *        This function is called repeatedly by SgListSort to compare two elements.
 *        It shall follow the following prototype:
 *           int cmpfn(void *p1, void *p2);
 *        Taking two pointers as arguments (both conveted to void*). The function
 *        defines the order of the elements by returning(in a stable and transitive manner):
 *          return value                     meaning
 *              < 0          The element pointed by p1 goes before the element pointed by p2
 *              = 0          The element pointed by p1 is equivalent to the element pointed by p2
 *              > 0          The element pointed by p1 goes after the element pointed by p2
 *       For types that can be compared using regular relational operators, a general cmpfn function
 *       may look like:
 *          int cmpfnMyType(void *a, void *b) {
 *              if (*(MyType *)a < *(MyType *)b) return -1;
 *              if (*(MyType *)a == *(MyType *)b) return 0;
 *              if (*(MyType *)a > *(MyType *)b) return 1;
 *          }
 * */
void SgListSort(SgList *sglist, int (*cmpfn)(void *, void *));

void SgListUnion(SgList *sglist1, SgList *sglist2, SgList *sglist3);

void SgListIntersection(SgList *sglist1, SgList *sglist2, SgList *sglist3);

void SgListComplements(SgList *sglist1, SgList *sglist2, SgList *sglist3);

void SgListClear(SgList *sglist);

#endif
