struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode *newHead = new ListNode(0);
		newHead->next = head;
		head = newHead;
		ListNode *p1,*p2,*p;
		for (int i=1;i<=n;++i)
		{
			if (i==m)
			{
				p1 = head;
			}
			if (i==n)
			{
				p2 = head->next;
			}
			head = head->next;
		}
		while (p1->next!=p2)
		{
			p = p1->next;
			p1->next = p->next;
			p->next = p2->next;
			p2->next = p;
		}
		return newHead->next;
	}
};