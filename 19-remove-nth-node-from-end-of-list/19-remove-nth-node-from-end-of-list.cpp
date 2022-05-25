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
    int length(ListNode* head){
        int len=0;
        while(head!=NULL)
        {
            head=head->next;len++;
        }
        return len;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL)
            return NULL;
        int l=length(head);
        if(n>l)
            return head;
        ListNode* h=head;
        int pos=l-n;
        if(pos==0)
            return head->next;
        else{
            int i=0;
            while(i<pos-1 and head->next!=NULL){
                head=head->next;i++;
            }
            if(head->next!=NULL){
                head->next=head->next->next;
            }
        }
        return h;
    }
};