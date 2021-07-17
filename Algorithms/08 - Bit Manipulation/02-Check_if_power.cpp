// PS : Given an integer, we have to find whether it can be represented as the power of some number or not
// Explanation : Simply find the log of the number with all bases from 2 till the number. If any one of them given as integer it means that number is power
// V.V.IMP : WITH THE WAY THE FUNCTIONS LIKE LOG, POW, SQRT, etc WORK IN C++, DON'T DIRECTLY EQUATE. INSTEAD, CHECK IF THE ABSOLUTE DIFFERENCE IS NEGLIGIBLE

#include <bits/stdc++.h>
using namespace std;

int isPower(int A) {
    if(A == 0) return 1;
    if(A == 1) return 1;
    if(A == 2) return 0;
    for(int i=2; i<=sqrt(A); i++) {
        double d1 = log2((double)A)/log2((double)i);
		if(abs(ceil(d1) - d1) < 1e-6) return 1;
    }
    return 0;
}

int main() {
	cout << isPower(823543);
}
