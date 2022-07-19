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
        if(head==NULL)
            return 0;
        return 1+length(head->next);
    }
    ListNode* swapNodes(ListNode* head, int k) {
        if(head==NULL or head->next==NULL)return head;
        ListNode* fast=head,*slow=head,*prevf=NULL,*prevs=NULL;
        int l=length(head);
        int lastk=l-k+1;
        if(k>l)return head;
        if(k>lastk){
            int tmp=k;
            k=lastk;lastk=tmp;
        }else if(k==lastk)return head;
        for(int i=0;i<k-1 and fast!=NULL;i++){
            prevs=slow;
            slow=slow->next;fast=fast->next;
        }
        for(int i=k-1;i<lastk-1 and fast!=NULL;i++){
            prevf=fast;
            fast=fast->next;
        }
        
        if(prevf==slow ){
            if(prevs==NULL){
                slow->next=fast->next;
                fast->next=prevf;
                return fast;
            }
            slow->next=fast->next;
            prevs->next=fast;
            fast->next=prevf;
            return head;
        }else if(prevs==NULL and prevf!=slow){
            ListNode* tmp=slow->next;
            slow->next=fast->next;
            fast->next=tmp;
            prevf->next=slow;
            head=fast;
            return head;
        }else{
            ListNode* tmp=slow->next;
            slow->next=fast->next;
            fast->next=tmp;
            prevf->next=slow;
            prevs->next=fast;
            return head;
        }
        
        cout<<slow->val<<" "<<fast->val<<endl;
        return head;
    }
};