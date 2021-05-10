// PS : Reverse groups of k elements in a linked printList

#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node* next;

    node(int x){
        data = x;
        next = NULL;
    }

};

void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    {
        if(k == 1) return head;
    	node* start = head;
    	node* end = start;
    	node* prev_start = nullptr;
    	node* next_start = nullptr;
    	while(true) {
    		int temp = k-1;
    		while(temp > 0 && end->next) {
    			end = end->next;
    			temp--;
    		}
    		if(end->next) next_start = end->next;
    		node* n1 = start;
    		node* n2 = n1->next;
    		while(n2) {
    			if(n2 == next_start) break;
    			node* temp = n2->next;
    			n2->next = n1;
    			n1 = n2;
    			n2 = temp;
    		}
    		if(start == head) head = end;
    		if(prev_start) prev_start->next = end;
    		prev_start = start;
    		prev_start->next = nullptr;
    		start = next_start;
    		end = start;
    		next_start = nullptr;
    		if(start == nullptr) break;
    	}
    	return head;
    }
};

int main(void)
{
    int t;
    cin>>t;

    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;

        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }

        int k;
        cin>>k;

        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }

    return(0);
}
