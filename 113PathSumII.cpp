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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
		if (root!=NULL)
		{
			vector<int> path;
			path.push_back(root->val);
			if(root->val==sum&&root->left==NULL&&root->right==NULL) 
			{
			    result.push_back(path);
			    return result;
			}
			solve(path,root->val,sum,result,root->left);
			solve(path,root->val,sum,result,root->right);
		}
		return result;
    }
	void solve(vector<int> &path,int cur,int tar, vector<vector<int>> &result,TreeNode *node)
	{
		if (node==NULL) return;
		else
		{
			if (cur+node->val==tar&&node->left==NULL&&node->right==NULL)
			{
				path.push_back(node->val);
				result.push_back(path);
				path.pop_back();
			}
			else
			{
				path.push_back(node->val);
				solve(path,cur+node->val,tar,result,node->left);
				solve(path,cur+node->val,tar,result,node->right);
				path.pop_back();
			}
		}   
	}
};