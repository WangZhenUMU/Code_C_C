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
		//���ȼ�����Ĭ��Ϊ��ѣ�������ҪС�ѣ�������Ҫ�޸���ȽϹ���
		std::priority_queue<Node*,vector<Node*>,Com<W>> q;
		// 1.��ʹ��������Ȩֵ����ֻ�и��ڵ�Ķ�����ɭ��
		for (size_t i = 0; i < size; ++i)
		{
			q.push(new Node(array[i]));
		}
		// 2.ѭ���������²��裬ֱ��������ɭ��ֻʣһ�Ŷ�����Ϊֹ��
		while(q.size() > 1)
		{
			// �ڶ�����ɭ������ȡȨֵ��С�����ö�����
			Node* left = q.top();
			q.pop();

			Node* right = q.top();
			q.pop();

			//��left��right��Ϊĳ���½ڵ����������������һ���µĶ�������
			//�¶��������ڵ��Ȩֵ���������Һ��ӵ�Ȩֵ֮��
			Node* parent = new Node(left->weight + right->weight);
			parent->left = left;
			parent->right = right;
			//���µĶ��������뵽�µĶ�����ɭ����
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
// ����  
void TestHuffmanTree()
{
	int array[] = { 3,1,7,5 };
	HuffmanTree<int> t;
	t.CreateHuffmanTree(array, sizeof(array) / sizeof(array[0]));
}