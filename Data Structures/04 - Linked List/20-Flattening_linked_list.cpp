// PROBLEM : A linked list is given in such a way that each node can have a sub-linkedlist attached to it at the bottom. This sub-linkedlist is always sorted
// For example :   5 -> 10 -> 19 -> 28
//                 |     |     |     |
//                 7     20    22   35
//                 |           |     |
//                 8          50    40
//                 |                 |
//                 30               45
// Our task is to flatten the given linked list into a sorted linear linked list in O(1) space.
//
// LOGIC USED : Take the first branch as the base branch which would be altered. Now, since each sub-linkelist is sorted, you can use the concept of merging
// of 2 sorted linked list to merge the nodes into the base branch. Do this for all the branches, and at the end rotate the linkedlist by 90 degrees to get
// a sorted linear linked list


#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;

	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}

};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;

			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){

				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}

Node *flatten(Node *root)
{
    Node* node_a = root;
    Node* node_b = node_a->next;
    while(node_b) {
        Node* temp = node_b;
        node_b = node_b->next;
        while(true) {
            if(temp == nullptr) break;
            if(node_a == root && node_a->data > temp->data) {
                Node* temp1 = temp->bottom;
                temp->bottom = node_a;
                root = temp;
                temp = temp1;
                node_a = root;
            }
            else if(node_a->bottom == nullptr) {
               node_a->bottom = temp;
               break;
            }
            else {
                Node* next_node = node_a->bottom;
                if(next_node->data <= temp->data) {
                   node_a = next_node;
                }
                else {
                   Node* temp1 = temp->bottom;
                   node_a->bottom = temp;
                   temp->bottom = next_node;
                   temp = temp1;
                   if(temp == nullptr) break;
                }
            }
        }
        node_a = root;
    }
    Node* cur = root;
    Node* temp = root->bottom;
    while(temp) {
        cur->next = temp;
        cur = cur->next;
        temp = temp->bottom;
    }
    return root;
}
