#include "maze_stack.h"

char num_to_dir(int i)  //showPath_on_maze
{
	if (i == 0)
		return ('^');
	else if (i == 1)
		return ('>');
	else if (i == 2)
		return ('v');
	else if (i == 3)
		return ('<');
	else
		return ('E');
}

char *num_to_str(int i)  //showPath
{
	if (i == 0)
		return ("UP");
	else if (i == 1)
		return ("RIGHT");
	else if (i == 2)
		return ("DOWN");
	else if (i == 3)
		return ("LEFT");
	else
		return ("END");
}

void showPath_on_Maze(LinkedStack *pStack, int mazeArray[HEIGHT][WIDTH])
{
	StackNode *tmp_node;
	char map[HEIGHT][WIDTH] = {0, };

	tmp_node = pStack->pTopElement;
	printf("PATH ON MAZE========\n");
	for (int i = 0; i < pStack->currentElementCount; i++)	
	{
		map[tmp_node->pos.y][tmp_node->pos.x] = num_to_dir(tmp_node->pos.dir);
		tmp_node = tmp_node->pLink;
	}
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
			printf("%c ", map[i][j] == 0 ? '.' : map[i][j]);
		printf("\n");
	}
	printf("====================\n");
}

void change_short(LinkedStack *pStack, LinkedStack *ShortStack)
{
	StackNode *tmp;

	while (ShortStack->currentElementCount)
		free(popLSMapPosition(ShortStack));
	tmp = pStack->pTopElement;
	while (tmp)
	{
		pushLSMapPosition(ShortStack, tmp->pos);
		tmp = tmp->pLink;
	}
	reverseLinkedStack(ShortStack);
}