#include <bits/stdc++.h>
using namespace std;

int top = -1;

void check(string s, char stack[]) {
    top=-1;
    for(int i=0; i<s.length(); i++) {
        if(s[i]=='(') {
            top = top+1;
            stack[top] = '(';
        }
        else if(s[i]==')') {
            if(top==-1) {
                top--;
                break;
            }
            else
                top--;
        }
    }
    if(top==-1)
        cout << "String is balanced\n";
    else
        cout << "Unbalanced\n";
}

int main() {
    string name = "(My name is Shreyash ((Kumar (Singh (!!)))))(";
    string name2 = "(Nice))(to meet you";
    char stack[1000];
    check(name, stack);
    check(name2, stack);
}
