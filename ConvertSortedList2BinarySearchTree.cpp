/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
	TreeNode* generate(int n)
	{
		if (n==0)
		{
			return NULL;
		}
		TreeNode *node = new TreeNode(0);
		node->left = generate(n/2);                  //先构造左子树
		node->val = list->val;                       //构造中节点
		list = list->next;                           //链表推进
		node->right = generate(n-n/2-1);             //构造右子树
		return node;
	}
    TreeNode* sortedListToBST(ListNode* head) {
        int size = 0;
        this->list = head;
        while(head!=NULL)
        {
        	++size;
        	head = head->next;
        }
        return generate(size);
    }
private:
	ListNode *list;
};