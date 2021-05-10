// PS : Here we have a linked list with only 0s, 1s and 2s as it's elements and we have to sort it. Generally this is a very easy problem as we can simply calculate the count
// of each of the 3 and then fill the values accordingly. However, in this case, we have to do the sorting without changing the values of the nodes, only changing the links, and
// that too without using any extra space or creating any new Linked List. This situation may arise if there is some extra information linked the the nodes which can't be changed

// Logic : Implemented the same logic as done in partitioning a linked list around a given value

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;

class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        Node* z_head = nullptr;
        Node* z = z_head;
        Node* o_head = nullptr;
        Node* o = o_head;
        Node* t_head = nullptr;
        Node* t = t_head;
        Node* cur = head;
        while(cur) {
            int k = cur->data;
            if(k == 0) {
                if(z == nullptr) {
                    z_head = cur;
                    z = cur;
                }
                else {
                    z->next = cur;
                    z = z->next;
                }
            }
            else if(k == 1) {
                if(o == nullptr) {
                    o_head = cur;
                    o = cur;
                }
                else {
                    o->next = cur;
                    o = o->next;
                }
            }
            else {
                if(t == nullptr) {
                    t_head = cur;
                    t = cur;
                }
                else {
                    t->next = cur;
                    t = t->next;
                }
            }
            cur = cur->next;
        }
        if(z) {
            head = z_head;
            z->next = nullptr;
        }
        if(o) {
            if(!z)
                head = o_head;
            else
                z->next = o_head;
            o->next = nullptr;
        }
        if(t) {
            if(!z && !o)
                head = t_head;
            else if(!o)
                z->next = t_head;
            else
                o->next = t_head;
            t->next = nullptr;
        }
        return head;
    }
};

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void insert(int n1) {
    int n, value, i;
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
