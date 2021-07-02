// PS : Given a stream of integers, at each step we have to find out the median value of all the integers which have come up till now
// Explanation : Here the brute force method is to sort the array at each step and return the median accordingly. However, the time complexity of this solution would be O(n^2 * log(n)) which
// is quite inefficient. Instead, we can convert this into O(n*log(n)). For this, we keep 2 heaps, one a max heap and other a min heap. The max heap stores the left half of the stream of
// integers and the min heap stores the right half. Hence, it is obvious that in case left heap has one extra element that is the median, otherwise the avg of maximum of the left half and the minimum
// of the right half give the median.
// The important thing is how to store the elements to ensure that we get desirable results. For this we need to ensure that the smaller half goes in max heap and vice versa. Hence we'll add
// the elements one by one alternately in both heaps. If the number to be added in max heap is greater than the minimum number of the min heap (which is accessible as top() that's why we took
// min heap), then interchange the 2. Similarly, if the number to be added in the min heap is smaller than the maximum number of the max heap, again interchange

#include <bits/stdc++.h>
using namespace std;

priority_queue<int> pql;
priority_queue<int, vector<int>, greater<int>> pqr;
bool b = true;

void insertHeap(int &x) {
    if(b) {
        if(pqr.size()==0) pql.push(x);
        else {
            int num = pqr.top();
            pqr.pop();
            if(x > num) {
                pql.push(num);
                pqr.push(x);
            }
            else {
                pql.push(x);
                pqr.push(num);
            }
        }
    }
    else {
        int num = pql.top();
        pql.pop();
        if(x < num) {
            pql.push(x);
            pqr.push(num);
        }
        else {
            pql.push(num);
            pqr.push(x);
        }
    }
    b = !b;
}

double getMedian() {
    if(pql.size() > pqr.size()) return pql.top();
    else {
        int a = pql.top();
        int b = pqr.top();
        return (double)(a+b)/2;
    }
}

int main() {
    int n, x;
	cin >> n;
	for(int i = 1;i<= n; ++i) {
		cin >> x;
		insertHeap(x);
	    cout << floor(getMedian()) << endl;
	}
}
