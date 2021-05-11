#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1000000007

class node {
public:
	int data;
	node* next;
	node(int x) {
		data = x;
		next = nullptr;
	}
};

node* reverseLinkedList(node* head) {
	node* n1 = head;
	node* n2 = n1->next;
	while(n2) {
		node* temp = n2->next;
		n2->next = n1;
		if(n1 == head)
			n1->next = nullptr;
		n1 = n2;
		n2 = temp;
	}
	head = n1;
	return head;
}

void printLinkedList(node* head) {
	node* cur = head;
	while(cur) {
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << "\n";
}

node* convertNumberToLinkedList(int n) {
	node* head = new node(-1);
	node* cur = head;
	while(n > 0) {
		int rem = n%10;
		if(cur->data == -1)
			cur->data = rem;
		else {
			node* new_node = new node(rem);
			cur->next = new_node;
			cur = cur->next;
		}
		n/=10;
	}
	head = reverseLinkedList(head);
	return head;
}

node* subtractNumbersInLinkedListRepresentation(node* head1, node* head2) {
	head1 = reverseLinkedList(head1);
	head2 = reverseLinkedList(head2);
	node* n1 = head1;
	node* n2 = head2;
	bool borrow = false;
	while(n2) {
		if(borrow)
			n1->data--;
		if(n1->data < n2->data) {
			n1->data += 10;
			borrow = true;
		}
		else
			borrow = false;
		n1->data -= n2->data;
		n1 = n1->next;
		n2 = n2->next;
	}
	while(borrow && n1) {
		n1->data--;
		if(n1->data < 0) {
			n1->data += 10;
		} else {
			borrow = false;
		}
		n1 = n1->next;
	}
	if(head1 == nullptr)
		return head1;
	head1 = reverseLinkedList(head1);
	while(head1 && head1->data == 0)
		head1 = head1->next;
	return head1;
}

signed main()
{
	int q;
	cout << "Enter number of queries : ";
	cin >> q;
	while(q--) {
		int a, b;
		cout << "Enter first number : ";
		cin >> a;
		cout << "Enter second number : ";
		cin >> b;
		bool neg = false;
		if(b > a) {
			int temp = a;
			a = b;
			b = temp;
			neg = true;
		}
		node* head1 = convertNumberToLinkedList(a);
		node* head2 = convertNumberToLinkedList(b);
		head1 = subtractNumbersInLinkedListRepresentation(head1, head2);
		if(head1 == nullptr)
			cout << "0\n";
		else {
			if(neg)
				cout << "- ";
			printLinkedList(head1);
		}
	}
}
