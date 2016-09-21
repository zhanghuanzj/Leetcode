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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int leftHeight = 0,rightHeight = 0;
        TreeNode *left = root,*right = root;
        while(left){
            ++leftHeight;
            left = left->left;
        }
        while(right){
            ++rightHeight;
            right = right->right;
        }
        if(leftHeight==rightHeight) return pow(2,leftHeight)-1;
        return countNodes(root->left)+countNodes(root->right)+1;
    }
};