#include <iostream>
#include "BinarySearchTree.h"
using namespace std;
int main()
{
	BinarySearchTree<int> bst;
	int a[] = { 1,3,2,4,6,5,9,8,7 };
	for (auto i : a)
	{
		bst.Insert(i);
	}
	bst.InOrder();
	cout <<"bst.Find(5) : "<<bst.Find(5)<<endl;
	bst.Erase(7);
	bst.InOrder();
	return 0;
}