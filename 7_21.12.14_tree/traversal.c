#include "bintree.h"

void preorder_traversal(BinTreeNode *pNode)
{
	if (!pNode)
		return ;
	if (pNode->visited == 0)
	{
		printf("%c ", pNode->data);
		pNode->visited = 1;
	}
	preorder_traversal(pNode->pLeftChild);
	preorder_traversal(pNode->pRightChild);
}

void visited_zero_traversal(BinTreeNode *pNode)
{
	if (!pNode)
		return ;
	pNode->visited = 0;
	visited_zero_traversal(pNode->pLeftChild);
	visited_zero_traversal(pNode->pRightChild);
}

void inorder_traversal(BinTreeNode *pNode)
{
	if (!pNode)
		return ;
	inorder_traversal(pNode->pLeftChild);
	if (pNode->visited == 0)
	{
		printf("%c ", pNode->data);
		pNode->visited = 1;
	}
	inorder_traversal(pNode->pRightChild);
}

void postorder_traversal(BinTreeNode *pNode)
{
	if (!pNode)
		return ;
	postorder_traversal(pNode->pLeftChild);
	postorder_traversal(pNode->pRightChild);
	if (pNode->visited == 0)
	{
		printf("%c ", pNode->data);
		pNode->visited = 1;
	}
}