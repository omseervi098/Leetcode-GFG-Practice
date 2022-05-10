//Problem no 25 hard
//Simple recursive Solution
class Solution {
public:
    ListNode* reverse(ListNode* head){
        if(head==NULL|head->next==NULL)
            return head;
        ListNode* sans=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return sans;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL||head->next==NULL||k==0)
            return head;
        int i=0;
        ListNode* temp=head;
        while(i<k-1&&temp!=NULL){
            temp=temp->next;
            i++;
        }ListNode* newnode;
        if(temp==NULL)
            return head;
        newnode=temp->next;
        temp->next=NULL;
        ListNode* newhead=reverse(head);
        ListNode* tail=newhead;
        while(tail->next!=NULL){
            tail=tail->next;
        }
        tail->next=newnode;
        tail->next=reverseKGroup(newnode,k);
        return newhead;
        
    }
};