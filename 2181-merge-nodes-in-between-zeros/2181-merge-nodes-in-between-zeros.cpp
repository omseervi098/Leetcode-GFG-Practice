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
    ListNode* mergeNodes(ListNode* head) {
        int sm=0;
        //0 3 1 0 
        // 0 4 0 4 5 2 0 
        ListNode* temp=head->next,*prev=head;
        while(temp!=NULL){
            if(temp->val==0){
                prev->next=new ListNode(sm,temp);
                prev=temp;
                sm=0;
            }else{
                sm+=temp->val;
            }
            temp=temp->next;
        }
        ListNode* tmp=head->next;
        while(tmp->next->next!=NULL){
            if(tmp->next->val==0)
                tmp->next=tmp->next->next;
            tmp=tmp->next;
                
        }
        tmp->next=nullptr;
        return head->next;
    }
};