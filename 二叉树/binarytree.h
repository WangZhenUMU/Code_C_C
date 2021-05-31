#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__
typedef int BDataType;
typedef struct BTNode
{
	BDataType data;
	struct BTNode *left;
	struct BTNode *right;
}BTNode;
//创建二叉树
BTNode* CrteateBinTree(BDataType array[], int size, BDataType invalid);

//二叉树前序遍历
void PreOrder(BTNode* root);
//二叉树中序遍历
void InOrder(BTNode* root);
//二叉树后序遍历
void PostOrder(BTNode* root);
// 层序遍历
void LevelOrder(BTNode* root);
// 求二叉树中节点的个数
int BinaryTreeSize(BTNode* root);
// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root);
// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k);
// 求二叉树的高度
int BinaryTreeHeight(BTNode* root);
// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BDataType x);
// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root);
// 销毁二叉树
void DestroyBinTree(BTNode** root);
#endif // __BINARYTREE_H__

