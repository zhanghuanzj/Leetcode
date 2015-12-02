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
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            return build(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1);
        }

        TreeNode* build(vector<int>& postorder,int l,int r,vector<int>& inorder,int s,int e)
        {
            if (l>r)
            {
                return NULL;
            }
            TreeNode* node = new TreeNode(postorder[r]);
            if (l==r){
                return node;
            }
            else
            {
                int index=s;
                while(inorder[index]!=postorder[r])
                {
                    ++index;
                }
                node->left = build(postorder,l,l+index-s-1,inorder,s,index-1);
                node->right = build(postorder,l+index-s,r-1,inorder,index+1,e);
            }
            return node;
        }
    };