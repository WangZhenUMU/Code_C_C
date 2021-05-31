#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include "queue.h"
#include "binarytree.h"
BTNode* BuyBinartTreeNode(BDataType data)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (NULL == node)
	{
		assert(0);
		return NULL;
	}
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

// 创建二叉树
BTNode* X_CrteateBinTree(BDataType array[], int size,int* index, BDataType invalid)
{
	BTNode* root = NULL;
	if (*index < size && invalid != array[*index])
	{
		//创建根结点
		root = BuyBinartTreeNode(array[*index]);
		++(*index);
		//创建左子树
		root->left = X_CrteateBinTree(array, size, index, invalid);
		++(*index);
		//创建右子树
		root->right = X_CrteateBinTree(array, size, index, invalid);
	}
	return root;
}
BTNode* CrteateBinTree(BDataType array[], int size, BDataType invalid)
{
	int index = 0;
	return X_CrteateBinTree(array, size, &index, invalid);
}
// 二叉树前序遍历
void PreOrder(BTNode* root)
{
	if (NULL != root)
	{ 
		// 先输出根结点的值
		// 然后遍历左子树
		// 最后遍历右子树
		printf("%d", root->data);
		PreOrder(root->left);
		PreOrder(root->right);
	}
}
// 二叉树中序遍历
void InOrder(BTNode* root)
{
	if (NULL != root)
	{
		// 先遍历左子树
		// 然后输出根结点的值
		// 最后遍历右子树
		PreOrder(root->left);
		printf("%d", root->data);
		PreOrder(root->right);
	}
}
// 二叉树后序遍历
void PostOrder(BTNode* root)
{
	if (NULL != root)
	{
		// 先遍历左子树
		// 然后遍历右子树
		// 最后输出根结点的值
		PreOrder(root->left);
		PreOrder(root->right);
		printf("%d", root->data);
	}
}

// 层序遍历
void LevelOrder(BTNode* root)
{
	//先创建一个队列，并初始化队列
	//将队列的根结点压入队列。
	//设置循环，将队头结点输出同时将该结点的左右子树压入队列（如果存在），最后将队头结点出队；
	Queue q;
	if (NULL == root)
		return;
	QueueInit(&q);
	QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* cur = QueueFront(&q);
		printf("%d", cur->data);
		if (cur->left)
		{
			QueuePush(&q, cur->left);
		}
		if (cur->right)
		{
			QueuePush(&q, cur->right);
		}
		QueuePop(&q);
	}
	QueueDestroy(&q);
}

// 求二叉树中节点的个数
int BinaryTreeSize(BTNode* root)
{
	return NULL == root ? 0 : BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}

// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root)
{
	if (NULL == root)
		return 0;
	if (NULL == root->left&&NULL == root->right)
		return 1;
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}

// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (NULL == root || k == 0)
		return 0;
	if (1 == k)
		return 1;
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}

// 求二叉树的高度
int BinaryTreeHeight(BTNode* root)
{
	if (root)
	{
		int leftheight = BinaryTreeHeight(root->left);
		int rightheight = BinaryTreeHeight(root->right);
		return leftheight > rightheight ? leftheight : rightheight;
	}
	return 0;
}
// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BDataType x)
{
	BTNode* retnode;
	if (NULL == root)
		return NULL;
	//
	if (x == root->data)
		return root;
	if (retnode = BinaryTreeFind(root->left, x))
		return retnode;
	return BinaryTreeFind(root->right, x);
}
// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root)
{
	//用层序遍历的方式进行判断
	Queue q;
	int flag = 0;
	// 当二叉树为空树的时候他是完全二叉树
	if (NULL == root)
		return 1;
	QueueInit(&q);
	QueuePush(&q, root);
	while (QueueEmpty(&q))
	{
		BTNode* cur = QueueFront(&q);
		if (flag)// 从第一个不包含节点之后，所有的节点不能有孩子
		{
			if (cur->left || cur->right)
			{
				QueueDestroy(&q);
				return 0;
			}
		}
		else
		{
			if (cur->left && cur->right)
			{
				QueuePush(&q, cur->left);
				QueuePush(&q, cur->right);
			}
			else if (cur->left)//如果左不为空，右为空，更改标记
			{
				QueuePush(&q, cur->left);
				flag = 1;
			}
			else if (cur->right)//如果右不为空，左为空，则一定不是完全二叉树
			{
				QueueDestroy(&q);
				return 0;
			}
			else//如果左右都为空，则更改标记为1
			{
				flag = 1;
			}
		}
		QueuePop(&q);
	}
	QueueDestroy(&q);
	return 1;
}
// 销毁二叉树
void DestroyBinTree(BTNode** root)
{
	if (NULL == *root)
		return;
	//按照后序遍历的方法进行销毁
	DestroyBinTree(&(*root)->left);
	DestroyBinTree(&(*root)->right);
	free(*root);
	*root = NULL;

}