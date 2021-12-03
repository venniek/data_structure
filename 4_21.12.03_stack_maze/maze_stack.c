#include "maze_stack.h"

// [0]UP [1]RIGHT [2]DOWN [3]LEFT
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int find_ans;
int short_dis;
LinkedStack *ShortStack;

int pushLSMapPosition(LinkedStack *pStack, MapPosition data)
{
	int ret = FALSE;
	StackNode *newNode = 0;

	if (pStack)
	{
		if ((newNode = (StackNode *)calloc(1, sizeof(StackNode))))
		{
			newNode->pos = data;
			newNode->pLink = pStack->pTopElement;
			pStack->pTopElement = newNode;
			pStack->currentElementCount++;
			ret = TRUE;
		}
	}
	else
		printf("Invalid pStack");
	return (ret);
}

StackNode *popLSMapPosition(LinkedStack *pStack)
{
	StackNode *ret = 0;

	if (pStack)
	{
		if (pStack->currentElementCount != 0)
		{
			ret = pStack->pTopElement;
			pStack->pTopElement = ret->pLink;
			ret->pLink = 0;
			pStack->currentElementCount--;
		}
	}
	else
		printf("Invalid pStack");
	return (ret);
}

void findPath(int mazeArray[HEIGHT][WIDTH], MapPosition startPos, MapPosition endPos, LinkedStack *pStack)
{
	if (startPos.x == endPos.x && startPos.y == endPos.y)
	{
		pushLSMapPosition(pStack, startPos);
		if (short_dis > pStack->currentElementCount)
			change_short(pStack, ShortStack);
		// 새로운 경로 찾을 때마다 출력해주기
		// showPath(pStack, mazeArray);
		// showPath_on_Maze(pStack, mazeArray);
		find_ans = 1;
		free(popLSMapPosition(pStack));
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		MapPosition next;
		MapPosition now;
		
		int nx = startPos.x + dx[i];
		int ny = startPos.y + dy[i];
		if (nx >= WIDTH || nx < 0 || ny >= HEIGHT || ny < 0)
			continue;
		if (mazeArray[ny][nx] != 0)
			continue;
		now.x = startPos.x;
		now.y = startPos.y;
		now.dir = i;
		next.x = nx;
		next.y = ny;
		next.dir = -1;
		mazeArray[ny][nx] = 2;
		pushLSMapPosition(pStack, now);
		findPath(mazeArray, next, endPos, pStack);
		free(popLSMapPosition(pStack));
		mazeArray[ny][nx] = 0;
	}
}

void showPath(LinkedStack *pStack, int mazeArray[HEIGHT][WIDTH])
{
	StackNode *tmp_node;

	reverseLinkedStack(pStack);
	tmp_node = pStack->pTopElement;
	printf("PATH================\n");
	for (int i = 0; i < pStack->currentElementCount; i++)	
	{
		printf("(%d, %d) %s\n", tmp_node->pos.x, tmp_node->pos.y, num_to_str(tmp_node->pos.dir));
		tmp_node = tmp_node->pLink;
	}
	printf("====================\n");
	reverseLinkedStack(pStack);
}

void printMaze(int mazeArray[HEIGHT][WIDTH])
{
	printf("MAZE================\n");
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
			printf("%d ", mazeArray[i][j]);
		printf("\n");
	}
	printf("====================\n");
}

int main()
{
	MapPosition startPos;
	MapPosition endPos;
	LinkedStack *pStack = createLinkedStack();
	startPos.x = 0;
	startPos.y = 0;
	startPos.dir = -1;
	endPos.x = WIDTH - 1;
	endPos.y = HEIGHT - 1;
	endPos.dir = -1;
	
	ShortStack = createLinkedStack();
	short_dis = HEIGHT * WIDTH;
	
	int mazeArray[HEIGHT][WIDTH] = {
		{0, 0, 0, 0, 0, 0, 0, 0},
		{1, 1, 1, 1, 0, 1, 1, 0},
		{1, 0, 0, 0, 0, 0, 0, 0},
		{1, 0, 1, 1, 0, 1, 0, 1},
		{1, 0, 1, 1, 0, 0, 0, 1},
		{1, 0, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0}
	};

	printMaze(mazeArray);
	mazeArray[0][0] = 2;
	findPath(mazeArray, startPos, endPos, pStack);
	if (find_ans == 0)
		printf("There's no answer.\n");
	else
	{
		showPath(ShortStack, mazeArray);
		showPath_on_Maze(ShortStack, mazeArray);
	}
	deleteLinkedStack(pStack);
	deleteLinkedStack(ShortStack);
	return 0;
}