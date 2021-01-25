#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* next;
    node() {
        data = -1;
        next = nullptr;
    }
    node(int x) {
        data = x;
        next = nullptr;
    }
};

class HashTable {
private:
    node* arr[10];
public:
    HashTable() {
        for(int i=0; i<10; i++) {
            arr[i] = new node;
        }
    }
    void insert_element(int x) {
        int idx = x%10;
        addNode(idx, x);
    };
    void delete_element(int x) {
        int t = x%10;
        deleteNode(t, x);
    };
    bool search(int x) {
        int t = x%10;
        return searchNode(t, x);
    };
    void addNode(int idx, int x);
    void deleteNode(int idx, int x);
    bool searchNode(int idx, int x);
};

void HashTable::addNode(int idx, int x) {
    node* cur = arr[idx];
    if(cur == nullptr) {
        cur = new node;
        node* new_node = new node(x);
        cur->next = new_node;
        return;
    }
    while(true) {
        node* temp = cur->next;
        if(temp == nullptr) {
            node* new_node = new node(x);
            cur->next = new_node;
            return;
        }
        else if(temp->data >= x) {
            node* new_node = new node(x);
            new_node->next = temp;
            cur->next = new_node;
            return;
        }
        cur = cur->next;
    }
}

void HashTable::deleteNode(int idx, int x) {
    node* cur = arr[idx];
    if(cur == nullptr) return;
    while(true) {
        node* temp = cur->next;
        if(temp == nullptr) return;
        if(temp->data == x) {
            cur->next = temp->next;
            delete temp;
            return;
        }
        cur = cur->next;
    }
}

bool HashTable::searchNode(int idx, int x) {
    node* cur = arr[idx];
    while(true) {
        if(cur == nullptr) return false;
        else if(cur->data == x) return true;
        cur = cur->next;
    }
}

int main() {
    HashTable ht;
    ht.insert_element(4);
    ht.insert_element(12);
    ht.insert_element(6);
    ht.insert_element(22);
    ht.insert_element(11);
    ht.insert_element(24);
    ht.insert_element(432);
    ht.insert_element(45);
    ht.insert_element(55);
    ht.delete_element(22);
    if(ht.search(432))
        cout << "Found\n";
}
