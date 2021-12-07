/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:32:02 by sujilee           #+#    #+#             */
/*   Updated: 2021/11/23 13:04:05 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arrayqueue.h"

int main()
{
	ArrayQueue *linkeds;
	ArrayQueueNode node1 = { 0 };
	ArrayQueueNode *curr;

	int len = 0;
	int position = 0;
	int max;
	char c;
	printf("input maxsize(0 when linkedlist): ");
	scanf(" %d", &max);
	linkeds = createArrayQueue(max);
	while(1)
	{
		rewind(stdin);
		printf("put Enqueue Dequeue Peek Full empTy pRint: ");
		scanf(" %c", &c);
		rewind(stdin);
		switch (c)
		{
		case 'E':
			scanf("%c", &(node1.data));
			enqueueAQ(linkeds, node1);
			break ;
		case 'D':
			curr = dequeueAQ(linkeds);
			printf("%d\n", curr ? curr->data : -1);
			free(curr);
			break ;
		case 'P':
			curr = peekAQ(linkeds);
			printf("%d\n", curr ? curr->data : -1);
			free(curr);
			break ;
		case 'F':
			printf("queue is %sfull\n", isArrayQueueFull(linkeds) == TRUE ? "" : "not ");
			break ;
		case 'T':
			printf("queue is %sempty\n", isArrayQueueEmpty(linkeds) == TRUE ? "" : "not ");
			break ;
		case 'R':
			displayArrayQueue(linkeds);
			break;
		case 'L':
			deleteArrayQueue(linkeds);
			break;
		default:
			break;
		}
		if (c == 'L')
			break;
	}
	return (0);
}
