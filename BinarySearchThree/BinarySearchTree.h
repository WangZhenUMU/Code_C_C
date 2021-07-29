#pragma once
#include <iostream>
using namespace std;
template<class T>
// ��������������Ľ��
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
	BinarySearchTree()//����
		:root(nullptr)
	{}
	~BinarySearchTree()//����
	{
		Destory(root);
	}
	bool Insert(const T& data) //������
	{
		if (root == nullptr) // ����Ϊ������ֱ�Ӳ��뷵��
		{
			root = new Node(data);
			return true;
		}
		Node* cur = root;
		Node* parent = nullptr;
		while (cur) // �ҳ���������Ĳ���λ��
		{
			parent = cur;
			if (data < cur->data)
				cur = cur->left;
			else if (data > cur->data)
				cur = cur->right;
			else
				return false;
		}
		//��������
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
			if (data == cur->data) // �ҵ�
				return cur;
			else //û���ҵ����Ƚ����vle��������������������
			{
				if (data < cur->data)
					cur = cur->left;
				else
					cur = cur->right;
			}
		}
		return nullptr; // û���ҵ�
	}
	bool Erase(const T& data)
	{
		Node* cur = root;
		Node* parent = nullptr;
		while (cur)
		{
			if (data == cur->data) // �ҵ���
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
		if (nullptr == cur) // û���ҵ�
			return false;
		// ɾ���ҵ��Ľ��
		// ���������
		// c��Ҷ�ӽ��
		// cֻ������
		// cֻ���Һ���
		// c���Һ��Ӷ���
		Node* Delnode = cur;
		//1. curֻ������|curΪҶ��
		if (nullptr == cur->right)
		{
			if (nullptr == parent) // ��ɾ����Ǹ����
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
		// 2.ֻ���Һ���|curΪҶ��
		else if (nullptr == cur->left)
		{
			if (nullptr == parent) // ��ɾ���Ϊ�����
				root = cur->right;
			else
			{
				if (cur == parent->left)
					parent->left = cur->right;
				else
					parent->right = cur->right;
			}
		}
		// 3.���ҽ�㶼��
		else
		{
			//��cur����������������
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
	// �������
	void InOrder()
	{
		_InOrder(root);
		cout << endl;
	}
private:
	void _InOrder(Node* root) // �������
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