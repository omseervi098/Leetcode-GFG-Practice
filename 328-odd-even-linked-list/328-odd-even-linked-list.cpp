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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode* temp=head;
        ListNode* t1=NULL,*t2=NULL,*t3=NULL,*t4=NULL;
        int cnt=1;
        while(temp!=NULL){
            if(cnt%2==0){
                if(t2==NULL){
                    t1=new ListNode(temp->val);
                    t2=t1;
                }else{
                    t1->next=new ListNode(temp->val);
                    t1=t1->next;
                }     
            }else{
                if(t4==NULL){
                    t3=new ListNode(temp->val);
                    t4=t3;
                }else{
                    t3->next=new ListNode(temp->val);
                    t3=t3->next;
                }  
            }
            temp=temp->next;
            cnt++;
        }head=t4;
        while(t4->next!=NULL){
            
            t4=t4->next;
        }
        t4->next=t2;
        return head;
    }
};