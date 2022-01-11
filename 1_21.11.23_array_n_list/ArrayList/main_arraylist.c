#include "arraylist.h"

int		main(void)
{
	char c;
	int len = 0, end = 0, position = 0;
	int maxcount;
	printf("maxcount: ");
	scanf("%d", &maxcount);
	ArrayList *pList = createArrayList(maxcount);
	ArrayListNode *curr;
	ArrayListNode node0 = { 0 };
	
	while (!end)
	{
		printf("Add Remove Get Clear Delete Print Length: ");
		scanf(" %c", &c);
		switch (c)
		{
		case 'A':
			printf("data, position: ");
			scanf("%d %d", &(node0.data), &position);
			addALElement(pList, position, node0);
			break;
		case 'R':
			printf("position: ");
			scanf("%d", &position);
			removeALElement(pList, position);
			break;
		case 'G':
			printf("position: ");
			scanf("%d", &position);
			curr = getALElement(pList, position);
			printf("%d\n", curr->data);
			break;
		case 'P':
			displayArrayList(pList);
			break;
		case 'L':
			len = getArrayListLength(pList);
			printf("%d\n", len);
			break;
		case 'C':
			clearArrayList(pList);
			break;
		case 'D':
			deleteArrayList(pList);
			pList = 0;
			end = 1;
			break;
		default:
			break;
		}
	}
	if (pList)
	{
		deleteArrayList(pList);
		pList = 0;
	}
	return 0;
}