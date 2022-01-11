#include "linkedlist.h"

void print_list(LinkedList* pList)
{
	ListNode *curr = &(pList->headerNode);

	while (curr->pLink)
	{
		curr = curr->pLink;
		printf("%d\n", curr->data);
	}
}

int	main()
{
	int len = 0, position = 0;
	char c;
	LinkedList *pList;
	ListNode *curr;
	ListNode node0 = {0, 0};

	pList = createLinkedList();
	
	while (pList)
	{
		printf("Add Remove Get Print Length Clear Delete: ");
		scanf(" %c", &c);
		switch (c)
		{
		case 'A':
			printf("data, position: ");
			scanf("%d %d", &(node0.data), &position);
			addLLElement(pList, position, node0);
			break;
		case 'R':
			printf("position: ");
			scanf("%d", &position);
			removeLLElement(pList, position);
			break;
		case 'G':
			printf("position: ");
			scanf("%d", &position);
			curr = getLLElement(pList, position);
			printf("%d\n", curr->data);
			break;
		case 'P':
			print_list(pList);
			break;
		case 'L':
			len = getLinkedListLength(pList);
			printf("%d\n", len);
			break;
		case 'C':
			clearLinkedList(pList);
			break;
		case 'D':
			deleteLinkedList(pList);
			pList = 0;
			break;
		default:
			break;
		}
	}
	if (pList)
	{
		deleteLinkedList(pList);
		pList = 0;
	}
	return 0;
}