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
	 bool isBalanced(TreeNode* root) {
		 int deep;
		 return check(root,deep);
	 }

	 bool check(TreeNode *node,int &deep)
	 {
		 if (node==NULL)
		 {
			 deep = 1;
			 return true;
		 }
		 int lo,ro,ld=0,rd=0;
		 lo = check(node->left,ld);
		 ro = check(node->right,rd);
		 deep = max(ld,rd)+1;
		 return lo&&ro&&(abs(ld-rd)<2);
	 }
 };