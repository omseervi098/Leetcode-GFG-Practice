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
        ListNode* tmp=head;
        int len=0;
        while(tmp!=NULL){
            tmp=tmp->next;
            len++;
        }return len;
    }
    ListNode* reverse(ListNode* head){
        if(head==NULL|head->next==NULL)
            return head;
        ListNode* sans=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return sans;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || k==0 || head->next==NULL)
            return head;
        int n=length(head);
        k=k%n;if(k==0)return head;
        ListNode* newhead=reverse(head);ListNode* temp=newhead;
        int i=0;
        while(i<k-1&&temp!=NULL){
            temp=temp->next;
            i++;
        }
        ListNode * save=temp->next;
        temp->next=NULL;
        ListNode* firstk=reverse(newhead);
        ListNode *lastk=reverse(save);
        temp=firstk;
        while(temp->next!=nullptr)
            temp=temp->next;
        temp->next=lastk;
        return firstk;
        
    }
};