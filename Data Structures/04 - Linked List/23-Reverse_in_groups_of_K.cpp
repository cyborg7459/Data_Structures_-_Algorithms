// PS : Reverse groups of k elements in a linked list
// Explanation : For reversing in groups of k, we first traverse k elements and fix the start and end nodes. Now these are the things that we have to ensure while reversing :-
// 1) The links are reversed from the start node to the end node
// 2) The start node of the previous group points at the end of this group (as the previous start has now become end, and current end will now become start)
// 3) The current start will become end, hence it should be stored somewhere so that it can be used to point to the next group

#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node* next;

    node(int x){
        data = x;
        next = NULL;
    }

};

void printList(struct node *node) {
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

struct node *reverse (struct node *head, int k) {
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

int main() {
    struct node* head = NULL;
    struct node* temp = NULL;
    int n;
    cin >> n;

    for(int i=0 ; i<n ; i++) {
        int value;
        cin >> value;
        if(i == 0) {
            head = new node(value);
            temp = head;
        }
        else {
            temp->next = new node(value);
            temp = temp->next;
        }
    }

    int k;
    cin>>k;

    head = reverse(head, k);
    printList(head);
}
