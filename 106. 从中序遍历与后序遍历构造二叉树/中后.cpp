/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* TraversalBinaryTree(vector<int>& inorder,vector<int>& postorder)
    {
        //判断数组大小是否为领，如果为零为空结点
        if(postorder.size()==0)
        return nullptr;
        // 从后序遍历中取出最后一个值，即为该结点的值
        int rootv = postorder[postorder.size()-1];
        TreeNode* root = new TreeNode(rootv);
        // 当该结点为叶子结点时，不需要切割数组
        if(postorder.size()==1)
            return root;
        else
        {
            int MIndex;
            for(MIndex = 0; MIndex<inorder.size();MIndex++)
                if(inorder[MIndex] == rootv)
                break;
            vector<int> LInOrder(inorder.begin(),inorder.begin()+MIndex);
            vector<int> RInOrder(inorder.begin()+MIndex+1,inorder.end());
            postorder.resize(postorder.size()-1);
            vector<int> LPostOrder(postorder.begin(),postorder.begin()+MIndex);
            vector<int> RPostOrder(postorder.begin()+MIndex,postorder.end());
            root->left=TraversalBinaryTree(LInOrder,LPostOrder);
            root->right=TraversalBinaryTree(RInOrder,RPostOrder);
            return root;
        }
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        if(inorder.size()==0||postorder.size()==0)
            return NULL;
        else
            return TraversalBinaryTree(inorder,postorder);
    }
};