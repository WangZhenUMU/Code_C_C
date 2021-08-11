#pragma once
#include <queue>
#include <vector>
using namespace std;

template<class W>
struct HuffmanTreeNode
{
	HuffmanTreeNode<W>* left;
	HuffmanTreeNode<W>* right;
	W weight;
	HuffmanTreeNode(const W& w = W())
		:left(nullptr)
		,right(nullptr)
		,weight(w)
	{}
};
template<class W>
struct Com
{
	typedef HuffmanTreeNode<W> Node;
	bool operator()(const Node* left, const Node* right)
	{
		return left->weight > right->weight;
	}
};
template<class W>
class HuffmanTree
{
	typedef HuffmanTreeNode<W> Node;
public:
	HuffmanTree()
		:root(nullptr)
	{}
	~HuffmanTree()
	{
		Destrory(root);
	}
	void CreateHuffmanTree(const W array[], size_t size)
	{
		//优先级队列默认为大堆，我们需要小堆，所以需要修改其比较规则
		std::priority_queue<Node*,vector<Node*>,Com<W>> q;
		// 1.先使用所给的权值创建只有根节点的二叉树森林
		for (size_t i = 0; i < size; ++i)
		{
			q.push(new Node(array[i]));
		}
		// 2.循环进行以下步骤，直至二叉树森林只剩一颗二叉树为止。
		while(q.size() > 1)
		{
			// 在二叉树森林中先取权值最小的俩棵二叉树
			Node* left = q.top();
			q.pop();

			Node* right = q.top();
			q.pop();

			//将left和right作为某个新节点的左右子树，构造一个新的二叉树，
			//新二叉树根节点的权值就是其左右孩子的权值之和
			Node* parent = new Node(left->weight + right->weight);
			parent->left = left;
			parent->right = right;
			//将新的二叉树插入到新的二叉树森林中
			q.push(parent);
		}
		root = q.top();
	}
	void Destrory(Node*& proot)
	{
		if (proot)
		{
			Destrory(proot->left);
			Destrory(proot->right);
			delete proot;
			proot = nullptr;
		}
	}
private:
	Node* root;
};
// 测试  
void TestHuffmanTree()
{
	int array[] = { 3,1,7,5 };
	HuffmanTree<int> t;
	t.CreateHuffmanTree(array, sizeof(array) / sizeof(array[0]));
}