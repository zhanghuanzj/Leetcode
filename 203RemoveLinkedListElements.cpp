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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode node(0);
        node.next = head;
        ListNode *p = &node;
        while(p->next){
            if(p->next->val==val){
                ListNode *q = p->next;
                p->next = p->next->next;
                delete q;
            }else{
                p = p->next;
            }
        }
        return node.next;
    }
};