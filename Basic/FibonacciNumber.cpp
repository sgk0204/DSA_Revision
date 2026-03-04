#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        else if(n == 1) return 1;
        else{
            return fib(n-1) + fib(n-2);
        }
    }
};

//Complexity Analysis
//Time Complexity: O(2^n) since we are making two recursive calls for each non-base case.
//Space Complexity: O(n) since the maximum depth of the recursion tree can be n in