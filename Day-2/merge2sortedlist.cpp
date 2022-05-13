//problem no 21
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
        ListNode* h1=list1;
        ListNode* h2=list2;
        ListNode* fh=NULL;
        ListNode* ft=NULL;
        while(h1!=NULL and h2!=NULL)
        {
            if(h1->val<h2->val){
                if(fh==NULL){
                    fh=new ListNode(h1->val);
                    ft=fh;
                }else{
                    ft->next=new ListNode(h1->val);
                    ft=ft->next;
                }
                h1=h1->next;
            }else{
                if(fh==NULL){
                    fh=new ListNode(h2->val);
                    ft=fh;
                }else{
                    ft->next=new ListNode(h2->val);
                    ft=ft->next;
                }h2=h2->next;
            }
        }
        if(h1!=NULL){
            if(fh==NULL){
                    fh=h1;
                    ft=fh;
            }else{
                    ft->next=h1;
            }
            
        }
        if(h2!=NULL){
            if(fh==NULL){
                    fh=h2;
                    ft=fh;
                }else{
                    ft->next=h2;
                }
        }
        
        return fh;
    }
};