// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node* partition(struct Node* head, int x);

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
int main(void) {
    int t;
    cin >> t;

    while (t--) {
        struct Node* head = NULL;
        struct Node* temp = NULL;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int value;
            cin >> value;
            if (i == 0) {
                head = new Node(value);
                temp = head;
            } else {
                temp->next = new Node(value);
                temp = temp->next;
            }
        }

        int k;
        cin >> k;

        // Solution ob;

        head = partition(head, k);
        printList(head);
    }

    return (0);
}
// } Driver Code Ends


// User function Template for C++

/*struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/

struct Node* partition(struct Node* head, int x) {
    Node* head1 = nullptr;
    Node* head2 = nullptr;
    Node* head3 = nullptr;
    Node* n1 = head1;
    Node* n2 = head2;
    Node* n3 = head3;
    Node* cur = head;
    while(cur) {
        int t = cur->data;
        if(t < x) {
            if(!head1) {
                head1 = cur;
                n1 = cur;
            } else {
                n1->next = cur;
                n1 = n1->next;
            }
        }
        else if(t == x) {
            if(!head2) {
                head2 = cur;
                n2 = cur;
            } else {
                n2->next = cur;
                n2 = n2->next;
            }
        }
        else {
            if(!head3) {
                head3 = cur;
                n3 = cur;
            } else {
                n3->next = cur;
                n3 = n3->next;
            }
        }
        cur = cur->next;
    }
    if(n1) {
        head = head1;
        n1->next = nullptr;
    }
    if(n2) {
        if(!n1) {
            head = head2;
        }
        else {
            n1->next = head2;
        }
        n2->next = nullptr;
    }
    if(n3) {
        if(!n1 && !n2) {
            head = head3;
        }
        else if(!n2) {
            n1->next = head3;
        }
        else {
            n2->next = head3;
        }
        n3->next = nullptr;
    }
    return head;
}
