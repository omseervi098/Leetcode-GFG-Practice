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
    ListNode* middle(ListNode* head){
        ListNode* fast=head,*slow=head;
        while (fast->next!=NULL and fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        fast=slow->next;
        slow->next=NULL;
        return fast;
    }
    ListNode* reverse(ListNode* head){
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* sub=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return sub;
    }
    int pairSum(ListNode* head) {
        ListNode* temp=middle(head);
        ListNode* second=reverse(temp);
        ListNode*i=head,*j=second;
        long long mx=0;
        while (i!=nullptr and j!=nullptr){
            long long check=i->val+j->val;
            mx=max(mx,check);
            i=i->next;
            j=j->next;
        }return mx;
    }
};