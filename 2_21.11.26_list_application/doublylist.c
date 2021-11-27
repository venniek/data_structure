#include "doublylist.h"

DoublyList* createDoublyList() //이중연결리스트
{
	DoublyList	*Dlist;

	if (!(Dlist = (DoublyList *)malloc(sizeof(DoublyList))))
		return (NULL);
	Dlist->headerNode.data = 0;
	Dlist->headerNode.pLLink = &(Dlist->headerNode);
	Dlist->headerNode.pRLink = &(Dlist->headerNode);
	Dlist->currentElementCount = 0;
	return (Dlist);
}

void deleteDoublyList(DoublyList* pList)
{
	if(!pList)
		return;
	clearDoublyList(pList);
	free(pList);
}

int addDLElement(DoublyList* pList, int position, DoublyListNode element)
{
	DoublyListNode *prev;
	DoublyListNode *new;

	if(!pList)
		return (FALSE);
	if (position < 0 || position > pList->currentElementCount)
		return (FALSE);
	if (!(new = (DoublyListNode *)malloc(sizeof(DoublyListNode))))
		return (FALSE);
	*new = element;
	new->pLLink = NULL;
	new->pRLink = NULL;
	prev = &(pList->headerNode);
	while(position--)
		prev = prev->pRLink;
	new->pRLink = prev->pRLink;
	prev->pRLink = new;
	new->pLLink = prev;
	new->pRLink->pLLink = new;
	pList->currentElementCount++;
	return (TRUE);
}

int removeDLElement(DoublyList* pList, int position) //이중연결리스트에 인자 삭제
{
	DoublyListNode	*prev;
	DoublyListNode	*delnode;

	if(!pList)
		return (FALSE);
	if (position < 0 || position > pList->currentElementCount)
		return (FALSE);
	prev = &(pList->headerNode);
	while(position--)
		prev = prev->pRLink;
	delnode = prev->pRLink;
	prev->pRLink = delnode->pRLink;
	delnode->pRLink->pLLink = delnode->pLLink;
	free(delnode);
	pList->currentElementCount--;
	return (TRUE);
}

void clearDoublyList(DoublyList* pList) //이중연결리스트 비우기
{
	while(pList->currentElementCount > 0)
		removeDLElement(pList, 0);
}

int getDoublyListLength(DoublyList* pList)
{
	if (!pList)
		return (FALSE);
	return (pList->currentElementCount);
}

DoublyListNode* getDLElement(DoublyList* pList, int position)
{
	DoublyListNode *prev;

	if(!pList)
		return (NULL);
	//// position이 절반보다 작은지 큰지 봐서 앞에서 올지 뒤에서 올지 먼저 결정. 시간복잡도 때문에!
	if (position < 0 || position >= pList->currentElementCount)
		return (NULL);
	prev = &(pList->headerNode);
	position++;
	while(position--)
		prev = prev->pRLink;
	return (prev);
}

void displayDoublyList(DoublyList* pList)
{
	DoublyListNode *tmp;

	if(!pList)
		return ;
	tmp = &(pList->headerNode);
	for (int i = 0; i < pList->currentElementCount; i++)
	{
		tmp = tmp->pRLink;
		printf("%d\n", tmp->data);
	}
}