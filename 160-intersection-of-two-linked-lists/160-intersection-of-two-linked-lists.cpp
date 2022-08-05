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
        ListNode* h1=headA,*h2=headB;
        while(h1!=nullptr and h2!=nullptr and h1!=h2){
            h1=h1->next;
            h2=h2->next;
            if(h1==h2) return h1;
            if(h1==nullptr) h1=headA;
            if(h2==nullptr) h2=headB;
        }
        return h1;
        
    }
};