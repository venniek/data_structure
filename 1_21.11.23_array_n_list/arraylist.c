#include "arraylist.h"
#include <string.h> //NULL
#include <stdlib.h> //malloc
#include <stdio.h> //printf

ArrayList* createArrayList(int maxElementCount)
{	
	ArrayList *array;

	if (maxElementCount < 0)
		return (NULL);
	if (!(array = (ArrayList *)malloc(sizeof(ArrayList))))
		return (NULL);
	array->currentElementCount = 0;
	array->maxElementCount = maxElementCount;
	if (!(array->pElement = (ArrayListNode *)calloc(array->maxElementCount, sizeof(ArrayListNode)))) ///malloc->calloc
		return (NULL);
	return (array);
}

void deleteArrayList(ArrayList* pList)
{
	if (!pList)
		return (NULL);
	clearArrayList(pList);   //add clearArrayList
	free(pList->pElement);
	free(pList);
}

int isArrayListFull(ArrayList* pList)
{
	if (!pList)
		return (NULL);
	if (pList->maxElementCount == pList->currentElementCount)
		return (TRUE);
	return (FALSE);
}

int addALElement(ArrayList* pList, int position, ArrayListNode element)
{
	int i = pList->currentElementCount - 1;

	if(!pList || &element == NULL)
		return (NULL);
	if (position < 0 || position >= pList->currentElementCount)
		return (NULL);
	if (isArrayListFull(pList))
		return (FALSE);
	while (i > position)
	{
		pList->pElement[i] = pList->pElement[i - 1];
		i--;
	}
	pList->pElement[position].data = element.data;   //add .data
	pList->currentElementCount++;
	return (TRUE);
}

int removeALElement(ArrayList* pList, int position)
{
	int i = position;
	if(!pList)
		return (NULL);
	if (position < 0 || position >= pList->currentElementCount)
		return (NULL);
	pList->pElement[i].data = 0;  //add 
	while(i < pList->currentElementCount - 1)
	{
		pList->pElement[i].data = pList->pElement[i + 1].data;  //add .data
		i++;
	}
	pList->currentElementCount--;
	return (TRUE);
}

ArrayListNode* getALElement(ArrayList* pList, int position)
{
	if(!pList)
		return (NULL);
	if (position < 0 || position >= pList->currentElementCount)
		return (NULL);
	return (&(pList->pElement)[position]);
}

void displayArrayList(ArrayList* pList)
{
	if(!pList)
		return (NULL);
	// printf("MAX ELEMENT COUNT:%d\n", pList->maxElementCount);
	// printf("CURRENT ELEMENT COUNT:%d\n", pList->currentElementCount);  ////remove? 
	for (int i = 0; i < pList->currentElementCount; i++)
		printf("pElement[%d]: %d\n", i, pList->pElement[i].data);
}

void clearArrayList(ArrayList* pList)
{
	if(!pList)
		return (NULL);
	for (int i = pList->currentElementCount - 1; i >= 0; i--)
		removeALElement(pList, i);
}

int getArrayListLength(ArrayList* pList)
{
	if(!pList)
		return (NULL);
	return (pList->currentElementCount);
}
