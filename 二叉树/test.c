#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"
void TestBinTree()
{
	int array[] = { 1, 2, 3, -1, -1, -1, 4, 5, -1, -1, 6 };
	int index = 0;
	BTNode* root = CrteateBinTree(array, sizeof(array) / sizeof(array[0]), -1);
	printf("二叉树前序遍历结果: ");
	PreOrder(root);
	printf("\n");

	printf("二叉树中序遍历结果: ");
	InOrder(root);
	printf("\n");

	printf("二叉树后序遍历结果: ");
	PostOrder(root);
	printf("\n");

	printf("层序遍历结果: ");
	LevelOrder(root);
	printf("\n");

	printf("树中节点总的个数为:%d\n", BinaryTreeSize(root));
	printf("树中叶子节点总的个数为:%d\n", BinaryTreeLeafSize(root));
	printf("树中第%d层节点总的个数为:%d\n", 3, BinaryTreeLevelKSize(root, 3));
	printf("树高度为:%d\n", BinaryTreeHeight(root));
	printf("查找%p\n", BinaryTreeFind(root, 5));
	printf("查找%p\n", BinaryTreeFind(root, 10));

	printf("%d \n", BinaryTreeComplete(root));

	// 如果想要通过形参改变外部的实参，传参时候
	// 必须传递实参的地址
	DestroyBinTree(&root);
}

int main()
{
	TestBinTree();
	return 0;
}