#include "linkedlist.h"
#include <string.h> //NULL
#include <stdlib.h> //malloc

LinkedList* createLinkedList()
{
	LinkedList	*list;

	if (!(list = (LinkedList *)malloc(sizeof(LinkedList))))
		return (NULL);
	list->headerNode.data = 0;
	list->headerNode.pLink = 0;
	list->currentElementCount = 0;
	return (list);
}

int addLLElement(LinkedList* pList, int position, ListNode element)
//element를 nownode에 넣어 list단위에서 pLink를 관리하면 편함
{
	ListNode *temp;
	ListNode *nownode;

	if(!pList)  //erase &element == NULL
		return (FALSE);  //change all NULL->FALSE
	if (position < 0 || position > pList->currentElementCount)
		return (FALSE);
	nownode->data = element.data;
	nownode->pLink = 0;
	temp = &(pList->headerNode);
	while(position--)
		temp = temp->pLink;
	nownode->pLink = temp->pLink;
	temp->pLink = nownode;
	pList->currentElementCount++;
	return (TRUE);
}

int removeLLElement(LinkedList* pList, int position)
{
	ListNode *temp;
	ListNode *delnode;

	if(!pList)
		return (FALSE);
	if (position < 0 || position >= pList->currentElementCount)
		return (FALSE);
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
		return;
	while(pList->currentElementCount > 0)
		removeLLElement(pList, 0);
}

int getLinkedListLength(LinkedList* pList)
{
	if(!pList)
		return (FALSE);
	return (pList->currentElementCount);
}

void deleteLinkedList(LinkedList* pList)
{
	if(!pList)
		return;
	clearLinkedList(pList);
	free(pList);
}