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
    int kthSmallest(TreeNode* root, int k) {
        int result;
        solve(root,k,result);
        return result;
    }
    void solve(TreeNode *root,int &k,int &result){
        if(!root) return;
        solve(root->left,k,result);
        if(k==0) return;
        --k;
        if(k==0) {
            result = root->val;
            return;
        }
        solve(root->right,k,result);
    }
};