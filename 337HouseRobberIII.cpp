class Solution {
public:
    int rob(TreeNode* root) {
		int l,r;
        return solve(root,l,r);
    }
private:
	int solve(TreeNode* root,int &l,int &r)
	{
		if (root==nullptr)
		{
			return 0;
		}
		int ll=0,lr=0,rl=0,rr=0;
		l = solve(root->left,ll,lr);
		r = solve(root->right,rl,rr);
		return max(l+r,root->val+ll+lr+rl+rr);
	}
};