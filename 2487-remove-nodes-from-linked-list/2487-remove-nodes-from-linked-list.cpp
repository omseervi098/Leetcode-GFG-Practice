/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* helper(ListNode* head){
        if(head==nullptr ) return nullptr;
        ListNode* sub=helper(head->next);
        if(sub!=nullptr and head->val<sub->val){
            return sub;
        }
            head->next=sub;
        return head;
    }
    ListNode* removeNodes(ListNode* head) {
        return helper(head);
    }
};