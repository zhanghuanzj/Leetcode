class Solution {
public:
	vector<TreeNode*> generateTrees(int n) {
		if(n==0) return vector<TreeNode*>();
		return generateTree(1,n+1);
	}
	vector<TreeNode*> generateTree(int left,int right)
	{
		vector<TreeNode*> result;
		if (left==right)
		{
			result.push_back(nullptr);
		}
		for (int i=left;i<right;++i)
		{
			vector<TreeNode*> lefts = generateTree(left,i);
			vector<TreeNode*> rights = generateTree(i+1,right);
			for (auto lt : lefts)
			{
				for (auto rt: rights)
				{
					TreeNode *root = new TreeNode(i);
					root->left = lt;
					root->right = rt;
					result.push_back(root);
				}
			}
		}
		return result;
	}
};