// A k-sorted linked list is one in which each element is at most 'k' positions away from it's correct sorted position.
// Out task is to sort a k-sorted Linked List.
// Solution : Basic approach would be like insertion sort with n*k complexity. However, we can use a priority_queue to solve it in nlog(k) time complexity

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1000000007

class Node {
public:
	int data;
	Node* next;
	Node* prev;
	Node(int x) {
		data = x;
		next = nullptr;
		prev = nullptr;
	}
};

void printLinkedList(Node* head) {
	Node* cur = head;
	while(cur) {
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << endl;
}

Node* createLinkedList(vector<int> v) {
	Node* head = new Node(v[0]);
	Node* cur = head;
	for(int i=1; i<v.size(); i++) {
		Node* new_node = new Node(v[i]);
		cur->next = new_node;
		new_node->prev = cur;
		cur = cur->next;
	}
	return head;
}

struct compare {
	bool operator()(Node* a, Node* b) {
		return a->data > b->data;
	}
};



signed main()
{
	int k = 2;
	vector<int> v = {3,6,2,12,56,8};
	priority_queue<Node*, vector<Node*>, compare> pq;
	Node* head = createLinkedList(v);
	Node* cur_node = head;
	for(int i=0; i<=k; i++) {
		if(!cur_node) break;
		pq.push(cur_node);
		cur_node = cur_node->next;
	}
	head = pq.top();
	head->prev = nullptr;
	Node* cur = head;
	pq.pop();
	while(!pq.empty()) {
		if(cur_node) {
			pq.push(cur_node);
			cur_node = cur_node->next;
		}
		Node* temp = pq.top();
		pq.pop();
		cur->next = temp;
		temp->prev = cur;
		cur = cur->next;
	}
	cur->next = nullptr;
	printLinkedList(head);
}
