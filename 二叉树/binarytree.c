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

// ����������
BTNode* X_CrteateBinTree(BDataType array[], int size,int* index, BDataType invalid)
{
	BTNode* root = NULL;
	if (*index < size && invalid != array[*index])
	{
		//���������
		root = BuyBinartTreeNode(array[*index]);
		++(*index);
		//����������
		root->left = X_CrteateBinTree(array, size, index, invalid);
		++(*index);
		//����������
		root->right = X_CrteateBinTree(array, size, index, invalid);
	}
	return root;
}
BTNode* CrteateBinTree(BDataType array[], int size, BDataType invalid)
{
	int index = 0;
	return X_CrteateBinTree(array, size, &index, invalid);
}
// ������ǰ�����
void PreOrder(BTNode* root)
{
	if (NULL != root)
	{ 
		// �����������ֵ
		// Ȼ�����������
		// ������������
		printf("%d", root->data);
		PreOrder(root->left);
		PreOrder(root->right);
	}
}
// �������������
void InOrder(BTNode* root)
{
	if (NULL != root)
	{
		// �ȱ���������
		// Ȼ�����������ֵ
		// ������������
		PreOrder(root->left);
		printf("%d", root->data);
		PreOrder(root->right);
	}
}
// �������������
void PostOrder(BTNode* root)
{
	if (NULL != root)
	{
		// �ȱ���������
		// Ȼ�����������
		// ������������ֵ
		PreOrder(root->left);
		PreOrder(root->right);
		printf("%d", root->data);
	}
}

// �������
void LevelOrder(BTNode* root)
{
	//�ȴ���һ�����У�����ʼ������
	//�����еĸ����ѹ����С�
	//����ѭ��������ͷ������ͬʱ���ý�����������ѹ����У�������ڣ�����󽫶�ͷ�����ӣ�
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

// ��������нڵ�ĸ���
int BinaryTreeSize(BTNode* root)
{
	return NULL == root ? 0 : BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}

// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root)
{
	if (NULL == root)
		return 0;
	if (NULL == root->left&&NULL == root->right)
		return 1;
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}

// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (NULL == root || k == 0)
		return 0;
	if (1 == k)
		return 1;
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}

// ��������ĸ߶�
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
// ����������ֵΪx�Ľڵ�
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
// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root)
{
	//�ò�������ķ�ʽ�����ж�
	Queue q;
	int flag = 0;
	// ��������Ϊ������ʱ��������ȫ������
	if (NULL == root)
		return 1;
	QueueInit(&q);
	QueuePush(&q, root);
	while (QueueEmpty(&q))
	{
		BTNode* cur = QueueFront(&q);
		if (flag)// �ӵ�һ���������ڵ�֮�����еĽڵ㲻���к���
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
			else if (cur->left)//�����Ϊ�գ���Ϊ�գ����ı��
			{
				QueuePush(&q, cur->left);
				flag = 1;
			}
			else if (cur->right)//����Ҳ�Ϊ�գ���Ϊ�գ���һ��������ȫ������
			{
				QueueDestroy(&q);
				return 0;
			}
			else//������Ҷ�Ϊ�գ�����ı��Ϊ1
			{
				flag = 1;
			}
		}
		QueuePop(&q);
	}
	QueueDestroy(&q);
	return 1;
}
// ���ٶ�����
void DestroyBinTree(BTNode** root)
{
	if (NULL == *root)
		return;
	//���պ�������ķ�����������
	DestroyBinTree(&(*root)->left);
	DestroyBinTree(&(*root)->right);
	free(*root);
	*root = NULL;

}