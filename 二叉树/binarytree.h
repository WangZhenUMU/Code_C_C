#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__
typedef int BDataType;
typedef struct BTNode
{
	BDataType data;
	struct BTNode *left;
	struct BTNode *right;
}BTNode;
//����������
BTNode* CrteateBinTree(BDataType array[], int size, BDataType invalid);

//������ǰ�����
void PreOrder(BTNode* root);
//�������������
void InOrder(BTNode* root);
//�������������
void PostOrder(BTNode* root);
// �������
void LevelOrder(BTNode* root);
// ��������нڵ�ĸ���
int BinaryTreeSize(BTNode* root);
// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root);
// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k);
// ��������ĸ߶�
int BinaryTreeHeight(BTNode* root);
// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BDataType x);
// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root);
// ���ٶ�����
void DestroyBinTree(BTNode** root);
#endif // __BINARYTREE_H__

