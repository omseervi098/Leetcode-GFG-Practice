//problem no 2
//time o(max(m,n))
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
    ListNode* reverse(ListNode * head){
        if(head==nullptr||head->next==nullptr)
            return head;
        ListNode* sans=reverse(head->next);
        head->next->next=head;
        head->next=nullptr;
        return sans;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    
        ListNode* temp=l2;
        
        ListNode*ans=nullptr;
        ListNode*tail=nullptr;
        int c=0;
        int sum=0;
        while(l1!=nullptr and l2!=nullptr)
        {
            sum=l1->val+l2->val+c;
            c=sum/10;
            if(tail==nullptr){
                ans=new ListNode(sum%10);
                tail=ans;
            }else{
                ListNode* newn=new ListNode(sum%10);
                newn->next=ans;
                ans=newn;
            }
            l1=l1->next;
            l2=l2->next;
       }
        while(l1!=nullptr){
            sum=l1->val+c;
            c=sum/10;
            sum%=10;
            if(ans==nullptr){
                ans=new ListNode(sum);
                tail=ans;
            }else{
                ListNode* newn=new ListNode(sum);
                newn->next=ans;
                ans=newn;
            }
            l1=l1->next;
        }
        while(l2!=nullptr){
            sum=l2->val+c;
            c=sum/10;
            sum%=10;
            if(ans==nullptr){
                ans=new ListNode(sum);
                tail=ans;
            }else{
                ListNode* newn=new ListNode(sum);
                newn->next=ans;
                ans=newn;
            }
            l2=l2->next;
        }
        if(c==1){
              ListNode* newn=new ListNode(1);
                newn->next=ans;
                ans=newn;
        }
        cout<<ans->val;
        ans=reverse(ans);
        return ans;
        
    }
};