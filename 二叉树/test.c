#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"
void TestBinTree()
{
	int array[] = { 1, 2, 3, -1, -1, -1, 4, 5, -1, -1, 6 };
	int index = 0;
	BTNode* root = CrteateBinTree(array, sizeof(array) / sizeof(array[0]), -1);
	printf("������ǰ��������: ");
	PreOrder(root);
	printf("\n");

	printf("����������������: ");
	InOrder(root);
	printf("\n");

	printf("����������������: ");
	PostOrder(root);
	printf("\n");

	printf("����������: ");
	LevelOrder(root);
	printf("\n");

	printf("���нڵ��ܵĸ���Ϊ:%d\n", BinaryTreeSize(root));
	printf("����Ҷ�ӽڵ��ܵĸ���Ϊ:%d\n", BinaryTreeLeafSize(root));
	printf("���е�%d��ڵ��ܵĸ���Ϊ:%d\n", 3, BinaryTreeLevelKSize(root, 3));
	printf("���߶�Ϊ:%d\n", BinaryTreeHeight(root));
	printf("����%p\n", BinaryTreeFind(root, 5));
	printf("����%p\n", BinaryTreeFind(root, 10));

	printf("%d \n", BinaryTreeComplete(root));

	// �����Ҫͨ���βθı��ⲿ��ʵ�Σ�����ʱ��
	// ���봫��ʵ�εĵ�ַ
	DestroyBinTree(&root);
}

int main()
{
	TestBinTree();
	return 0;
}