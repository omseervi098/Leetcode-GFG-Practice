//Problem no 83

//my solution 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL||head->next==NULL)return head;
        ListNode* temp=head;
        ListNode* tail=head->next;
        while(tail!=NULL){
            if(temp->val!=tail->val){
                temp->next=tail;
                temp=tail;
            }tail=tail->next;
        }temp->next=NULL;
        return head;
    }
};
//more better and easy way
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *temp = head;
        
        if (!head) // return if list is empty
            return head;
        
        while (temp -> next != NULL) // loop until you reach end of list
        {
            if (temp -> val == temp -> next -> val) // check if current val equals next val
            {
                temp -> next = temp -> next -> next; // delete duplicate 
            }
            
            else
                temp = temp -> next; // if no duplicate move to next position
        }
        return head;
    }
};