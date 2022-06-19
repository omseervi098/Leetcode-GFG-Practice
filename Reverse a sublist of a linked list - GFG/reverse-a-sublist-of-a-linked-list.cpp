// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};


 // } Driver Code Ends
//User function Template for C++

/*Link list node 
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
    Node* reverse(Node* head){
        if(head==NULL||head->next==NULL)
        return head;
        Node* sans=reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return sans;
    }
    Node* reverseBetween(Node* head, int m, int n)
    {
        //code here
        int cnt=1;
        Node* ptr=head;
        Node* prev=NULL;
        while(cnt<m){
            prev=ptr;
            ptr=ptr->next;
            cnt++;
        }
        Node* st=ptr;
        while(cnt<n){
            ptr=ptr->next;
            cnt++;
        }
        if(prev!=NULL)
        prev->next=NULL;
        Node* end=ptr;
        Node* endnext=ptr->next;
        end->next=NULL;
        if(prev==NULL){
            Node* temp=reverse(head);
            Node* nhead=temp;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=endnext;
            return nhead;
        }
        Node* temp=reverse(st);
        prev->next=temp;
        while(temp->next!=NULL){
            //cout<<temp->data<<" ";
            temp=temp->next;
        }
        temp->next=endnext;
        return head; 
        
    }
};

// { Driver Code Starts.

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}



// Driver program to test above functions
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int N, m, n;
		cin >> N>>m>>n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

		

        Solution ob;

		Node* newhead = ob.reverseBetween(head, m, n);
		printList(newhead);

		cout << "\n";



	}
	return 0;
}
  // } Driver Code Ends