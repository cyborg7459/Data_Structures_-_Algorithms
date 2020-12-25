// Problem statement : To have a special stack from which we can retreive the minimum value in O(1)

// Explanation :-
// We store a separate global variable min, which has to hold the current value of minimum element. Now suppose we push x into the stack when the stack is empty, then we directly
// push x and make min = x. However if the stack is non-empty and the element to be added is smaller than the current minimum, then instead of storing x in stack, we store (2*x - min) into the
// stack and put min = x. So the stack doesn't hold the actual value, but the variable min does.

// Now when we are popping the elements then if the number is greater than min then we pop off normally, but if it is smaller than min it means that we are removing the current minimum value.

// How do we know that if x is smaller than min then we are removing the current minimum?? This is related to the way we pushed the elemnts into the stack. If a new minimum was encountered then we
// stored it as (2*new_min - prev_min). Now since (new_min < prev_min), hence this expression's value is smaller than (new_min) value, thus the value pushed into the stack is smaller than the value
// of value assigned to min variable.

// Now we replace min by (2*min - x), and pop off x. How does this help?
// While pushing elements into the stack, when we would have encounterd this min value, then we stored it in the stack as (2*x - prev_min), and stored the value x in min. Now on doing 2*min-x
// we are doing 2*x - (2*x - prev_min), hence the value of min becomes equal to the prev_min, which was the minimum value before that element was added, which is now the minimum value as we
// popped off the current minimum

#include <bits/stdc++.h>
using namespace std;

class SpecialStack {
private:
    stack<int> st;
    int min;
public:
    Stack() {};
    bool isEmpty();
    void push(int x);
    int pop();
    int minEl();
};

bool SpecialStack::isEmpty() {
    return st.empty();
}

void SpecialStack::push(int x) {
    if(isEmpty()) {
        min = x;
        st.push(x);
    }
    else {
        if(x < min) {
            st.push(2*x - min);
            min = x;
        }
        else
            st.push(x);
    }
}

int SpecialStack::pop() {
    int res = st.top();
    if(res >= min) {
        st.pop();
        return res;
    }
    else {
        int temp = min;
        min = 2*min - res;
        st.pop();
        return temp;
    }
}

int SpecialStack::minEl() {
    if(isEmpty())
        return -1;
    return min;
}

int main() {
    SpecialStack stk;
    stk.push(10);
    cout << stk.minEl() << "\n";
    stk.push(8);
    cout << stk.minEl() << "\n";
    stk.push(16);
    cout << stk.minEl() << "\n";
    stk.push(9);
    cout << stk.minEl() << "\n";
    stk.push(4);
    cout << stk.minEl() << "\n";
    while(!stk.isEmpty()) {
        cout << "Popped off " << stk.pop() << " from stack\n";
        cout << "Minimum value in stack is " << stk.minEl() << "\n";
    }
}
