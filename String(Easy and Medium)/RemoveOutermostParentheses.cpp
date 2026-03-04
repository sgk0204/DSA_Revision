#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeOuterParentheses(string s) {
        int level = 0;
        string res = "";
        for(char c : s){
            if(c == '('){
                if(level > 0){
                    res += c;
                }
                level++;
            }else if (c == ')'){
                level--;
                if(level > 0){
                    res += c;
                }
            }
        }
        return res;
    }
};
int main(){
    Solution s;
    string str = "(()())(())";
    cout << s.removeOuterParentheses(str) << endl;
    return 0;
}

//Complexity Analysis
//Time Complexity: O(n) where n is the length of the input string. We are iterating through the input string once, so the time complexity is O(n).
//Space Complexity: O(n) since we are using a string to store the result, and in the worst case, the result can be of the same length as the input string.