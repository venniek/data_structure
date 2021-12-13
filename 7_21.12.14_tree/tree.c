#include "bintree.h"

BinTree* makeBinTree(BinTreeNode rootNode)
{
	BinTree *bintree;

	if (!(bintree = (BinTree*)malloc(sizeof(BinTree))))
		return (NULL);
	if (!(bintree->pRootNode = (BinTreeNode *)malloc(sizeof(BinTreeNode))))
		return (NULL);
	*bintree->pRootNode = rootNode;
	bintree->pRootNode->pParent = NULL;
	return (bintree);
}

BinTreeNode* getRootNodeBT(BinTree* pBinTree)
{
	if (!pBinTree)
		return (NULL);
	return (pBinTree->pRootNode);
}

BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	BinTreeNode *NewTreeNode;

	if (!pParentNode)
		return (NULL);
	if (!(NewTreeNode = (BinTreeNode *)malloc(sizeof(BinTreeNode))))
		return (NULL);
	*NewTreeNode = element;
	NewTreeNode->pParent = pParentNode;
	pParentNode->pLeftChild = NewTreeNode;
	return (NewTreeNode);
}

BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	BinTreeNode *NewTreeNode;

	if (!pParentNode)
		return (NULL);
	if (!(NewTreeNode = (BinTreeNode *)malloc(sizeof(BinTreeNode))))
		return (NULL);
	*NewTreeNode = element;
	NewTreeNode->pParent = pParentNode;
	pParentNode->pRightChild = NewTreeNode;
	return (NewTreeNode);
}

BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode)
{
	if (!pNode)
		return (NULL);
	return (pNode->pLeftChild);
}

BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode)
{
	if (!pNode)
		return (NULL);
	return (pNode->pRightChild);
}

void deleteBinTree(BinTree* pBinTree)
{
	BinTreeNode *pRootNode = pBinTree->pRootNode;

	if (!pBinTree)
		return ;
	while (pRootNode->pLeftChild != NULL || pRootNode->pRightChild != NULL)
		deleteBinTreeNode(pRootNode);
	free(pRootNode);
	pBinTree->pRootNode = NULL;
	free(pBinTree);
	return ;
}

void deleteBinTreeNode(BinTreeNode* pNode)
{
	BinTreeNode *curr;

	if (!pNode)
		return ;
	curr = pNode;
	while (curr)
	{
		if (curr->pRightChild)
			curr = curr->pRightChild;
		else if (curr->pLeftChild)
			curr = curr->pLeftChild;
		else
			break ;
	}
	if (curr->pParent == NULL)
	{
		free(curr);
		return ;
	}
	if (curr->pParent->pRightChild == curr)
		curr->pParent->pRightChild = NULL;
	else if (curr->pParent->pLeftChild == curr)
		curr->pParent->pLeftChild = NULL;
	pNode->data = curr->data;
	free(curr);
}
