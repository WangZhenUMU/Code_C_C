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
    TreeNode* TraversalBinaryThree(vector<int>& preorder, vector<int>& inorder)
    {
        if(preorder.size()==0)
            return nullptr;
        int rootv=preorder[0];
        TreeNode* root=new TreeNode(rootv);
        if(preorder.size()>1)
        {
            int index;
            for(index=0;index<inorder.size();index++)
                if(inorder[index]==rootv)
                    break;
            vector<int> Linorder(inorder.begin(),inorder.begin()+index);
            vector<int> Rinorder(inorder.begin()+index+1,inorder.end());
            vector<int> Lpreorder(preorder.begin()+1,preorder.begin()+index+1);
            vector<int> Rpreorder(preorder.begin()+index+1,preorder.end());
            root->left=TraversalBinaryThree(Lpreorder,Linorder);
            root->right=TraversalBinaryThree(Rpreorder,Rinorder);
        }
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        if(preorder.size()==0||inorder.size()==0)
            return nullptr;
        else
            return TraversalBinaryThree(preorder,inorder);
    }
};