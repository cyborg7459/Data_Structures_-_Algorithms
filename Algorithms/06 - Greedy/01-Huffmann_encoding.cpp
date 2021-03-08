#include <bits/stdc++.h>
using namespace std;

class tree_node {
public:
    int data;
    tree_node* left_child;
    tree_node* right_child;
    tree_node(int x) {
        data = x;
        left_child = nullptr;
        right_child = nullptr;
    }
    tree_node(tree_node* a, tree_node *b) {
        data = a->data + b->data;
        left_child = a;
        right_child = b;
    }
};

class character {
public:
    char c;
    int freq;
    bool operator<(const character* c1) {
        return (this->freq < c1->freq);
    }
    character(char x, int y) {
        c = x;
        freq = y;
    }
};

int main() {
    vector<pair<char, int>> v = {{'a',13}, {'c',5}, {'b',45}, {'d',12}, {'e',16}, {'f',9}};
    priority_queue<int, std::vector<int>, greater<int>> pq;
    for(int i=0; i<v.size(); i++) {
        character* temp = new character(v[i].first, v[i].second);
        pq.push(temp);
    }
    while(!pq.empty()) {
        auto x = pq.top();
        cout << x->c << " " << x->freq << "\n";
        pq.pop();
    }
}
