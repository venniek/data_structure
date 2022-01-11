#include "arraylist.h"

ArrayList* createArrayList(int maxElementCount)
{	
	ArrayList *array;

	if (maxElementCount < 0)
		return (NULL);
	if (!(array = (ArrayList *)malloc(sizeof(ArrayList))))
		return (NULL);
	array->currentElementCount = 0;
	array->maxElementCount = maxElementCount;
	if (!(array->pElement = (ArrayListNode *)calloc(array->maxElementCount, sizeof(ArrayListNode))))
		return (NULL);
	return (array);
}

void deleteArrayList(ArrayList* pList)
{
	if (!pList)
		return ;
	clearArrayList(pList);
	free(pList->pElement);
	free(pList);
}

int isArrayListFull(ArrayList* pList)
{
	if (!pList)
		return (FALSE);
	if (pList->maxElementCount == pList->currentElementCount)
		return (TRUE);
	return (FALSE);
}

int addALElement(ArrayList* pList, int position, ArrayListNode element)
{
	if(!pList)
		return (FALSE);
	if (position < 0 || position > pList->currentElementCount)
		return (FALSE);
	if (isArrayListFull(pList))
		return (FALSE);
	for (int i = pList->currentElementCount; i > position; i--)
		pList->pElement[i] = pList->pElement[i - 1];
	pList->pElement[position] = element;
	pList->currentElementCount++;
	return (TRUE);
}

int removeALElement(ArrayList* pList, int position)
{
	if(!pList)
		return (FALSE);
	if (position < 0 || position >= pList->currentElementCount)
		return (FALSE);
	for (int i = position; i < pList->currentElementCount - 1; i++)
		pList->pElement[i] = pList->pElement[i + 1];
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
		return ;
	for (int i = 0; i < pList->currentElementCount; i++)
		printf("pElement[%d]: %d\n", i, pList->pElement[i].data);
}

void clearArrayList(ArrayList* pList)
{
	if (!pList)
		return ;
	for (int i = pList->currentElementCount - 1; i >= 0; i--)
		removeALElement(pList, i);
}

int getArrayListLength(ArrayList* pList)
{
	if(!pList)
		return (FALSE);
	return (pList->currentElementCount);
}
