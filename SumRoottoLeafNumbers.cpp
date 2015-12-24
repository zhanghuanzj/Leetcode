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
    int sumNumbers(TreeNode* root) {
        int var = 0;
        solve(root,var,0);
        return var;
    }

    void solve(TreeNode* node,int &var,int sum)
    {
    	if (node==NULL)
    	{
    		return;
    	}
    	else if (node->left==NULL&&node->right==NULL)
    	{
    		var += node->val+sum*10;
    	}
    	else
    	{
    		sum = sum*10+node->val;
    		solve(node->left,var,sum);
    		solve(node->right,var,sum);
    	}
    }
};