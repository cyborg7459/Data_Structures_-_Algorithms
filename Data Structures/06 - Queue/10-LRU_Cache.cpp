// LRU (Least recently used) Cache is a system of caching data. We store the data in key-value pairs. In case the cache is full and we wish to add a new element, then we remove the least
// recently used element from the cache, i.e. the element that has been updated or called the least recently. The GET and SET, both operations need to be in O(1) time

// Explanation :-
// 1) CHOICE OF DATA STRUCTURE : First of all, we need to fetch the key values in O(1) time, and hence we need to use a hashmap. Also, there cannot be duplicate keys, thus an unordered_map
//    would suffice. Secondly, in the actual cache itself, we need to delete elements from random position in O(1) time, and hence the data structure suited for the job would be a doubly
//    linked list
// 2) ALGORITHM : In the linked list, we'll store key-value pairs, and in the hashmap, we'll store the iterator to that key (iterator because we do not have indexes in a linked list). Hence
//    if we need to GET an element, we simply extract the iterator to that key in O(1) time and print it's value. Also, we delete that element from the cache and push it to the back as it has
//    been used most recently, and then accordingly update the iterator value in the hashmap. While SET operation, if the key is already present, we'll change the value and then push the key
//    to the back of the cache and update the iterator value. In case the key is not present, then we remove the first element of the doubly linked list, as it would be the  least recently used
//    element. We'll also remove that from the hashmap and then add the new key-value pair to the cache as well as the hashmap, all in O(1) time

#include <bits/stdc++.h>
using namespace std;

class LRUCache {
private:
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    list<pair<int, int>> v;
    int capacity;

public:
    LRUCache(int cap) {
        capacity = cap;
        mp.clear();
        v.clear();
    }

    int get(int key) {
        auto it = mp.find(key);
        if(it == mp.end()) return -1;
        else {
            auto list_it = it->second;
            int key = list_it->first;
            int value = list_it->second;
            v.erase(list_it);
            v.push_back({key, value});
            auto new_it = --v.end();
            it->second = new_it;
            return value;
        }
    }

    void set(int key, int value) {
        auto it = mp.find(key);
        if(it == mp.end()) {
            if(v.size() == capacity) {
                int lru_key = v.begin()->first;
                mp.erase(mp.find(lru_key));
                v.erase(v.begin());
            }
            v.push_back({key, value});
            auto new_it = --v.end();
            mp.insert({key, new_it});
            return;
        }
        else {
            auto list_it = it->second;
            v.erase(list_it);
            v.push_back({key, value});
            auto new_it = --v.end();
            it->second = new_it;
            return;
        }
    }
};

int main() {
    cout << "Enter size of cache : ";
    int capacity;
    cin >> capacity;
    LRUCache *cache = new LRUCache(capacity);
    cout << "Enter number of queries : ";
    int queries;
    cin >> queries;
    while (queries--) {
        cout << "Enter query type (SET/GET) : ";
        string q;
        cin >> q;
        if (q == "S") {
            cout << "Enter key : ";
            int key;
            cin >> key;
            cout << "Enter value : ";
            int value;
            cin >> value;
            cache->set(key, value);
            cout << "Value set\n";
        }
        else {
            cout << "Enter key : ";
            int key;
            cin >> key;
            cout << cache->get(key) << endl;
        }
    }
}
