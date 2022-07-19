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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* tmp=head,*prev=nullptr;
        int m=left;
        while(tmp!=nullptr and (left--)>1){
            prev=tmp;
            tmp=tmp->next;
        }if(tmp==nullptr){
            return head;
        }
        ListNode* st=tmp;
        int k=right-m;
        if(prev!=nullptr)prev->next=nullptr;
        while(tmp!=nullptr and (k--)>0){
            cout<<k<<endl;
            tmp=tmp->next;
        }if(tmp==nullptr){
            return head;
        }
        ListNode* next=tmp->next;
        ListNode* end=tmp;
        end->next=nullptr;
        ListNode* newst=reverse(st);
        if(prev==nullptr){
            st->next=next;
            return newst;
        }else{
            prev->next=newst;
            st->next=next;
            return head;
        }
    }
};