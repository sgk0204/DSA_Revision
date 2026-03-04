#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0){
            return false;
        }
        long reverse = 0;
        int xcopy = x;
        while(x > 0){
            reverse = (reverse * 10) + (x %10);
            x /= 10;
        }
        return reverse == xcopy;
    }
};

//Complexity Analysis
//Time Complexity: O(log10(n)) where n is the input number. We are dividing the input number by 10 in every iteration, so the time complexity is O(log10(n)).
//Space Complexity: O(1) since we are using only a constant amount of space to store the variables.