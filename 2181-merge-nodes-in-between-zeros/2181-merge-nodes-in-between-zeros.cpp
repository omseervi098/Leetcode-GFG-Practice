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
        ListNode* temp=head->next,*prev=head;
        while(temp!=NULL){
            if(temp->val==0){
                prev->val=sm;
                 if(temp->next==NULL)
                {prev->next=NULL;break;}
                prev->next=temp;
                prev=temp;
                sm=0; 
            }else{
                sm+=temp->val;
            }
            temp=temp->next;
        }
        return head;
    }
};