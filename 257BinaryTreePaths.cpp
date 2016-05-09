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
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<int> path;
		vector<string> paths;
		getPaths(root,paths,path);
		return paths;
	}

	void getPaths(TreeNode *root,vector<string> &paths,vector<int> &path)
	{
		if (root==NULL) return;
		path.push_back(root->val);
		if(root->left==NULL&&root->right==NULL)
		{
			if (!path.empty())
			{
				stringstream ss;
				string s;
				ss<<path.front();
				for (int i=1;i<path.size();++i)
				{
					ss<<"->"<<path[i];
				}
				ss>>s;
				paths.push_back(s);
			}
		}
		else
		{
			getPaths(root->left,paths,path);
			getPaths(root->right,paths,path);
			
		}
		path.pop_back();
	}
};