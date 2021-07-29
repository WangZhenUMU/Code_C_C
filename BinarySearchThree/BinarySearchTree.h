#pragma once
#include <iostream>
using namespace std;
template<class T>
// 定义二叉搜索数的结点
struct BSTNode
{
	BSTNode(const T& x = T())
		:left(nullptr), right(nullptr), data(x)
	{}
	BSTNode<T>*left;
	BSTNode<T>*right;
	T data;
};

template<class T>
class BinarySearchTree
{
	typedef BSTNode<T> Node;
public:
	BinarySearchTree()//构造
		:root(nullptr)
	{}
	~BinarySearchTree()//析构
	{
		Destory(root);
	}
	bool Insert(const T& data) //插入结点
	{
		if (root == nullptr) // 假设为空树，直接插入返回
		{
			root = new Node(data);
			return true;
		}
		Node* cur = root;
		Node* parent = nullptr;
		while (cur) // 找出待插入结点的插入位置
		{
			parent = cur;
			if (data < cur->data)
				cur = cur->left;
			else if (data > cur->data)
				cur = cur->right;
			else
				return false;
		}
		//将结点插入
		cur = new Node(data);
		if (data < parent->data)
			parent->left = cur;
		else
			parent->right = cur;
		return true;

	}
	Node* Find(const T& data)const
	{
		Node* cur = root;
		while (cur)
		{
			if (data == cur->data) // 找到
				return cur;
			else //没有找到，比较这个vle在左左子树还是右子树
			{
				if (data < cur->data)
					cur = cur->left;
				else
					cur = cur->right;
			}
		}
		return nullptr; // 没有找到
	}
	bool Erase(const T& data)
	{
		Node* cur = root;
		Node* parent = nullptr;
		while (cur)
		{
			if (data == cur->data) // 找到了
				break;
			else
			{
				parent = cur;
				if (data < cur->data)
					cur = cur->left;
				else
					cur = cur->right;
			}
		}
		if (nullptr == cur) // 没有找到
			return false;
		// 删除找到的结点
		// 分情况讨论
		// c是叶子结点
		// c只有左孩子
		// c只有右孩子
		// c左右孩子都有
		Node* Delnode = cur;
		//1. cur只有左孩子|cur为叶子
		if (nullptr == cur->right)
		{
			if (nullptr == parent) // 待删结点是根结点
			{
				root = cur->left;
			}
			else
			{
				if (cur == parent->left)
					parent->left = cur->left;
				else
					parent->right = cur->left;
			}
		}
		// 2.只有右孩子|cur为叶子
		else if (nullptr == cur->left)
		{
			if (nullptr == parent) // 待删结点为根结点
				root = cur->right;
			else
			{
				if (cur == parent->left)
					parent->left = cur->right;
				else
					parent->right = cur->right;
			}
		}
		// 3.左右结点都有
		else
		{
			//在cur的子树中找替代结点
			parent = cur;
			Delnode = cur->left;
			while (Delnode->right)
			{
				parent = Delnode;
				Delnode = Delnode->right;
			}
			cur->data = Delnode->data;
			if (Delnode == parent->left)
				parent->left = Delnode->left;
			else
				parent->right = Delnode->left;
		}
		delete(Delnode);
		return true;
	}
	// 中序遍历
	void InOrder()
	{
		_InOrder(root);
		cout << endl;
	}
private:
	void _InOrder(Node* root) // 中序遍历
	{
		if (root)
		{
			_InOrder(root->left);
			cout << root->data<<" ";
			_InOrder(root->right);
		}
	}

	void Destory(Node* &root)
	{
		if (root)
		{
			Destory(root->left);
			Destory(root->right);
			delete root;
			root = nullptr;
		}
	}
	BSTNode<T>* root;
};