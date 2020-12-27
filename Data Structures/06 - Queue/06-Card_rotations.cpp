// Problem Statement
// ==================================================================================================================================
// Given a sorted deck of cards numbered 1 to N.
// 1) We pick up 1 card and put it on the back of the deck.
// 2) Now, we pick up another card , it turns out to be card numbered 1 , we put it outside the deck.
// 3) Now we pick up 2 cards and put it on the back of the deck.
// 4) Now, we pick up another card and it turns out to be card numbered 2 , we put it outside the deck. ...
// We perform this step till the last card.
// If such arrangement of decks is possible, output the arrangement, if it is not possible for a particular value of N then output -1.

// Explanation
// ===================================================================================================================================
// In the given question, we have to repeatedly remove elements from the front and add them to the back, thus this is a question of
// queue. Now, we need to decide what to store in the queue. As we can see, we just need to know that what index of the array will be
// at the front after given number of operations, and thus the next element should be on that index. Hence, we'll store the indices in
// the queue from 0 to N-1, and then operate accordingly


#include <bits/stdc++.h>
using namespace std;

#define qtime long long q;\
                        cin >> q;\
                        while(q--)
#define nl "\n"
#define int long long
#define loop(i,n) for(long long i=0;i<n;i++)
#define print(x) for(auto t : x)\
                            cout << t << " ";\
                            cout << "\n";
#define fast ios_base::sync_with_stdio(false);\
                     cin.tie(NULL);

void solve() {
    queue <int> q;
    int n;
    cin >> n;
    int arr[n] = {};
    for(int i=0; i<n; i++)
        q.push(i);
    int num = 1;
    while(q.size()!=1) {
        int temp = num;
        while(temp--) {
            int x = q.front();
            q.pop();
            q.push(x);
        }
        int idx = q.front();
        arr[idx] = num;
        q.pop();
        num++;
    }
    int idx = q.front();
    arr[idx] = n;
    print(arr);
}

signed main()
{
//    fileIO;
    fast;
    int q = 1;
    cin >> q;
    while(q--)
        solve();
}
