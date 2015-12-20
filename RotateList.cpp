/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *last=head;
		if (head==nullptr)
		{
			return head;
		}
		int size = 1;
		while (last->next!=nullptr)
		{
			last = last->next;
			++size;
		}
		int off =(size-k%size)%size;
		ListNode *pre=head,*newHead=pre->next;
		if (off==0)
		{
			return head;
		}
		else
		{
			while (--off)
			{
				pre = pre->next;
				newHead = pre->next;
			}
		}
		last->next = head;
		pre->next = nullptr;
		head = newHead;
		return head;
    }
};