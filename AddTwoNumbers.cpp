struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/**
*类似于归并排序中的两数组合并，这里要考虑每个value为个位数字
*最终可能有剩余的进位要处理
**/
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode * result = new ListNode(0);
		ListNode * it=result;
		int remain = 0;
		while (l1!=NULL&&l2!=NULL) {
			handle(it,l1->val,l2->val,remain);
			l1 = l1->next;
			l2 = l2->next;
		}
		while (l1!=NULL) {
			handle2(it,l1->val,remain);
			l1 = l1->next;
		}
		while (l2!=NULL) {
			handle2(it,l2->val,remain);
			l2 = l2->next;
		}
		if (remain)
		{
			it->next = new ListNode(remain);
		}
		return result->next;
	}

	void handle(ListNode *& it,int v1,int v2,int & remain) {
		int digital = (v1+v2+remain)%10;
		remain = (v1+v2+remain)/10;
		it->next = new ListNode(digital);
		it = it->next;
	}

	void handle2(ListNode *& it,int v,int & remain)
	{
		int digital = (v+remain)%10;
		remain = (v+remain)/10;
		it->next = new ListNode(digital);
		it = it->next;
	}
};