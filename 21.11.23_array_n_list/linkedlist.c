#include "linkedlist.h"
#include <string.h> //NULL
#include <stdlib.h> //malloc

//headernode는 변경되면 안되는 것인지?

LinkedList* createLinkedList()
{
	LinkedList	*list;

	if (!(list = (LinkedList *)malloc(sizeof(LinkedList))))
		return (NULL);
	list->headerNode.data = NULL;
	list->headerNode.pLink = NULL;
	list->currentElementCount = 0;
	
	return (list);
}

int addLLElement(LinkedList* pList, int position, ListNode element)
//element를 nownode에 넣어 list단위에서 pLink를 관리하면 편함
{
	ListNode *temp;

	if(!pList || &element == NULL)
		return (NULL);
	if (position < 0 || position > pList->currentElementCount)
		return (NULL);
	temp = &(pList->headerNode);
	while(position--)
		temp = temp->pLink;
	element.pLink = temp->pLink->pLink;
	temp->pLink = &element;
	pList->currentElementCount++;
	return (TRUE);
}

int removeLLElement(LinkedList* pList, int position)
{
	ListNode *temp;
	ListNode *delnode;

	if(!pList)
		return (NULL);
	if (position < 0 || position >= pList->currentElementCount)
		return (NULL);
	temp = &(pList->headerNode);
	while(position--)
		temp = temp->pLink;
	delnode = temp->pLink;
	temp->pLink = delnode->pLink;
	free(delnode);
	pList->currentElementCount--;
	return (TRUE);
}

ListNode* getLLElement(LinkedList* pList, int position)
{
	ListNode *temp;

	if(!pList)
		return (NULL);
	if (position < 0 || position >= pList->currentElementCount)
		return (NULL);
	temp = &(pList->headerNode);
	position++;
	while(position--)
		temp = temp->pLink;
	return (temp);
	//리턴값을 따로 선언해야하나요?
}

void clearLinkedList(LinkedList* pList)
{
	ListNode *temp;

	if(!pList)
		return (NULL);
	while(pList->currentElementCount > 0)
		removeLLElement(pList, 0);
}

int getLinkedListLength(LinkedList* pList)
{
	if(!pList)
		return (NULL);
	return (pList->currentElementCount);
}

void deleteLinkedList(LinkedList* pList)
{
	if(!pList)
		return (NULL);
	clearLinkedList(pList);
	free(pList);
}