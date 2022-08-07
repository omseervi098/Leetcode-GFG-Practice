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
     ListNode* reverse(ListNode* head){
        if(head==NULL|head->next==NULL)
            return head;
        ListNode* sans=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return sans;
    }
    ListNode* swapPairs(ListNode* head) {
     
        if(head==NULL||head->next==NULL)
            return head;
        int i=0;
        ListNode* temp=head;
        while(i<1&&temp!=NULL){
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
        tail->next=swapPairs(newnode);
        return newhead;
    }
};