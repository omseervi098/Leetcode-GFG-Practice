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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *p1=list1,*p2=list2,*prev=NULL,*head=NULL,*tail=NULL;
        if(p1 and p2 and p1->val<=p2->val) head=p1;
        else if(p1 and p2 and p2->val<p1->val) head=p2;
        tail=head;
        while(p1!=NULL and p2!=NULL){
            if(p1->val<=p2->val){
                prev=NULL;
                while(p1!=NULL and p1->val<=p2->val){
                    prev=p1;
                    p1=p1->next;
                }
                prev->next=p2;
            }else{
                prev=NULL;
                while(p2!=NULL and p2->val<p1->val){
                    prev=p2;
                    p2=p2->next;
                }
                prev->next=p1;
            }
            
        }
        if(p1!=NULL){
            if(prev==NULL) return p1;
            else
            prev->next=p1;
        }
        if(p2!=NULL){
            if(prev==NULL) return p2;
            else prev->next=p2;
        }
        return head;
        
    }
};