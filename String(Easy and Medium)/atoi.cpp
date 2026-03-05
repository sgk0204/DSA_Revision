#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        int i = 0, sign = 1;
        long res = 0;

        while (i < s.size() && s[i] == ' ') i++;

        if (i == s.size()) return 0;

        if (s[i] == '-') { sign = -1; i++; }

        else if (s[i] == '+') i++;

        while (i < s.size() && isdigit(s[i])) {
            res = res * 10 + (s[i] - '0');

            if (sign * res > INT_MAX) return INT_MAX;
            if (sign * res < INT_MIN) return INT_MIN;

            i++;
        }

        return (int)(sign * res);
    }
};
int main(){
    Solution s;
    string str = "   -42";
    cout << s.myAtoi(str) << endl; // Output: -42
    return 0;
}

//Complexity Analysis
//Time Complexity: O(n) where n is the length of the input string. We are iterating through the input string once, so the time complexity is O(n).
//Space Complexity: O(1) since we are using a constant amount of space to store the result and the sign.