#ifndef __SINGLE_LIST_H_
#define __SINGLE_LIST_H_

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
 * @return If failed, the return is zero, otherwise, non-zero will be returned
 * */
int SgListGetElem(SgList *sglist, int pos, void *elem_addr);

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
 *             int cmpfn(void * p1, void *p2);
 *        return value                               meaning
 *            < 0        The element pointed by p1 goes before the element pointed by p2
 *            = 0        The element pointed by p1 is equivalent to the element pointed by p2
 *            > 0        The element pointed by p1 goes after the element pointed by p2
 * */
void SgListSort(SgList *sglist, int (*cmpfn)(void *, void *));

#endif
