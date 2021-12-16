#include <stdlib.h>
#include <stdio.h>
#include "bintree.h"

int main()
{
	BinTreeNode rootNode_a = {'A', 0, 0, 0, 0};
	BinTreeNode rootNode_b = {'B', 0, 0, 0, 0};
	BinTreeNode rootNode_c = {'C', 0, 0, 0, 0};
	BinTreeNode rootNode_d = {'D', 0, 0, 0, 0};
	BinTreeNode rootNode_e = {'E', 0, 0, 0, 0};
	BinTreeNode rootNode_f = {'F', 0, 0, 0, 0};
	BinTreeNode rootNode_g = {'G', 0, 0, 0, 0};
	BinTreeNode rootNode_h = {'H', 0, 0, 0, 0};
	BinTreeNode rootNode_i = {'I', 0, 0, 0, 0};
	BinTreeNode rootNode_j = {'J', 0, 0, 0, 0};
	BinTreeNode rootNode_k = {'K', 0, 0, 0, 0};
	BinTreeNode rootNode_l = {'L', 0, 0, 0, 0};
	BinTreeNode rootNode_m = {'M', 0, 0, 0, 0};
	BinTree *bintree = makeBinTree(rootNode_a);
	BinTreeNode *curr;

	insertLeftChildNodeBT(bintree->pRootNode, rootNode_b);
	insertRightChildNodeBT(bintree->pRootNode, rootNode_c);
	curr = getLeftChildNodeBT(bintree->pRootNode);
	insertLeftChildNodeBT(curr, rootNode_d);
	insertLeftChildNodeBT(curr->pLeftChild, rootNode_h);
	insertRightChildNodeBT(curr->pLeftChild, rootNode_i);
	insertRightChildNodeBT(curr, rootNode_e);
	insertLeftChildNodeBT(curr->pRightChild, rootNode_j);

	curr = getRightChildNodeBT(bintree->pRootNode);
	insertLeftChildNodeBT(curr, rootNode_f);
	insertRightChildNodeBT(curr->pLeftChild, rootNode_k);
	insertRightChildNodeBT(curr, rootNode_g);
	insertLeftChildNodeBT(curr->pRightChild, rootNode_l);
	insertRightChildNodeBT(curr->pRightChild, rootNode_m);

	printf("=========preorder==========\n");
	preorder_traversal(bintree->pRootNode);
	visited_zero_traversal(bintree->pRootNode);
	printf("\n===========done============\n");

	printf("\n=========inorder===========\n");
	inorder_traversal(bintree->pRootNode);
	visited_zero_traversal(bintree->pRootNode);
	printf("\n===========done============\n");

	printf("\n=========postorder=========\n");
	postorder_traversal(bintree->pRootNode);
	visited_zero_traversal(bintree->pRootNode);
	printf("\n===========done============\n");

	deleteBinTree(bintree);

	return 0;
}
