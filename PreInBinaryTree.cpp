/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }

    TreeNode* build(vector<int>& preorder,int l,int r,vector<int>& inorder,int s,int e)
    {
    	if (l>r)
    	{
    		return NULL;
    	}
    	TreeNode* node = new TreeNode(preorder[l]);
    	if (l==r)
    	{
    		return node;
    	}
    	else
    	{
    		int index=s;
    		while(inorder[index]!=preorder[l])
    		{
    			++index;
    		}
    		node->left = build(preorder,l+1,l+index-s,inorder,s,index-1);
    		node->right = build(preorder,l+index-s+1,r,inorder,index+1,e);
    	}
    	return node;
    }
};