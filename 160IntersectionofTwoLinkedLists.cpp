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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getLength(headA);
        int lenB = getLength(headB);
        if(lenA<lenB){
            for(int i=0;i<lenB-lenA;++i)
                headB = headB->next;
        }else{
            for(int i=0;i<lenA-lenB;++i)
                headA = headA->next;
        }
        while(headA!=headB){
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
    int getLength(ListNode *node){
        int len = 0;
        while(node){
            ++len;
            node = node->next;
        }
        return len;
    }
};