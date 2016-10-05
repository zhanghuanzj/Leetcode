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
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr) return head;
        ListNode *odd = head,*even = head,*newHead = head;
        head = head->next;
        int index = 2;
        while(head){
            if(index&1){
                ListNode *next = head->next;
                head->next = odd->next;
                odd->next = head;
                head = next;
                odd = odd->next;
            }else{
                even->next = head;
                head = head->next;
                even = even->next;
                even->next = nullptr;
            }
            ++index;
        }
        return newHead;
    }
};