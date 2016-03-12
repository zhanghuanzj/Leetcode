class Solution {
public: 
    bool isPalindrome(ListNode *head) {
        left = head;
		return check(head);
    }
	bool check(ListNode *right)
	{
		if (right==nullptr)
		{
			return true;
		}
		bool result = check(right->next)&&(right->val==left->val);
		left = left->next;
		return result;
	}
private:
	ListNode *left;
};